#pragma once
// -----------------------
//		BufferWriter
// -----------------------
class BufferWriter
{
public:
	BufferWriter();
	BufferWriter(BYTE* buffer, uint32 size, uint32 pos = 0);
	~BufferWriter();

	BYTE*			Buffer() { return _buffer; }
	uint32			Size() { return _size; }
	uint32			WriteSize() { return _pos; }
	uint32			FreeSize() { return _size - _pos; }

	// [헤더][데이터] 이런 식으로 메모리를 쓸 때에 [헤더] 부분을 비워두기 위한 함수
	template<typename T>
	T*				Reserve();

	// Write를 편하게 쓰기 위한 템플릿 버전
	template<typename T>
	bool			Write(T* src) { return Write(src, sizeof(T)); }
	bool			Write(void* src, uint32 len);

	template<typename T>
	BufferWriter&	operator<<(const T& src);

	template<typename T>
	BufferWriter&	operator<<(T&& src);

private:
	BYTE*			_buffer = nullptr;
	uint32			_size = 0;
	uint32			_pos = 0;
};

template<typename T>
inline T* BufferWriter::Reserve()
{
	if (FreeSize() < sizeof(T))
	{
		return nullptr;
	}

	T* ret = reinterpret_cast<T*>(&_buffer[_pos]);
	_pos += sizeof(T);
	return ret;
}

template<typename T>
inline BufferWriter& BufferWriter::operator<<(const T& src)
{
	*reinterpret_cast<T*>(&_buffer[_pos]) = src;
	_pos += sizeof(T);
	return *this;
}

template<typename T>
inline BufferWriter& BufferWriter::operator<<(T&& src)
{
	*reinterpret_cast<std::remove_reference_t<T>*>(&_buffer[_pos]) = std::move(src);
	_pos += sizeof(T);
	return *this;
}