#pragma once
#include <string>
#include <vector>
#include <map>
#include "ItemClass.h"
#include "CharacterClass.h"
#include "AbilityClass.h"
#include "AbilityList.h"
#include "ItemList.h"
#include "Enemies.h"
#include <cstdlib>
#include "game.h"



//creation of player class
class Player : public Character
{
public:
	//not i made everythign public to allow ease of creation
	std::vector<weaponItem> weapons = {};
	std::vector<regenItem> regenItems = {};
	//std::vector<buffItem> buffItems;
	//std::vector<debuffItem> debuffItems;
	std::vector<damageAbility> powers =  {};
	//std::vector<buffAbility> buffs;
	//std::vector<debuffAbility> debuffs;
	//std::vector<passiveAbility> passives;
	int race;
	//int occupation;
	int level;
	bool isAlive = true;


	
	
	//constructor for building new character
	Player(itemList items, AbilityList abilities)
	{
		std::string validName = getValidString("Enter your characters name: ");
		name = validName;

		std::cout << "Choose your race: \n";
		std::cout << "1. Soulleech\n";
		std::cout << "2. Shapechange \n";
		std::cout << "3. Mystic \n";
		int choice = getValidInt("Make your choice..", 1, 3);
		race = choice;
		health = 2;
		maxHealth = 2;
		isAlive = true;
		damageAbility firstAbility;
		int index;
		if (race == 1)
		{
			index = 1;
		}
		else if (race == 2)
		{
			index = 11;
		}
		else
		{
			index = 21;
		}
		firstAbility = abilities.findDamageAbility(race, index);
		powers.push_back(firstAbility);
		level = 1;
		int random = 0;
		weaponItem weapon = weaponItem("", 1);
		weapon = getRandWeapon(items, 1);
		weapons.push_back(weapon);
	}


