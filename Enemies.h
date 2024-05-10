#pragma once
#include "CharacterClass.h"
#include "ItemClass.h"
#include "PlayerCharacterClass.h"
#include "AbilityClass.h"


//creation of basic enemey
class BasicEnemy : public Character
{
public:
	weaponItem enemyWeapon = weaponItem("claws", 1);
	bool isAlive;



	//basic enemey constructor
	BasicEnemy()
	{
		name = "Feral Ghoul";
		health = 1;
		enemyWeapon.setDamage(1);
		enemyWeapon.setName("Claws");
	}

	std::string getName()
	{
		return name;
	}


	Character& operator++(int stat)
	{
		switch (stat)
		{
		case 1:
			health++;
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
	*/

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

	void setName(std::string input)
	{
		name = input;
	}

	void setHealth(int var)
	{
		health = var;
	}
	int setMaxHealth(int var)
	{
		maxHealth = var;
	}

	void setWeapon(std::string nameinput, int damageinput)
	{
		enemyWeapon = weaponItem(nameinput, damageinput);
	}

	/*
	std::string toStringHealth()
	{
		std::string healthString = std::to_string(health);
		std::string maxHealthString = std::to_string(maxHealth);
		std::string outputString = " Health: " + healthString + "/" + maxHealthString;
		return outputString;
	}
	*/
	/*
	std::string toStringWillpower()
	{
		std::string willpowerString = std::to_string(willpower);
		std::string maxWillpowerString = std::to_string(maxWillpower);
		std::string outputString = "Willpower: " + willpowerString + "/" + maxWillpowerString;
		return outputString;
	}
	*/
	weaponItem getWeapon()
	{
		return enemyWeapon;
	}


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


	bool checkIsAlive()
	{
		return isAlive;
	}

	int takeDamage(weaponItem weapon)
	{
		int damage = health - weapon.getDamage();

		return damage;
	}





	int takeDamageAbility(damageAbility ability)
	{
		int damage = health - ability.getDamage();

		return damage;
	}
};











//final boss delaraation
class FinalBoss : public Character
{
protected:
	weaponItem enemyWeapon = weaponItem("shovel", 2);
	bool isAlive;
public:
	FinalBoss()
	{
		name = "George of the Tombs";
		health = 10;
		enemyWeapon.setDamage(2);
		enemyWeapon.setName("Shovel");
	}



	void setName(std::string input)
	{
		name = input;
	}

	void setHealth(int var)
	{
		health = var;
	}

	void setWeapon(std::string nameinput, int damageinput)
	{
		enemyWeapon = weaponItem(nameinput, damageinput);
	}



	int takeDamage(weaponItem weapon)
	{
		int damage = health - weapon.getDamage();

		return damage;
	}


	/*
	Character& operator++(int stat)
	{
		switch (stat)
		{
		case 1:
			health++;
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
	*/
	/*/
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
	*/

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
	/*
	std::string toStringHealth()
	{
		std::string healthString = std::to_string(health);
		std::string maxHealthString = std::to_string(maxHealth);
		std::string outputString = "Health: " + healthString + "/" + maxHealthString;
		return outputString;
	}
	*/
	/*
	std::string toStringWillpower()
	{
		std::string willpowerString = std::to_string(willpower);
		std::string maxWillpowerString = std::to_string(maxWillpower);
		std::string outputString = "Willpower: " + willpowerString + "/" + maxWillpowerString;
		return outputString;
	}
	*/


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


	bool checkIsAlive()
	{
		return isAlive;
	}

	int setMaxHealth(int var)
	{
		maxHealth = var;
	}

	weaponItem getWeapon()
	{
		return enemyWeapon;
	}


	int takeDamageAbility(damageAbility ability)
	{
		int damage = health - ability.getDamage();

		return damage;
	}
};


