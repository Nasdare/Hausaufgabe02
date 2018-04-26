﻿// Hausaufgabe02.cpp: Definiert den Einstiegspunkt fuer die Konsolenanwendung.
#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <regex>

using namespace std;

void aufgabe1();
void calculatorInt(int operation);
void processCalculator();
string getOperationFromUser();
void calculateResult(string &input);
double calculate(double &number1, double &number2, char operatorChar);

struct DoubleCalculator 
{
	double number1, number2;

	DoubleCalculator(double number1, double number2) : number1(number1), number2(number2) {

	}

	double add()
	{
		return number1 + number2;
	}

	double subtract()
	{
		return number1 - number2;
	}

	double multiply()
	{
		return number1 * number2;
	}

	double divide()
	{
		return number1 / number2;
	}

	double modulo()
	{
		return fmod(number1, number2);
	}
};



// Start
int main()
{
	int option = -1;

	while (option != 0)
	{

	do 
	{
		cout << "Bitte Aufgabe waehlen:\n<1> Aufgabe 1\n<2> Aufgabe 2\n<0> Beenden" << endl;
		cin >> option;
	} while (option != 0 && option != 1 && option != 2);

	switch (option)
	{
	case 1:
		// Aufruf Methode fuer Aufgabe 1
		aufgabe1();
		break;
	case 2:
		// Aufruf Methode fuer Aufgabe 2
		processCalculator();
		break;
	case 0:
		cout << "Auf Wiedersehen!" << endl;
		break;
	}
	}
	
}

// Loesung von Aufgabe 1
void aufgabe1() 
{
	int option = -1;

	// Wiederholung bis Eingabe == 0
	do 
	{
		cout << "######################################" << endl;
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


void processCalculator()
{
	static int count = 0;
	string repeat;
	string input;

	cout << "######################################" << endl;

	do 
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		input = getOperationFromUser();
		calculateResult(input);
		count++;

		cout << "Moechten Sie weitere Rechenoperationen druchfuehren ?\nJa: j\nNein: n" << endl;

		do 
		{
			cin >> repeat;

			if (repeat != "j" && repeat != "n")
			{
				cout << "Ungueltige Eingabe (nur 'j' oder 'n' erlaubt)." << endl;
			}
		} while (repeat != "j" && repeat != "n");

	} while (repeat != "n");

	
	cout << "Programmteil beendet\n######################################" << endl;
}


void calculateResult(string &input)
{

	double number1, number2, result = 0.0;
	int operationPosition = 0;
	char operatorChar = ' ';
	string str = input;

	// Sucht Operator im String (Start bei 1 statt 0, da erstes Zeichen nur Vorzeichen sein kann)
	for (unsigned int i = 1; i < str.length(); i++)
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%') {
			operatorChar = str[i];
			operationPosition = i;
			break;
		}
	}

	if (operatorChar != ' ')
	{
		number1 = stod(str.substr(0, operationPosition));
		number2 = stod(str.substr(operationPosition + 1, str.length() - 1));
		result = calculate(number1, number2, operatorChar);

		cout << number1 << " " << operatorChar << " " << number2 << " = " << result << endl;

	}
	else
	{
		cout << "Unerwarteter Fehler." << endl;
	}
}

double calculate(double &number1, double &number2, char operatorChar)
{

	DoubleCalculator calculator = DoubleCalculator(number1, number2);
	double result = 0.0;

	switch (operatorChar) 
	{
	case '+':
		result = calculator.add();
		break;
	case '-':
		result = calculator.subtract();
		break;
	case '*':
		result = calculator.multiply();
		break;
	case '/':
		result = calculator.divide();
		break;
	case '%':
		result = calculator.modulo();
		break;
	}

	return result;
	
}

string getOperationFromUser()
{
	string str;
	bool valid = false;
	regex check("(\\+|-)?(0|\\d+)(\\.\\d+)?(\\+|-|\\*|\\/|%)(-)?(0|\\d+)(\\.\\d+)?");
	

	while (!valid)
	{
		cout << "Bitte gueltige Rechenoperation eingeben:" << endl;
		getline(cin, str);

		str.erase(std::remove(str.begin(), str.end(), ' '), str.end());

		if (regex_match(str, check))
		{
			valid = true;
		}
		else 
		{
			cout << "Ungueltige Eingabe" << endl;
		}
	}
	
	return str;
}



