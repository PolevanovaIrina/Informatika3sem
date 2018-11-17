#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include"List.cpp"

struct Patients
{
	std::string  name;
	std::string  surname;
	std::string  sex;
	std::string  age;
	std::string  city;
	std::string  visitcount;
};

struct DataBase
{
 private:
	List<Patients> ListOfPatients;
	int patientscount = 0;
public:
	void getInfo(int id);
	void copyBase(DataBase* copy);
	void cleanMemory();
	void loadFrom(std::string filePath);
	void saveDataBase(std::string filename);
	void deletePatient(int id);
	void addPatient(std::string name, std::string surname, std::string  sex, std::string age, std::string city, std::string visitcount);

};



