#include<iostream>
#include<conio.h>
#include<Windows.h>
#include"Menu.h"
#include"working_with_data.h"
#include"Doctor_data.h"
#include"Patient_data.h"

using namespace std;

void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void Menu::HomeScr()
{
	system("cls");
	cout << endl;
	SetColor(10, 0);
	cout << " Course Project \t \t \t \t\t \t \t \t\t \t \t \t Final Project" << endl;
	cout << " Subject area - hospital. \t \t \t \t\t \t \t \t \t \t \t Anton Kozyar" << endl;
	SetColor(15, 0);
	cout << "\n\n\n\n";
	cout << "\n \t \t \t \t \t [~]  All patient                            [~]";
	cout << "\n \t \t \t \t \t [~]  Add patient                            [~]";
	cout << "\n \t \t \t \t \t [~]  Delete patient                         [~]";
	cout << "\n \t \t \t \t \t [~]  Sort by diagnosis                      [~]";
	cout << "\n \t \t \t \t \t [~]  Serch patient                          [~]";
	cout << "\n \t \t \t \t \t [~]  Select patients by day and diagnosis   [~]";
	cout << "\n \t \t \t \t \t [~]  List written out                       [~]";
	cout << "\n \t \t \t \t \t [~]  Number of patients in wards            [~]";
	cout << "\n \t \t \t \t \t [~]  Cost treatment                         [~]";
	cout << "\n \t \t \t \t \t [~]  Delete patient discharge last year     [~]";
	cout << "\n \t \t \t \t \t [~]  Table of patients                      [~]";
	cout << "\n \t \t \t \t \t [~]  Check for treatment                    [~]";	
	cout << "\n \t \t \t \t \t [~]  Doc data                               [~]";
	cout << "\n \t \t \t \t \t [~]  Save data                              [~]";	
	cout << "\n \t \t \t \t \t [~]  Exit                                   [~]";
}
void Menu::HomeScr1()
{
	system("cls");
	cout << endl;
	SetColor(10, 0);
	cout << " Course Project \t \t \t \t\t \t \t \t\t \t \t \t Final Project" << endl;
	cout << " Subject area - hospital. \t \t \t \t\t \t \t \t \t \t \t Anton Kozyar" << endl;
	SetColor(15, 0);
	cout << "\n\n\n\n";
	SetColor(10, 0);
	cout << "\n \t \t \t \t     >>>      All patient                                <<<";
	SetColor(15, 0);
	cout << "\n \t \t \t \t \t [~]  Add patient                            [~]";
	cout << "\n \t \t \t \t \t [~]  Delete patient                         [~]";
	cout << "\n \t \t \t \t \t [~]  Sort by diagnosis                      [~]";
	cout << "\n \t \t \t \t \t [~]  Serch patient                          [~]";
	cout << "\n \t \t \t \t \t [~]  Select patients by day and diagnosis   [~]";
	cout << "\n \t \t \t \t \t [~]  List written out                       [~]";
	cout << "\n \t \t \t \t \t [~]  Number of patients in wards            [~]";
	cout << "\n \t \t \t \t \t [~]  Cost treatment                         [~]";
	cout << "\n \t \t \t \t \t [~]  Delete patient discharge last year     [~]";
	cout << "\n \t \t \t \t \t [~]  Table of patients                      [~]";
	cout << "\n \t \t \t \t \t [~]  Check for treatment                    [~]";
	cout << "\n \t \t \t \t \t [~]  Doc data                               [~]";
	cout << "\n \t \t \t \t \t [~]  Save data                              [~]";
	cout << "\n \t \t \t \t \t [~]  Exit                                   [~]";
}
void Menu::HomeScr2()
{
	system("cls");
	cout << endl;
	SetColor(10, 0);
	cout << " Course Project \t \t \t \t\t \t \t \t\t \t \t \t Final Project" << endl;
	cout << " Subject area - hospital. \t \t \t \t\t \t \t \t \t \t \t Anton Kozyar" << endl;
	SetColor(15, 0);
	cout << "\n\n\n\n";
	cout << "\n \t \t \t \t \t [~]  All patient                            [~]";
	SetColor(10, 0);
	cout << "\n \t \t \t \t     >>>      Add patient                                <<<";
	SetColor(15, 0);
	cout << "\n \t \t \t \t \t [~]  Delete patient                         [~]";
	cout << "\n \t \t \t \t \t [~]  Sort by diagnosis                      [~]";
	cout << "\n \t \t \t \t \t [~]  Serch patient                          [~]";
	cout << "\n \t \t \t \t \t [~]  Select patients by day and diagnosis   [~]";
	cout << "\n \t \t \t \t \t [~]  List written out                       [~]";
	cout << "\n \t \t \t \t \t [~]  Number of patients in wards            [~]";
	cout << "\n \t \t \t \t \t [~]  Cost treatment                         [~]";
	cout << "\n \t \t \t \t \t [~]  Delete patient discharge last year     [~]";
	cout << "\n \t \t \t \t \t [~]  Table of patients                      [~]";
	cout << "\n \t \t \t \t \t [~]  Check for treatment                    [~]";
	cout << "\n \t \t \t \t \t [~]  Doc data                               [~]";
	cout << "\n \t \t \t \t \t [~]  Save data                              [~]";
	cout << "\n \t \t \t \t \t [~]  Exit                                   [~]";
}
void Menu::HomeScr3()
{
	system("cls");
	cout << endl;
	SetColor(10, 0);
	cout << " Course Project \t \t \t \t\t \t \t \t\t \t \t \t Final Project" << endl;
	cout << " Subject area - hospital. \t \t \t \t\t \t \t \t \t \t \t Anton Kozyar" << endl;
	SetColor(15, 0);
	cout << "\n\n\n\n";
	cout << "\n \t \t \t \t \t [~]  All patient                            [~]";
	cout << "\n \t \t \t \t \t [~]  Add patient                            [~]";
	SetColor(10, 0);
	cout << "\n \t \t \t \t     >>>      Delete patient                             <<<";
	SetColor(15, 0);
	cout << "\n \t \t \t \t \t [~]  Sort by diagnosis                      [~]";
	cout << "\n \t \t \t \t \t [~]  Serch patient                          [~]";
	cout << "\n \t \t \t \t \t [~]  Select patients by day and diagnosis   [~]";
	cout << "\n \t \t \t \t \t [~]  List written out                       [~]";
	cout << "\n \t \t \t \t \t [~]  Number of patients in wards            [~]";
	cout << "\n \t \t \t \t \t [~]  Cost treatment                         [~]";
	cout << "\n \t \t \t \t \t [~]  Delete patient discharge last year     [~]";
	cout << "\n \t \t \t \t \t [~]  Table of patients                      [~]";
	cout << "\n \t \t \t \t \t [~]  Check for treatment                    [~]";
	cout << "\n \t \t \t \t \t [~]  Doc data                               [~]";
	cout << "\n \t \t \t \t \t [~]  Save data                              [~]";
	cout << "\n \t \t \t \t \t [~]  Exit                                   [~]";
}
void Menu::HomeScr4()
{
	system("cls");
	cout << endl;
	SetColor(10, 0);
	cout << " Course Project \t \t \t \t\t \t \t \t\t \t \t \t Final Project" << endl;
	cout << " Subject area - hospital. \t \t \t \t\t \t \t \t \t \t \t Anton Kozyar" << endl;
	SetColor(15, 0);
	cout << "\n\n\n\n";
	cout << "\n \t \t \t \t \t [~]  All patient                            [~]";
	cout << "\n \t \t \t \t \t [~]  Add patient                            [~]";
	cout << "\n \t \t \t \t \t [~]  Delete patient                         [~]";
	SetColor(10, 0);
	cout << "\n \t \t \t \t     >>>      Sort by diagnosis                          <<<";
	SetColor(15, 0);
	cout << "\n \t \t \t \t \t [~]  Serch patient                          [~]";
	cout << "\n \t \t \t \t \t [~]  Select patients by day and diagnosis   [~]";
	cout << "\n \t \t \t \t \t [~]  List written out                       [~]";
	cout << "\n \t \t \t \t \t [~]  Number of patients in wards            [~]";
	cout << "\n \t \t \t \t \t [~]  Cost treatment                         [~]";
	cout << "\n \t \t \t \t \t [~]  Delete patient discharge last year     [~]";
	cout << "\n \t \t \t \t \t [~]  Table of patients                      [~]";
	cout << "\n \t \t \t \t \t [~]  Check for treatment                    [~]";
	cout << "\n \t \t \t \t \t [~]  Doc data                               [~]";
	cout << "\n \t \t \t \t \t [~]  Save data                              [~]";
	cout << "\n \t \t \t \t \t [~]  Exit                                   [~]";
}
void Menu::HomeScr5()
{
	system("cls");
	cout << endl;
	SetColor(10, 0);
	cout << " Course Project \t \t \t \t\t \t \t \t\t \t \t \t Final Project" << endl;
	cout << " Subject area - hospital. \t \t \t \t\t \t \t \t \t \t \t Anton Kozyar" << endl;
	SetColor(15, 0);
	cout << "\n\n\n\n";
	cout << "\n \t \t \t \t \t [~]  All patient                            [~]";
	cout << "\n \t \t \t \t \t [~]  Add patient                            [~]";
	cout << "\n \t \t \t \t \t [~]  Delete patient                         [~]";
	cout << "\n \t \t \t \t \t [~]  Sort by diagnosis                      [~]";
	SetColor(10, 0);
	cout << "\n \t \t \t \t     >>>      Serch patient                              <<<";
	SetColor(15, 0);
	cout << "\n \t \t \t \t \t [~]  Select patients by day and diagnosis   [~]";
	cout << "\n \t \t \t \t \t [~]  List written out                       [~]";
	cout << "\n \t \t \t \t \t [~]  Number of patients in wards            [~]";
	cout << "\n \t \t \t \t \t [~]  Cost treatment                         [~]";
	cout << "\n \t \t \t \t \t [~]  Delete patient discharge last year     [~]";
	cout << "\n \t \t \t \t \t [~]  Table of patients                      [~]";
	cout << "\n \t \t \t \t \t [~]  Check for treatment                    [~]";
	cout << "\n \t \t \t \t \t [~]  Doc data                               [~]";
	cout << "\n \t \t \t \t \t [~]  Save data                              [~]";
	cout << "\n \t \t \t \t \t [~]  Exit                                   [~]";
}
void Menu::HomeScr6()
{
	system("cls");
	cout << endl;
	SetColor(10, 0);
	cout << " Course Project \t \t \t \t\t \t \t \t\t \t \t \t Final Project" << endl;
	cout << " Subject area - hospital. \t \t \t \t\t \t \t \t \t \t \t Anton Kozyar" << endl;
	SetColor(15, 0);
	cout << "\n\n\n\n";
	cout << "\n \t \t \t \t \t [~]  All patient                            [~]";
	cout << "\n \t \t \t \t \t [~]  Add patient                            [~]";
	cout << "\n \t \t \t \t \t [~]  Delete patient                         [~]";
	cout << "\n \t \t \t \t \t [~]  Sort by diagnosis                      [~]";
	cout << "\n \t \t \t \t \t [~]  Serch patient                          [~]";
	SetColor(10, 0);
	cout << "\n \t \t \t \t     >>>      Select patients by day and diagnosis       <<<";
	SetColor(15, 0);
	cout << "\n \t \t \t \t \t [~]  List written out                       [~]";
	cout << "\n \t \t \t \t \t [~]  Number of patients in wards            [~]";
	cout << "\n \t \t \t \t \t [~]  Cost treatment                         [~]";
	cout << "\n \t \t \t \t \t [~]  Delete patient discharge last year     [~]";
	cout << "\n \t \t \t \t \t [~]  Table of patients                      [~]";
	cout << "\n \t \t \t \t \t [~]  Check for treatment                    [~]";
	cout << "\n \t \t \t \t \t [~]  Doc data                               [~]";
	cout << "\n \t \t \t \t \t [~]  Save data                              [~]";
	cout << "\n \t \t \t \t \t [~]  Exit                                   [~]";
}
void Menu::HomeScr7()
{
	system("cls");
	cout << endl;
	SetColor(10, 0);
	cout << " Course Project \t \t \t \t\t \t \t \t\t \t \t \t Final Project" << endl;
	cout << " Subject area - hospital. \t \t \t \t\t \t \t \t \t \t \t Anton Kozyar" << endl;
	SetColor(15, 0);
	cout << "\n\n\n\n";
	cout << "\n \t \t \t \t \t [~]  All patient                            [~]";
	cout << "\n \t \t \t \t \t [~]  Add patient                            [~]";
	cout << "\n \t \t \t \t \t [~]  Delete patient                         [~]";
	cout << "\n \t \t \t \t \t [~]  Sort by diagnosis                      [~]";
	cout << "\n \t \t \t \t \t [~]  Serch patient                          [~]";
	cout << "\n \t \t \t \t \t [~]  Select patients by day and diagnosis   [~]";
	SetColor(10, 0);
	cout << "\n \t \t \t \t     >>>      List written out                           <<<";
	SetColor(15, 0);
	cout << "\n \t \t \t \t \t [~]  Number of patients in wards            [~]";
	cout << "\n \t \t \t \t \t [~]  Cost treatment                         [~]";
	cout << "\n \t \t \t \t \t [~]  Delete patient discharge last year     [~]";
	cout << "\n \t \t \t \t \t [~]  Table of patients                      [~]";
	cout << "\n \t \t \t \t \t [~]  Check for treatment                    [~]";
	cout << "\n \t \t \t \t \t [~]  Doc data                               [~]";
	cout << "\n \t \t \t \t \t [~]  Save data                              [~]";
	cout << "\n \t \t \t \t \t [~]  Exit                                   [~]";
}
void Menu::HomeScr8()
{
	system("cls");
	cout << endl;
	SetColor(10, 0);
	cout << " Course Project \t \t \t \t\t \t \t \t\t \t \t \t Final Project" << endl;
	cout << " Subject area - hospital. \t \t \t \t\t \t \t \t \t \t \t Anton Kozyar" << endl;
	SetColor(15, 0);
	cout << "\n\n\n\n";
	cout << "\n \t \t \t \t \t [~]  All patient                            [~]";
	cout << "\n \t \t \t \t \t [~]  Add patient                            [~]";
	cout << "\n \t \t \t \t \t [~]  Delete patient                         [~]";
	cout << "\n \t \t \t \t \t [~]  Sort by diagnosis                      [~]";
	cout << "\n \t \t \t \t \t [~]  Serch patient                          [~]";
	cout << "\n \t \t \t \t \t [~]  Select patients by day and diagnosis   [~]";
	cout << "\n \t \t \t \t \t [~]  List written out                       [~]";
	SetColor(10, 0);
	cout << "\n \t \t \t \t     >>>      Number of patients in wards                <<<";
	SetColor(15, 0);
	cout << "\n \t \t \t \t \t [~]  Cost treatment                         [~]";
	cout << "\n \t \t \t \t \t [~]  Delete patient discharge last year     [~]";
	cout << "\n \t \t \t \t \t [~]  Table of patients                      [~]";
	cout << "\n \t \t \t \t \t [~]  Check for treatment                    [~]";
	cout << "\n \t \t \t \t \t [~]  Doc data                               [~]";
	cout << "\n \t \t \t \t \t [~]  Save data                              [~]";
	cout << "\n \t \t \t \t \t [~]  Exit                                   [~]";
}
void Menu::HomeScr9()
{
	system("cls");
	cout << endl;
	SetColor(10, 0);
	cout << " Course Project \t \t \t \t\t \t \t \t\t \t \t \t Final Project" << endl;
	cout << " Subject area - hospital. \t \t \t \t\t \t \t \t \t \t \t Anton Kozyar" << endl;
	SetColor(15, 0);
	cout << "\n\n\n\n";
	cout << "\n \t \t \t \t \t [~]  All patient                            [~]";
	cout << "\n \t \t \t \t \t [~]  Add patient                            [~]";
	cout << "\n \t \t \t \t \t [~]  Delete patient                         [~]";
	cout << "\n \t \t \t \t \t [~]  Sort by diagnosis                      [~]";
	cout << "\n \t \t \t \t \t [~]  Serch patient                          [~]";
	cout << "\n \t \t \t \t \t [~]  Select patients by day and diagnosis   [~]";
	cout << "\n \t \t \t \t \t [~]  List written out                       [~]";
	cout << "\n \t \t \t \t \t [~]  Number of patients in wards            [~]";
	SetColor(10, 0);
	cout << "\n \t \t \t \t     >>>      Cost treatment                             <<<";
	SetColor(15, 0);
	cout << "\n \t \t \t \t \t [~]  Delete patient discharge last year     [~]";
	cout << "\n \t \t \t \t \t [~]  Table of patients                      [~]";
	cout << "\n \t \t \t \t \t [~]  Check for treatment                    [~]";
	cout << "\n \t \t \t \t \t [~]  Doc data                               [~]";
	cout << "\n \t \t \t \t \t [~]  Save data                              [~]";
	cout << "\n \t \t \t \t \t [~]  Exit                                   [~]";
}
void Menu::HomeScr10()
{
	system("cls");
	cout << endl;
	SetColor(10, 0);
	cout << " Course Project \t \t \t \t\t \t \t \t\t \t \t \t Final Project" << endl;
	cout << " Subject area - hospital. \t \t \t \t\t \t \t \t \t \t \t Anton Kozyar" << endl;
	SetColor(15, 0);
	cout << "\n\n\n\n";
	cout << "\n \t \t \t \t \t [~]  All patient                            [~]";
	cout << "\n \t \t \t \t \t [~]  Add patient                            [~]";
	cout << "\n \t \t \t \t \t [~]  Delete patient                         [~]";
	cout << "\n \t \t \t \t \t [~]  Sort by diagnosis                      [~]";
	cout << "\n \t \t \t \t \t [~]  Serch patient                          [~]";
	cout << "\n \t \t \t \t \t [~]  Select patients by day and diagnosis   [~]";
	cout << "\n \t \t \t \t \t [~]  List written out                       [~]";
	cout << "\n \t \t \t \t \t [~]  Number of patients in wards            [~]";
	cout << "\n \t \t \t \t \t [~]  Cost treatment                         [~]";
	SetColor(10, 0);
	cout << "\n \t \t \t \t     >>>      Delete patient discharge last year         <<<";
	SetColor(15, 0);
	cout << "\n \t \t \t \t \t [~]  Table of patients                      [~]";
	cout << "\n \t \t \t \t \t [~]  Check for treatment                    [~]";
	cout << "\n \t \t \t \t \t [~]  Doc data                               [~]";
	cout << "\n \t \t \t \t \t [~]  Save data                              [~]";
	cout << "\n \t \t \t \t \t [~]  Exit                                   [~]";
}
void Menu::HomeScr11()
{
	system("cls");
	cout << endl;
	SetColor(10, 0);
	cout << " Course Project \t \t \t \t\t \t \t \t\t \t \t \t Final Project" << endl;
	cout << " Subject area - hospital. \t \t \t \t\t \t \t \t \t \t \t Anton Kozyar" << endl;
	SetColor(15, 0);
	cout << "\n\n\n\n";
	cout << "\n \t \t \t \t \t [~]  All patient                            [~]";
	cout << "\n \t \t \t \t \t [~]  Add patient                            [~]";
	cout << "\n \t \t \t \t \t [~]  Delete patient                         [~]";
	cout << "\n \t \t \t \t \t [~]  Sort by diagnosis                      [~]";
	cout << "\n \t \t \t \t \t [~]  Serch patient                          [~]";
	cout << "\n \t \t \t \t \t [~]  Select patients by day and diagnosis   [~]";
	cout << "\n \t \t \t \t \t [~]  List written out                       [~]";
	cout << "\n \t \t \t \t \t [~]  Number of patients in wards            [~]";
	cout << "\n \t \t \t \t \t [~]  Cost treatment                         [~]";
	cout << "\n \t \t \t \t \t [~]  Delete patient discharge last year     [~]";
	SetColor(10, 0);
	cout << "\n \t \t \t \t     >>>      Table of patients                          <<<";
	SetColor(15, 0);
	cout << "\n \t \t \t \t \t [~]  Check for treatment                    [~]";
	cout << "\n \t \t \t \t \t [~]  Doc data                               [~]";
	cout << "\n \t \t \t \t \t [~]  Save data                              [~]";
	cout << "\n \t \t \t \t \t [~]  Exit                                   [~]";
}
void Menu::HomeScr12()
{
	system("cls");
	cout << endl;
	SetColor(10, 0);
	cout << " Course Project \t \t \t \t\t \t \t \t\t \t \t \t Final Project" << endl;
	cout << " Subject area - hospital. \t \t \t \t\t \t \t \t \t \t \t Anton Kozyar" << endl;
	SetColor(15, 0);
	cout << "\n\n\n\n";
	cout << "\n \t \t \t \t \t [~]  All patient                            [~]";
	cout << "\n \t \t \t \t \t [~]  Add patient                            [~]";
	cout << "\n \t \t \t \t \t [~]  Delete patient                         [~]";
	cout << "\n \t \t \t \t \t [~]  Sort by diagnosis                      [~]";
	cout << "\n \t \t \t \t \t [~]  Serch patient                          [~]";
	cout << "\n \t \t \t \t \t [~]  Select patients by day and diagnosis   [~]";
	cout << "\n \t \t \t \t \t [~]  List written out                       [~]";
	cout << "\n \t \t \t \t \t [~]  Number of patients in wards            [~]";
	cout << "\n \t \t \t \t \t [~]  Cost treatment                         [~]";
	cout << "\n \t \t \t \t \t [~]  Delete patient discharge last year     [~]";
	cout << "\n \t \t \t \t \t [~]  Table of patients                      [~]";
	SetColor(10, 0);
	cout << "\n \t \t \t \t     >>>      Check for treatment                        <<<";
	SetColor(15, 0);
	cout << "\n \t \t \t \t \t [~]  Doc data                               [~]";
	cout << "\n \t \t \t \t \t [~]  Save data                              [~]";
	cout << "\n \t \t \t \t \t [~]  Exit                                   [~]";
}
void Menu::HomeScr13()
{
	system("cls");
	cout << endl;
	SetColor(10, 0);
	cout << " Course Project \t \t \t \t\t \t \t \t\t \t \t \t Final Project" << endl;
	cout << " Subject area - hospital. \t \t \t \t\t \t \t \t \t \t \t Anton Kozyar" << endl;
	SetColor(15, 0);
	cout << "\n\n\n\n";
	cout << "\n \t \t \t \t \t [~]  All patient                            [~]";
	cout << "\n \t \t \t \t \t [~]  Add patient                            [~]";
	cout << "\n \t \t \t \t \t [~]  Delete patient                         [~]";
	cout << "\n \t \t \t \t \t [~]  Sort by diagnosis                      [~]";
	cout << "\n \t \t \t \t \t [~]  Serch patient                          [~]";
	cout << "\n \t \t \t \t \t [~]  Select patients by day and diagnosis   [~]";
	cout << "\n \t \t \t \t \t [~]  List written out                       [~]";
	cout << "\n \t \t \t \t \t [~]  Number of patients in wards            [~]";
	cout << "\n \t \t \t \t \t [~]  Cost treatment                         [~]";
	cout << "\n \t \t \t \t \t [~]  Delete patient discharge last year     [~]";
	cout << "\n \t \t \t \t \t [~]  Table of patients                      [~]";
	cout << "\n \t \t \t \t \t [~]  Check for treatment                    [~]";
	SetColor(10, 0);
	cout << "\n \t \t \t \t     >>>      Doc data                                   <<<";
	SetColor(15, 0);
	cout << "\n \t \t \t \t \t [~]  Save data                              [~]";
	cout << "\n \t \t \t \t \t [~]  Exit                                   [~]";
}
void Menu::HomeScr14()
{
	system("cls");
	cout << endl;
	SetColor(10, 0);
	cout << " Course Project \t \t \t \t\t \t \t \t\t \t \t \t Final Project" << endl;
	cout << " Subject area - hospital. \t \t \t \t\t \t \t \t \t \t \t Anton Kozyar" << endl;
	SetColor(15, 0);
	cout << "\n\n\n\n";
	cout << "\n \t \t \t \t \t [~]  All patient                            [~]";
	cout << "\n \t \t \t \t \t [~]  Add patient                            [~]";
	cout << "\n \t \t \t \t \t [~]  Delete patient                         [~]";
	cout << "\n \t \t \t \t \t [~]  Sort by diagnosis                      [~]";
	cout << "\n \t \t \t \t \t [~]  Serch patient                          [~]";
	cout << "\n \t \t \t \t \t [~]  Select patients by day and diagnosis   [~]";
	cout << "\n \t \t \t \t \t [~]  List written out                       [~]";
	cout << "\n \t \t \t \t \t [~]  Number of patients in wards            [~]";
	cout << "\n \t \t \t \t \t [~]  Cost treatment                         [~]";
	cout << "\n \t \t \t \t \t [~]  Delete patient discharge last year     [~]";
	cout << "\n \t \t \t \t \t [~]  Table of patients                      [~]";
	cout << "\n \t \t \t \t \t [~]  Check for treatment                    [~]";
	cout << "\n \t \t \t \t \t [~]  Doc data                               [~]";
	SetColor(10, 0);
	cout << "\n \t \t \t \t     >>>      Save data                                  <<<";
	SetColor(15, 0);
	cout << "\n \t \t \t \t \t [~]  Exit                                   [~]";
}
void Menu::HomeScr15()
{
	system("cls");
	cout << endl;
	SetColor(10, 0);
	cout << " Course Project \t \t \t \t\t \t \t \t\t \t \t \t Final Project" << endl;
	cout << " Subject area - hospital. \t \t \t \t\t \t \t \t \t \t \t Anton Kozyar" << endl;
	SetColor(15, 0);
	cout << "\n\n\n\n";
	cout << "\n \t \t \t \t \t [~]  All patient                            [~]";
	cout << "\n \t \t \t \t \t [~]  Add patient                            [~]";
	cout << "\n \t \t \t \t \t [~]  Delete patient                         [~]";
	cout << "\n \t \t \t \t \t [~]  Sort by diagnosis                      [~]";
	cout << "\n \t \t \t \t \t [~]  Serch patient                          [~]";
	cout << "\n \t \t \t \t \t [~]  Select patients by day and diagnosis   [~]";
	cout << "\n \t \t \t \t \t [~]  List written out                       [~]";
	cout << "\n \t \t \t \t \t [~]  Number of patients in wards            [~]";
	cout << "\n \t \t \t \t \t [~]  Cost treatment                         [~]";
	cout << "\n \t \t \t \t \t [~]  Delete patient discharge last year     [~]";
	cout << "\n \t \t \t \t \t [~]  Table of patients                      [~]";
	cout << "\n \t \t \t \t \t [~]  Check for treatment                    [~]";
	cout << "\n \t \t \t \t \t [~]  Doc data                               [~]";
	cout << "\n \t \t \t \t \t [~]  Save data                              [~]";
	SetColor(10, 0);
	cout << "\n \t \t \t \t     >>>      Exit                                       <<<";
	SetColor(15, 0);
}
int Menu::Home()
{
	char key;
	int flag = 0;
	while (1)
	{
		key = _getch();
		if (key == 0xE0) key = _getch();
		if (key == 'P') // key = Down
		{
			flag++;
			if (flag > 15)  flag = 1;

			switch(flag) {

			case 1:
				HomeScr1();
				break;
			case 2:
				HomeScr2();
				break;
			case 3:
				HomeScr3();
				break;
			case 4:
				HomeScr4();
				break;
			case 5:
				HomeScr5();
				break;
			case 6:
				HomeScr6();
				break;
			case 7:
				HomeScr7();
				break;
			case 8:
				HomeScr8();
				break;
			case 9:
				HomeScr9();
				break;
			case 10:
				HomeScr10();
				break;
			case 11:
				HomeScr11();
				break;
			case 12:
				HomeScr12();
				break;
			case 13:
				HomeScr13();
				break;
			case 14:
				HomeScr14();
				break;
			case 15:
				HomeScr15();
				break;
			}
			
		}
		else if (key == 72) // key = Up
		{
			flag--;
			if (flag < 1)  flag = 15;

			switch (flag) {
				
			case 1:
				HomeScr1();
				break;
			case 2:
				HomeScr2();
				break;
			case 3:
				HomeScr3();
				break;
			case 4:
				HomeScr4();
				break;
			case 5:
				HomeScr5();
				break;
			case 6:
				HomeScr6();
				break;
			case 7:
				HomeScr7();
				break;
			case 8:
				HomeScr8();
				break;
			case 9:
				HomeScr9();
				break;
			case 10:
				HomeScr10();
				break;
			case 11:
				HomeScr11();
				break;
			case 12:
				HomeScr12();
				break;
			case 13:
				HomeScr13();
				break;
			case 14:
				HomeScr14();
				break;
			case 15:
				HomeScr15();
				break;
			}
			
		}
		else if (key == 13 || key == 10) // key = enter
		{
			return flag;
			break;
		}
	}
	return flag;
}
void Menu::endfile()
{	
	char key;
	SetColor(10, 0);
	cout << "\n \n \t \t \t \t \t     Are you sure you want to Exit ?";
	cout << "\n \n \t \t \t \t \t Press 'ENTER' to Exit , 'ESC' to Cancel";
	key = _getch();
	if ((key == 10) || (key == 13))
	{
		system("cls");
		cout << "\n \n \n \n \n \n \n \t \t \t \t \t \t GOOOOD BYE";
		exit(0);
	}
	else if (key == 27) { HomeScr(); }
}

