#include<iostream>
#include<windows.h>
#include<conio.h>
#include<fstream>
#include<iomanip>
#include"working_with_data.h"
#include"Doctor_data.h"
#include"Patient_data.h"
#include"Menu.h"


using namespace std;

void Fill_Data(Patient*& data, string path, int& Size)
{
	char tmp[255];

	ifstream readFile;

	readFile.open(path);
	if (!readFile.is_open()) {
		cout << " [!] Can't open file!" << endl;
	}

	else {
		readFile.getline(tmp, 255);
		Size = atoi(tmp);
		data = new Patient[Size];


		for (int i = 0; i < Size; i++) {

			readFile.getline(tmp, 255);
			data[i].id = atoi(tmp);

			readFile.getline(tmp, 255);
			data[i].name = tmp;

			readFile.getline(tmp, 255);
			data[i].surname = tmp;

			readFile.getline(tmp, 255);
			data[i].day_of_receipt = atoi(tmp);
			readFile.getline(tmp, 255);
			data[i].months_of_receipt = atoi(tmp);
			readFile.getline(tmp, 255);
			data[i].year_of_receipt = atoi(tmp);

			readFile.getline(tmp, 255);
			data[i].diagnosis = tmp;

			readFile.getline(tmp, 255);
			data[i].healing = tmp;

			readFile.getline(tmp, 255);
			data[i].palata = atoi(tmp);

			readFile.getline(tmp, 255);
			data[i].insurance_policy = atoi(tmp);

			readFile.getline(tmp, 255);
			data[i].cost_of_treatment = atoi(tmp);

			readFile.getline(tmp, 255);
			data[i].day_of_discharge = atoi(tmp);
			readFile.getline(tmp, 255);
			data[i].months_of_discharge = atoi(tmp);
			readFile.getline(tmp, 255);
			data[i].year_of_discharge = atoi(tmp);

		}
	}
	readFile.close();
}

void Fill_Doc(Doctor*& doc, string path2, int& Size)
{
	char tmp[255];

	ifstream readFile;

	readFile.open(path2);
	if (!readFile.is_open()) {
		cout << " [!] Can't open file!" << endl;
	}

	else {
		readFile.getline(tmp, 255);
		doc = new Doctor[3];

		for (int i = 0; i < 3; i++) {

			readFile.getline(tmp, 255);
			doc[i].name = tmp;

			readFile.getline(tmp, 255);
			doc[i].surname = tmp;

			readFile.getline(tmp, 255);
			doc[i].palata = atoi(tmp);

		}
	}
	readFile.close();
}

void Data_overwrite(Patient& data1, Patient data2)
{
	data1.id = data2.id;
	data1.name = data2.name;
	data1.surname = data2.surname;
	data1.day_of_receipt = data2.day_of_receipt;
	data1.months_of_receipt = data2.months_of_receipt;
	data1.year_of_receipt = data2.year_of_receipt;
	data1.diagnosis = data2.diagnosis;
	data1.healing = data2.healing;
	data1.palata = data2.palata;
	data1.insurance_policy = data2.insurance_policy;
	data1.cost_of_treatment = data2.cost_of_treatment;
	data1.day_of_discharge = data2.day_of_discharge;
	data1.months_of_discharge = data2.months_of_discharge;
	data1.year_of_discharge = data2.year_of_discharge;
}

void Add_Patient(Patient*& data, Patient data2, int& Size)
{
	Patient *newData = new Patient[Size + 1];

	for (int i = 0; i < Size; i++)
	{
		Data_overwrite(newData[i], data[i]);
	}
	Data_overwrite(newData[Size], data2);

	delete[] data;
	data = newData;
	Size++;

}

