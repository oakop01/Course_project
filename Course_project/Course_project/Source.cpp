#include<iostream>
#include<string>

using namespace std;

struct Patient {

	string name;
	string surname;
	string diagnosis;
	string healing;
	int palata;
	string date_of_receipt;
	int insurance_policy;
	double cost_of_treatment;
	int SIZE = 0;

	void AddPatient()
	{
		Patient *new_patient = new Patient[SIZE + 1];

		cout << " Enter name: ";
		cin >> name;
		cout << " Enter surname: ";
		cin >> surname;
		cout << " Enter diagnosis: ";
		cin >> diagnosis;
		cout << " Enter palata: ";
		cin >> palata;
		cout << " Enter data of receipt: ";
		cin >> date_of_receipt;
		cout << " Enter insurance policy: ";
		cin >> insurance_policy;
		cout << " Enter healing: ";
		cin >> healing;
		cout << " Enter coust of treatment: ";
		cin >> cost_of_treatment;

	}

	void ShowPatient()
	{
		cout << " Name: " << name << endl;
		cout << " Surname: " << surname << endl;
		cout << " Diagnosis: " << diagnosis << endl;
		cout << " Palata: " << palata << endl;
		cout << " Data of receipt: " << date_of_receipt << endl;
		cout << " Insurance policy: " << insurance_policy << endl;
		cout << " Healing: " << healing << endl;
		cout << " Coust of treatment: " << cost_of_treatment <<" $"<< endl;
	}

};

int main()
{
	

	Patient* patient;
	


	system("pause");
	return 0;

}