#pragma once
#include <iostream>
#include <string.h>
#include <fstream>

#define ISCONSOLELOG
#define ISFILELOG

#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
// https://stackoverflow.com/questions/8487986/file-macro-shows-full-path

static std::ofstream ofs("LOG.txt");


#define LOGINFO "[" << "LOG" << "]" << " [" << __TIME__ << "]"<< " [" << __FILENAME__ << ": " << __LINE__ <<"]\t\t"
#define WARNINFO "[" << "WARN" << "]" << " [" << __TIME__ << "]"<< " [" << __FILENAME__ << ": " << __LINE__ <<"]\t\t"
#define ERRORINFO "[" << "ERROR" << "]" << " [" << __TIME__ << "]"<< " [" << __FILENAME__ << ": " << __LINE__ <<"]\t\t"


#ifdef ISFILELOG
#ifdef ISCONSOLELOG
#define LOG(...)		std::cout << LOGINFO;\
						consolePrint(__VA_ARGS__);\
						ofs << LOGINFO;\
						filePrint(__VA_ARGS__)

#define WARN(...)		std::cout << WARNINFO;\
						consolePrint(__VA_ARGS__);\
						ofs << WARNINFO;\
						filePrint(__VA_ARGS__)

#define ERROR(...)		std::cout << ERRORINFO;\
						consolePrint(__VA_ARGS__);\
						ofs << ERRORINFO;\
						filePrint(__VA_ARGS__)
#endif
#endif


#ifdef ISFILELOG
#ifndef ISCONSOLELOG
#define LOG(...)		ofs << LOGINFO;\
						filePrint(__VA_ARGS__)

#define WARN(...)		ofs << WARNINFO;\
						filePrint(__VA_ARGS__)

#define ERROR(...)		ofs << ERRORINFO;\
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