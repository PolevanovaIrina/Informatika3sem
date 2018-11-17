#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include "List.h"


template <typename T>
Node<T>* List<T>::findAddress(T value) {
	Node<T>* address = NULL;
	Node<T>* answer = NULL;
	address = head_;
	while (address) {
		if (address->value == value) {
			answer = address;
			break;
		};

		address = address->next;
	};
	return answer;
}
template <typename T>
bool List<T>::find(T value)
{
	bool answer = false;
	if (findAddress(value)) {
		answer = true;
	}
	return answer;
}
template <typename T>
void List<T>::insert(T value)
{
	if (!head_) {
		head_ = new Node<T>(value, NULL);
	}


	else {
		head_ = new Node<T>(value, head_);
	}
	capacity++;



}
template <typename T>
int List<T>::findNumber(T value) {
	int count = 0;
	Node<T>* address = head_;
	while (address) {
		if (address->value == value) {
			break;
		}
		count++;
		address = address->next;
	}
	return count;
}
template <typename T>
void List<T>::deleteNumber(int index) {
	Node<T>* current = head_;
	Node<T>* prev = 0;
	Node<T>* next = 0;
	if (index == capacity) {
		head_ = current->next;
		delete current;
		current = nullptr;

	}
	else if (index == 1) {
		for (int i = 0; i <= capacity - 2; i++) {
			current = current->next;
			if (i == capacity - 3) {
				delete current->next;
				current->next = nullptr;
			}
		}


	}
	else {
		for (int i = 0; i <= index; i++) {
			if (i == index - 1) {
				prev = current;

			}
			if (i == index) {
				next = current->next;
				delete current;
				current = nullptr;

				break;
			}

			current = current->next;
		}

		prev->next = next;
	}
	capacity--;



}
template <typename T>
void List<T>::deleteValue(T value) {
	int index = findNumber(value);
	deleteNumber(index);
}
template <typename T>
void List<T>::print(int index) {
	Node<T>* current = head_;
	for (int i = 1; i <= capacity - index; i++) {
		current = current->next;
	}
	std::cout << current->value << "\n";
}
template <typename T>
Node<T>* List<T>::giveAddress(int index) {
	Node<T>* current = head_;
	for (int i = 1; i <= capacity - index; i++) {
		current = current->next;
	}
	return current;
}
template <typename T>
void List<T>::empty() {
	for (int i = capacity; i >= 1; i--) {
		deleteNumber(i);
	}




}



