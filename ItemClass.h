#pragma once
#include <string>
#include <iostream>
#include <iomanip>

class Item
{
public:
	std::string name;
};

class Consumable : public Item
{
public:
	std::string name;
	bool used;
	
	
	virtual void invertUsed() = 0;
};




class regenItem : public Consumable
{
protected:
	int addAmount;
	int statVar;
public:
	int getStatVar()
	{
		return statVar;
	}
	float getAddAmount()
	{
		return addAmount;
	}
	void invertUsed()
	{
		used = !used;
	}
	void setName(std::string string)
	{
		name = string;
	}
	void setAdd(int var)
	{
		addAmount = var;
	}
	void setStat(int var)
	{
		statVar = var;
	}
	void displayItem()
	{
		std::cout << name << " - Regen Amount: " << addAmount << std::endl;
	}


	/*
	class buffItem : Consumable
	{
	protected:
		int buffTarget;
		int statBuff;
		float buffAmount;
		int turnAmount;
	public:
		int getTarget()
		{
			return buffTarget;
		}
		int getStat()
		{
			return statBuff;
		}
		float getAmount()
		{
			return buffAmount;
		}
		int getTurns()
		{
			return turnAmount;
		}
		void invertUsed()
		{
			used = !used;
		}
		void setName(std::string string)
		{
			name = string;
		}
		void setTarget(int var)
		{
			buffTarget = var;
		}
		void setStat(int var)
		{
			statBuff = var;
		}
		void setAmount(int var)
		{
			buffAmount = var;
		}
		void setTurns(int var)
		{
			turnAmount = var;
		}


	};
	*/
	/*
	class debuffItem : Consumable
	{
	protected:
		int debuffTarget;
		//int statDebuff;
		//float debuffAmount;
		//int turnAmount;
	public:
		int getTarget()
		{
			return debuffTarget;
		}


		int getStat()
		{
			return statDebuff;
		}
		float getAmount()
		{
			return debuffAmount;
		}
		int getTurns()
		{
			return turnAmount;
		}

		void invertUsed()
		{
			used = !used;
		}

		void setName(std::string string)
		{
			name = string;
		}
		void setTarget(int var)
		{
			debuffTarget = var;
		}

		void setStat(int var)
		{
			statDebuff = var;
		}
		void setAmount(int var)
		{
			debuffAmount = var;
		}
		void setTurns(int var)
		{
			turnAmount = var;
		}


	};
	*/
};

class weaponItem : public Item
{
protected:
	int damage = 1;
public:
	weaponItem(std::string nameInput, int damageInput)
	{
		name = nameInput;
		damage = damageInput;
	}



	int getDamage()
	{
		return damage;
	}
	std::string getName()
	{
		return name;
	}
	void setName(std::string string)
	{
		name = string;
	}
	void setDamage(int var)
	{
		damage = var;
	}

	void displayWeapon()
	{
		std::cout << getName() << " - Damage: " << getDamage() << std::endl;
	}
};

/*
class meleeWeapon : weaponItem
{
protected:
	int damageType = 0;
public:
	void setName(std::string string)
	{
		name = string;
	}
	void setDamage(int var)
	{
		damage = var;
	}
};


class rangedWeapon : weaponItem
{
protected:
	int damageType = 1;
public:
	void setName(std::string string)
	{
		name = string;
	}
	void setDamage(int var)
	{
		damage = var;
	}
};

class mysticWeapon : weaponItem
{
protected:
	int damageType = 2;
public:
	void setName(std::string string)
	{
		name = string;
	}
	void setDamage(int var)
	{
		damage = var;
	}
};

class consumableWeapon : weaponItem, Consumable
{
protected:
	std::string name;
	int damageType;
public:
	void setName(std::string string)
	{
		name = string;
	}
	void setDamage(int var)
	{
		damage = var;
	}
	void invertUsed()
	{
		used = !used;
	}
};
	*/