	//unused functions that do not work properly
	/*
	Character& operator++(int stat)
	{
		switch (stat)
		{
		case 1:
			health++;
			break;
			
		case 2:
			speed++;
			break;
		case 3:
			willpower++;
			break;
		case 4:
			intelligence++;
			break;
		case 5:
			charisma++;
			break;
			
		}

		return *this;

	}
	*/
	/*
	bool GetisAlive()
	{
		return isAlive;
	}
	
	Character& operator + (regenItem& regen)
	{
		int stat = regen.getStatVar();
		int regenAmount = regen.getAddAmount();


		switch (stat)
		{
		case 1:
			if ((health + regenAmount) > maxHealth)
			{
				health = maxHealth;
			}
			else
			{
				health += regenAmount;
			}
			break;
			
			case 2:
				if ((willpower + regenAmount) > maxWillpower)
				{
					willpower = maxWillpower;
				}
				else
				{
					willpower += regenAmount;
				}
				break;
			}
			
			regen.invertUsed();
			return *this;
		}
		*/
		/*
		Character& operator + (buffItem& buff)
		{
			int stat = buff.getStat();
			int amount = buff.getAmount();

			switch (stat)
			{
			case 0:
				maxHealth += amount;
				break;
			case 1:
				maxWillpower += amount;
				break;
			case 2:
				speed += amount;
				break;
			case 3:
				intelligence += amount;
				break;
			case 4:
				charisma += amount;
				break;
			}
			buff.invertUsed();
			return *this;
		}
		Character& operator - (weaponItem weapon)
		{
			int damage = weapon.getDamage();
			if ((health - damage) <= 0)
			{
				isAlive = false;
				health = 0;
			}
			else
			{
				health -= damage;
			}
			return *this;
		}



		Character& operator - (damageAbility damageAb)
		{
			int damage = damageAb.getDamage();
			if ((health - damage) <= 0)
			{
				isAlive = false;
				health = 0;
			}
			else
			{
				health -= damage;
			}
			return *this;
		}



		Character& operator - (debuffItem& debuff)
		{
			int stat = debuff.getStat();
			int amount = debuff.getAmount();

			switch (stat)
			{
			case 0:
				maxHealth -= amount;
				if (health > maxHealth)
				{
					health = maxHealth;
				}
				break;
			case 1:
				maxWillpower -= amount;
				if (willpower > maxWillpower)
				{
					willpower = maxWillpower;
				}
				break;
			case 2:
				speed -= amount;
				break;
			case 3:
				intelligence -= amount;
				break;
			case 4:
				charisma -= amount;
				break;
			}
			debuff.invertUsed();
			return *this;
		}
		*/
		/*
		int getHealth()
		{
			return health;
		}
		
		int getWillpower()
		{
			return willpower;
		}
		
		int getMaxHealth()
		{
			return maxHealth;
		}
		
		int getMaxWillpower()
		{
			return maxWillpower;
		}
		
		std::string toStringHealth()
		{
			std::string healthString = std::to_string(health);
			std::string maxHealthString = std::to_string(maxHealth);
			std::string outputString = "Health: " + healthString + "/" + maxHealthString;
			return outputString;
		}
		
		std::string toStringWillpower()
		{
			std::string willpowerString = std::to_string(willpower);
			std::string maxWillpowerString = std::to_string(maxWillpower);
			std::string outputString = "Willpower: " + willpowerString + "/" + maxWillpowerString;
			return outputString;
		}
	
	}
	*/






//function to add ability
	void addAbility(int ID, AbilityList abilities)
	{

		abilities.displayAndGetAbility(race, level, ID);


		if (ID <= 30)
		{
			powers.push_back(abilities.findDamageAbility(race, ID));
		}
		/*
		else if (ID <= 60)
		{
			buffs.push_back(abilities.findBuffAbility(race, ID));
		}
		else if (ID <= 90)
		{
			debuffs.push_back(abilities.findDebuffAbility(race, ID));
		}
		else
		{
			passives.push_back(abilities.findPassiveAbility(race, ID));
		}
		*/
	}
	/*
	void addItem(int ID, itemList itemList)
	{
		
		if (ID <= 3)
		{
			buffItem temp;
			temp = itemList.findBuffItem(ID);
			buffItems.push_back(temp);
		}
		else if (ID > 3 && ID <= 6)
		{
			debuffItem temp;
			temp = itemList.findDebuffItem(ID);
			debuffItems.push_back(temp);
		}
		
		if (ID <= 3)
		{
			regenItem temp;
			temp = itemList.findRegenItem(ID);
			regenItems.push_back(temp);
		}
		else
		{
			weaponItem temp = weaponItem("", 0);
			temp = itemList.findWeaponItem(ID);
			weapons.push_back(temp);
		}
	}
	*/
	
	

	//function to see if the character is still alive
	void setIsAlive()
	{
		if (health <= 0)
		{
			isAlive = false;
		}
		else
		{
			isAlive = true;
		}
	}

	//function to check is alive
	bool checkIsAlive()
	{
		return isAlive;
	}
	//function to use a weapon
	void useWeapon(BasicEnemy& ghoul)
	{
		int choice;
		std::cout << "Choose a weapon to use:\n";
		int counter = 1;
		int i = 0;
		for (i; i < weapons.size(); i++)
		{
			std::cout << counter << ". ";
			weapons[i].displayWeapon();
			counter++;
		}
		choice = getValidInt("Make your choice: ", 1, (weapons.size()));
		choice = choice - 1;
		ghoul.setHealth(ghoul.takeDamage(weapons[choice]));
		std::cout << "You hit the ghoul! Health remaining:" << ghoul.toStringHealth() << std::endl;
		
	}

	//function to use an ability
	void useAbility(BasicEnemy& ghoul)
	{
		int choice;
		std::cout << "Choose an ability to use:\n";
		int counter = 1;
		int i = 0;
		for (i; i < powers.size(); i++)
		{
			std::cout << counter << ". ";
			powers[i].displayAbility();
			counter++;
		}
		choice = getValidInt("Make your choice: ", 1, powers.size());
		choice = choice - 1;
		ghoul.setHealth(ghoul.takeDamageAbility(powers[choice]));
		std::cout << "You hit the ghoul! Health remaining:" << ghoul.toStringHealth() << std::endl;

	}



