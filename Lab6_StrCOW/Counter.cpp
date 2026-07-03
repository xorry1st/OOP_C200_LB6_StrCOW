#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include "Counter.h"

size_t Counter::m_counters = 0;
Counter* Counter::m_pHead = nullptr;

//Counter::Counter() {
//	m_pStr = nullptr;
//	m_pNext = nullptr;
//}

Counter::Counter(const char* str) {

	m_pStr = new char[strlen(str) + 1];
	strcpy(m_pStr, str);
	if (!m_pHead) {
		m_pHead = this;
	}
	else {
		Counter* pTmp = m_pHead;
		while (pTmp->m_pNext != nullptr) {
			pTmp = pTmp->m_pNext;
		}
		pTmp->m_pNext = this;
	}
	m_counters++;
}

Counter::~Counter() {
	delete[] m_pStr;
	Counter* pTmp = m_pHead;
	while (pTmp->m_pNext != this) {
		pTmp = pTmp->m_pNext;
	}
	pTmp->m_pNext = this->m_pNext;
	m_counters--;
}

void Counter::AddOwner() {
	m_owners++;
}

void Counter::DeleteOwner() {
	m_owners--;
	if (!m_owners) {
		delete this;		
	}	
}

void Counter::ReplaceStr(const char* str) {
	if (strlen(str) > strlen(m_pStr)) {
		char* buf = new char[strlen(str) + 1];
		strcpy(buf, str);
		delete[] m_pStr;
		m_pStr = buf;
	}
	else {
		strcpy(m_pStr, str);
	}
}

std::ostream& operator<<(std::ostream& out, const Counter& counter) {
	out << counter.m_pStr << " owners = " << counter.m_owners;
	return out;
}
