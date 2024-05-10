#pragma once
#include <ctime>
#include <cstdlib>
#include "PlayerCharacterClass.h"
#include "Enemies.h"
#include "combat.h"
#include <ctime>
#include <random>



//random functions to get random items.
int getRandomInt(int start, int end, int& random)
{
	std::random_device rand;
	std::mt19937 gen(rand());

	std::uniform_int_distribution<> distr(start, end);
	random = distr(gen);
	return random;
}


regenItem getRandItem(itemList& items, int random)
{
	getRandomInt(0, 2, random);

	return items.findRegenItem(random);
}

weaponItem getRandWeapon(itemList& items, int random)
{
	getRandomInt(3, 8, random);
	return items.findWeaponItem(random);
}





//All thsi  code below is faulty, I left it in so my thought process could be seen.
//It doesnt work because of how the parameters are passed, they don't change when the functions execute.


/*



regenItem lootLoop(itemList items, regenItem& loot1, weaponItem& loot2, int random)
{
	random = getRandomInt(3, 9, random);
	switch (random)
	{
	case 1:

		loot1 = getRandItem(items, random);
		std::cout << "You found: ";
		loot1.displayItem();
		//yourcharacter.addItem(loot1);
		break;
	case 2:
		loot2 = getRandWeapon(items, random);
		std::cout << "You found: ";
		loot2.displayWeapon();
		//yourcharacter.addWeapon(loot2);
		break;
	}
}



void combatLoop(Player& yourcharacter, BasicEnemy ghoul, AbilityList abilites, itemList items, bool isAlive, regenItem loot1, weaponItem loot2, int random)
{
	basicCombat(yourcharacter, ghoul);

	if (isAlive)
	{

		std::cout << "You defeated a ghoul!\n";
		yourcharacter.levelUp(abilites);
	}
}




void getEventchoice1(Player& yourcharacter, int& random, int& clues, AbilityList abilities, itemList items, regenItem loot1, weaponItem loot2, BasicEnemy ghoul)
{
	random = getRandomInt(1, 2, random);
	switch (random)
	{
	case 1:
		clues++;
		std::cout << "You found a clue!";
		break;
	case 2:;
		basicCombat(yourcharacter, ghoul);
		bool isAlive = yourcharacter.GetisAlive();
		if (isAlive)
		{
			std::cout << "You defeated a ghoul!\n";
			yourcharacter.levelUp(abilities);
			int random2 = rand() % 2;	
		}
		break;
	}
}








void getEventchoice2(Player& yourcharacter, int random, int& clues, int& spotted, AbilityList abilities, itemList items, BasicEnemy ghoul, regenItem loot1, weaponItem loot2)
{
	bool isAlive = yourcharacter.GetisAlive();
	random = getRandomInt(1, 3, random);
	switch (random)
	{
	case 1:
		lootLoop(yourcharacter, items, loot1, loot2, random);
		break;
	case 2:
		combatLoop(yourcharacter, ghoul, abilities, items, isAlive, loot1, loot2, random);
		break;
	case 3:
		spotted++;
		std::cout << "A random passerby saw you rumaging around... you flee to avoid alarming them.\n";
		break;
	}
	isAlive = yourcharacter.GetisAlive();
}

void eventCase3(Player& yourcharcter, int random, itemList items, bool& special, weaponItem loot2)
{
	switch (random)
	{
	case 10 :
		loot2 = items.findWeaponItem(9);
		std::cout << "You found: ";
		loot2.displayWeapon();
		yourcharcter.addWeapon(loot2);
		special = true;
	}
}


void game(itemList items, AbilityList abilities, int& clues, int& spotted, int& random, Player& yourCharacter, bool& foundAll, bool& caguht, bool& special, regenItem& loot1, weaponItem& loot2, BasicEnemy ghoul, int choice, bool isAlive)
{
	//yourCharacter = Player(items);

;
	//foundAll = false;
	//caught = false;
	//special = false;

	

	std::cout << "Recently brought into the supernatural world,\n";
	std::cout << "the Overseer instructed you to find a troublesome\n";
	std::cout << "individual named George. ";
	std::cout << "George is threatening to raise the local graveyard's\n";
	std::cout << "dead as ghouls, which would expose the supernatural world\n";
	std::cout << "to the local humans.\n";

	std::cout << "Find him and stop him from completing his task..\n";

	//random = 1;
	//getEventchoice1(yourCharacter, random, clues, abilities, items, loot1, loot2, ghoul);

	while ((isAlive == true) && (foundAll == false) && (caught == false) && (special == false))
	{
		std::cout << "Objective: Find George\n";
		std::cout << "Clues: " << clues << std::endl;
		std::cout << "Spotted Times: " << spotted << std::endl << std::endl;
		std::cout << "Choose what you would like to do\n";
		std::cout << "1. Search for clues\n";
		std::cout << "2. Search for items\n";
		std::cout << "3. Inspect surrondings\n";
		choice = getValidInt("Make your choice..", 1, 3);

		switch (choice)
		{
		case 1:
			getEventchoice1(yourCharacter, random, clues, abilities, items, loot1, loot2, ghoul);
			break;
		case 2:
			getEventchoice2(yourCharacter, random, clues, spotted, abilities, items, ghoul, loot1, loot2);
			break;
		case 3:
			eventCase3(yourCharacter, random, items, special, loot2);
			break;
		}
		if (clues == 10)
		{
			foundAll = true;
		}
		if (spotted == 5)
		{
			caught = true;
		}
	}

	if (isAlive == false)
	{
		std::cout << "You Died: Game Over!\n\n\n";
	
	}
	if (foundAll == true)
	{
		FinalBoss george;
		finalCombat(yourCharacter, george, isAlive);
		if (isAlive == false)
		{
			std::cout << "You Died: Game Over!\n\n\n";
		}
		else
		{
			std::cout << "You found and defeated George, it will be a queiter place now.\n";
			std::cout << "You Win! Game Over! \n\n\n";
		}
	}
	if (caught == true)
	{
		std::cout << "You were caught by Supernatural Hunters to prevent the public from finding out any more...";
		std::cout << "You Died! Game Over!";
	}
	if (special == true)
	{
		BasicEnemy MachineMan;
		MachineMan.setHealth(100);
		MachineMan.setName("Machine Hulk");
		MachineMan.setWeapon("Flamethrower", 10);

		basicCombat(yourCharacter, MachineMan, isAlive);
		

		if (isAlive == false)
		{
			std::cout << "You Died: Game Over!\n\n\n";
		}
		else
		{
			std::cout << "Democracy Previals Yet Again.\n";
		}
	}
}
*/