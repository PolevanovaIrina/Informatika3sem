#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

template <typename T>
struct Node
{
	T value;
	Node<T>* next = NULL;
	Node(T value, Node<T>* next)
	{
		this->value = value;
		this->next = next;
	}

};


template <typename T>
class List
{
	private:
		Node<T>* head_ = NULL;
		int capacity = 0;

public:
	Node<T>* findAddress(T value);
	bool find(T value);
	void insert(T value);
	int findNumber(T value);
	void deleteNumber(int index); 	
	void deleteValue(T value); 
	void print(int index);
	Node<T>* giveAddress(int index); 
	void empty();
};


