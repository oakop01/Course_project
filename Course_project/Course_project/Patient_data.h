#pragma once

#include<iostream>
#include<string>

using namespace std;

struct Patient 
{
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

	void ShowData();

};