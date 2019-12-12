#include "House.h"

int House::floors = 5;
string House::name_file_where_save = "House.bin";

void House::AddRoom(Room& room)
{

	Room* temp = new Room[total_rooms_house + 1];
	for (int i = 0; i < total_rooms_house; i++)
	{
		temp[i] = rooms[i];
	}
	temp[total_rooms_house] = room;
	total_rooms_house++;
	if (rooms != nullptr) delete[] rooms;
	rooms = temp;
}

void House::AddRoom()
{
	Room r2;
	r2.EditOwners();
	r2.EditParamsRoom();
	Room* temp = new Room[total_rooms_house + 1];
	for (int i = 0; i < total_rooms_house; i++)
	{
		temp[i] = rooms[i];
	}
	temp[total_rooms_house] = r2;
	total_rooms_house++;
	if (rooms != nullptr) delete[] rooms;
	rooms = temp;
}

Room& House::GetRoom(int index) const
{
	if (index - 1 > 0 and index - 1 <= total_rooms_house)
	{
		return rooms[index - 1];
	}
}

void House::RemoveRoom()
{
	int number;
	cout << "\nВведите номер квартиры для удаления: ";
	cin >> number;
	for (int i = 0; i < total_rooms_house; i++)
	{
		if (number == rooms[i].GetNumberRoom())
		{
			Room* temp = new Room[total_rooms_house - 1];
			int count = 0;
			for (int i = 0; i < total_rooms_house; i++)
			{
				if (number == rooms[i].GetNumberRoom())
				{
					continue;
				}
				temp[count++] = rooms[i];
			}
			delete[] rooms;
			rooms = temp;
			total_rooms_house--;
			
		}
	}
}

void House::ShowAllRoomsInfo() const
{
	cout << "\n====================================ИНФОРМАЦИЯ О КВАРТИРАХ====================================\n";
	for (int i = 0; i < total_rooms_house; i++)
	{
		cout << "Номер квартиры: " << rooms[i].GetNumberRoom() << " Этаж: " << rooms[i].GetFloor() << " Собственник: " << rooms[i].GetOwner()  << endl;

	}
	cout << "\nВсего квартир в доме: " << GetTotalRooms() << " Количество этажей: " << House::GetTotalFloors() << endl;
	cout << "==================================================================================================\n";
}

void House::ShowDetailedInfo(int number_room) const
{
	bool check = false;
	for (int i = 0; i < total_rooms_house; i++)
	{
		if (number_room == rooms[i].GetNumberRoom())
		{
			check = true;
			rooms[i].ShowAllParamsRoom();
		}

	}
	if (check == false)
	{
		cout << "\nКвартира не найдена" << endl;
	}


}

void House::EditRoomInfo()
{
	bool check = false;
	int number;
	cout << "\nВведите номер квартиры для редактирования: ";
	cin >> number;
	for (int i = 0; i < total_rooms_house; i++)
	{
		if (rooms[i].GetNumberRoom() == number)
		{
			check = true;
			rooms[i].EditParamsRoom();
			break;
		}
	}
	if (check == false)
	{
		cout << "\nКвартира не найдена!";
	}

}

void House::EditOwnersInfo()
{
	bool check = false;
	int number;
	cout << "\nВведите номер квартиры для редактирования: ";
	cin >> number;
	for (int i = 0; i < total_rooms_house; i++)
	{
		if (rooms[i].GetNumberRoom() == number)
		{
			check = true;
			rooms[i].EditOwners();
			break;
		}
	}
	if (check == false)
	{
		cout << "\nКвартира не найдена!";
	}
}



int House::GetTotalRooms() const
{
	return total_rooms_house;
}

int House::GetTotalFloors()
{
	return floors;
}


string House::GetFileName()
{
	return name_file_where_save;
}

void House::Save()
{

	ofstream save(name_file_where_save, ios::binary);
	if (save.is_open())
	{
		save.write((char*)& total_rooms_house, sizeof(int));
		save.write((char*)&floors, sizeof(int));
		for (int i = 0; i < total_rooms_house; i++)
		{
			rooms[i].SaveRoom(save);
		}
	}
	else cout << "\ntrouble with file";


	save.close();

}

void House::Load()
{
	ifstream load(name_file_where_save, ios::binary);
	if (load.is_open())
	{
		int a;
		load.read((char*)& a, sizeof(int));
		total_rooms_house = a;
		load.read((char*)& a, sizeof(int));
		floors = a;
		rooms = new Room[total_rooms_house];
		for (int i = 0; i < total_rooms_house; i++)
		{
			rooms[i].LoadRoom(load);
		}
	}
	else cout << "\ntrouble with file";


	load.close();
}

void House::HouseMenu()
{

		char choice;
		int number;
		do
		{
			cout << "\n1. Показать краткую сводку о квартирах в доме";
			cout << "\n2. Детальная информация о квартире";
			cout << "\n3. Отредактировать параметры квартиры";
			cout << "\n4. Добавить квартиру";
			cout << "\n5. Удалить квартиру";
			cout << "\n6. Загрузить данные";
			cout << "\n7. Сохранить данные";
			choice = _getch();
	
		} while (choice < 0 and choice > 7);
		switch (choice)
		{
		case '1':
			system("cls");
			ShowAllRoomsInfo();
			break;
		case '2':

			cin.clear();
			cin.ignore();
			cout << "\nВведите номер квартиры: ";	
			cin >> number;
			system("cls");
			ShowDetailedInfo(number);
			break;
		case '3':
		EditOwnersInfo();
		EditRoomInfo(); 
		break;
		case '4':
			system("cls");
			AddRoom();
			break;
		case '5':
			system("cls");
			RemoveRoom();
			break;
		case '6':
		
			Load();
			system("cls");
			break;
		case '7':

			Save();
			system("cls");
			break;
		default:
			break;
		}


}

House::House()
{
	Load();
}

//House::House(Room rooms, int room)
//{
//	Room r{ rooms };
//	total_rooms_house = room;
//	this->rooms = new Room[1];
//	this->rooms[0] = r;
//}





House::House(const House& src)
{
	//cout << "\nHouse copy" << endl;
	total_rooms_house = src.total_rooms_house;
	rooms = new Room [total_rooms_house];
	for (int i = 0; i < total_rooms_house; i++)
	{
		rooms[i] = src.rooms[i];
	}
}





House::~House()
{

	delete[] rooms;
}
