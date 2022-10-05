﻿using DummyClient;
using ServerCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class PacketHandler
{
    public static void S_ChatHandler(PacketSession session, IPacket iPacket)
    {
        //S_Chat chatPacket = iPacket as S_Chat;
        //ServerSession serverSesion = session as ServerSession;

        //Console.WriteLine(chatPacket.playerId + ":" + chatPacket.chatMessage);
    }

    internal static void S_BroadcastEnterGameHandler(PacketSession session, IPacket iPacket)
    {
        S_BroadcastEnterGame pkt = iPacket as S_BroadcastEnterGame;
        ServerSession serverSession = session as ServerSession;
    }

    internal static void S_BroadcastLeaveGameHandler(PacketSession session, IPacket iPacket)
    {
        S_BroadcastLeaveGame pkt = iPacket as S_BroadcastLeaveGame;
        ServerSession serverSession = session as ServerSession;
    }

    internal static void S_PlayerListHandler(PacketSession session, IPacket iPacket)
    {
        S_PlayerList pkt = iPacket as S_PlayerList;
        ServerSession serverSession = session as ServerSession;
    }

    internal static void S_BroadcastMoveHandler(PacketSession session, IPacket iPacket)
    {
        S_BroadcastMove pkt = iPacket as S_BroadcastMove;
        ServerSession serverSession = session as ServerSession;
    }
}

