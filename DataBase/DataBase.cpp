#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include"DataBase.h"



void DataBase::addPatient(std::string name, std::string surname, std::string  sex, std::string age, std::string city, std::string visitcount)
	{
		Patients patient;
		patient.name = name;
		patient.age = age;
		patient.city = city;
		patient.sex = sex;
		patient.surname = surname;
		patient.visitcount = visitcount;
		ListOfPatients.insert(patient);
		patientscount += 1;
	}
void DataBase::getInfo(int id)
	{ 
		Node<Patients>* address = ListOfPatients.giveAddress(id);

		std::cout << "Name: " << address->value.name << ", surname:" << address->value.surname << ", gender:" << address->value.sex << ", age:" << address->value.age << ", city:" << address->value.city << ", number of visits:" << address->value.visitcount << "\n";
	}
void DataBase::copyBase(DataBase* copy)
	{
		for (int i = 1; i <= patientscount; i++) {
			Node<Patients>* addressTo = copy->ListOfPatients.giveAddress(i);
			Node<Patients>* addressFrom = ListOfPatients.giveAddress(i);
			addressTo->value.name = addressFrom->value.name;
			addressTo->value.surname = addressFrom->value.surname;
			addressTo->value.city = addressFrom->value.city;
			addressTo->value.age = addressFrom->value.age;
			addressTo->value.visitcount = addressFrom->value.visitcount;
			addressTo->value.sex = addressFrom->value.sex;

		}
	}
void DataBase::deletePatient(int id)
	{
		ListOfPatients.deleteNumber(id);
		
	}
void DataBase::cleanMemory()
	{
		ListOfPatients.empty();
	}
void DataBase::loadFrom(std::string filePath)
	{
		std::ifstream fin;
		fin.open(filePath);
		std::vector<std::string> buffer;
		int i = 0;
		int CountOfatients = 0;
		while (fin) {
			
			std::vector<std::string> elements;
			std::string item;
			char delim = ' ';
			
			for (i = 0; i < 6; i++) {
				if (i == 5) {
					std::getline(fin, item);
					elements.push_back(item);
					CountOfatients++;
				}

				else {
					std::getline(fin, item, ' ');
					elements.push_back(item);
				}
			}
			addPatient(elements[0], elements[1], elements[2], elements[3], elements[4], elements[5]);
		}
		fin.close();
	}
void DataBase::saveDataBase(std::string filename)
	{
		std::ofstream DataBase(filename);

		Node<Patients>* address = ListOfPatients.giveAddress(patientscount);
		Node<Patients>* current;

		for (int k = 0; k <= patientscount-1; k++) {

			current = address;

			if (k == patientscount - 1) {
				DataBase << current->value.name << " " << current->value.surname << " " << current->value.sex << " " << current->value.age << " " << current->value.city << " " << current->value.visitcount << "\n";
			}
			else {
				for (int i = 0; i <= patientscount - k - 2; i++)
				{
					current = current->next;
				}
				DataBase << current->value.name << " " << current->value.surname << " " << current->value.sex << " " << current->value.age << " " << current->value.city << " " << current->value.visitcount << "\n";
			}
		}
			
		DataBase.close();

	}



int main()

{
	DataBase db;
	
	db.loadFrom("hi.txt");
	
	std::cout << "Press 1 to add a patient,press 2 to display information,press 3 to exit" "\n";

	int answer = 0;
	std::cin >> answer;

	while (answer != 3) {

		switch (answer)

		{
		case 1: {

			std::string name = " ";
			std::string surname = "0";
			std::string gender = "0";
			std::string age = "0";
			std::string city = "0";
			std::string visitcount = "0";

			std::cout << "Enter through a space name, surname, gender(0 - men, 1 - women), age, city, number of visits" "\n";
			std::cin >> name;
			std::cin >> surname >> gender >> age >> city >> visitcount;

			db.addPatient(name, surname, gender, age, city, visitcount);
			std::cout << "Press 1 to add a patient,press 2 to display information,press 3 to exit" "\n";
			std::cin >> answer;
			continue; }

		case 2: {
			int id = 0;
			std::cout << "Enter number of patient" "\n";
			std::cin >> id;

			db.getInfo(id);


			std::cout << "Press 1 to add a patient,press 2 to display information,press 3 to exit" "\n";
			std::cin >> answer;
			continue; }

		case 3: {
			break; }

		case 4: {
			DataBase db2;
			db.copyBase(&db2); }



		default: std::cout << "Press 1 to add a patient,press 2 to display information,press 3 to exit" "\n";
			std::cin >> answer;
			continue;




		}



	}
	db.saveDataBase("hi.txt");

	return 0;
}
