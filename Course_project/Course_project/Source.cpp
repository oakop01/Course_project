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
	Patient data2;
	
	string path = "data.txt";
	string path2 = "doc.txt";
	
	Fill_Data(data, path, Size);
	Fill_Doc(doc, path2, Size);

	Menu menu;
	menu.HomeScr();
	int index = 0;
	int flag = 0;

	while (1)
	{
		index = menu.Home();
		if (index == 15) menu.endfile();
		else if (index == 1){ 			
			Print_Data(data, Size);			
		}
		else if (index == 2) {
			cout << "\n Add new patient: " << endl;
			cout << " ID: " << Size ;
			data2.id = Size ;

			cout << "\n Name: ";
			cin >> data2.name;

			cout << " Surname: ";
			cin >> data2.surname;

			cout << " Data of receipt: ";
			cout << "Day:";
			cin >> data2.day_of_receipt;
			cout << "Months:";
			cin >> data2.months_of_receipt;
			cout << "Year:";
			cin >> data2.year_of_receipt;

			cout << " Diagnosis: ";
			cin >> data2.diagnosis;

			cout << " Healing: ";
			cin >> data2.healing;

			cout << " Palata: ";
			cin >> data2.palata;

			cout << " Insurance policy: ";
			cin >> data2.insurance_policy;

			cout << " Coust of treatment: ";
			cin >> data2.cost_of_treatment;

			cout << " Date of discharge: ";
			cout << "Day:";
			cin >> data2.day_of_discharge;
			cout << "Months:";
			cin >> data2.months_of_discharge;
			cout << "Year:";
			cin >> data2.year_of_discharge;

			Add_Patient(data, data2, Size);
			flag = 1;
			
		}
		else if (index == 3){
			Delete_data(data, Size);
			Print_Data(data, Size);
		}
		else if (index == 4) {
			Sort_diagnosis(data, Size);			
		}
		else if (index == 5){			
			Serch_data(data, Size);			
		}
		else if (index == 6){
			Sample(data, Size);
		}
		else if (index == 7){
			List_written_out(data, Size);			
		}	
		else if (index == 8){
			Serch_in_palata(data, doc, Size);			
		}
		else if (index == 9){
			Coust_treatment(data, Size);
		}
		else if (index == 10){
			Delete_patient_discharge_last_year(data, Size);			
		}
		else if (index == 11){
			Table_patient(data, Size);
		}
		else if (index == 12){
			Account_for_treatment(data, Size);
		}
		else if (index == 13){			
			Print_Doc(doc, Size);
		}
		else if (index == 14){			
			Save_Data(path, data, Size);
		}
	}
	system("pause");
	return 0;
}
