﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpServer.Contents
{
    public class RoomManager
    {
        public static RoomManager Instance { get; } = new RoomManager();

        object _lock = new object();
        Dictionary<int, Room> _rooms = new Dictionary<int, Room>();
        int _roomId = 1;

        public Room Add(int mapId)
        {
            Room room = new Room();
            room.Push(room.Init, mapId);

            lock (_lock)
            {
                room.RoomId = _roomId;
                _rooms.Add(_roomId, room);
                _roomId++;
            }

            return room;
        }

        public bool Remove(int roomId)
        {
            lock (_lock)
            {
                return _rooms.Remove(roomId);
            }
        }

        public Room Find(int roomId)
        {
            lock (_lock)
            {
                Room room;
                _rooms.TryGetValue(roomId, out room);

                return room;
            }
        }
    }
}
