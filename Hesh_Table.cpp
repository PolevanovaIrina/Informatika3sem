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
	std::list<std::string> *arr = new std::list<std::string>[0];

	HESH_TABLE(int k)
	{
		std::list<std::string> *arr1 = new std::list<std::string>[k];
		this->arr = arr1;

	}

	int hesh_Function(std::string name)
	{
		int len = name.length();
		int i = 0;
		int sum = 0;

		while (i < len) {
			sum = sum + (int)name[i];
		};
		int number = sum % 100;
		return number;
	}

	void fill_Book(std::string name)
	{
		int number = hesh_Function(name);
		(arr[number]).push_front(name);

	}

	bool find_Book(std::string name)
	{
		int number = hesh_Function(name);
		bool answer = false;

		std::list<std::string>::iterator ptr;
		for (ptr = arr[number].begin(); ptr != arr[number].end(); ptr++)
		{
			if (*ptr == name) {
				answer = true;
			}
		}

		return answer;

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

	}

	void show_Distribution()
	{

		for (int i = 0; i <= 99; i++) {
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
	std::cin >> count;
	HESH_TABLE one = HESH_TABLE(count);

	std::ifstream fin;
	fin.open("words.txt");
	std::vector<std::string> buffer;
	int CountOfatients = 0;
	while (fin) {

		std::vector<std::string> elements;
		std::string item;


		std::getline(fin, item);
		elements.push_back(item);
		one.fill_Book(item);




	}
	fin.close();
}
