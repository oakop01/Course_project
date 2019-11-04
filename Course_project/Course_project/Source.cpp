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
	}


};

struct Doctor {

	string name;
	int palata;
};

void Print_Data(Patient* data)
{
	for (int i = 0; i < Size; i++)
	{
		cout << "Index [ " << i + 1 << " ]" << endl;
		data[i].ShowData();
		cout << "\n__________________________________" << endl;
	}

}


void Add_Patient(Patient* data, string path)
{
	Size++;
	//Patient *newData = new Patient[Size+1];
	string name;
	string surname;
	string date_of_receipt;
	string diagnosis;
	string healing;
	int palata;
	int insurance_policy;
	int cost_of_treatment;

	cout << " Add new patient: " << endl;

	ofstream writeFile;
	writeFile.open(path, ofstream::app);
	if (!writeFile.is_open()){ 
		cout << "Can't open file!" << endl;
	}
	else {

		cout << " Name: ";
		getline(cin, name);
		writeFile << name << endl;

		cout << " Surname: ";
		cin >> surname;
		writeFile << surname << endl;

		cout << " Data of receipt: ";
		cin >> date_of_receipt;
		writeFile << date_of_receipt << endl;

		cout << " Diagnosis: ";
		cin >>diagnosis;
		writeFile << diagnosis << endl;

		cout << " Healing: ";
		cin >> healing;
		writeFile << healing << endl;

		cout << " Palata: ";
		cin >> palata;
		writeFile << palata << endl;

		cout << " Insurance policy: ";
		cin >> insurance_policy;
		writeFile << insurance_policy << endl;

		cout << " Coust of treatment: ";
		cin >>cost_of_treatment;
		writeFile << cost_of_treatment << endl;
	}
	writeFile.close();
	
}


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

		}
	}
	readFile.close();
	cout << "Data fill!!!" << endl;
}



int main()
{
	Patient *data;
	string path = "data.txt";

	Fill_Data(data, path);

	
	
	int choise = 0;
	bool exit = false;
	
	cout << "____Menu____" << endl;
	cout << " 1. Add patient. " << endl;
	cout << " 2. Delete patient." << endl;
	cout << " 3. All patient." << endl;
	cout << " 0. Exit." << endl;

	
	while (!exit) {

		cout << "Enter your choise:";
		cin >> choise;

	switch(choise) {

		case 1: 
			Add_Patient(data, path);
			break;
		case 2:
			
			break;
		case 3:
			cout << "\n Database\n__________________________________" << endl;
			Print_Data(data);
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