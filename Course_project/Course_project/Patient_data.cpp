#include"Patient_data.h"
#include<iostream>

using namespace std;

void Patient::ShowData()
{
	
	cout << " Name: " << name << endl;
	cout << " Surname: " << surname << endl;
	cout << " Data of receipt: " << day_of_receipt << "." << months_of_receipt << "." << year_of_receipt << endl;
	cout << " Diagnosis: " << diagnosis << endl;
	cout << " Healing: " << healing << endl;
	cout << " Palata: " << palata << endl;
	cout << " Insurance policy: " << insurance_policy << endl;
	cout << " Coust of treatment: " << cost_of_treatment << " $" << endl;
	cout << " Date of discharge: " << day_of_discharge << "." << months_of_discharge << "." << year_of_discharge << endl;
}

