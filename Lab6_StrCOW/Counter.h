#pragma once

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
	void ReplaceStr(const char* str);

	friend class MyStringCow;
	friend std::ostream& operator<<(std::ostream& out, const Counter& counter);
	friend std::ostream& operator<<(std::ostream& out, const MyStringCow& str);
};

std::ostream& operator<<(std::ostream& out, const Counter& counter);