void Delete_data(Patient*& data, int& Size)
{
	int id=0;
	SetColor(10, 0);
	cout << "\n\n\n\n==================================" << endl;
	SetColor(15, 0);
	cout << "\n\n\n\n [~] Enter id patient: ";
	cin >> id;
	SetColor(10, 0);
	cout << "\n==================================\n" << endl;
	SetColor(15, 0);
	Patient* newData = new Patient[Size-1];
	
	for (int i = 0; i < Size-1; i++)
	{			
		if(i!=id) {
			newData[i].id = data[i].id;
			newData[i].name = data[i].name;
			newData[i].surname = data[i].surname;
			newData[i].day_of_receipt = data[i].day_of_receipt;
			newData[i].months_of_receipt = data[i].months_of_receipt;
			newData[i].year_of_receipt = data[i].year_of_receipt;
			newData[i].diagnosis = data[i].diagnosis;
			newData[i].healing = data[i].healing;
			newData[i].palata = data[i].palata;
			newData[i].insurance_policy = data[i].insurance_policy;
			newData[i].cost_of_treatment = data[i].cost_of_treatment;
			newData[i].day_of_discharge = data[i].day_of_discharge;
			newData[i].months_of_discharge = data[i].months_of_discharge;
			newData[i].year_of_discharge = data[i].year_of_discharge;
		}
	}

	for (int i = id; i < Size - 1; i++){
		Data_overwrite(newData[i], data[i+1]);
	}

	for (int i = 0; i < Size - 1; i++){
		newData[i].id = i;
	}
	
	delete[] data;
	data = newData;
	Size--;
	cout << "\n\n\n\n";
	SetColor(14, 0);
	for (int i = 1; i < 10; ++i) {
		Sleep(50);
		cout << "\t\t\t\t\t [~] Data Delete... [ \\ ]\r";
		Sleep(50);
		cout << "\t\t\t\t\t [~] Data Delete... [ | ]\r";
		Sleep(50);
		cout << "\t\t\t\t\t [~] Data Delete... [ / ]\r";
		Sleep(50);
		cout << "\t\t\t\t\t [~] Data Delete... [ - ]\r";
	}
	SetColor(15, 0);
	cout << "\n\n\t\t\t\t\t\t Enter [^]  back to menu." << endl;

}

void Coust_treatment(Patient* data, int& Size)
{
	int id = 0;
	int tmp = 0;
	bool exit = false;

	SetColor(10, 0);
	cout << "\n\n\n\n==================================" << endl;
	SetColor(15, 0);

	while (!exit) {

		cout << "\n [~] Enter ID patient: ";
		cin >> id;

		if (id >= 0 && id <= Size)
		{
			exit = true;
		}
		else
			cout << "\n [!] Try again!";
	}
	SetColor(10, 0);
	cout << "\n==================================" << endl;
	SetColor(15, 0);
	for (int i = 0; i < Size; i++)
	{
		if (data[i].id == id)
		{
			tmp++;
			cout << "\n Name: " << data[i].name << " " << data[i].surname << endl;
			cout << " You mast pay: " << data[i].cost_of_treatment <<" $"<< endl;
		}
	}

	if (tmp == 0)
	{
		cout << " [!] No patient ID " << id << endl;
	}
	cout << "\n\n\t\t\t\t\t\t Enter [^]  back to menu." << endl;

}

