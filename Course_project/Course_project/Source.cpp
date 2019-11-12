#include<iostream>
#include<windows.h>
#include<string>
#include<fstream>
#include<iomanip>
#include<conio.h>
#include"Menu.h"
#include"Patient_data.h"
#include"Doctor_data.h"
#include"working_with_data.h"

using namespace std;
int Size = 6;

int main()
{
	Patient *data;
	Doctor *doc;	
	
	string path = "data.txt";
	string path2 = "doc.txt";
	
	Fill_Data(data, path, Size);
	Fill_Doc(doc, path2, Size);
	Authorization();

	Menu menu;
	menu.HomeScr();
	int index = 0;
	int flag = 0;
	   
	while (1)
	{
		index = menu.Home();

		switch (index)
		{
		case 1:
			Print_Data(data, Size);
			break;
		case 2:			
			Add_new_patuent(data, Size);			
			break;
		case 3:
			Delete_data(data, Size);
			break;
		case 4:
			Sort_diagnosis(data, Size);
			break;
		case 5:
			Serch_data(data, Size);
			break;
		case 6:
			Sample(data, Size);
			break;
		case 7:
			List_written_out(data, Size);
			break;
		case 8:
			Serch_in_palata(data, doc, Size);
			break;
		case 9:
			Coust_treatment(data, Size);
			break;
		case 10:
			Delete_patient_discharge_last_year(data, Size);
			break;
		case 11:
			Table_patient(data, Size);
			break;
		case 12:
			Account_for_treatment(data, Size);
			break;
		case 13:
			Print_Doc(doc, Size);
			break;
		case 14:
			Save_Data(path, data, Size);
			break;
		case 15:
			Exit(path, data, Size, menu);
			break;		
		}
	}
	system("pause");
	return 0;
}
