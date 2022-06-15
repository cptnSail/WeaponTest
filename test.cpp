#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;


class Weapon
{
public:
	virtual void Use() = 0;

	virtual string ToView() = 0;

	void Drop()
	{
		cout << "You dropped out a weapon\n" << endl;
	}

};


class Dagger : public Weapon
{
	void Use() override
	{
		cout << "Piercing Melee Damage!\n" << endl;
	}

	string ToView() override
	{
		return "Dagger";
	}
};

class Bow : public Weapon
{
	void Use() override
	{
		cout << "Piercing Range Damage!\n" << endl;
	}

	string ToView() override
	{
		return "Bow";
	}

};

class MagicStick : public Weapon
{
	void Use() override
	{
		cout << "FIREBALL!!!\n" << endl;
	}

	string ToView() override
	{
		return "Magic Stick";
	}

};

class Hero
{
public:
	Hero() { cout << "You don't have any weapon. Find something!\n" << endl; }

	Hero(Weapon* wpn) { 
		inventory.push_back(wpn); 

		ptr = inventory.begin();
	}

	void PickUpTheWeapon(Weapon* wpn)
	{
		cout << "You found something!\n" << endl;

		if (inventory.size() == MaxSlot)
			cout << "But inventory is full!\n" << endl;
		else if (inventory.empty()){
			inventory.push_back(wpn);

			ptr = inventory.begin();
		}
		else {
			inventory.push_back(wpn);
		}


	}

	void Use()
	{
		if (inventory.size())
		{
			(*ptr)->Use();
		}
		else
		{
			cout << "You don't have any weapon. Find something!\n" << endl;
		}
	}

	void DropTheWeapon()
	{
		if (!inventory.empty())
		{
			(*ptr)->Drop();

			inventory.erase(ptr);

			SwapTheWeapon(1);
		}
		else
		{
			cout << "You don't have any weapon. Find something!\n" << endl;
		}
	}

	void SwapTheWeapon(int slot)
	{
		if (inventory.size() > 1)
		{
			ptr = (inventory.begin() + --slot);
		}
	}

	void InventoryView()
	{
		cout << "You open the backpack and see..." << endl;

		for (int i = 0; i < (int)inventory.size(); ++i)
		{
			cout << inventory[i]->ToView() << "\t";
		}
	
		cout << endl << endl;
	}


private:
	vector<Weapon*> inventory;
	vector<Weapon*>::iterator ptr;

	const int MaxSlot = 4;
};




int main()
{
	setlocale(LC_ALL, "rus");

	Dagger dgr;
	Bow bw;
	MagicStick stick;

	Hero Lol(&stick), Chel(&stick);

	Lol.Use();

	Lol.DropTheWeapon();

	Lol.PickUpTheWeapon(&dgr);
	Lol.PickUpTheWeapon(&bw);
	Lol.PickUpTheWeapon(&stick);

	Lol.SwapTheWeapon(2);

	Lol.InventoryView();

	//Lol.PickUpTheWeapon(&bw);

	Lol.Use();


	/*fstream test;

	try
	{
		test.open("�haracter.txt", fstream::in | fstream::out | fstream::app);

		test.read((char*)&Chel, sizeof(Hero));

		test.close();
	}
	catch (const fstream::failure& fuck)
	{
		test.close();

		cout << "�� �����!!" << endl;
		cout << fuck.what() << endl;
		cout << fuck.code() << endl;
	}*/

	return 0; 
}