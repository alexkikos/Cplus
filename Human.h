#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;

class Human
{
	string fio;
	string home_phone;
	string work_phone;

public:
	void SetFio(string name);
	string   GetFio() const;

	void SetHomePhone(string phone);
	string  GetHomePhone() const;


	void SetWorkPhone(string phone);
	string GetWorkPhone() const;


	
	void ShowHumanInfo() const;
	void HumanSetInfo();

	void SaveHuman(ofstream& save);
	void LoadHuman(ifstream& load);





	Human(string name = "dafult", string phone = "def", string work_phone = "def");
	explicit Human(const Human& src);

	Human& operator =(const Human& src);


};