void Delete_patient_discharge_last_year(Patient *&data, int& Size)
{
		
	int id = 0;
	int tmp = 0;

	for (int i = 0; i < Size; i++)
	{
		if (data[i].year_of_discharge <= 2018)
			tmp++;
	}

	for(int i=0; i<tmp; i++)
	{
		id = 0;

		for (int i = 0; i < Size; i++)		{
			if (data[i].year_of_discharge <= 2018) {
				id = i;
			}
		}

		Patient* newData = new Patient[Size - 1];

		for (int i = 0; i < Size - 1; i++)
		{
			if (i != id) {
				Data_overwrite(newData[i], data[i]);
			}
		}

		for (int i = id; i < Size - 1; i++) {
			Data_overwrite(newData[i], data[i + 1]);
		}

		for (int i = 0; i < Size - 1; i++) {
			newData[i].id = i;
		}

		delete[] data;
		data = newData;
		Size--;

		
	}
	

	/*for (int i = 0; i < Size; i++)
	{
		if (data[i].year_of_discharge <= 2018){		
			id = i;
		}
	}
	cout << "\n Patient delete ID: " << id;

	Patient* newData = new Patient[Size - 1];

	for (int i = 0; i < Size - 1; i++)
	{
		if (i != id) {
			newData[i].id = data[i].id;
			newData[i].name = data[i].name;
			newData[i].surname = data[i].surname;
			newData[i].day_of_receipt = data[i].day_of_receipt;
			newData[i].months_of_receipt = data[i].months_of_receipt;
			newData[i].year_of_receipt = data[i].year_of_receipt;
			newData[i].diagnosis = data[i].diagnosis;
			newData[i].healing = data[i].healing;
			newData[i].palata = data[i].palata;
			newData[i].insurance_policy = data[i].insurance_policy;
			newData[i].cost_of_treatment = data[i].cost_of_treatment;
			newData[i].day_of_discharge = data[i].day_of_discharge;
			newData[i].months_of_discharge = data[i].months_of_discharge;
			newData[i].year_of_discharge = data[i].year_of_discharge;
		}
	}

	for (int i = id; i < Size - 1; i++) {
		Data_overwrite(newData[i], data[i+1]);
	}

	for (int i = 0; i < Size - 1; i++) {
		newData[i].id = i;
	}

	delete[] data;
	data = newData;
	Size--;*/

	cout << "\n\n\n\n";
	SetColor(14, 0);
	for (int i = 1; i < 10; ++i) {
		Sleep(50);
		cout << "\t\t\t\t\t [~] Data Delete... [ \\ ]\r";
		Sleep(50);
		cout << "\t\t\t\t\t [~] Data Delete... [ | ]\r";
		Sleep(50);
		cout << "\t\t\t\t\t [~] Data Delete... [ / ]\r";
		Sleep(50);
		cout << "\t\t\t\t\t [~] Data Delete... [ - ]\r";
	}
	SetColor(15, 0);
	cout << "\n\n\n\n\t\t\t\t\t\t Enter [^]  back to menu." << endl;

}

void List_written_out(Patient* data, int& Size)
{
	int day = 0;
	int tmp = 0;
	bool exit = false;

	SetColor(10, 0);
	cout << "\n\n\n\n==================================" << endl;
	SetColor(15, 0);

	while (!exit) {
		cout << "\n [~] Enter day: ";
		cin >> day;
		if (day > 0 && day <= 31)
			exit = true;
		else
			cout << "\n [!] Try againe!";
	}
	cout << endl;
	SetColor(10, 0);
	cout << "\n==================================" << endl;
	SetColor(15, 0);
	for (int i = 0; i < Size; i++)	{
		if (data[i].day_of_discharge == day)		{
			tmp++;
			cout << " Name:  " << data[i].name << " " << data[i].surname << endl;
		}
	}
	if (tmp == 0)	{
		cout << " [!] No patient to discharge" << endl;
	}

	cout << "\n\n\t\t\t\t\t\t Enter [^]  back to menu." << endl;

}

void Sample(Patient* data, int& Size)
{
	int day;
	string diagnosis;
	int tmp = 0;
	bool exit = false;

	SetColor(10, 0);
	cout << "\n\n\n\n==================================" << endl;
	SetColor(15, 0);

	while (!exit) {
		cout << "\n [~] Enter day: ";
		cin >> day;
		if (day > 0 && day <= 31)
			exit = true;
		else
			cout << "\n [!] Try againe!";
	}

	cout << "\n [~] Enter diagnosis: ";
	cin >> diagnosis;
	SetColor(10, 0);
	cout << "\n==================================" << endl;
	SetColor(15, 0);
	for (int i = 0; i < Size; i++)	{
		if (data[i].day_of_receipt == day && data[i].diagnosis == diagnosis){
			tmp++;
			cout << "\n Name    " << data[i].name << " " << data[i].surname << endl;
			cout << " Palata  [ " << data[i].palata << " ]" << endl;
		}
	}
	if (tmp == 0)	{
		cout << "\n\n [!] No patient in this day and diagnosis" << endl;
	}

	cout << "\n\n\t\t\t\t\t\t Enter [^]  back to menu." << endl;
}

