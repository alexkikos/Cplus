#pragma once
#include "Human.h"

class Room
{
	Human* humans_in_room;
	int size_humans_in_room;//���������� ����� � ��������
	float square;//������� ��������
	int total_rooms;//���������� ������, �� ������ �� ��������� � ������������� �������
	int balkonies;// ���������� ��������
	int nubmer_room;//����� ������� � ����
	int floor;

public:
	void UserMenu();



	int GetHumansInRoom() const;
	void SetHumansInRoom(int number);


	string GetOwner();//1 ����������� == ��������

	void AddHuman();//��� ��������� ���������� � ���������� ����
	void AddHuman(Human& human); //��� ���������� �������� �������
	void RemoveHuman(int index);

	void SetSquare(float number);
	float GetSquare() const;

	void SetTotalRooms(int number);
	int GetTotalRooms() const;

	void SetBalkonies(int number);
	int GetTotalBalkonies() const;

	void SetNumberForRoom(int number);
	int GetNumberRoom() const;


	void ShowAllHumansLivesRoom() const;
	void ShowAllParamsRoom() const;
	void EditParamsRoom();//����� ��������� ��������
	void EditOwners(); //������� � ��������

	void SetFloor(int floor);
	int GetFloor() const;

	void SaveRoom(ofstream& save);
	void LoadRoom(ifstream& load);
	Room(const Room& src);
	
	explicit Room(Human human = {"z"}, int size_humans_in_room = 1, float square = 45, int total_rooms = 1, int balkonies = 1, int number_room = 1, int floor = 1);
	Room& operator = (const Room& src);
	~Room();


};

