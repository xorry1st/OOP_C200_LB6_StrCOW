#include "MyStringCow.h"

MyStringCow::MyStringCow() {
	m_pCounter = nullptr;
}

MyStringCow::MyStringCow(const char* str) {
	if (str) {
		if (m_pCounter = StrFind(str), m_pCounter) {
			m_pCounter->AddOwner();
		}
		else {
			m_pCounter = new Counter(str);
			m_pCounter->AddOwner();
		}
	}
	else {
		m_pCounter = nullptr;
	}
}

MyStringCow::MyStringCow(const MyStringCow& other) {
	if (&other) {
		if (other.m_pCounter) {
			m_pCounter = other.m_pCounter;
			m_pCounter->AddOwner();
		}
		else {
			m_pCounter = nullptr;
		}
	}
	else {
		*this = MyStringCow();
	}
}

MyStringCow::MyStringCow(MyStringCow&& other) {
	if (&other) {
		if (other.m_pCounter) {
			m_pCounter = other.m_pCounter;
			other.m_pCounter = nullptr;
		}
		else {
			m_pCounter = nullptr;
		}
	}
	else {
		*this = MyStringCow();
	}
}

MyStringCow& MyStringCow::operator=(const MyStringCow& other) {
	if (this != &other) {

	}
	return *this;
}

Counter* MyStringCow::StrFind(const char* str) {
	Counter* pTmp = Counter::m_pHead;
	while (pTmp->m_pNext != nullptr) {
		if (!strcmp(m_pCounter->m_pStr, str)) {
			return pTmp;
		}
		pTmp = pTmp->m_pNext;
	}
	return nullptr;
}