void Save_Data(string path, Patient*& data, int& Size)
{
	cout << "\n\n\n\n";
	SetColor(14, 0);
	for (int i = 1; i < 10; ++i)	{
		Sleep(70);
		cout << "\t\t\t\t\t [~] Data Save... [ \\ ]\r";	
		Sleep(70);
		cout << "\t\t\t\t\t [~] Data Save... [ | ]\r";		
		Sleep(70);
		cout << "\t\t\t\t\t [~] Data Save... [ / ]\r";
		Sleep(70);
		cout << "\t\t\t\t\t [~] Data Save... [ - ]\r";
	}
	SetColor(15, 0);
	ofstream writeFile;
	writeFile.open(path);

	if (!writeFile.is_open())
	{
		cout << " [!] Can't save file!" << endl;
	}
	else {
		writeFile << Size << endl;
		for (int i = 0; i < Size; i++)
		{
			writeFile << data[i].id << endl;
			writeFile << data[i].name << endl;
			writeFile << data[i].surname << endl;
			writeFile << data[i].day_of_receipt << endl;
			writeFile << data[i].months_of_receipt << endl;
			writeFile << data[i].year_of_receipt << endl;
			writeFile << data[i].diagnosis << endl;
			writeFile << data[i].healing << endl;
			writeFile << data[i].palata << endl;
			writeFile << data[i].insurance_policy << endl;
			writeFile << data[i].cost_of_treatment << endl;
			writeFile << data[i].day_of_discharge << endl;
			writeFile << data[i].months_of_discharge << endl;
			writeFile << data[i].year_of_discharge << endl;
		}
	}
	writeFile.close();
	cout << endl;

	cout << "\n\n\t\t\t\t\t\t Enter [^]  back to menu." << endl;
}

void Print_Data(Patient* data, int& Size)
{
	SetColor(10, 0);
	cout << "\n\n\n\n==================================" << endl;
	SetColor(15, 0);
	for (int i = 0; i < Size; i++) {
		cout << "\n ID [ " << data[i].id << " ]" << endl;
		data[i].ShowData();
		SetColor(10, 0);
		cout << "\n==================================" << endl;
		SetColor(15, 0);
	}

	cout << "\n\n\t\t\t\t\t\t Enter [^]  back to menu." << endl;
}

void Print_Doc(Doctor* doc, int& Size)
{
	SetColor(10, 0);
	cout << "\n\n\n\n==================================" << endl;
	SetColor(15, 0);
	for (int i = 0; i < 3; i++) {
		cout << "\n";
		doc[i].ShowData();
		SetColor(10, 0);
		cout << "\n==================================" << endl;
		SetColor(15, 0);
	}

	cout << "\n\n\t\t\t\t\t\t Enter [^]  back to menu." << endl;
}

void Serch_data(Patient* data, int& Size)
{
	int id = 0;
	SetColor(10, 0);
	cout << "\n\n\n\n==================================" << endl;
	SetColor(15, 0);
	cout << "\n [~] Enter id patient to serch: ";
	cin >> id;
	SetColor(10, 0);
	cout << "\n==================================\n" << endl;
	SetColor(15, 0);
	bool exit = false;

	for (int i = 0; i < Size; i++)	{
		if (data[i].id == id){
			exit = true;
			data[i].ShowData();			
		}
	}
	if (!exit){
		cout << " [~] No serch patient with this >>> " << id << " ID." << endl;
	}

	cout << "\n\n\t\t\t\t\t\t Enter [^]  back to menu." << endl;
}

void Serch_in_palata(Patient*& data, Doctor*& doc, int& Size)
{
	int index = 0;
	int pal = 0;
	int num = 1;


	SetColor(10, 0);
	cout << "\n\n\n\n==================================" << endl;
	SetColor(15, 0);
	cout << "\n [~] Enter # palata: ";
	cin >> pal;
	SetColor(10, 0);
	cout << "\n==================================" << endl;
	SetColor(15, 0);

	if (pal <=3) {

		cout << "\n Doctor in palata: " << doc[pal - 1].name << " " << doc[pal - 1].surname << endl;
		for (int i = 0; i < Size; i++){
			if (data[i].palata == pal){
				index++;
			}
		}
		cout << "\n [ " << index << " ] patient in palata\n\n";

		SetColor(10, 0);
		cout << "==================================\n\n" << endl;
		SetColor(15, 0);

		cout << " #" << setw(12) << " Name" << setw(11) << "Surname" << setw(13) << "Diagnosis" << setw(12) << "Healing\n";
		SetColor(10, 0);
		cout<<"____________________________________________________\n\n";
		SetColor(15, 0);
		for (int i = 0; i < Size; i++){
			if (data[i].palata == pal){
				
				cout <<" ["<<num++<<"]"<<setw(10)<< data[i].name << setw(11) << data[i].surname << setw(13) << data[i].diagnosis << setw(13)<< data[i].healing << endl;
			}
		}		
	}
	else {
		cout << " [~] No palata # " << pal << endl;
	}

	cout << "\n\n\t\t\t\t\t\t Enter [^]  back to menu." << endl;
}

