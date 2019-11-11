#include"working_with_data.h"
#include"Doctor_data.h"
#include"Patient_data.h"
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

void Fill_Data(Patient*& data, string path, int& Size)
{
	char tmp[255];

	ifstream readFile;

	readFile.open(path);
	if (!readFile.is_open()) {
		cout << "Can't open file!" << endl;
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
	cout << "Data fill!!!" << endl;
}

void Fill_Doc(Doctor*& doc, string path2, int& Size)
{
	char tmp[255];

	ifstream readFile;

	readFile.open(path2);
	if (!readFile.is_open()) {
		cout << "Can't open file!" << endl;
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
	cout << "Data fill!!!" << endl;
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
	cout << "\n\n Enter id patient: ";
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

	for (int i = id; i < Size-1; i++){
		Data_overwrite(newData[i], data[i+1]);
	}

	for (int i = 0; i < Size - 1; i++){
		newData[i].id = i;
	}
	
	delete[] data;
	data = newData;
	Size--;

}

void Coust_treatment(Patient *data, int& Size)
{
	int id = 0;
	int tmp = 0;
	cout << "\n\n Enter ID patient: ";
	cin >> id;

	for (int i = 0; i < Size; i++)
	{
		if (data[i].id == id)
		{
			tmp++;
			cout << "\n Name: " << data[i].name << " " << data[i].surname << endl;
			cout << " You mast pay: " << data[i].cost_of_treatment << endl;
		}
	}

	if (tmp == 0)
	{
		cout << "\n No patient ID " << id << endl;
	}

}

void Delete_patient_discharge_last_year(Patient *data, int& Size)
{
	cout << "\n Delete data..." << endl;
	int tmp = 0;

	for (int i = 0; i < Size; i++)
	{
		if (data[i].year_of_discharge <= 2018)
		{
			tmp++;//çíàõîäèìî ê³ëüê³ñòü ïàö³ºíò³â ùî âèïèñàëèñÿ á³ëüøå ðîêó òîìó
		}
	}

	cout << " Patient count >>> " << tmp << endl;

	Patient* newData = new Patient[Size - tmp];

	for (int i = 0; i < Size-tmp; i++)
	{
		//Data_overwrite(newData[i], data[i]);
	}
	for (int i = 0; i < Size-tmp; i++)
	{
		if (data[i].year_of_discharge > 2018) 
		{
			Data_overwrite(newData[i], data[i]);
		}
	}

	
	
	delete[] data;
	data = newData;
	Size=-tmp;

}

void List_written_out(Patient *data, int& Size)
{
	int day = 0;
	int tmp = 0;
	cout << "\n\n Enter day: ";
	cin >> day;

	for (int i = 0; i < Size; i++)
	{
		if (data[i].day_of_discharge == day)
		{
			tmp++;
			cout << "\n Name > " << data[i].name << " " << data[i].surname << endl;
		}
	}

	if (tmp == 0)
	{
		cout << "\n\n No patient to discharge" << endl;
	}

}

void Sample(Patient *data, int& Size)
{
	int day;
	string diagnosis;
	int tmp = 0;

	cout << "\n\n Enter day: ";
	cin >> day;
	cout << "\n Enter diagnosis: ";
	cin >> diagnosis;

	for (int i = 0; i < Size; i++)
	{
		if (data[i].day_of_receipt == day && data[i].diagnosis == diagnosis)
		{
			tmp++;
			cout << "\n Name    " << data[i].name << " " << data[i].surname << endl;
			cout << " Palata [ " << data[i].palata << " ]" << endl;
		}
	}

	if (tmp == 0)
	{
		cout << "\n\n No patient in this day and diagnosis" << endl;
	}
}

void Save_Data(string path, Patient*& data, int& Size)
{
	ofstream writeFile;
	writeFile.open(path);

	if (!writeFile.is_open())
	{
		cout << "Can't save file!" << endl;
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
}

void Print_Data(Patient* data, int& Size)
{
	for (int i = 0; i < Size; i++) {
		cout << "\n__________________________________" << endl;
		cout << "\n\n ID [ " << data[i].id << " ]" << endl;
		data[i].ShowData();
		cout << "\n==================================" << endl;
	}
}

void Print_Doc(Doctor* doc, int& Size)
{
	for (int i = 0; i < 3; i++) {
		doc[i].ShowData();
		cout << "\n__________________________________" << endl;
	}
}

void Serch_data(Patient* data, int& id, int& Size)
{
	bool exit = false;

	for (int i = 0; i < Size; i++)
	{
		if (data[i].id == id)
		{
			exit = true;
			data[i].ShowData();
			cout << "\n\n";
		}
	}

	if (!exit)
	{
		cout << "\n No serch patient with this >>> " << id << " ID." << endl;
	}
}

void Serch_in_palata(Patient*& data, Doctor*& doc, int& Size)
{
	int index = 0;
	int pal = 0;

	cout << "\n Enter # palata: ";
	cin >> pal;

	if (pal <=3) {

		cout << "\n Doctor in palata: " << doc[pal - 1].name << " " << doc[pal - 1].surname << endl;
		for (int i = 0; i < Size; i++){
			if (data[i].palata == pal){
				index++;
			}
		}
		cout << "\n [ " << index << " ] patient in palata\n\n";
		cout << " Name" << setw(20) << "Diagnosis" << setw(10) << "Healing" << setw(20) << "\n" << "__________________________________________\n\n";
		for (int i = 0; i < Size; i++){
			if (data[i].palata == pal){
				cout << data[i].name << " " << data[i].surname << setw(5) << "|" << data[i].diagnosis << setw(15) << data[i].healing << endl;
			}
		}		
	}
	else {
		cout << " No palata # " << pal << endl;
	}
}

void Table_patient(Patient *data, int& Size)
{
	cout << "\n Palata" << setw(10) << "Name" << setw(15) << "Surname" << setw(20) << "Data of receipt" << setw(15) << "Diagnosis" << setw(15) << "Healing" << setw(20) << "Insurance policy" << setw(20)
		<< "Coust of treatment" <<
		setw(20) << "Date of discharge\n" << "______________________________________________________________________________________________________________________________________________" << endl;

	for (int i = 0; i < Size; i++)
	{
		cout << "  [" << data[i].palata << "]" << setw(10) << data[i].name << setw(15) << data[i].surname << setw(18) << data[i].day_of_receipt << "." << data[i].months_of_receipt << "." << data[i].year_of_receipt << setw(15) << data[i].diagnosis << setw(15)
			<< data[i].healing <<
			setw(20) << data[i].insurance_policy << setw(15) << data[i].cost_of_treatment << setw(15) << data[i].day_of_discharge << "." << data[i].months_of_discharge << "." << data[i].year_of_discharge << endl;
	}
}

void Sort_diagnosis(Patient *data, int& Size)
{
	Patient temp;

	for (int i = 0; i < Size; i++) {
		for (int j = 0; j < Size - i - 1; j++) {

			if (_strcmpi(data[j].diagnosis.c_str(), data[j + 1].diagnosis.c_str()) > 0)
			{
				temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < Size; i++)
	{
		cout << "\n______________________________" << endl;
		cout << "\n ID [ " << data[i].id << " ]" << endl;
		data[i].ShowData();
		cout << "\n=============================" << endl;
	}

}
