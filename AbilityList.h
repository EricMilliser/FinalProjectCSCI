#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include "AbilityClass.h"
#include "validInputs.h"


//Note there is a lot of commented code. The code is commented out 
//because I did not have time to implement those functions and
// aspects of the game

//class ability list, storing all the ablities
class AbilityList
{
protected:

	//damage abilities for each class
	std::map<int, damageAbility> class1DmgAbl;
	std::map<int, damageAbility> class2DmgAbl;
	std::map<int, damageAbility> class3DmgAbl;
	/*
	std::map<int, buffAbility> class1BuffAbl;
	std::map<int, buffAbility> class2BuffAbl;
	std::map<int, buffAbility> class3BuffAbl;

	std::map<int, debuffAbility> class1DebuffAbl;
	std::map<int, debuffAbility> class2DebuffAbl;
	std::map<int, debuffAbility> class3DebuffAbl;

	std::map<int, passiveAbility> class1PassAbl;
	std::map<int, passiveAbility> class2PassAbl;
	std::map<int, passiveAbility> class3PassAbl;
	*/
public:
	/// <summary>
	/// Constructor that pulls from each of the filles and loads them
	/// There is a lot of code here that is not used
	/// Index in the maps is based on the ID created by the counter
	/// </summary>
	AbilityList()
	{
		std::string inputName;
		//int abilityType;
		int damage;
		int cooldown;
		//int buffAmount;
		//int buffStat;
		//int turnAmount;
		//int passive;


		std::ifstream fin;
		std::cout << "Loading Soulleech Abilities\n";
		fin.open("SoulleechDamageAbilities.txt");
		int counter = 1;
		damageAbility type1;
		while (!fin.eof())
		{
			fin.clear();
			std::getline(fin, inputName);
			fin >> damage;
			fin >> cooldown;
			type1.setName(inputName);
			type1.setDamage(damage);
			type1.setCooldown(cooldown);

			std::cout << "Loading: ";
			type1.displayAbility();

			class1DmgAbl.insert({counter, type1});
			std::cout << "Done!\n";
			counter++;
		}
		fin.close();
		std::cout << "Loading Shapechanger Abilities\n";
		fin.open("ShapechangerDamageAbilities.txt");
		while (!fin.eof())
		{
			fin.clear();
			std::getline(fin, inputName);
			fin >> damage;
			fin >> cooldown;
			type1.setName(inputName);
			type1.setDamage(damage);
			type1.setCooldown(cooldown);

			std::cout << "Loading: ";
			type1.displayAbility();

			class2DmgAbl.insert({ counter, type1 });
			counter++;
			std::cout << "Done!\n";
		}
		fin.close();
		std::cout << "Loading Mystic Class Abilities\n";
		fin.open("MysticDamageAbilities.txt");
		while (!fin.eof())
		{
			fin.clear();
			std::getline(fin, inputName);
			fin >> damage;
			fin >> cooldown;
			type1.setName(inputName);
			type1.setDamage(damage);
			type1.setCooldown(cooldown);

			std::cout << "Loading: ";
			type1.displayAbility();

			class3DmgAbl.insert({ counter, type1 });
			counter++;
			std::cout << "Done!\n";
		}
		fin.close();
		
		///
		///
		/// 
		//Dropped these types of ability, I do not want to be using this.
/*
		buffAbility type2;
		fin.open("SoulleechBuffAbilities.txt");
		while (!fin.eof())
		{
			fin.clear();
			fin.ignore(100, '\n');
			std::getline(fin, inputName);
			fin >> buffAmount;
			fin >> buffStat;
			fin >> turnAmount;

			type2.setName(inputName);
			type2.setAmount(buffAmount);
			type2.setStat(buffStat);
			type2.setTurn(turnAmount);

			class1BuffAbl.insert({counter, type2});
			
			counter++;
		}
		fin.close();
		fin.open("ShapchangerBuffAbilities.txt");
		while (!fin.eof())
		{
			fin.clear();
			fin.ignore(100, '\n');
			std::getline(fin, inputName);
			fin >> buffAmount;
			fin >> buffStat;
			fin >> turnAmount;

			type2.setName(inputName);
			type2.setAmount(buffAmount);
			type2.setStat(buffStat);
			type2.setTurn(turnAmount);

			class2BuffAbl.insert({ counter, type2 });

			counter++;
		}
		fin.close();
		fin.open("MysticBuffAbilities.txt");
		while (!fin.eof())
		{
			fin.clear();
			fin.ignore(100, '\n');
			std::getline(fin, inputName);
			fin >> buffAmount;
			fin >> buffStat;
			fin >> turnAmount;

			type2.setName(inputName);
			type2.setAmount(buffAmount);
			type2.setStat(buffStat);
			type2.setTurn(turnAmount);

			class3BuffAbl.insert({ counter, type2 });

			counter++;
		}
		fin.close();


		debuffAbility type3;
		fin.open("SoulleechDebuffAbilities.txt");
		while (!fin.eof())
		{
			fin.clear();
			fin.ignore(100, '\n');
			std::getline(fin, inputName);
			fin >> buffAmount;
			fin >> buffStat;
			fin >> turnAmount;

			type3.setName(inputName);
			type3.setAmount(buffAmount);
			type3.setStat(buffStat);
			type3.setTurn(turnAmount);

			class1DebuffAbl.insert({ counter, type3 });

			counter++;
		}
		fin.close();
		fin.open("ShapchangerDebuffAbilities.txt");
		while (!fin.eof())
		{
			fin.clear();
			fin.ignore(100, '\n');
			std::getline(fin, inputName);
			fin >> buffAmount;
			fin >> buffStat;
			fin >> turnAmount;

			type2.setName(inputName);
			type2.setAmount(buffAmount);
			type2.setStat(buffStat);
			type2.setTurn(turnAmount);

			class2DebuffAbl.insert({ counter, type3 });

			counter++;
		}
		fin.close();
		fin.open("MysticDebuffAbilities.txt");
		while (!fin.eof())
		{
			fin.clear();
			fin.ignore(100, '\n');
			std::getline(fin, inputName);
			fin >> buffAmount;
			fin >> buffStat;
			fin >> turnAmount;

			type2.setName(inputName);
			type2.setAmount(buffAmount);
			type2.setStat(buffStat);
			type2.setTurn(turnAmount);

			class3DebuffAbl.insert({ counter, type3 });

			counter++;
		}
		fin.close();




		passiveAbility type4;
		fin.open("SoulleechPassiveAbililites.txt");
		while(!fin.eof())
		{
			fin.clear();
			fin.ignore(100, '\n');
			std::getline(fin, inputName);
			fin >> passive;
			type4.setName(inputName);
			type4.setEffect(passive);

			class1PassAbl.insert({ counter, type4 });
		}
		fin.close();
		fin.open("ShapechangerPassiveAbililites.txt");
		while (!fin.eof())
		{
			fin.clear();
			fin.ignore(100, '\n');
			std::getline(fin, inputName);
			fin >> passive;
			type4.setName(inputName);
			type4.setEffect(passive);

			class2PassAbl.insert({ counter, type4 });
		}
		fin.close();
		fin.open("MysticPassiveAbililites.txt");
		while (!fin.eof())
		{
			std::getline(fin, inputName);
			fin >> passive;
			type4.setName(inputName);
			type4.setEffect(passive);

			class3PassAbl.insert({ counter, type4 });
		}
		fin.close();
		*/
	}
	//functgion for finding damage ability
	damageAbility findDamageAbility(int race, int index)
	{

		

		switch (race)
		{
		case 1:
			for (auto it = class1DmgAbl.begin(); it != class1DmgAbl.end(); ++it)
				if (it->first == index)
					return it->second;
		case 2:
			for (auto it = class2DmgAbl.begin(); it != class2DmgAbl.end(); ++it)
				if (it->first == index)
					return it->second;
		case 3:
			for (auto it = class3DmgAbl.begin(); it != class3DmgAbl.end(); ++it)
				if (it->first == index)
					return it->second;
		}
	}



