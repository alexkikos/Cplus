#pragma once
#include "Room.h"


class House
{
	Room* rooms;
	int total_rooms_house;
	int static floors;
	string static name_file_where_save;

public:
	void AddRoom();
	void AddRoom(Room& room);
	Room& GetRoom(int index) const;
	void RemoveRoom();




	void ShowAllRoomsInfo() const; //краткая информация о всех квартирах
	void ShowDetailedInfo(int number_room) const; //детальная информация о квартире
	void EditRoomInfo();//редактирую информацию о квартире
	void EditOwnersInfo();


	int GetTotalRooms() const;
	int static GetTotalFloors();


	static string GetFileName();

	void Save();
	void Load();


	void HouseMenu();
	House();
	//House(Room rooms = {}, int room = 1);

	House(const House& src);
	~House();


};

