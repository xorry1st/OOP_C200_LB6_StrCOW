#pragma once

class MyStringCow;

class Counter {
	char* m_pStr;
	Counter* m_pNext;
	size_t m_owners;
	static size_t m_counters;
	static Counter* m_pHead;
	
	//Counter();
	Counter(const char* str);
	~Counter();

	void AddOwner();
	void DeleteOwner();

	friend class MyStringCow;
};
