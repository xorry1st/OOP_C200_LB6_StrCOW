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

MyStringCow::~MyStringCow() {
	if (m_pCounter) {
		m_pCounter->DeleteOwner();
	}
}

MyStringCow& MyStringCow::operator=(const MyStringCow& other) {
	if ((this != &other) && (&other) && (other.m_pCounter)) {
		if (m_pCounter) {
			m_pCounter->DeleteOwner();
			m_pCounter = other.m_pCounter;
			m_pCounter->AddOwner();
		}
		else {
			m_pCounter = other.m_pCounter;
			m_pCounter->AddOwner();
		}	
	}
	return *this;
}

MyStringCow& MyStringCow::operator=(const char* str) {
	if (str) {
		if (m_pCounter) {
			if (strcmp(m_pCounter->m_pStr, str)) {
				Counter* pTmp = StrFind(str);
				if (pTmp) {
					if (m_pCounter->m_owners == 1) {
						m_pCounter->ReplaceStr(str);
						return *this;
					}
					m_pCounter->DeleteOwner();
					m_pCounter = pTmp;
					m_pCounter->AddOwner();
				}
				else {
					// Если строку в списке не нашли
					m_pCounter->DeleteOwner();
					m_pCounter = new Counter(str);
					m_pCounter->AddOwner();
				}
			}
		}
		else {
			/*
				Тут надо сначала проверить есть ли такая строка в списке
				Если нет, то выделить память и т.д.
				если есть, то направить указатель туда
			*/
			Counter* pTmp = StrFind(str);
			if (pTmp) {
				m_pCounter = pTmp;
				m_pCounter->AddOwner();
			}
			else {
				m_pCounter = new Counter(str);
			}
		}
	}
	return *this;
}

MyStringCow& MyStringCow::operator=(MyStringCow&& other) {
	if ((this != &other) && (&other) && (other.m_pCounter)) {
		m_pCounter->DeleteOwner();
		m_pCounter = other.m_pCounter;
		other.m_pCounter = nullptr;
	}
	return *this;
}

Counter* MyStringCow::StrFind(const char* str) {
	Counter* pTmp = Counter::m_pHead;
	while (pTmp != nullptr) {
		if (!strcmp(pTmp->m_pStr, str)) {
			return pTmp;
		}
		pTmp = pTmp->m_pNext;
	}
	return pTmp;
}

std::ostream& operator<<(std::ostream& out, const MyStringCow& str) {
	out << *str.m_pCounter << sep;
	return out;
}

void MyStringCow::print() {
	Counter* pTmp = Counter::m_pHead;
	while (pTmp != nullptr) {
		std::cout << *pTmp << std::endl;
		pTmp = pTmp->m_pNext;
	}
	std::cout << sep;
}

void MyStringCow::changeCase() {
	Counter* pTmp = Counter::m_pHead;
	while (pTmp != nullptr) {
		for (int i = 0; i < strlen(pTmp->m_pStr); i++) {
			if (islower(pTmp->m_pStr[i])) {
				pTmp->m_pStr[i] = toupper(pTmp->m_pStr[i]);
			}
			else {
				pTmp->m_pStr[i] = tolower(pTmp->m_pStr[i]);
			}
		}
		pTmp = pTmp->m_pNext;
	}
}
