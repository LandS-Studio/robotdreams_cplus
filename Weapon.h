#pragma once
#include <iostream>

class AWeapon {
public:
	AWeapon();
	~AWeapon();

	float GetDamage() const;
	std::string GetName();

protected:
	void initDamage(float damageValue);
	void initName(std::string name);

private:
	float weaponDamage;
	std::string weaponName;

};

class MeleeWeapon : public AWeapon {
public:
	MeleeWeapon() {
		initDamage(1.f);
		initName("Melee Weapon");
	};
};

class Knife : public AWeapon {
public:
	Knife() {
		initDamage(2.f);
		initName("Knife");
	};
};

class RangeWeapon : public AWeapon {
public:
	RangeWeapon() {
		initDamage(3.f);
		initName("Range Weapon");
	};
};

class Pistol : public RangeWeapon {
public:
	Pistol() {
		initDamage(5.f);
		initName("Pistol");
	};
};

class AssaultRifle : public RangeWeapon {
public:
	AssaultRifle() {
		initDamage(6.f);
		initName("Assault Rifle");
	};
};

class SniperRifle : public RangeWeapon {
public:
	SniperRifle() {
		initDamage(8.f);
		initName("Sniper Rifle");
	};
};


