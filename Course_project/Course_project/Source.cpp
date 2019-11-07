#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;
int Size = 2;

struct Patient {

	int id;
	string name;
	string surname;
	string diagnosis;
	string healing;
	int day_of_receipt;
	int months_of_receipt;
	int year_of_receipt;
	int palata;
	int insurance_policy;
	int cost_of_treatment;
	int day_of_discharge;
	int months_of_discharge;
	int year_of_discharge;

	void ShowData()
	{
		cout << " ID patient: " << id << endl;
		cout << " Name: " << name << endl;
		cout << " Surname: " << surname << endl;
		cout << " Data of receipt: " << day_of_receipt<<"."<< months_of_receipt <<"."<< year_of_receipt << endl;
		cout << " Diagnosis: " << diagnosis << endl;
		cout << " Healing: " << healing << endl;
		cout << " Palata: " << palata << endl;
		cout << " Insurance policy: " << insurance_policy << endl;
		cout << " Coust of treatment: " << cost_of_treatment << " $" << endl;
		cout << " Date of discharge: " << day_of_discharge<<"."<<months_of_discharge << "." << year_of_discharge << endl;
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
		cout << " Palata # [ " << palata << " ]" << endl;
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

void Print_Data(Patient* data)
{
	for (int i = 0; i < Size; i++) {
		cout << "Id [ " << data[i].id << " ]" << endl;
		data[i].ShowData();
		cout << "\n__________________________________" << endl;
	}
}

void Print_Doc(Doctor* doc)
{
	for (int i = 0; i < 3; i++) {
		doc[i].ShowData();
		cout << "\n__________________________________" << endl;
	}
}

void Data_overwrite(Patient & data1, Patient data2) //ïåðåçàïèñ äàííèõ
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

void Add_Patient(Patient*& data, Patient data2)
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

void Delete_data(Patient*& data, int id)
{
	Patient* newData = new Patient[Size];

	for (int i = 0; i < id; i++)
	{
		Data_overwrite(newData[i], data[i]);
	}
	for (int i = id + 1; i < Size; i++)
	{
		Data_overwrite(newData[i - 1], data[i]);
	}
	delete[] data;
	data = newData;
	Size--;

}

void Serch_data(Patient* data, int id)
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
		cout << " No serch patient with this >>> " << id << " ID." << endl;
	}
}

void Serch_in_palata(Patient *data, int palata, Doctor *doc)
{
	bool exit = false;
	int index=0;

	for (int i = 0; i < Size; i++)
	{
		if (data[i].palata == palata)
		{
			index++;
			exit = true;
			cout << "\n Doctor in palata: " << doc[i].name << " " << doc[i].surname << endl;
			cout <<" [ "<< index << " ] patient in palata\n\n";
		

			cout << "Name" << setw(20) << "Diagnosis" << setw(10) << "Healing" << setw(20) << "\n"<<"__________________________________________\n\n";

			for (int i = 0; i < index; i++)
			{
				cout << data[i].name << " " << data[i].surname << setw(5) <<"|"<< data[i].diagnosis << setw(15) << data[i].healing << endl;
			}

			
		}
	}

	if (!exit)
	{
		cout << "No serch palata #" << palata << endl;
	}
}

void Table_patient(Patient *data)
{
	cout << "Palata" << setw(10) << "Name" << setw(15) << "Surname" << setw(20) << "Data of receipt" << setw(15) << "Diagnosis" << setw(15) << "Healing" << setw(20) << "Insurance policy" << setw(20)
		<< "Coust of treatment" <<
		setw(20) << "Date of discharge\n" << "______________________________________________________________________________________________________________________________________________"<<endl;

	for (int i = 0; i < Size; i++)
	{
		cout <<"  ["<< data[i].palata<<"]" << setw(10) << data[i].name << setw(15) << data[i].surname << setw(18) << data[i].day_of_receipt<<"."<<data[i].months_of_receipt<<"."<<data[i].year_of_receipt<<setw(15) << data[i].diagnosis << setw(15)
			<< data[i].healing <<
			setw(20) << data[i].insurance_policy << setw(15) << data[i].cost_of_treatment << setw(15) << data[i].day_of_discharge<<"."<<data[i].months_of_discharge << "." << data[i].year_of_discharge << endl;
	}
}

void Sort_diagnosis(Patient *data)
{
	Patient temp;

	for (int i = 0; i < Size; i++) {
		for (int j = 0; j < Size - i - 1; j++) {

			if (_strcmpi(data[j].diagnosis.c_str(), data[j + 1].diagnosis.c_str()) > 0)
			{
				temp = data[j];
				data[j] = data[j + 1];
				data[j+1]=temp;
			}
		}
	}

	for (int i = 0; i < Size; i++)
	{
		cout << "ID [ " << data[i].id << " ]" << endl;
		data[i].ShowData();
		cout << "______________________________" << endl;
	}
	
}

void Sample(Patient *data)
{
	int day;
	string diagnosis;
	int tmp = 0;

	cout << " Enter day: ";
	cin >> day;
	cout << " Enter diagnosis: ";
	cin >> diagnosis;

	for (int i = 0; i < Size; i++)
	{
		if (data[i].day_of_receipt == day && data[i].diagnosis == diagnosis)
		{
			tmp++;
			cout << " Name    " << data[i].name << " " << data[i].surname << endl;
			cout << " Palata [ " << data[i].palata <<" ]"<< endl;
		}
	}

	if (tmp == 0)
	{
		cout << "No patient in this day and diagnosis" << endl;
	}
}

void List_written_out(Patient *data)
{
	int day=0;
	int tmp = 0;
	cout << "Enter day: ";
	cin >> day;

	for (int i = 0; i < Size; i++)
	{
		if (data[i].day_of_discharge == day)
		{
			tmp++;
			cout << " Name > " << data[i].name << " " << data[i].surname << endl;
		}
	}

	if (tmp == 0)
	{
		cout << "No patient to discharge" << endl;
	}

}

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
	int palata = 0;


	while (!exit) {

		cout << " ____________" << endl;
		cout << " ____Menu____" << endl;
		cout << " ____________\n" << endl;

		cout << "\t 1. Add patient.\n" << endl;
		cout << "\t 2. Delete patient.\n" << endl;
		cout << "\t 3. All patient.\n" << endl;
		cout << "\t 4. Save data.\n" << endl;
		cout << "\t 5. Doc data.\n" << endl;
		cout << "\t 6. Serch data.\n" << endl;
		cout << "\t 7. Patient in palata.\n" << endl;
		cout << "\t 8. Table patient.\n" << endl;
		cout << "\t 9. Sort by diagnosis.\n" << endl;
		cout << "\t 10. Sample.\n" << endl;
		cout << "\t 11. List written out.\n" << endl;
		cout << "\t 0. Exit.\n" << endl;


		cout << "Enter your choise:";
		cin >> choise;

		switch (choise) {

		case 1:

			cout << " Add new patient: " << endl;
			cout << " ID: ";
			cin >> data2.id;

			cout << " Name: ";
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
		case 6:
			cout << "\n____________________________________" << endl;
			cout << "Enter id patient to serch:";
			cin >> id;
			Serch_data(data, id);
			break;
		case 7:
			cout << "\n_____________________________________" << endl;
			cout << "Enter # palata: ";
			cin >> palata;
			Serch_in_palata(data, palata, doc);
			break;
		case 8:
			Table_patient(data);
			break;
		case 9:
			Sort_diagnosis(data);
			break;
		case 10:
			Sample(data);
			break;
		case 11:
			List_written_out(data);
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
