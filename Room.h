#pragma once
#include "Human.h"

class Room
{
	Human* humans_in_room;
	int size_humans_in_room;//количество людей в квартире
	float square;//площадь квартиры
	int total_rooms;//количество комнат, не статик тк относится к определенному обьекту
	int balkonies;// количество балконов
	int nubmer_room;//номер команты в доме
	int floor;

public:
	void UserMenu();



	int GetHumansInRoom() const;
	void SetHumansInRoom(int number);


	string GetOwner();//1 собственник == владалец

	void AddHuman();//для точечного добавления с елементами меню
	void AddHuman(Human& human); //для Добавления готового обьекта
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
	void EditParamsRoom();//меняю параметры квартиры
	void EditOwners(); //работаю с жильцами

	void SetFloor(int floor);
	int GetFloor() const;

	void SaveRoom(ofstream& save);
	void LoadRoom(ifstream& load);
	Room(const Room& src);
	
	explicit Room(Human human = {"z"}, int size_humans_in_room = 1, float square = 45, int total_rooms = 1, int balkonies = 1, int number_room = 1, int floor = 1);
	Room& operator = (const Room& src);
	~Room();


};

