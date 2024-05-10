#pragma once
#include <string>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <iostream>
#include "ItemClass.h"
#include "AbilityClass.h"




class Actor
{
protected:

};


//character class
class Character : Actor
{
public:
	std::string name;
	int health;
	int maxHealth;
	//int speed;
	//int willpower;
	//int maxWillpower;
	//int intelligence;
	//int charisma;
	bool isAlive = true;


	void addHealth()
	{
		health = health + 1;
		maxHealth = health + 1;
	}


	Character& operator++(int stat)
	{
		switch (stat)
		{
		case 1:
			addHealth();
			break;
			/*
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
			*/
		}

		return *this;

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
			/*
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

		*/
		}
		regen.invertUsed();
		return *this;
	}
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
	*/

	/*
	void takeDamage(weaponItem weapon)
	{
		health -= weapon.getDamage();
	}


	Character& operator - (weaponItem weapon)
	{
		
		takeDamage(weapon);
		
		
		
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

	*/
	/*
	Character& operator - (damageAbility& damageAb)
	{
		 health -= damageAb.getDamage();
		
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
	*/

	/*
	/*
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
	int getHealth()
	{
		return health;
	}
	/*
	int getWillpower()
	{
		return willpower;
	}
	*/
	int getMaxHealth()
	{
		return maxHealth;
	}
	/*
	int getMaxWillpower()
	{
		return maxWillpower;
	}
	*/
	std::string toStringHealth()
	{
		std::string healthString = std::to_string(health);
		std::string maxHealthString = std::to_string(maxHealth);
		std::string outputString = "Health: " + healthString + "/" + maxHealthString;
		return outputString;
	}
	/*
	std::string toStringWillpower()
	{
		std::string willpowerString = std::to_string(willpower);
		std::string maxWillpowerString = std::to_string(maxWillpower);
		std::string outputString = "Willpower: " + willpowerString + "/" + maxWillpowerString;
		return outputString;
	}
	*/
};