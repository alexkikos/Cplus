#include "Room.h"


void Room::UserMenu() 
{
	cout << "\n1. add \n2. Show";
	int a;
	cin >> a;
	switch (a)
	{
	case 1: AddHuman(); break;
	case 2: ShowAllHumansLivesRoom();  break;
	default:
		break;
	}
}

int Room::GetHumansInRoom() const
{
	return size_humans_in_room;
}
void Room::SetHumansInRoom(int number)
{
	size_humans_in_room = number;
}
string Room::GetOwner()
{
	return humans_in_room[0].GetFio();
}

void Room::AddHuman()
{
	Human my;
	my.HumanSetInfo();
	cout << "\nEnter square room: ";
	cin >> square;
	cout << "\nEnter total_rooms: ";
	cin >> total_rooms;
	cout << "\nEnter total balkonies: ";
	cin >> balkonies;
	cout << "\nEnter number Room: ";
	cin >> nubmer_room;
	AddHuman(my);
 }

void Room::AddHuman(Human& human)
{
	Human* temp = new Human[size_humans_in_room + 1];
	for (int i = 0; i < size_humans_in_room; i++)
	{
		temp[i] = humans_in_room[i];
	}
	temp[size_humans_in_room] = human;	
	if (size_humans_in_room > 0) delete[] humans_in_room;
	humans_in_room = temp;
	size_humans_in_room++;
}

void Room::RemoveHuman(int index)
{
	Human* temp = new Human[size_humans_in_room - 1];
	for (int i = 0; i < size_humans_in_room - 1; i++)
	{
		if (i == index) continue;
		temp[i] = humans_in_room[i];
	}
	delete[] humans_in_room;
	humans_in_room = temp;
	size_humans_in_room--;

}
void Room::SetSquare(float number)
{
	square = number;
}
float Room::GetSquare() const
{
	return square;
}
void Room::SetTotalRooms(int number)
{
	total_rooms = number;
}
int Room::GetTotalRooms() const
{
	return total_rooms;
}
void Room::SetBalkonies(int number)
{
	balkonies = number;
}
int Room::GetTotalBalkonies() const
{
	return balkonies;
}

void Room::SetNumberForRoom(int number)
{
	nubmer_room = number;
}

int Room::GetNumberRoom() const
{
	return nubmer_room;
}


void Room::ShowAllHumansLivesRoom() const
{
	for (int i = 0; i < size_humans_in_room; i++)
	{
		cout << humans_in_room[i].GetFio() << endl;
	}
}

void Room::ShowAllParamsRoom() const
{
	cout << "\n========================================";
	cout << "\nТЕХПАСПОРТ КВАРТИРЫ: " << endl;
	cout << "\nНомер квартиры: " << GetNumberRoom();
	cout << "\nКоличество прописанных жильцов: " << GetHumansInRoom();
	cout << "\nПлощадь квартиры: " << GetSquare();
	cout << "\nКоличество комнат: " << GetTotalRooms();
	cout << "\nКоличество балконов: " << GetTotalBalkonies();
	cout << "\n========================================";
	cout << "\nИнформация о прописанных людях: " << endl;
	for (int i = 0; i < size_humans_in_room; i++)
	{
		humans_in_room[i].ShowHumanInfo();
		cout  << "\n---------------------------------------------";
	}
	cout << endl;
}

void Room::EditParamsRoom()
{	

	cout << "\n========================================";
	cout << "\nТЕХПАСПОРТ КВАРТИРЫ";
	float a;
	cout << "\nПлощадь квартиры: ";
	cin >> a;
	square = a;
	int s;
	cout << "\nКоличество комнат: ";
	cin >> s;
	total_rooms = s;
	int b;
	cout << "\nКОличество балконов: ";
	cin >> b;
	balkonies = b;
	int g;
	cout << "\nНомер квартиры: ";
	cin >> g;
	nubmer_room = g;
	int g1;
	cout << "\nЭтаж: ";
	cin >> g1;
	floor = g1;
}

void Room::EditOwners()
{
	int a;
	cout << "\n Введите количество проживающий людей: ";
	cin >> a;
	size_humans_in_room = a;
	delete[] humans_in_room;
	humans_in_room = new Human[a];
	for (int i = 0; i < a; i++)
	{
		humans_in_room[i].HumanSetInfo();
	}
}

void Room::SetFloor(int floor)
{
	this->floor = floor;
}

int Room::GetFloor() const
{
	return floor;
}

void Room::SaveRoom(ofstream& save)
{
	save.write((char*)& size_humans_in_room, sizeof(int));
	save.write((char*)& square, sizeof(int));
	save.write((char*)& total_rooms, sizeof(int));
	save.write((char*)& balkonies, sizeof(int));
	save.write((char*)& nubmer_room, sizeof(int));
	save.write((char*)& floor, sizeof(int));
	for (int i = 0; i < size_humans_in_room; i++)
	{
		humans_in_room[i].SaveHuman(save);
	}

}

void Room::LoadRoom(ifstream& load)
{
	int size;
	load.read((char*)& size, sizeof(int));
	size_humans_in_room = size;
	float sq;
	load.read((char*)& sq, sizeof(int));
	square = sq;
	load.read((char*)& size, sizeof(int));
	total_rooms = size;
	load.read((char*)& size, sizeof(int));
	balkonies = size;
	load.read((char*)& size, sizeof(int));
	nubmer_room = size;
	load.read((char*)& size, sizeof(int));
	floor = size;
	humans_in_room = new Human[size_humans_in_room];
	for (int i = 0; i < size_humans_in_room; i++)
	{
		humans_in_room[i].LoadHuman(load);
	}
}

Room::Room(Human human, int size_humans_in_room, float square, int total_rooms, int balkonies, int number_room, int floor1)
{
	humans_in_room = new Human[1];
	this->humans_in_room[0].SetFio(human.GetFio());
	this->humans_in_room[0].SetHomePhone(human.GetHomePhone());
	this->humans_in_room[0].SetWorkPhone(human.GetWorkPhone());
	this->size_humans_in_room = size_humans_in_room;
	this->square = square;
	this->total_rooms = total_rooms;
	this->balkonies = balkonies;
	this->nubmer_room = number_room;
	this->floor = floor1;

}

Room& Room::operator=(const Room& src)
{
	//cout << "=";
	this->size_humans_in_room = src.size_humans_in_room;
	this->humans_in_room = new Human[size_humans_in_room];

	for (int i = 0; i < this->size_humans_in_room; i++)
	{
		this->humans_in_room[i] = src.humans_in_room[i];

	}
	this->square = src.square;
	this->total_rooms = src.total_rooms;;//количество комнат, не статик тк относится к определенному обьекту
	this->balkonies = src.balkonies;;// количество балконов
	this->nubmer_room = src.nubmer_room;;//номер команты в доме
	this->floor = src.floor;
	return *this;
}

Room::~Room()
{
	delete[] humans_in_room;
}



Room::Room(const Room& src)
{
	//cout << "\nCopy Room" << endl;
	this->size_humans_in_room = src.size_humans_in_room;
	this->humans_in_room = new Human[size_humans_in_room];	

	for (int i = 0; i < this->size_humans_in_room; i++)
	{
		this->humans_in_room[i] = src.humans_in_room[i];
	
	}
	this->square = src.square;
	this->total_rooms= src.total_rooms;;//количество комнат, не статик тк относится к определенному обьекту
	this->balkonies= src.balkonies;;// количество балконов
	this->nubmer_room= src.nubmer_room;;//номер команты в доме
	this->floor= src.floor;
}


