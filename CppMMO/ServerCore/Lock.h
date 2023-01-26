#pragma once

// -----------------------
// Reader-Writer SpinLock
// -----------------------

// Reader-Writer lock 같은 경우는 읽기만 있다면 여러 스레드가 가능하고,
// 쓰기 작업을 할 때에만 베타적으로 접근한다.
// 아래처럼 32비트를 16비트씩 쪼개서 사용한다.
// [WWWWWWWW][WWWWWWWW][RRRRRRRR][RRRRRRRR]
// W : WriteFlag (현재 lock을 차지한 ThreadId)
// R : ReadFlag (현재 Read하고 있는 스레드 갯수)

// TODO: 아래 내용 나머지 코드 구현되는거 보면서 재확인 필요
// Lock 정책
// Write -> Write 순으로 lock 잡는 것 가능
// Write -> Read 순으로 lock을 잡는 것 가능
// Read -> Write 순으로 lock을 잡는 것 불가능, 이렇게 잡을 거라면 WriteLock을 먼저 잡아야 한다.
class Lock
{
	enum : uint32
	{
		ACQUIRE_TIMEOUT_TICK = 10000,
		MAX_SPIN_COUNT = 5000,
		WRITE_THREAD_ID_MASK = 0xFFFF'0000,
		READ_THREAD_COUNT_MASK = 0x0000'FFFF,
		EMPTY_FLAG = 0x0000'0000
	};

public:
	void WriteLock();
	void WriteUnlock();
	void ReadLock();
	void ReadUnlock();

private:
	Atomic<uint32> _lockFlag = EMPTY_FLAG;
	uint16 _writeCount = 0; // // WriteLock을 잡고 있는 상태에서 또 잡을 수도 있다. 그것을 체크하기 위한 변수
};


// -----------------------
// LockGuards
// -----------------------
class ReadLockGuard
{
public:
	ReadLockGuard(Lock& lock) : _lock(lock)
	{
		_lock.ReadLock();
	}

	~ReadLockGuard()
	{
		_lock.ReadUnlock();
	}

private:
	Lock& _lock;
};


class WriteLockGuard
{
public:
	WriteLockGuard(Lock& lock) : _lock(lock)
	{
		_lock.WriteLock();
	}

	~WriteLockGuard()
	{
		_lock.WriteUnlock();
	}

private:
	Lock& _lock;
};
