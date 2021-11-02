#pragma once
#include <iostream>
#include <string.h>
#include <fstream>

#include <chrono>  // chrono::system_clock
#include <ctime>   // localtime
#include <sstream> // stringstream
#include <iomanip> // put_time
#include <string>  // string

#ifdef _DEBUG
#define ISCONSOLELOG
#endif
#define ISFILELOG

// https://stackoverflow.com/questions/8487986/file-macro-shows-full-path
#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)

#define TIME time_stamp()

static std::ofstream ofs("LOG.txt");


// https://stackoverflow.com/questions/35431298/setting-individual-text-colors-in-c
#define LOGINFO "[" << "\033[1;32m LOG \033[0m" << "]" << " [" << TIME << "]"<< " [" << __FILENAME__ << ": " << __LINE__ <<"]\t\t"
#define WARNINFO "[" << "\033[1;33m WARN \033[0m" << "]" << " [" << TIME << "]"<< " [" << __FILENAME__ << ": " << __LINE__ <<"]\t\t"
#define ERRORINFO "[" << "\033[1;31 ERROR \033[0m" << "]" << " [" << TIME << "]"<< " [" << __FILENAME__ << ": " << __LINE__ <<"]\t\t"

#define FILELOGINFO "[" << " LOG " << "]" << " [" << TIME << "]"<< " [" << __FILENAME__ << ": " << __LINE__ <<"]\t\t"
#define FILEWARNINFO "[" << " WARN " << "]" << " [" << TIME << "]"<< " [" << __FILENAME__ << ": " << __LINE__ <<"]\t\t"
#define FILEERRORINFO "[" << " ERROR " << "]" << " [" << TIME << "]"<< " [" << __FILENAME__ << ": " << __LINE__ <<"]\t\t"

#ifdef ISFILELOG
#ifdef ISCONSOLELOG
#define LOG(...)		std::cout << LOGINFO;\
						consolePrint(__VA_ARGS__);\
						ofs << FILELOGINFO;\
						filePrint(__VA_ARGS__)

#define WARN(...)		std::cout << WARNINFO;\
						consolePrint(__VA_ARGS__);\
						ofs << FILEWARNINFO;\
						filePrint(__VA_ARGS__)

#define ERROR(...)		std::cout << ERRORINFO;\
						consolePrint(__VA_ARGS__);\
						ofs << FILEERRORINFO;\
						filePrint(__VA_ARGS__)
#endif
#endif


#ifdef ISFILELOG
#ifndef ISCONSOLELOG
#define LOG(...)		ofs << FILELOGINFO;\
						filePrint(__VA_ARGS__)

#define WARN(...)		ofs << FILEWARNINFO;\
						filePrint(__VA_ARGS__)

#define ERROR(...)		ofs << FILEERRORINFO;\
						filePrint(__VA_ARGS__)
#endif
#endif


#ifdef ISCONSOLELOG 
#ifndef ISFILELOG
#define LOG(...)		std::cout << LOGINFO;\
						consolePrint(__VA_ARGS__);

#define WARN(...)		std::cout << WARNINFO;\
						consolePrint(__VA_ARGS__);

#define ERROR(...)		std::cout << ERRORINFO;\
						consolePrint(__VA_ARGS__);
#endif
#endif


// https://docs.microsoft.com/en-us/cpp/cpp/ellipses-and-variadic-templates?view=msvc-160
template <typename T>
void consolePrint(const T& t) {
	std::cout << t << "\n";
}

template <typename First, typename... Rest>
void consolePrint(const First& first, const Rest&... rest) {
	std::cout << first << " ";
	consolePrint(rest...);
}


template <typename T>
void filePrint(const T& t) {
	ofs << t << "\n";
}

template <typename First, typename... Rest>
void filePrint(const First& first, const Rest&... rest) {
	ofs << first << " ";
	filePrint(rest...);
}


// https://stackoverflow.com/questions/38034033/c-localtime-this-function-or-variable-may-be-unsafe
inline std::tm localtime_xp(std::time_t timer)
{
	std::tm bt{};
#if defined(__unix__)
	localtime_r(&timer, &bt);
#elif defined(_MSC_VER)
	localtime_s(&bt, &timer);
#else
	static std::mutex mtx;
	std::lock_guard<std::mutex> lock(mtx);
	bt = *std::localtime(&timer);
#endif
	return bt;
}

// default = "YYYY-MM-DD HH:MM:SS"
inline std::string time_stamp(const std::string& fmt = "%T")
{
	auto bt = localtime_xp(std::time(0));
	char buf[64];
	return { buf, std::strftime(buf, sizeof(buf), fmt.c_str(), &bt) };
}