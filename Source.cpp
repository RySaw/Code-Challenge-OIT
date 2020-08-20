//Created by Ryan Sawyer on 20 August 2020
//BYU OIT Code Challenge
//Converts numbers from 1 to 5000 from decimal integers to roman numerals and vice versa;

/*
This program is incomplete. I exceeded the four hour time limit. 
It can reliably convert from decimal integers to roman numerals, 
but there are still some issues with convertime from roman numeral to decimal.
Given the time, I would resolve these issues.
*/

#include <iostream>	
#include <string>
#include <sstream>

using namespace std;

bool isDecimal(char inputChar)
{
	if (inputChar == '1' || inputChar == '2' || inputChar == '3' || inputChar == '4' || inputChar == '5' ||
		inputChar == '6' || inputChar == '7' || inputChar == '8' || inputChar == '9' || inputChar == '0')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isRoman(char inputChar)
{
	if (inputChar == 'I' || inputChar == 'V' || inputChar == 'X' || inputChar == 'L' || 
		inputChar == 'C' ||	inputChar == 'D' || inputChar == 'M')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isValidDecimal(string userInput)
{
	char firstChar = userInput.at(0);
	if (isDecimal(firstChar))
	{
		for (int i = 0; i < (userInput.size() - 1); i++)
		{
			if (!isDecimal(userInput.at(i)))
				return false;
		}
	}
	else
	{
		return false;
	}
}

bool isValidRoman(string userInput)
{
	char firstChar = userInput.at(0);
	if (isRoman(firstChar))
	{
		for (int i = 0; i < (userInput.size() - 1); i++)
		{
			if (!isRoman(userInput.at(i)))
				return false;
		}
	}
	else
	{
		return false;
	}
}

int main() 
{
	cout << "Created by Ryan Sawyer on 20 August 2020" << endl
		<< "BYU OIT Code Challenge" << endl
		<< "Converts numbers from 1 to 5000 from decimal integers to roman numerals and vice versa" << endl << endl


		<< "This program is incomplete. I exceeded the four hour time limit." << endl
		<< "It can reliably convert from decimal integers to roman numerals," << endl
		<< "but there are still some issues with conversions from roman numeral to decimal." << endl
		<< "Given the time, I would resolve these issues." << endl << endl;

	bool isValid = false;
	string userInput;

	do
	{
		cout << "Enter number to be converted: ";		
		getline(cin, userInput);
		cout << endl << endl;

		if (!isValidDecimal(userInput) && !isValidRoman(userInput))
		{
			cout << "Invalid Number" << endl;
			isValid = false;
		}

		if (isValidDecimal(userInput) || isValidRoman(userInput))
		{			
			isValid = true;
		}

	} while (!isValid);

	if (isValidDecimal(userInput))
	{
		stringstream convertToInt(userInput);				
		int inputNumber;
		convertToInt >> inputNumber;

		if (inputNumber < 1 || inputNumber > 5000)
		{
			cout << "Invalid: Number must be between 1 and 5000";
			system("pause");
			return 0;
		}

		string thousandPlace[6] = { "", "M", "MM", "MMM", "MMMM", "MMMMM" };
		string hundredPlace[10] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
		string tenPlace[10] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
		string onePlace[10] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };

		int thousands = inputNumber / 1000;
		int hundreds = (inputNumber - (thousands * 1000)) / 100;
		int tens = (inputNumber - (thousands * 1000) - (hundreds * 100)) / 10;
		int ones = (inputNumber - (thousands * 1000) - (hundreds * 100) - (tens * 10));

		cout << inputNumber << " in Roman Numerals is: ";
		cout << thousandPlace[thousands] << hundredPlace[hundreds] << tenPlace[tens] << onePlace[ones] << endl	;

	}

	if (isValidRoman(userInput))
	{

		string thousandPlace[6] = { "", "M", "MM", "MMM", "MMMM", "MMMMM" };
		string hundredPlace[10] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
		string tenPlace[10] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
		string onePlace[10] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
		
		int placeHolder = 0;
		int thousandFinal = 0;
		int hundredFinal = 0;
		int tenFinal = 0;
		int oneFinal = 0;

		for (int i = 0; i < 6; i++)
		{	
			if ((thousandPlace[i]).size() <= userInput.size())
			{
				if ((userInput.substr(0, ((thousandPlace[i]).size()))) == thousandPlace[i])
				{
					thousandFinal = i;
					placeHolder = i;
				}
			}
		}

		for (int i = 0; i < 10; i++)
		{
			if ((hundredPlace[i]).size() <= (userInput.size() - placeHolder))
			{
				if ((userInput.substr(placeHolder, (placeHolder + (hundredPlace[i]).size()))) == hundredPlace[i])
				{
					hundredFinal = i;
					placeHolder = i;
				}
			}
		}

		for (int i = 0; i < 10; i++)
		{
			if ((tenPlace[i]).size() <= (userInput.size() - placeHolder))
			{
				if ((userInput.substr(placeHolder, (placeHolder + (tenPlace[i]).size()))) == tenPlace[i])
				{
					tenFinal = i;
					placeHolder = i;
				}
			}
		}

		for (int i = 0; i < 10; i++)
		{
			if ((onePlace[i]).size() <= (userInput.size() - placeHolder))
			{
				if ((userInput.substr(placeHolder, (placeHolder + (userInput.size() - 1)))) == onePlace[i])
				{
					oneFinal = i;
					placeHolder = i;
				}
			}
		}

		cout << thousandFinal << hundredFinal << tenFinal << oneFinal << endl;

	}

	system("pause");
	return 0;
}