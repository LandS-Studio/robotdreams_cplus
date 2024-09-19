#pragma once
#include <iostream>
#include <memory>

#include "Weapon.h"

class ACharacter {
public:
	ACharacter();
	~ACharacter();

	void SetWeapon(int weaponSlot, std::unique_ptr<AWeapon> weapon);
	void DropWeapon(int weaponSlot);
	void EquipWeapon(int weaponSlot);
	void UnequipWeapon();
	void SwapWeapon(int weaponSlot);

	AWeapon* GetWeaponInSlot(int weaponSlot) const;
	AWeapon* GetCurrentWeapon() const;

private:
	std::unique_ptr<AWeapon> primaryWeapon;
	std::unique_ptr<AWeapon> secondaryWeapon;

	std::unique_ptr<AWeapon> currentWeapon;

};
