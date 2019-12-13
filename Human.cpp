#include "Human.h"

void Human::SetFio(string name)
{
	if (name.size() > 0)
	{
		fio = name;
	}
	else
		cout << "\nCheck FIO input" << endl;
}

string Human::GetFio() const
{
	return fio;
}

void Human::SetHomePhone(string phone)
{
	if (phone.size() > 0) home_phone = phone;
	else
		cout << "\nCheck phone size" << endl;
}

string Human::GetHomePhone() const
{
	return work_phone;
}

void Human::SetWorkPhone(string phone)
{
	if (phone.size() > 0) work_phone = phone;
	else
		cout << "\nCheck phone size" << endl;
}

string Human::GetWorkPhone() const
{
	return work_phone;
}

void Human::ShowHumanInfo() const
{
	cout << "\nFIO: " << fio;
	cout << "\n Home phone: " << home_phone;
	cout << "\nWork phone: " << work_phone;
}

void Human::HumanSetInfo()
{

	string s1,s2;
	char a[100];
	cout << "\n==============USER CONTACT===========" << endl;
	cin.clear();
	cin.ignore();
	cout << "\nEnter FIO : " ;
	
	cin.getline(a, 100);
	fio = a;
	cout << "\nHome phone: ";

	cin >> s1;
	home_phone = s1;
	cin.clear();
	cin.ignore();

	cout << "\nWork phone: ";
	cin >> s2;
	work_phone = s2;
	cin.clear();
	cin.ignore();
}

void Human::SaveHuman(ofstream& save)
{
	int size_fio = fio.length() + 1;
	save.write((char*)& size_fio, sizeof(int));
	save.write(fio.c_str(), size_fio);

	int size_home_phone = home_phone.length() + 1;
	save.write((char*)& size_home_phone, sizeof(int));
	save.write(home_phone.c_str(), size_home_phone);

	int size_work_phone = work_phone.length() + 1;
	save.write((char*)& size_work_phone, sizeof(int));
	save.write(work_phone.c_str(), size_work_phone);

}

void Human::LoadHuman(ifstream& load)
{
	int size_fio ;
	load.read((char*)& size_fio, sizeof(int));
	char* buff = new char[size_fio];
	load.read((char*)buff, size_fio);
	fio = buff;



	load.read((char*)& size_fio, sizeof(int));
	char* buff1 = new char[size_fio];
	load.read((char*)buff1, size_fio);
	home_phone = buff1;


	load.read((char*)& size_fio, sizeof(int));
	char* buff2 = new char[size_fio];
	load.read((char*)buff2, size_fio);
	work_phone = buff2;




}



Human::Human(string fio1, string home_phone1, string work_phone1)
{
	fio = fio1;
	home_phone = home_phone1;
	work_phone = work_phone1;
}

Human::Human(const Human& src)
{
//	cout << "\ncopy Fio";
	string s, s1, s2;
	s = src.fio;
	s1 = src.home_phone;
	s2 = src.work_phone;
	fio = s;
	home_phone = s1;
	work_phone = s2;
}

Human& Human::operator=(const Human& src)
{
	//cout << "\nAssign Human ";
	this->fio = src.fio;
	this->home_phone = src.home_phone;
	this->work_phone = src.work_phone;
	return *this;
}