	//functions that would have been used to find the other types of abilities
	/*
	buffAbility findBuffAbility(int race, int index)
	{
		switch (race)
		{
		case 1:
			for (auto it = class1BuffAbl.begin(); it != class1BuffAbl.end(); ++it)
				if (it->first == index)
					return it->second;
		case 2:
			for (auto it = class2BuffAbl.begin(); it != class2BuffAbl.end(); ++it)
				if (it->first == index)
					return it->second;
		case 3:
			for (auto it = class3BuffAbl.begin(); it != class3BuffAbl.end(); ++it)
				if (it->first == index)
					return it->second;
		}
	}


	debuffAbility findDebuffAbility(int race, int index)
	{
		switch (race)
		{
		case 1:
			for (auto it = class1DebuffAbl.begin(); it != class1DebuffAbl.end(); ++it)
				if (it->first == index)
					return it->second;
		case 2:
			for (auto it = class2DebuffAbl.begin(); it != class2DebuffAbl.end(); ++it)
				if (it->first == index)
					return it->second;
		case 3:
			for (auto it = class3DebuffAbl.begin(); it != class3DebuffAbl.end(); ++it)
				if (it->first == index)
					return it->second;
		}
	}



	passiveAbility findPassiveAbility(int race, int index)
	{
		switch (race)
		{
		case 1:
			for (auto it = class1PassAbl.begin(); it != class1PassAbl.end(); ++it)
				if (it->first == index)
					return it->second;
		case 2:
			for (auto it = class2PassAbl.begin(); it != class2PassAbl.end(); ++it)
				if (it->first == index)
					return it->second;
		case 3:
			for (auto it = class3PassAbl.begin(); it != class3PassAbl.end(); ++it)
				if (it->first == index)
					return it->second;
		}
	}
	*/


