#pragma once

class MyStingCow;

class Counter {
	char* m_pStr;
	Counter* m_pNext;
	size_t m_owners;
	static size_t m_counters;
	static Counter* m_pHead;

	Counter();
	Counter(const char* str);


	void AddOwner();
	void DeleteOwner();
	bool StrFind(const char* str);

	friend class MyStingCow;
};
