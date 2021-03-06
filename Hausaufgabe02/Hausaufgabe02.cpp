// Hausaufgabe02.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

void aufgabe1();
void aufgabe2();
void calculatorInt(int operation);
double processCalculator(double &number1, double &number2, int operation);

// Start
int main()
{
	// Aufruf Methode fuer Aufgabe 1
	//aufgabe1();

	// Aufruf Methode fuer Aufgabe 2
	aufgabe2();

}

// Loesung von Aufgabe 1
void aufgabe1() 
{
	int option = -1;

	// Wiederholung bis Eingabe == 0
	do 
	{
		cout << "<1> Addition\n<2> Subtraktion\n<3> Multiplikation\n<4> Division\n<0> Beenden" << endl;
		cin >> option;

		// Korrekte Eingabe: Aufruf der Calculator-Funtkion 
		if (option >= 1 && option <= 4){
			calculatorInt(option);

		// Beenden: (Schleife wird anschließend verlassen)
		} else if (option == 0) {
			cout << "Programmteil beendet.\n######################################" << endl;

		// Fehlerhafte Eingabe:
		} else {
			cout << "Fehlerhafte Eingabe. Bitte Wählen Sie eine der folgenden Optionen:" << endl;
		}

	} while (option != 0);
}

void calculatorInt(int operation)
{
	int number1, number2;

	cout << "Bitte 2 Ganzzahlen eingeben:" << endl;
	cin >> number1 >> number2;

	switch (operation)
	{
	case 1: 
		cout << number1 << " + " << number2 << " = " << number1 + number2 << endl;
		break;
	case 2:
		cout << number1 << " - " << number2 << " = " << number1 - number2 << endl;
		break;
	case 3:
		cout << number1 << " * " << number2 << " = " << number1 * number2 << endl;
		break;
	case 4: 
		cout << number1 << " / " << number2 << " = " << number1 / number2 << endl;
		break;
	}

	cout << "######################################" << endl;
}

void aufgabe2()
{

	double number1, number2 = 0.0;
	int operation = 0;
	int operationPosition = 0;
	string sOperator;
	string str;

	cout << "Eingabe:" << endl;
	getline(cin, str);
	str.erase(std::remove(str.begin(), str.end(), ' '), str.end());

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '+') {
			sOperator = "+";
			operation = 1;
			operationPosition = i;
		}
		else if (str[i] == '-') {
			sOperator = "-";
			operation = 2;
			operationPosition = i;
		}
		else if (str[i] == '*') {
			sOperator = "*";
			operation = 3;
			operationPosition = i;
		}
		else if (str[i] == '/') {
			sOperator = "/";
			operation = 4;
			operationPosition = i;
		}
		else if (str[i] == '%') {
			sOperator = "%";
			operation = 5;
			operationPosition = i;
		}
	}

	if (operation > 0)
	{
		number1 = stod(str.substr(0, operationPosition - 1));
		number2 = stod(str.substr(operationPosition + 1, str.length() - 1));

		cout << number1 << " " << sOperator << " " << number2 << " = " << processCalculator(number1, number2, operation) << endl;
	}
	
}

double processCalculator(double &number1, double &number2, int operation)
{
	double result = 0.0;

	switch (operation) 
	{
	case 1:
		result = number1 + number2;
		break;
	case 2:
		result = number1 - number2;
		break;
	case 3:
		result = number1 * number2;
		break;
	case 4:
		result = number1 / number2;
		break;
	case 5:
		result = fmod(number1, number2);
		break;
	}

	return result;
}



