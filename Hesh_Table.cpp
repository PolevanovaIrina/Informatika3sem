#include "pch.h"
#include <cassert>
#include <iostream>
#include <string>
#include <strstream>
#include<list>

struct HESH_TABLE
{
	std::list<std::string> arr[100];

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
	
}