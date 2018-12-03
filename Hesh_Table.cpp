#include "pch.h"
#include <cassert>
#include <iostream>
#include <fstream>
#include <string>
#include <strstream>
#include<list>
#include <vector>


struct HESH_TABLE
{
	std::list<std::string> *arr = new std::list<std::string>[1000000];

	int hesh_Function(std::string name, int count)
	{
		
		int len = name.length();
		int i = 0;
		int sum = 0;

		while (i < len) {
			sum = sum + (int)name[i];
			i++;
		};
		int number = abs(sum % (count-1));
		return number;
		
	}

	void fill_Book(std::string name,int count)
	{
	
		int number = hesh_Function(name, count);
		(arr[number]).push_back(name);

	}

	void find_Book(std::string name)
	{
		int number = hesh_Function(name);

		std::list<std::string>::iterator iter = std::find((arr[number]).begin(), (arr[number]).end(),name);

		if (iter != (arr[number]).end()) {
			std::cout << "book is here" << "\n";
		}
		else {
			std::cout << "book is not here" << "\n";
		}
		


	}

	void delete_Book(std::string name)
	{
		int number = hesh_Function(name);
		bool answer = false;

		std::list<std::string>::iterator ptr;
		for (ptr = arr[number].begin(); ptr != arr[number].end(); ptr++)
		{
			if (*ptr == name) {
				arr[number].remove(*ptr);
			}

		}
		std::cout << "ia ydolyay knigi";
	}

	void show_Distribution(int count)
	{

		for (int i = 0; i <= count-1; i++) {
			int k = 0;
			std::list<std::string>::iterator ptr;
			for (ptr = arr[i].begin(); ptr != arr[i].end(); ptr++)
			{
				k++;
			}
			std::cout << i << " - " << k << "\n";
		}
	}

};








int main()
{
	int count;
	setlocale(LC_ALL, "Russian");

	HESH_TABLE one;
	std::cout << "Сколько ячеек хотите использовать?" << "\n";
	std::cin >> count;

	std::ifstream fin;
	fin.open("words.txt");

	while (fin) {

		std::string item;

		std::getline(fin, item);
		one.fill_Book(item,count);

	
	}
	fin.close();
	//one.find_Book("объяснение1");
	one.show_Distribution(count);
}
