#include <string>
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

	Counter* pTmp = m_pHead;
	while (pTmp->m_pNext != nullptr) {
		pTmp = pTmp->m_pNext;
	}
	pTmp->m_pNext = this;
	m_counters++;
}