	//function  to display the abilities one by one and add return an ability based on input
	void displayAndGetAbility(int race, int level, int& choice)
	{
		damageAbility type1;
		//buffAbility type2;
		//debuffAbility type3;
		//passiveAbility type4;

		int id1;
		//int id2;
		//int id3;
		//int id4;


		if(level == 1)
		{
			switch (race)
			{
			case 1:
				id1 = 1;
				//id2 = 31;
				//id3 = 61;
				//id4 = 91;
				break;
			case 2:
				id1 = 11;
				//id2 = 41;
				//id3 = 71;
				//id4 = 101;
				break;
			case 3:
				id1 = 21;
				//id2 = 51;
				//id3 = 81;
				//id4 = 111;
				break;
			}
		}



		if (level == 2)
		{
			switch (race)
			{
			case 1:
				id1 = 2;
				//id2 = 32;
				//id3 = 62;
				//id4 = 92;
				break;
			case 2:
				id1 = 12;
				//id2 = 42;
				//id3 = 72;
				//id4 = 102;
				break;
			case 3:
				id1 = 22;
				//id2 = 52;
				//id3 = 82;
				//id4 = 112;
				break;
			}
		}


		if (level == 3)
		{
			switch (race)
			{
			case 1:
				id1 = 3;
				//id2 = 33;
				//id3 = 63;
				//id4 = 93;
				break;
			case 2:
				id1 = 13;
				//id2 = 43;
				//id3 = 73;
				//id4 = 103;
				break;
			case 3:
				id1 = 23;
				//id2 = 53;
				//id3 = 83;
				//id4 = 113;
				break;
			}
		}


		if (level == 4)
		{
			switch (race)
			{
			case 1:
				id1 = 4;
				//id2 = 34;
				//id3 = 64;
				//id4 = 94;
				break;
			case 2:
				id1 = 14;
				//id2 = 44;
				//id3 = 74;
				//id4 = 104;
				break;
			case 3:
				id1 = 24;
				//id2 = 54;
				//id3 = 84;
				//id4 = 114;
				break;
			}
		}

		if (level == 5)
		{
			switch (race)
			{
			case 1:
				id1 = 5;
				//id2 = 35;
				//id3 = 65;
				//id4 = 95;
				break;
			case 2:
				id1 = 15;
				//id2 = 45;
				//id3 = 75;
				//id4 = 105;
				break;
			case 3:
				id1 = 25;
				//id2 = 55;
				//id3 = 85;
				//id4 = 115;
				break;
			}
		}

		if (level == 6)
		{
			switch (race)
			{
			case 1:
				id1 = 6;
				//id2 = 36;
				//id3 = 66;
				//id4 = 96;
				break;
			case 2:
				id1 = 16;
				//id2 = 46;
				//id3 = 76;
				//id4 = 106;
				break;
			case 3:
				id1 = 26;
				//id2 = 56;
				//id3 = 86;
				//id4 = 116;
				break;
			}
		}

		if (level == 7)
		{
			switch (race)
			{
			case 1:
				id1 = 7;
				//id2 = 37;
				//id3 = 67;
				//id4 = 97;
				break;
			case 2:
				id1 = 17;
				//id2 = 47;
				//id3 = 77;
				//id4 = 107;
				break;
			case 3:
				id1 = 27;
				//id2 = 57;
				//id3 = 87;
				//id4 = 117;
				break;
			}
		}

		if (level == 8)
		{
			switch (race)
			{
			case 1:
				id1 = 8;
				//id2 = 38;
				//id3 = 68;
				//id4 = 98;
				break;
			case 2:
				id1 = 18;
				//id2 = 48;
				//id3 = 78;
				//id4 = 108;
				break;
			case 3:
				id1 = 28;
				//id2 = 58;
				//id3 = 88;
				//id4 = 118;
				break;
			}
		}

		if (level == 9)
		{
			switch (race)
			{
			case 1:
				id1 = 9;
				//id2 = 39;
				//id3 = 69;
				//id4 = 99;
				break;
			case 2:
				id1 = 19;
				//id2 = 49;
				//id3 = 79;
				//id4 = 109;
				break;
			case 3:
				id1 = 29;
				//id2 = 59;
				//id3 = 89;
				//id4 = 119;
				break;

			}
		}

		if (level == 10)
		{
			switch (race)
			{
			case 1:
				id1 = 10;
				//id2 = 40;
				//id3 = 70;
				//id4 = 100;
				break;
			case 2:
				id1 = 20;
				//id2 = 50;
				//id3 = 80;
				//id4 = 110;
				break;
			case 3:
				id1 = 30;
				//id2 = 60;
				//id3 = 90;
				//id4 = 120;
				break;
			}
		}


		choice = id1;


		/*
		switch (level)
		{
		case 1:
			type1 = findDamageAbility(race, id1);
			//type2 = findBuffAbility(race, id2);
			//type3 = findDebuffAbility(race, id3);
			//type4 = findPassiveAbility(race, id4);
			std::cout << "Choose an Ability\n";
			std::cout << "1. " << type1.getName() << " - Damage: " << type1.getDamage() << std::endl;
			//std::cout << "2. " << type2.getName() << " - Buff Type: " << type2.getBuffType() << " by " << type2.getAmount() << " - No. turns = " << type2.getTurns() << std::endl;
			//std::cout << "3. " << type3.getName() << " - Debuff Type: " << type3.getBuffType() << " by " << type3.getAmount() << " - No. turns = " << type2.getTurns() << std::endl;
			choice = getValidInt("Make your choice", 1, 1);
			switch (choice){
		
			case 1:
				choice = id1;
				break;
			case 2:
				//choice = id2;
				//break;
			case 3:
				//choice = id3;
				//break;
			//type 4 would go here but I will not be doing type 4 buffs for this one.
			break;
			}
			break;
		case 2:
			type1 = findDamageAbility(race, id1);
			//type2 = findBuffAbility(race, id2);
			//type3 = findDebuffAbility(race, id3);
			//type4 = findPassiveAbility(race, id4);
			std::cout << "Choose an Ability\n";
			std::cout << "1. " << type1.getName() << " - Damage: " << type1.getDamage() << std::endl;
			//std::cout << "2. " << type2.getName() << " - Buff Type: " << type2.getBuffType() << " by " << type2.getAmount() << " - No. turns = " << type2.getTurns() << std::endl;
			//std::cout << "3. " << type3.getName() << " - Debuff Type: " << type3.getBuffType() << " by " << type3.getAmount() << " - No. turns = " << type2.getTurns() << std::endl;
			//type 4 would go here but I will not be doing type 4 buffs for this one.
			choice = getValidInt("Make your choice", 1, 1);
			switch (choice) {
			case 1:
				choice = id1;
				break;
			case 2:
				//choice = id2;
				//break;
			case 3:
				//choice = id3;
				break;
			}
			break;
		case 3:
			type1 = findDamageAbility(race, id1);
			//type2 = findBuffAbility(race, id2);
			//type3 = findDebuffAbility(race, id3);
			//type4 = findPassiveAbility(race, id4);
			std::cout << "Choose an Ability\n";
			std::cout << "1. " << type1.getName() << " - Damage: " << type1.getDamage() << std::endl;
			//std::cout << "2. " << type2.getName() << " - Buff Type: " << type2.getBuffType() << " by " << type2.getAmount() << " - No. turns = " << type2.getTurns() << std::endl;
			//std::cout << "3. " << type3.getName() << " - Debuff Type: " << type3.getBuffType() << " by " << type3.getAmount() << " - No. turns = " << type2.getTurns() << std::endl;
			//type 4 would go here but I will not be doing type 4 buffs for this one.
			choice = getValidInt("Make your choice", 1, 1);
			switch (choice){
			
			case 1:
				choice = id1;
				break;
			case 2:
				//choice = id2;
				break;
			case 3:
				//choice = id3;
				break;
			}
			break;

		case 4:
			type1 = findDamageAbility(race, id1);
			//type2 = findBuffAbility(race, id2);
			//type3 = findDebuffAbility(race, id3);
			//type4 = findPassiveAbility(race, id4);
			std::cout << "Choose an Ability\n";
			std::cout << "1. " << type1.getName() << " - Damage: " << type1.getDamage() << std::endl;
			//std::cout << "2. " << type2.getName() << " - Buff Type: " << type2.getBuffType() << " by " << type2.getAmount() << " - No. turns = " << type2.getTurns() << std::endl;
			//std::cout << "3. " << type3.getName() << " - Debuff Type: " << type3.getBuffType() << " by " << type3.getAmount() << " - No. turns = " << type2.getTurns() << std::endl;
			//type 4 would go here but I will not be doing type 4 buffs for this one.
			choice = getValidInt("Make your choice", 1, 1);
			switch (choice)
			{
			case 1:
				choice = id1;
				break;
			case 2:
				//choice = id2;
				break;
			case 3:
				//choice = id3;
				break;
			}
			break;
		case 5:
			type1 = findDamageAbility(race, id1);
			//type2 = findBuffAbility(race, id2);
			//type3 = findDebuffAbility(race, id3);
			//type4 = findPassiveAbility(race, id4);
			std::cout << "Choose an Ability\n";
			std::cout << "1. " << type1.getName() << " - Damage: " << type1.getDamage() << std::endl;
			//std::cout << "2. " << type2.getName() << " - Buff Type: " << type2.getBuffType() << " by " << type2.getAmount() << " - No. turns = " << type2.getTurns() << std::endl;
			//std::cout << "3. " << type3.getName() << " - Debuff Type: " << type3.getBuffType() << " by " << type3.getAmount() << " - No. turns = " << type2.getTurns() << std::endl;
			//type 4 would go here but I will not be doing type 4 buffs for this one.
			choice = getValidInt("Make your choice", 1, 1);
			switch (choice)
			{
			case 1:
				choice = id1;
				break;
			case 2:
				//choice = id2;
				break;
			case 3:
				//choice = id3;
				break;
			}
			break;
		case 6:
			type1 = findDamageAbility(race, id1);
			//type2 = findBuffAbility(race, id2);
			//type3 = findDebuffAbility(race, id3);
			//type4 = findPassiveAbility(race, id4);
			std::cout << "Choose an Ability\n";
			std::cout << "1. " << type1.getName() << " - Damage: " << type1.getDamage() << std::endl;
			//std::cout << "2. " << type2.getName() << " - Buff Type: " << type2.getBuffType() << " by " << type2.getAmount() << " - No. turns = " << type2.getTurns() << std::endl;
			//std::cout << "3. " << type3.getName() << " - Debuff Type: " << type3.getBuffType() << " by " << type3.getAmount() << " - No. turns = " << type2.getTurns() << std::endl;
			//type 4 would go here but I will not be doing type 4 buffs for this one.
			choice = getValidInt("Make your choice", 1, 1);
			switch (choice)
			{
			case 1:
				choice = id1;
				break;
			case 2:
				//choice = id2;
				break;
			case 3:
				//choice = id3;
				break;
			}
			break;
		case 7:
			type1 = findDamageAbility(race, id1);
			//type2 = findBuffAbility(race, id2);
			//type3 = findDebuffAbility(race, id3);
			//type4 = findPassiveAbility(race, id4);
			std::cout << "Choose an Ability\n";
			std::cout << "1. " << type1.getName() << " - Damage: " << type1.getDamage() << std::endl;
			//std::cout << "2. " << type2.getName() << " - Buff Type: " << type2.getBuffType() << " by " << type2.getAmount() << " - No. turns = " << type2.getTurns() << std::endl;
			//std::cout << "3. " << type3.getName() << " - Debuff Type: " << type3.getBuffType() << " by " << type3.getAmount() << " - No. turns = " << type2.getTurns() << std::endl;
			//type 4 would go here but I will not be doing type 4 buffs for this one.
			choice = getValidInt("Make your choice", 1, 1);
			switch (choice)
			{
			case 1:
				choice = id1;
				break;
			case 2:
				//choice = id2;
				break;
			case 3:
				//choice = id3;
				break;
			}
			break;
		case 8:
			type1 = findDamageAbility(race, id1);
			//type2 = findBuffAbility(race, id2);
			//type3 = findDebuffAbility(race, id3);
			//type4 = findPassiveAbility(race, id4);
			std::cout << "Choose an Ability\n";
			std::cout << "1. " << type1.getName() << " - Damage: " << type1.getDamage() << std::endl;
			//std::cout << "2. " << type2.getName() << " - Buff Type: " << type2.getBuffType() << " by " << type2.getAmount() << " - No. turns = " << type2.getTurns() << std::endl;
			//std::cout << "3. " << type3.getName() << " - Debuff Type: " << type3.getBuffType() << " by " << type3.getAmount() << " - No. turns = " << type2.getTurns() << std::endl;
			//type 4 would go here but I will not be doing type 4 buffs for this one.
			choice = getValidInt("Make your choice", 1, 1);
			switch (choice)
			{
			case 1:
				choice = id1;
				break;
			case 2:
				//choice = id2;
				break;
			case 3:
				//choice = id3;
				break;
			}
			break;
		case 9:
			type1 = findDamageAbility(race, id1);
			//type2 = findBuffAbility(race, id2);
			//type3 = findDebuffAbility(race, id3);
			//type4 = findPassiveAbility(race, id4);
			std::cout << "Choose an Ability\n";
			std::cout << "1. " << type1.getName() << " - Damage: " << type1.getDamage() << std::endl;
			//std::cout << "2. " << type2.getName() << " - Buff Type: " << type2.getBuffType() << " by " << type2.getAmount() << " - No. turns = " << type2.getTurns() << std::endl;
			//std::cout << "3. " << type3.getName() << " - Debuff Type: " << type3.getBuffType() << " by " << type3.getAmount() << " - No. turns = " << type2.getTurns() << std::endl;
			//type 4 would go here but I will not be doing type 4 buffs for this one.
			choice = getValidInt("Make your choice", 1, 1);
			switch (choice)
			{
			case 1:
				choice = id1;
				break;
			case 2:
				//choice = id2;
				break;
			case 3:
				//choice = id3;
				break;
			}
			break;
		case 10:
			type1 = findDamageAbility(race, id1);
			//type2 = findBuffAbility(race, id2);
			//type3 = findDebuffAbility(race, id3);
			//type4 = findPassiveAbility(race, id4);
			std::cout << "Choose an Ability\n";
			std::cout << "1. " << type1.getName() << " - Damage: " << type1.getDamage() << std::endl;
			//std::cout << "2. " << type2.getName() << " - Buff Type: " << type2.getBuffType() << " by " << type2.getAmount() << " - No. turns = " << type2.getTurns() << std::endl;
			//std::cout << "3. " << type3.getName() << " - Debuff Type: " << type3.getBuffType() << " by " << type3.getAmount() << " - No. turns = " << type2.getTurns() << std::endl;
			//type 4 would go here but I will not be doing type 4 buffs for this one.
			choice = getValidInt("Make your choice", 1, 1);
			switch (choice)
			{
			case 1:
				choice = id1;
				break;
			case 2:
				//choice = id2;
				break;
			case 3:
				//choice = id3;
				break;
			}
			break;
			
		}
		*/
	}
	

};







