#include "pch.h"
#include "FileUtils.h"
#include <filesystem>
#include <fstream>

// ----------------------------
//			FileUtils
// ----------------------------

namespace fs = std::filesystem; // C++ 17에 추가된 파일 시스템 라이브러리

myVector<BYTE> FileUtils::ReadFile(const WCHAR* path)
{
	myVector<BYTE> ret;

	fs::path filePath{ path };

	const uint32 fileSize = static_cast<uint32>(fs::file_size(filePath));
	ret.resize(fileSize);

	basic_ifstream<BYTE> inputStream{ filePath };
	inputStream.read(&ret[0], fileSize);

	return ret;
}

myString FileUtils::Convert(string str)
{
	const int32 srcLen = static_cast<int32>(str.size());

	myString ret;
	if (srcLen == 0)
		return ret;

	const int32 retLen = ::MultiByteToWideChar(CP_UTF8, 0, reinterpret_cast<char*>(&str[0]), srcLen, NULL, 0);
	ret.resize(retLen);
	::MultiByteToWideChar(CP_UTF8, 0, reinterpret_cast<char*>(&str[0]), srcLen, &ret[0], retLen);

	return ret;
}
