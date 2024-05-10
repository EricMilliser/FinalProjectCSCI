/*
Author:  Eric Milliser
Date written : 05 / 10 / 24
Assignment : Module8 Final Project
Short Desc : Short RPG game with 3 classes and 3 enemies
*/



#include "combat.h"
#include <ctime>
#include <cstdlib>
#include "game.h"
#include "PlayerCharacterClass.h"







int main()
{
	//declarations
	int clues = 0;
	int spotted = 0;
	int random =0;
	int choice;


	bool foundAll = false;
	bool caught = false;
	bool special = false;
	bool isAlive;
	regenItem loot1;
	weaponItem loot2 = weaponItem("name", 0);
	BasicEnemy ghoul;


	//loading items from file
	std::cout << "Loading items...\n";
	itemList items;
	std::cout << "Done!\n";
	std::cout << "Loading abilities...\n";
	AbilityList abilities;
	std::cout << "Done!\n";

	//create character
	Player yourCharacter = Player(items, abilities);

	choice = 0;
	std::cout << "Choose what you would like to do:\n";
	std::cout << "1. Play Game\n";
	std::cout << "2. Exit\n";
	choice = getValidInt("Choose from the menu,", 1, 2);
	if (choice == 1)
	{
		int clues = 0;
		int spotted = 0;
		int random;

		//intro
		isAlive = yourCharacter.checkIsAlive();
		std::cout << "Recently brought into the supernatural world,\n";
		std::cout << "the Overseer instructed you to find a troublesome\n";
		std::cout << "individual named George. ";
		std::cout << "George is threatening to raise the local graveyard's\n";
		std::cout << "dead as ghouls, which would expose the supernatural world\n";
		std::cout << "to the local humans.\n";

		std::cout << "Find him and stop him from completing his task..\n";

		while ((isAlive == true) && (foundAll == false) && (caught == false) && (special == false))
		{
			//prompt
			std::cout << "\nObjective: Find George\n";
			std::cout << "Clues: " << clues << std::endl;
			std::cout << "Spotted Times: " << spotted << std::endl << std::endl;
			std::cout << "Choose what you would like to do\n";
			std::cout << "1. Search for clues\n";
			std::cout << "2. Search for items\n";
			std::cout << "3. Inspect surrondings\n";


			choice = getValidInt("Make your choice..", 1, 3);
 
			//choices
			if (choice == 1)
			{
				random = getRandomInt(1, 2, random);
				switch (random)
				{
				case 1:
					std::cout << "\nYou Found a Clue!\n";
					clues++;
					break;
				case 2:
					basicCombat(yourCharacter, ghoul, isAlive);

					isAlive = yourCharacter.checkIsAlive();
					if (isAlive)
					{
						std::cout << "You defeated a ghoul!\n";
						yourCharacter.levelUp(abilities);
						random = getRandomInt(1, 2, random);
						switch (random)
						{
						case 1:

							loot1 = getRandItem(items, random);
							std::cout << "You found: ";
							loot1.displayItem();
							yourCharacter.addItem(loot1);
							break;
						case 2:
							loot2 = getRandWeapon(items, random);
							std::cout << "You found: ";
							loot2.displayWeapon();
							yourCharacter.addWeapon(loot2);
							break;
						}
						break;
					}
				}
			}
			if (choice == 2)
			{
				random = getRandomInt(1, 3, random);
				switch (random)
				{
				case 1:
					random = getRandomInt(3, 9, random);
					switch (random)
					{
					case 1:

						loot1 = getRandItem(items, random);
						std::cout << "You found: ";
						loot1.displayItem();
						yourCharacter.addItem(loot1);
						break;
					case 2:
						loot2 = getRandWeapon(items, random);
						std::cout << "You found: ";
						loot2.displayWeapon();
						yourCharacter.addWeapon(loot2);
						break;
					}
					break;
				case 2:
					basicCombat(yourCharacter, ghoul, isAlive);
					random = getRandomInt(3, 9, random);
					isAlive = yourCharacter.checkIsAlive();
					if (isAlive)
					{
						std::cout << "You defeated a ghoul!\n";
						yourCharacter.levelUp(abilities);
						random = getRandomInt(1, 2, random);
						switch (random)
						{
						case 1:

							loot1 = getRandItem(items, random);
							std::cout << "You found: ";
							loot1.displayItem();
							yourCharacter.addItem(loot1);
							break;
						case 2:
							loot2 = getRandWeapon(items, random);
							std::cout << "You found: ";
							loot2.displayWeapon();
							yourCharacter.addWeapon(loot2);
							break;
						}
						break;
					}
				case 3:
					spotted++;
					std::cout << "A random passerby saw you rumaging around... you flee to avoid alarming them.\n";
					break;
				}
			}
			if (choice == 3)
			{
				random = getRandomInt(1, 10, random);
				switch (random)
				{
				case 10:
					loot2 = items.findWeaponItem(9);
					std::cout << "You found: ";
					loot2.displayWeapon();
					yourCharacter.addWeapon(loot2);
					special = true;
				}
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


	}
	else if (choice == 2)
	{
		return 0;
	}

	//game over message
	if (isAlive == false)
	{
		std::cout << "You Died: Game Over!\n\n\n";

	}
	//final boss
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
	//secret boss
	if (special == true)
	{
		//note i just used a public declartion of the emeny to create this enemy type
		BasicEnemy MachineMan;
		MachineMan.setHealth(100);
		MachineMan.setName("Machine Hulk");
		MachineMan.setWeapon("Flamethrower", 10);
		MachineMan.isAlive = true;


	
		basicCombat2(yourCharacter, MachineMan, isAlive);


		if (isAlive == false)
		{
			std::cout << "You Died: Game Over!\n\n\n";
		}
		else
		{
			std::cout << "Democracy Previals Yet Again.\n";
		}
	}
	
};