#pragma once


#pragma once
#include <string>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <cstdlib>
#include <ctime>




//input failure check
bool inputFailCheck()
{
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "Error - Invalid Input: Input was not a number\n";
		return false;
	}
	else
	{
		return true;
	}
}

//check for int within range
bool withinRange(int input, int lowValue, int highValue)
{
	if (input < lowValue || input > highValue)
	{
		std::cout << "Error - Invalid Input: Input must be in range: " << lowValue << "-" << highValue << "\n";
		return false;
	}
	else
	{
		return true;
	}
}


//get valid int
int getValidInt(std::string paramMsg, int lowParam, int highParam)
{

	int input;
	bool isValid = false;
	while (isValid == false)
	{
		std::cout << paramMsg << " (" << lowParam << "-" << highParam << "): ";
		std::cin >> input;
		isValid = inputFailCheck();
		isValid = withinRange(input, lowParam, highParam);
	}
	return input;
}

//string input error
void stringInputError(bool checked)
{
	if (checked == true)
	{
		std::cout << "Error - Invalid Input: No value was entered.\n";
	}
}

//validated string
std::string getValidString(std::string paramMsg)
{
	bool isValid = false;
	bool beenChecked = false;
	std::string input;
	while (isValid == false)
	{
		stringInputError(beenChecked);
		std::cout << paramMsg << "\n";
		std::getline(std::cin, input);
		if (input.empty())
		{
			isValid = false;
		}
		else
		{
			isValid = true;
		}
		beenChecked = true;
	}
	return input;
}


