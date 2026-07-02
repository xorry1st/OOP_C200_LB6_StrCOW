#pragma once
#include <iostream>
#include "Counter.h"

class MyStringCow {
	Counter* m_pCounter;
	
	MyStringCow();
	MyStringCow(const char* str);
	MyStringCow(const MyStringCow& other);
	MyStringCow(MyStringCow&&);

	MyStringCow& operator=(const MyStringCow& other);
	MyStringCow& operator=(MyStringCow&&);

	Counter* StrFind(const char* str);

	friend std::ostream& operator<<(std::ostream& out, const MyStringCow& str);
};

std::ostream& operator<<(std::ostream& out, const MyStringCow& str);
