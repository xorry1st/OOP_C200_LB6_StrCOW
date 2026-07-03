//==============================================================================
// Т Е М Ы
// Статические члены класса. Класс с подсчетом ссылок.
//==============================================================================
#define _CRT_SECURE_NO_WARNINGS
#include "MyStringCow.h"
#include <intrin.h>
#include <iostream>

#define stop __nop();

int main()
{
	using namespace std;
	// Задание на разработку класса находится в файле - lab_static_1.doc	
	// Здесь проверяем работоспособность разработанного класса

	MyStringCow test("test");
	cout << test << endl;

	// С помощью профилировщика проверяем всю ли динамическую память освободили
	stop  // здесь делаем 1-ый снимок памяти

	{
		//
		// 1. Создаем строки
		//
#if 1
		MyStringCow str("bbb");
		MyStringCow str2("bbb");
		MyStringCow str3("CCC");
		MyStringCow* str4 = new MyStringCow("ddd");
		MyStringCow* str5 = new MyStringCow("CCC");

		MyStringCow::print();   // при печати выводим строку и количество ее пользователей
		stop
#endif
		//
		// 2. Конструктор копирования
		//
#if 1
		MyStringCow s;
		MyStringCow s2 = str2;
		MyStringCow s3 = s2;
		MyStringCow::print();
		stop

		MyStringCow s4 = std::move(*str4);
		delete str4;
		MyStringCow::print();
		stop
#endif
		//
		// 3. Оператор присваивания
		//
#if 1
		s3 = s4;
		MyStringCow::print();

		*str5 = std::move(s3);
		MyStringCow::print();

		s4 = "bbb";
		MyStringCow::print();

		delete str5;
		MyStringCow::print();

		s4 = "FFF";
		MyStringCow::print();
		stop
#endif
		//
		// 4. Изменили регистр у всех строк на противоположный
		//
#if 1
		MyStringCow s5("FFF");
		MyStringCow::print();

		MyStringCow::changeCase();
		MyStringCow::print();
		stop
#endif
		//
		// 5*. Распечатали строки в алфавитном порядке
		//
#if 0
		MyStringCow::printAlph();		
		stop
#endif
		//
		// 6*. Дополнительные тесты
		//
		// ...
	}

    stop		// здесь делаем 2-ый снимок памяти и смотрим результаты
		 
	return 0;
}