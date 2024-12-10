﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PacketGenerator
{
    class PacketManagerCodeGenForamt
    {
        // 패킷 매니저 포맷
        // {0} 새로운 패킷 Register 부분
        // {1} 패킷 로그 적용 포맷
        public static string managerFormat =
@"using Google.Protobuf;
using Google.Protobuf.Protocol;
using ServerCore;
using System;
using System.Collections.Generic;

public enum MsgId
{{{0}
}}

class PacketManager
{{
	#region Singleton
	static PacketManager _instance = new PacketManager();
	public static PacketManager Instance {{ get {{ return _instance; }} }}
	#endregion

	PacketManager()
	{{
		Register();
	}}

	Dictionary<ushort, Action<PacketSession, ArraySegment<byte>, ushort>> _packetCreatorMap = new Dictionary<ushort, Action<PacketSession, ArraySegment<byte>, ushort>>();
	Dictionary<ushort, Action<PacketSession, IMessage>> _packetHandlerMap = new Dictionary<ushort, Action<PacketSession, IMessage>>();
		
	public Action<PacketSession, ushort, IMessage> CustomHandler {{ get; set; }}

	public void Register()
	{{{1}
	}}

	public void OnRecvPacket(PacketSession session, ArraySegment<byte> buffer)
	{{
		ushort count = 0;

		ushort size = BitConverter.ToUInt16(buffer.Array, buffer.Offset);
		count += 2;
		ushort id = BitConverter.ToUInt16(buffer.Array, buffer.Offset + count);
		count += 2;

		Action<PacketSession, ArraySegment<byte>, ushort> action = null;
		if (_packetCreatorMap.TryGetValue(id, out action))
			action.Invoke(session, buffer, id);
	}}

	void MakePacket<T>(PacketSession session, ArraySegment<byte> buffer, ushort id) where T : IMessage, new()
	{{
		T pkt = new T();
		pkt.MergeFrom(buffer.Array, buffer.Offset + 4, buffer.Count - 4);

		if (CustomHandler != null)
		{{
			CustomHandler.Invoke(session, id, pkt);
		}}
		else
		{{
			Action<PacketSession, IMessage> action = null;
			if (_packetHandlerMap.TryGetValue(id, out action))
				action.Invoke(session, pkt);
		}}
	}}

	public Action<PacketSession, IMessage> GetPacketHandler(ushort id)
	{{
		Action<PacketSession, IMessage> action = null;
		if (_packetHandlerMap.TryGetValue(id, out action))
			return action;
		return null;
	}}
}}";

        // {0} 패킷 이름
        public static string packetHandlerFormat =
@"		
		_packetCreatorMap.Add((ushort)MsgId.{0}, MakePacket<{0}>);
		_packetHandlerMap.Add((ushort)MsgId.{0}, PacketHandler.{0}Handler);";

        // {0} 패킷 이름
        // {1} ID
        public static string msgIdFormat =
@"
	{0} = {1},";

    }
}
