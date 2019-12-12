#include "House.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	//Вариант запуска 1
	//Human h{ "Alex", "033", "1212" }, h2{ "defa", "1", "1" };
	//Room r, r2{ r };
	//r.AddHuman(h);
	//r.AddHuman(h2);
	////House my{r};//и так и так можно
	//House my;
	//my.AddRoom(r2);


	/////////////////////////
	///ВАРИАНТ 2
	House my; //грузит сразу данные из файла



	while (true) my.HouseMenu();


}