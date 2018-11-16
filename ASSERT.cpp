#include "pch.h"
#include <iostream>
#include <string>
#include <vector>


template <typename T>
void ASSERT_EQUAL(T a, T b)
{
	if (a != b) {

		std::cout << "Что-то не то, они не равны, первое = " << a << ", второе = " << b << "\n";

	}
};

template <typename T>
void ASSERT_NEQUAL(T a, T b)
{
	if (a == b) {

		std::cout << "Что-то не то, равны " << a <<  "\n";

	}
};

template <typename T>
void ASSERT_TRUE(T a)
{
	if (!a) {

		std::cout << "Что-то не то, значение FALSE" << "\n";

	}
};

template <typename T>
void ASSERT_FALSE(T a)
{
	if (a) {

		std::cout << "Что-то не то, значение TRUE  = " << a << "\n";

	}
};