	//function to use a weapon against a final boss type
	void useWeaponFinal(FinalBoss& ghoul)
	{
		int choice;
		std::cout << "Choose a weapon to use:\n";
		int counter = 1;
		int i = 0;
		for (i; i < weapons.size(); i++)
		{
			
			std::cout << counter << ". ";
			weapons[i].displayWeapon();
			counter++;
		}
		choice = getValidInt("Make your choice: ", 1, weapons.size());
		choice = choice - 1;
		ghoul.setHealth(ghoul.takeDamage(weapons[choice]));
		std::cout << "You hit the ghoul!"  << ghoul.toStringHealth() << std::endl;

	}
	//function to use an ability against a final boss typoe
	void useAbilityFinal(FinalBoss& ghoul)
	{
		int choice;
		std::cout << "Choose an ability to use:\n";
		int counter = 1;
		int i = 0;
		for (i; i < powers.size(); i++)
		{
			std::cout << counter << ". ";
			powers[i].displayAbility();
			counter++;
		}
		choice = getValidInt("Make your choice: ", 1, powers.size());
		choice = choice - 1;
		ghoul.setHealth(ghoul.takeDamageAbility(powers[choice]));;
		std::cout << "You hit the George!" << ghoul.toStringHealth() << std::endl;

	}


	//function to take damage
	void takeDamage(weaponItem weapon)
	{
		health -= weapon.getDamage();
	}


	//function to chose an action  to do against a basic enemy
	void doAction(BasicEnemy& ghoul)
	{
		int choice = 0;
		std::cout << "What would you like to do?\n";
		std::cout << "1. Use a Weapon\n";
		std::cout << "2. Use an ability.\n";
		std::cout << "3. Use an item\n";
		choice = getValidInt("Make your choice: ", 1, 3);
		switch (choice)
		{
		case 1:
			useWeapon(ghoul);
			break;
		case 2:
			useAbility(ghoul);
			break;
		case 3:
			if (regenItems.size() > 0);
			{
				std::cout << "Choose an item:\n";
				int counter = 1;
				for (int i = 0; i < regenItems.size(); i++)
				{
					std::cout << counter << ". ";
					regenItems[i].displayItem();
				}
				choice = getValidInt("Make your choice: ", 1, (regenItems.size() + 1));
				choice -= 1;
				int regenAmount = regenItems[choice].getAddAmount();
				if ((health + regenAmount) > maxHealth)
				{
					health = maxHealth;
				}
				else
				{
					health += regenAmount;
				}
			}
			if (regenItems.size() <= 0)
			{
				std::cout << "You have no items!\n";
			}
			break;
		}
	}
	//function to do an action against a final boss
	void doActionFinal(FinalBoss& ghoul)
	{
		int choice;
		std::cout << "What would you like to do?\n";
		std::cout << "1. Use a Weapon\n";
		std::cout << "2. Use an ability.\n";
		std::cout << "3. Use an item\n";
		choice = getValidInt("Make your choice: ", 1, 3);
		int i = 0;

		switch (choice)
		{
		case 1:
			useWeaponFinal(ghoul);
			break;
		case 2:
			useAbilityFinal(ghoul);
			break;
		case 3:
			if (regenItems.size() > 0);
			{
				std::cout << "Choose an item:\n";
				int choice;
				int counter = 1;
				for (i; i < regenItems.size(); i++)
				{
					std::cout << counter << ". ";
					regenItems[i].displayItem();

				}
				choice = getValidInt("Make your choice: ", 1, (regenItems.size() + 1));
				choice -= 1;
				int regenAmount = regenItems[choice].getAddAmount();
				if ((health + regenAmount) > maxHealth)
				{
					health = maxHealth;
				}
				else
				{
					health += regenAmount;
				}
				break;
			}
		}
	}



	//level up function
	void levelUp(AbilityList listAbilities)
	{
		std::cout << "You leveled up!\n";
		health = health + 1;
		maxHealth = maxHealth + 1;
		int choice;
		level = level + 1;
		if(level < 11)
		{
			listAbilities.displayAndGetAbility(race, level, choice);
		}
		addAbility(choice, listAbilities);
	}


	//add items and weapons
	void addItem(regenItem& item)
	{
		regenItems.push_back(item);
	}

	void addWeapon(weaponItem& item)
	{
		weapons.push_back(item);
	}

};