void Table_patient(Patient* data, int& Size)
{
	
	cout << "\n\n\n\n\n Palata" << setw(10) << "Name" << setw(15) << "Surname" << setw(20) << "Data of receipt" << setw(15) << "Diagnosis" << setw(13) << "Healing" << setw(22) << "Insurance policy" << setw(23)
		<< "Coust of treatment" <<
		setw(22) << "Date of discharge\n";
	SetColor(10, 0);
	cout<<"___________________________________________________________________________________________________________________________________________________" << endl;	
	SetColor(15, 0);
	for (int i = 0; i < Size; i++)
	{
		cout << "  [" << data[i].palata << "]" << setw(12) << data[i].name << setw(15) << data[i].surname << setw(12) << data[i].day_of_receipt << "." << data[i].months_of_receipt << "." << data[i].year_of_receipt << setw(15) << data[i].diagnosis << setw(15)
			<< data[i].healing <<
			setw(20) << data[i].insurance_policy << setw(15) << data[i].cost_of_treatment<<" $" << setw(17) << data[i].day_of_discharge << "." << data[i].months_of_discharge << "." << data[i].year_of_discharge << endl;
	}
	SetColor(10, 0);
	cout<< "___________________________________________________________________________________________________________________________________________________" << endl;
	SetColor(15, 0);
	cout << "\n\n\t\t\t\t\t\t Enter [^]  back to menu." << endl;
}

void Sort_diagnosis(Patient* data, int& Size)
{
	Patient tmp;

	for (int i = 0; i < Size; i++) {
		for (int j = 0; j < Size - i - 1; j++) {

			if (_strcmpi(data[j].diagnosis.c_str(), data[j + 1].diagnosis.c_str()) > 0)
			{
				tmp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = tmp;
			}
		}
	}

	SetColor(10, 0);
	cout << "\n\n\n\n=============================" << endl;
	SetColor(15, 0);

	for (int i = 0; i < Size; i++)
	{	
		cout << "\n ID [ " << data[i].id << " ]" << endl;
		data[i].ShowData();
		SetColor(10, 0);
		cout << "\n=============================" << endl;
		SetColor(15, 0);
	}

	cout << "\n\n\t\t\t\t\t\t Enter [^]  back to menu." << endl;	

}

void Account_for_treatment(Patient* data, int& Size)
{
	cout << "\n\n\n\n ID " << setw(10) << "Name" << setw(15) << "Surname" << setw(15) << "Diagnosis" << setw(20) << "Insurance policy" << setw(20) << "Coust of treatment" << endl;
	SetColor(10, 0);	
	cout<<"______________________________________________________________________________________" << endl;
	SetColor(15, 0);

	for (int i = 0; i < Size; i++)
	{
		cout <<" ["<<data[i].id<<"]"<<setw(10)<< data[i].name << setw(15) << data[i].surname << setw(13) << data[i].diagnosis << setw(20)
		<< data[i].insurance_policy << setw(13) << data[i].cost_of_treatment <<" $" << endl;
	}
	cout << "\n\n\n\t\t\t\t\t\t Enter [^]  back to menu." << endl;
}

