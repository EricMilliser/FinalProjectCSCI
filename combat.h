#pragma once
#include "PlayerCharacterClass.h"
#include "Enemies.h"















//basic combat for basic enemmies
void basicCombat(Player& yourcharacter, BasicEnemy& ghoul, bool& isAlive)
{
	ghoul.health = 1;
	ghoul.maxHealth = 1;
	ghoul.setWeapon("claws", 1);
	ghoul.isAlive = true;


	bool enemyIsAlive = ghoul.checkIsAlive();
	std::cout << "\n\n";
	std::cout << "A " << ghoul.getName() <<" pops out from the ground!\n";
	while (enemyIsAlive && isAlive)
	{
		yourcharacter.doAction(ghoul);
		

		ghoul.setIsAlive();
		enemyIsAlive = ghoul.checkIsAlive();
		if(enemyIsAlive)
		{
			std::cout << "The " << ghoul.getName() << " attacks!\n\n";
			yourcharacter.takeDamage(ghoul.getWeapon());
			std::cout << "Your health: " << yourcharacter.toStringHealth() << "\n";
			yourcharacter.setIsAlive();
			isAlive = yourcharacter.checkIsAlive();
		}
	}
}


//combat for enemies
void finalCombat(Player& yourcharacter, FinalBoss& george, bool& isAlive)
{

	bool enemyIsAlive = george.checkIsAlive();
	std::cout << "From the darkness, George of the Tomb appears!\n";
	while (enemyIsAlive && isAlive)
	{
		yourcharacter.doActionFinal(george);

		george.setIsAlive();
		enemyIsAlive = george.checkIsAlive();
		if (enemyIsAlive)
		{
			std::cout << "George heaves his trusty shovel!";
			yourcharacter.takeDamage(george.getWeapon());
			yourcharacter.toStringHealth();
			yourcharacter.setIsAlive();
			isAlive = yourcharacter.checkIsAlive();
		}
	}
}


//combat declaring the machine man stats
void basicCombat2(Player& yourcharacter, BasicEnemy& ghoul, bool& isAlive)
{
	ghoul.health = 100;
	ghoul.maxHealth = 100;
	ghoul.setWeapon("Flamethrower", 10);



	bool enemyIsAlive = ghoul.checkIsAlive();
	std::cout << "\n\n";
	std::cout << "A " << ghoul.getName() << " pops out from the ground!\n";
	while (enemyIsAlive && isAlive)
	{
		yourcharacter.doAction(ghoul);


		ghoul.setIsAlive();
		enemyIsAlive = ghoul.checkIsAlive();
		if (enemyIsAlive)
		{
			std::cout << "The " << ghoul.getName() << " attacks!\n\n";
			yourcharacter.takeDamage(ghoul.getWeapon());
			std::cout << "Your health: " << yourcharacter.toStringHealth() << "\n";
			enemyIsAlive = ghoul.checkIsAlive();
			yourcharacter.setIsAlive();
			isAlive = yourcharacter.checkIsAlive();
		}
	}
}