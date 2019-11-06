#include<iostream>
#include<string>
#include<fstream>

using namespace std;
int Size = 2;

struct Patient {

	string name;
	string surname;
	string date_of_receipt;
	string diagnosis;
	string healing;
	int palata;
	int insurance_policy;
	int cost_of_treatment;
	string date_of_discharge;
	int year_of_discharge;

	void ShowData()
	{
		cout << " Name: " << name << endl;
		cout << " Surname: " << surname << endl;
		cout << " Data of receipt: " << date_of_receipt << endl;
		cout << " Diagnosis: " << diagnosis << endl;
		cout << " Healing: " << healing << endl;
		cout << " Palata: " << palata << endl;
		cout << " Insurance policy: " << insurance_policy << endl;
		cout << " Coust of treatment: " << cost_of_treatment << " $" << endl;
		cout << " Date of discharge: " << date_of_discharge << "." << year_of_discharge << endl;
	}


};

struct Doctor {

	string name;
	string surname;
	int palata;

	void ShowData()
	{
		cout << " Name: " << name << endl;
		cout << " Surname: " << surname << endl;
		cout << " Palata # [ " << palata <<" ]"<< endl;
	}
};

void Fill_Data(Patient*& data, string path)
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
			data[i].name = tmp;

			readFile.getline(tmp, 255);
			data[i].surname = tmp;

			readFile.getline(tmp, 255);
			data[i].date_of_receipt = tmp;

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
			data[i].date_of_discharge = tmp;

			readFile.getline(tmp, 255);
			data[i].year_of_discharge = atoi(tmp);

		}
	}
	readFile.close();
	cout << "Data fill!!!" << endl;
}

void Fill_Doc(Doctor*& doc, string path2)
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

void Save_Data(string path, Patient*& data)
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
			writeFile << data[i].name << endl;
			writeFile << data[i].surname << endl;
			writeFile << data[i].date_of_receipt << endl;
			writeFile << data[i].diagnosis << endl;
			writeFile << data[i].healing << endl;
			writeFile << data[i].palata << endl;
			writeFile << data[i].insurance_policy << endl;
			writeFile << data[i].cost_of_treatment << endl;
		}
	}
	writeFile.close();
	cout << endl;
}

void Print_Data(Patient* data)
{
	for (int i = 0; i < Size; i++){
		cout << "Id [ " << i + 1 << " ]" << endl;
		data[i].ShowData();
		cout << "\n__________________________________" << endl;
	}
}

void Print_Doc(Doctor* doc)
{
	for (int i = 0; i < 3; i++){
		doc[i].ShowData();
		cout << "\n__________________________________" << endl;
	}
}

void Data_overwrite(Patient & data1, Patient data2) //перезапис данних
{
	data1.name = data2.name;
	data1.surname = data2.surname;
	data1.date_of_receipt = data2.date_of_receipt;
	data1.diagnosis = data2.diagnosis;
	data1.healing = data2.healing;
	data1.palata = data2.palata;
	data1.insurance_policy = data2.insurance_policy;
	data1.cost_of_treatment = data2.cost_of_treatment;
	data1.date_of_discharge = data2.date_of_discharge;
	data1.year_of_discharge = data2.year_of_discharge;
}

void Add_Patient(Patient*& data, Patient data2)
{
	Patient *newData = new Patient[Size+1];

	for (int i = 0; i < Size; i++)
	{
		Data_overwrite(newData[i], data[i]);
	}
	Data_overwrite(newData[Size], data2);
	
	delete[] data;
	data = newData;
	Size++;

}

void Delete_data(Patient*& data, int id)
{
	Patient* newData = new Patient[Size];

	for (int i = 0; i < id; i++)
	{
		Data_overwrite(newData[i], data[i]);
	}
	for (int i = id + 1; i < Size; i++)
	{
		Data_overwrite(newData[i-1], data[i]);
	}
	delete[] data;
	data = newData;
	Size--;

}

//void Edit_data(Patient*& data, int id, string path)
//{
//	char input;
//	string name;
//	Patient data3;
//	cout << "\tPatient ID >>> " << id << endl;
//		
//		cout << "To edit name                >>> enter [n]" << endl;
//		cout << "To edit surname             >>> enter [s]" << endl;
//		cout << "To edit Data of receipt     >>> enter [d]" << endl;
//		cout << "to edit Diagnosis:          >>> enter [i]" << endl;
//		cout << "To edit Healing:            >>> enter [h]" << endl;
//		cout << "To edit Palata:             >>> enter [p]" << endl;
//		cout << "To edit Insurance policy:   >>> enter [o]" << endl;
//		cout << "To edit Coust of treatment: >>> enter [c]" << endl;
//		cout << "Enter choice: ";
//		cin >> input;
//
//		
//
//		if (input == 'n')
//		{
//			cout << " Please enter the patient's name: ";
//
//			cin >> data3.name;
//			
//			//data[id].name = data3.name;
//			
//					
//		}
//		else if (input == 's')
//		{
//			cout << " Please enter the patient's surname: ";
//			
//			
//
//		}
//		
//		
//		Save_Data(path, data);
//}
//
//
//
//
//



int main()
{
	Patient *data;
	Doctor *doc;
	Patient data2;
	string path = "data.txt";
	string path2 = "doc.txt";
	Fill_Data(data, path);
	Fill_Doc(doc, path2);
	
	int choise = 0;
	bool exit = false;
	int id = 0;
	
	while (!exit) {
		
		cout << " ____________" << endl;
		cout << " ____Menu____" << endl;
		cout << " ____________\n" << endl;

		cout << "\t 1. Add patient.\n" << endl;
		cout << "\t 2. Delete patient.\n" << endl;
		cout << "\t 3. All patient.\n" << endl;
		cout << "\t 4. Save data.\n" << endl;
		cout << "\t 5. Doc data.\n" << endl;
		cout << "\t 0. Exit.\n" << endl;

		
		cout << "Enter your choise:";
		cin >> choise;
		
	switch(choise) {

		case 1: 
			
			cout << " Add new patient: " << endl;
				cout << " Name: ";
				cin >> data2.name;
				
				cout << " Surname: ";
				cin >> data2.surname;
				
				cout << " Data of receipt: ";
				cin >> data2.date_of_receipt;
				
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

				cout << " Date of discharge (day.months): ";
				cin >> data2.date_of_discharge;

				cout << " Year of discharge: ";
				cin >> data2.year_of_discharge;

			Add_Patient(data, data2);
			break;

		case 2:
			cout << "Enter id patient: ";
			cin >> id;
			Delete_data(data, id);
			Print_Data(data);
			break;

		case 3:
			cout << "\n Database\n__________________________________" << endl;
			Print_Data(data);
			break;

		case 4:
			cout << "Saving data...";
			Save_Data(path, data);
			break;

		case 5:
			cout << "\n__________________________________" << endl;
			Print_Doc(doc);
			break;
	
		case 0:
			exit = true;
			break;
		}
		
	}
	cout << "_______________________________" << endl;
	

	system("pause");
	return 0;
}