#pragma once
#include <string>



//creation of Ability super class
class Ability
{
protected:
	std::string name;
};

//class damage ability
class damageAbility : Ability
{
protected:
	int abilityType = 0;
	int damage;
	int cooldown;
public:
	void setName(std::string string)
	{
		name = string;
	}
	void setDamage(int var)
	{
		damage = var;
	}
	void setCooldown(int var)
	{
		cooldown = var;
	}
	std::string getName()
	{
		return name;
	}

	int getDamage()
	{
		return damage;
	}

	void displayAbility()
	{
		std::cout << name << " - Damage: " << damage << " - Cooldown: " << cooldown << std::endl;
	}

};
//unused abilities
/*
class buffAbility : Ability
{
protected:
	int abilityType = 1;
	float buffAmount;
	int buffStat;
	int turnAmount;
public:
	void setName(std::string string)
	{
		name = string;
	}
	void setAmount(float var)
	{
		buffAmount = var;
	}
	void setStat(int var)
	{
		buffStat = var;
	}
	void setTurn(int var)
	{
		turnAmount = var;
	}

	std::string getName()
	{
		return name;
	}

	std::string getBuffType()
	{
		switch (buffStat)
		{
		case 1:
			return "Health Buff";
		case 2:
			return "Damage Buff";
		case 3:
			return "Willpower Buff";
		}
	}
	
	int getAmount()
	{
		return buffAmount;
	}

	int getTurns()
	{
		return turnAmount;
	}


};
class debuffAbility : Ability
{
protected:
	int abilityType = 2;
	float debuffAmount;
	int debuffStat;
	int turnAmount;
public:
	void setName(std::string string)
	{
		name = string;
	}
	void setAmount(float var)
	{
		debuffAmount = var;
	}
	void setStat(int var)
	{
		debuffStat = var;
	}
	void setTurn(int var)
	{
		turnAmount = var;
	}
	std::string getName()
	{
		return name;
	}

	std::string getBuffType()
	{
		switch (debuffStat)
		{
		case 1:
			return "Health Buff";
		case 2:
			return "Damage Buff";
		case 3:
			return "Willpower Buff";
		}
	}

	int getAmount()
	{
		return debuffAmount;
	}

	int getTurns()
	{
		return turnAmount;
	}

};
class passiveAbility : Ability
{
protected:
	int abilityType = 3;
	int passiveEffect;
public:
	void setName(std::string string)
	{
		name = string;
	}
	void setEffect(float var)
	{
		passiveEffect = var;
	}
	std::string getName()
	{
		return name;
	}
	std::string getEffect()
	{
		switch (passiveEffect)
		{
		default:
			return "(This was supposed to be the Passive Buffs, examples include health regen, discovery rate, etc... it's out of my scope).";
		}
	}
	
};
*/






