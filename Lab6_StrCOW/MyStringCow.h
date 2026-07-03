#pragma once
#include <iostream>
#include "Counter.h"

#define sep "\n------------------------------------\n"

class MyStringCow {
	Counter* m_pCounter;
public:
	MyStringCow();
	MyStringCow(const char* str);
	MyStringCow(const MyStringCow& other);
	MyStringCow(MyStringCow&&);
	~MyStringCow();

	MyStringCow& operator=(const MyStringCow& other);
	MyStringCow& operator=(const char* str);
	MyStringCow& operator=(MyStringCow&&);

	Counter* StrFind(const char* str);
	static void print();
	static void changeCase();

	friend std::ostream& operator<<(std::ostream& out, const MyStringCow& str);
};

std::ostream& operator<<(std::ostream& out, const MyStringCow& str);
