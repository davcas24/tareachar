#ifndef MATCH_H
#define MATCH_H

#include <string>

class match {
	 char* str1;
	 char* str2;
public:
	match(const char*, const char*);
	//string toString();
	char* getStr1();
	char* getStr2();
};

#endif
