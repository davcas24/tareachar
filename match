#include "match.h"
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

match::match(const char* str1, const char* str2){
	this->str1=new char[sizeof(str1)];
	this->str2=new char[sizeof(str2)];
	strncpy(this->str1,str1,sizeof(str1));
	strncpy(this->str2,str2,sizeof(str2));
}

/*string match::toString(){
	stringstream ss;
	ss<<str1<<" , "<<str2;
	return ss.str();
}*/

char* match::getStr1(){
	return str1;
}

char* match::getStr2(){
	return str2;
}
