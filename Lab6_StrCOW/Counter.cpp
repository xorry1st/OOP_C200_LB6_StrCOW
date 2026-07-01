#include <string>
#include "Counter.h"

size_t Counter::m_counters = 0;
Counter* Counter::m_pHead = nullptr;

Counter::Counter() {
	m_pStr = nullptr;
	m_pNext = nullptr;
	m_pHead = this;
}

Counter::Counter(const char* str) {
	/*
		ПЕРЕДЕЛАТЬ
		это бессмысленно в конструкторе Counter искать есть ли 
		Counter-ы с такой строкой, т.к. новый Counter должен
		появиться только тогда, когда нет схожих строк

		Конструктор по факту должен выделить память и откопировать в новую
		выделенную память содержимое передаваемой строки
	*/
	if (str) {
		if (StrFind(str)) {
			AddOwner();
		}
		else {
			m_pStr = new char[strlen(str) + 1];
			strcpy(m_pStr, str);
		}
	}
	else {
		*this = Counter();
	}
}



bool Counter::StrFind(const char* str) {
	/*
		ПЕРЕМЕСТИТЬ в MyStringCow
		этот метод должен быть в MyStrCow потому что мы создаем Counter
		после того как не нашли строку
	*/
	bool flag = false;
	Counter* pTmp = m_pHead;
	while (pTmp->m_pNext != nullptr) {
		if (!strcmp(m_pStr, str)) {
			flag = true;
			break;
		}
		pTmp = pTmp->m_pNext;
	}
	return flag;
}
