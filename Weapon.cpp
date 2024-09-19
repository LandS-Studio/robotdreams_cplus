#include "Weapon.h"

AWeapon::AWeapon(){
	weaponDamage = 5.f;
	weaponName = "BaseWeapon";
	std::cout << "Weapon acquired\n";
}

AWeapon::~AWeapon(){
	std::cout << "Weapon destroyed\n";
}

float AWeapon::GetDamage() const{
	return weaponDamage;
}

std::string AWeapon::GetName(){
	return weaponName;
}

void AWeapon::initDamage(float damageValue){
	weaponDamage = damageValue;
}

void AWeapon::initName(std::string name){
	weaponName = name;
}
