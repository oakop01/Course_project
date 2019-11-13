#pragma once

#include<iostream>
#include<string>
#include<fstream>
#include"Doctor_data.h"
#include"Patient_data.h"
#include"Menu.h"
using namespace std;


void SetColor(int text, int background);

void Fill_Data(Patient*& data, string path, int& Size);

void Fill_Doc(Doctor*& doc, string path2, int& Size);

void Data_overwrite(Patient & data1, Patient data2);

void Add_Patient(Patient*& data, Patient data2, int& Size);

void Delete_data(Patient*& data, int& Size);

void Coust_treatment(Patient *data, int& Size);

void Delete_patient_discharge_last_year(Patient *&data, int& Size);

void List_written_out(Patient *data, int& Size);

void Sample(Patient *data, int& Size);

void Save_Data(string path, Patient*& data, int& Size);

void Print_Data(Patient* data, int& Size);

void Print_Doc(Doctor* doc, int& Size);

void Serch_data(Patient* data, int& Size);

void Serch_in_palata(Patient*& data, Doctor*& doc, int& Size);

void Table_patient(Patient *data, int& Size);

void Sort_diagnosis(Patient *data, int& Size);

void Account_for_treatment(Patient *data, int& Size);

void Add_new_patuent(Patient *&data, int &Size);

void Authorization();

void Exit(string path, Patient*& data, int& Size, Menu &menu);
