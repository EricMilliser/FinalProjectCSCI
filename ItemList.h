#pragma once
#include "ItemClass.h"
#include <map>
#include <fstream>



class itemList
{
public:
	//std::map<int, buffItem> buffs;
	//std::map<int, debuffItem> debuffs;
	std::map<int, regenItem> heals = {};
	std::map<int, weaponItem> weapons = {};

	//std::map<int, meleeWeapon> melee;
	//std::map<int, rangedWeapon> ranged;
	//std::map<int, mysticWeapon> mystic;
	//std::map<int, consumableWeapon> bombs;

	/*
	buffItem findBuffItem(int ID)
	{
		for (auto it = buffs.begin(); it != buffs.end(); ++it)
			if (it->first == ID)
				return it->second;
	}
	debuffItem findDebuffItem(int ID)
	{
		for (auto it = debuffs.begin(); it != debuffs.end(); ++it)
			if (it->first == ID)
				return it->second;
	}
	*/

	itemList()
	{
		std::ifstream fin;
		int var;
		std::string name;
		int counter = 1;
		//buffItem type1;


		/*
		fin.open("BuffItems.txt");
		while (!fin.eof())
		{
			std::getline(fin, name);
			type1.setName(name);
			fin >> var;
			type1.setStat(var);
			fin >> var;
			type1.setAmount(var);
			fin >> var;
			type1.setTarget(var);
			fin >> var;
			type1.setTurns(var);

			buffs.insert({ counter, type1 });
			counter++;
		}
		fin.close();
		debuffItem type2;
		fin.open("DebuffItems.txt");
		while (!fin.eof())
		{
			std::getline(fin, name);
			type2.setName(name);
			fin >> var;
			type2.setStat(var);
			fin >> var;
			type2.setAmount(var);
			fin >> var;
			type2.setTarget(var);
			fin >> var;
			type2.setTurns(var);

			debuffs.insert({ counter, type2 });
			counter++;
		}

		*/
		fin.close();
		regenItem type3;
		fin.open("RegenItems.txt");
		while (!fin.eof())
		{
			fin.clear();
			std::getline(fin, name);
			type3.setName(name);
			fin >> var;
			type3.setStat(var);
			fin >> var;
			type3.setAdd(var);

			std::cout << "Loading: ";
			type3.displayItem();
			

			heals.insert({ counter, type3 });
			std::cout << "Done!\n";
			counter++;
		}
		fin.close();

		counter = 3;
		weaponItem type4 = weaponItem("name", 1);
		fin.open("weaponItems.txt");
		while (!fin.eof())
		{
			fin.clear();
			std::getline(fin, name);
			type4.setName(name);
			fin >> var;
			type4.setDamage(var);

			std::cout << "Loading ID " << counter << ": ";
			type4.displayWeapon();

			weapons.insert({ counter, type4 });
			counter++;
		}
		fin.close();
		//Decided to cut down here, the other types of items I would have added had I implemented a system that involved different ranges
		// and armor and what not. It is out of scope but here is how it is.
		/*
		meleeWeapon type4;
		fin.open("meleeItems.txt");
		while (!fin.eof())
		{
			std::getline(fin, name);
			type4.setName(name);
			fin >> var;
			type4.setDamage(var);

			melee.insert({ counter, type4 });
			counter++;
		}
		fin.close();
		rangedWeapon type5;
		fin.open("rangedItems.txt");
		while (!fin.eof())
		{
			std::getline(fin, name);
			type5.setName(name);
			fin >> var;
			type5.setDamage(var);

			ranged.insert({ counter, type5 });
			counter++;
		}
		fin.close();
		mysticWeapon type6;
		fin.open("mysticItems.txt");
		while (!fin.eof())
		{
			std::getline(fin, name);
			type6.setName(name);
			fin >> var;
			type6.setDamage(var);

			mystic.insert({ counter, type6 });
			counter++;
		}
		fin.close();
		consumableWeapon type7;
		fin.open("bombItems.txt");
		while (!fin.eof())
		{
			std::getline(fin, name);
			type7.setName(name);
			fin >> var;
			type7.setDamage(var);

			bombs.insert({ counter, type7 });
			counter++;
		}
		fin.close();
		*/
	}

	regenItem findRegenItem(int ID)
	{
		for (auto it = heals.begin(); it != heals.end(); ++it)
		{
			if (it->first == ID)
				return it->second;
		}
	}


	weaponItem& findWeaponItem(int ID)
	{
		int counter = 1;
		for (auto it = weapons.begin(); it != weapons.end(); ++it)
		{
			if (it->first == ID)
			{
				return it->second;
			}
		}
	}

};