void Add_new_patuent(Patient *&data, int &Size)
{
	Patient data2;

	SetColor(10, 0);
	cout << "\n\n\n\n==================================" << endl;
	SetColor(15, 0);
	cout << "\n\t [Add new patient] " << endl;
	cout << "\n ID: " << Size;
	data2.id = Size;
	
	SetColor(14, 0);
	cout << "\n\n Name: ";
	cin >> data2.name;

	cout << " Surname: ";
	cin >> data2.surname;

	cout << "\n\t [Data of receipt]" << endl;
	
	cout << " Day:";
	cin >> data2.day_of_receipt;
	cout << " Months:";
	cin >> data2.months_of_receipt;
	cout << " Year:";
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

	cout << "\n\t [Date of discharge]" << endl;
	cout << " Day:";
	cin >> data2.day_of_discharge;
	cout << " Months:";
	cin >> data2.months_of_discharge;
	cout << " Year:";
	cin >> data2.year_of_discharge;

	SetColor(15, 0);

	cout << "\n\n\t\t\t\t\t\t Enter [^]  back to menu." << endl;

	Add_Patient(data, data2, Size);

}

void Authorization() 
{
	string login;
	string pass;
	int log = 0;
	int pas = 0;
	int sum = 0;
	bool exit = false;
	
	
	while (!exit)
	{
		system("cls");
		log = pas = 0;
		SetColor(10, 0);
		cout << "\n\n\n\n\n\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		cout << "\n\n\n\t\t\t\t\t\t\tWELCOME TO HOSPITAL " << endl;
		cout << "\n\t\t\t\t\t\t\t  [ doc | doc ]";
		cout << "\n\n\n\t\t\t\t\t\tLOGIN : ";
		cin >> login;
		cout << "\n\t\t\t\t\t\tPASSWORD : ";
		cin >> pass;

		if (login == "doc"){
			log = 1;
		}
		if (pass == "doc"){
			pas = 1;
		}
		sum = log + pas;
		if (sum == 2){
			exit = true;
		}
		else {
			SetColor(14, 0);
			cout << "\n\n\t\t\t\t\t[!] Login or Passworg is not corect. Try again  [!]";
			SetColor(10, 0);
			cout << "\n\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
			SetColor(15, 0);
			Sleep(1500);
		}

		SetColor(15, 0);		

	}
}

void Exit(string path, Patient*& data, int& Size, Menu &menu)
{
	char key;
	system("cls");	
	SetColor(14, 0);
	cout <<"\n\n\n\n\n\t\t\t\t\t[!]\t\tSAVE DATA?\t\t[!]"; 
	cout<< "\n\n \t\t\t\t\t   Press 'ENTER' to Save, 'ESC' to Cancel" << endl;
	key = _getch();
	
	if ((key == 10) || (key == 13)) {

		cout << "\n\n";
	for (int i = 1; i < 10; ++i) {
		Sleep(70);
		cout << "\t\t\t\t\t\t [~] Data Save... [ \\ ]\r";
		Sleep(70);
		cout << "\t\t\t\t\t\t [~] Data Save... [ | ]\r";
		Sleep(70);
		cout << "\t\t\t\t\t\t [~] Data Save... [ / ]\r";
		Sleep(70);
		cout << "\t\t\t\t\t\t [~] Data Save... [ - ]\r";
	}
	cout << "\n\n";
		SetColor(15, 0);
		ofstream writeFile;
		writeFile.open(path);

		if (!writeFile.is_open())	{
			cout << " [!] Can't save file!" << endl;
		}
		else {
			writeFile << Size << endl;
		for (int i = 0; i < Size; i++){
			writeFile << data[i].id << endl;
			writeFile << data[i].name << endl;
			writeFile << data[i].surname << endl;
			writeFile << data[i].day_of_receipt << endl;
			writeFile << data[i].months_of_receipt << endl;
			writeFile << data[i].year_of_receipt << endl;
			writeFile << data[i].diagnosis << endl;
			writeFile << data[i].healing << endl;
			writeFile << data[i].palata << endl;
			writeFile << data[i].insurance_policy << endl;
			writeFile << data[i].cost_of_treatment << endl;
			writeFile << data[i].day_of_discharge << endl;
			writeFile << data[i].months_of_discharge << endl;
			writeFile << data[i].year_of_discharge << endl;
		}
	}
		writeFile.close();		
	}

	menu.endfile();
}
