#include<iostream>
#include<windows.h>
#include"working_with_data.h"
#include"Doctor_data.h"
#include"Patient_data.h"
#include<fstream>
#include<iomanip>

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
		//Size = atoi(tmp);
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
	cout << "\n\n\n\n [~] Enter id patient: ";
	cin >> id;

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
	cout << "\n\n\t\t\t\t\t\t Enter [^]  back to menu." << endl;

}

void Coust_treatment(Patient* data, int& Size)
{
	int id = 0;
	int tmp = 0;
	bool exit = false;

	while (!exit) {

		cout << "\n\n\n\n [~] Enter ID patient: ";
		cin >> id;

		if (id >= 0 && id <= Size)
		{
			exit = true;
		}
		else
			cout << "\n [!] Try again!";
	}
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
	cout << "\n\n\n\n [~] Delete data..." << endl;
	
	int id = 0;

	for (int i = 0; i < Size; i++)
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
	Size--;

	cout << "\n\n\t\t\t\t\t\t Enter [^]  back to menu." << endl;

}

void List_written_out(Patient* data, int& Size)
{
	int day = 0;
	int tmp = 0;
	bool exit = false;

	while (!exit) {
		cout << "\n\n\n\n [~] Enter day: ";
		cin >> day;
		if (day > 0 && day <= 31)
			exit = true;
		else
			cout << "\n [!] Try againe!";
	}
	cout << endl;
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

	while (!exit) {
		cout << "\n\n\n\n [~] Enter day: ";
		cin >> day;
		if (day > 0 && day <= 31)
			exit = true;
		else
			cout << "\n [!] Try againe!";
	}

	cout << "\n [~] Enter diagnosis: ";
	cin >> diagnosis;

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
	cout << "\n\n\n\n ==================================" << endl;
	for (int i = 0; i < Size; i++) {
		cout << "\n ID [ " << data[i].id << " ]" << endl;
		data[i].ShowData();
		cout << "\n==================================" << endl;
	}

	cout << "\n\n\t\t\t\t\t\t Enter [^]  back to menu." << endl;
}

void Print_Doc(Doctor* doc, int& Size)
{
	cout << "\n\n\n\n==================================" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "\n";
		doc[i].ShowData();
		cout << "\n==================================" << endl;
	}

	cout << "\n\n\t\t\t\t\t\t Enter [^]  back to menu." << endl;
}

void Serch_data(Patient* data, int& Size)
{
	int id = 0;
	cout << "\n\n\n\n==================================" << endl;
	cout << "\n [~] Enter id patient to serch: ";
	cin >> id;
	cout << "\n";
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

	cout << "\n\n\n\n [~] Enter # palata: ";
	cin >> pal;

	if (pal <=3) {

		cout << "\n Doctor in palata: " << doc[pal - 1].name << " " << doc[pal - 1].surname << endl;
		for (int i = 0; i < Size; i++){
			if (data[i].palata == pal){
				index++;
			}
		}
		cout << "\n [ " << index << " ] patient in palata\n\n";
		cout << " #"<<setw(12)<<" Name" << setw(11)<<"Surname"<<setw(13)<< "Diagnosis" << setw(12) << "Healing"  << "\n====================================================\n\n";
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
	cout << "\n\n\n Palata" << setw(10) << "Name" << setw(15) << "Surname" << setw(20) << "Data of receipt" << setw(15) << "Diagnosis" << setw(13) << "Healing" << setw(22) << "Insurance policy" << setw(23)
		<< "Coust of treatment" <<
		setw(22) << "Date of discharge\n" << "___________________________________________________________________________________________________________________________________________________" << endl;

	for (int i = 0; i < Size; i++)
	{
		cout << "  [" << data[i].palata << "]" << setw(12) << data[i].name << setw(15) << data[i].surname << setw(12) << data[i].day_of_receipt << "." << data[i].months_of_receipt << "." << data[i].year_of_receipt << setw(15) << data[i].diagnosis << setw(15)
			<< data[i].healing <<
			setw(20) << data[i].insurance_policy << setw(15) << data[i].cost_of_treatment<<" $" << setw(17) << data[i].day_of_discharge << "." << data[i].months_of_discharge << "." << data[i].year_of_discharge << endl;
	}
	cout<< "___________________________________________________________________________________________________________________________________________________" << endl;
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

	for (int i = 0; i < Size; i++)
	{	
		cout << "\n ID [ " << data[i].id << " ]" << endl;
		data[i].ShowData();
		cout << "\n=============================" << endl;
	}

	cout << "\n\n\t\t\t\t\t\t Enter [^]  back to menu." << endl;	

}

void Account_for_treatment(Patient* data, int& Size)
{
	cout << "\n\n\n ID "<<setw(10)<<"Name" << setw(15) << "Surname" << setw(15) << "Diagnosis" << setw(20) << "Insurance policy" << setw(20) << "Coust of treatment" <<
		 "\n______________________________________________________________________________________" << endl;

	for (int i = 0; i < Size; i++)
	{
		cout <<" ["<<data[i].id<<"]"<<setw(10)<< data[i].name << setw(15) << data[i].surname << setw(13) << data[i].diagnosis << setw(20)
		<< data[i].insurance_policy << setw(13) << data[i].cost_of_treatment <<" $" << endl;
	}
	cout << "\n\n\t\t\t\t\t\t Enter [^]  back to menu." << endl;
}

void Authorization() 
{
	string login;
	string pass;
	
		cout << "\n\n\n\n\n\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		cout << "\n\n\n\t\t\t\tWELCOME TO HOSPITAL " << endl;
			

		cout << "\n\n\t\t LOGIN : ";
		cin >> login;
		

		cout << "\t\t PASSWORD : ";
		cin >> pass;
		
	
	
	
}
