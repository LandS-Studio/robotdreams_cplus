#include "Character.h"

ACharacter::ACharacter(){

}

ACharacter::~ACharacter(){

}

void ACharacter::SetWeapon(int weaponSlot, std::unique_ptr<AWeapon> weapon){

	if (weapon) {
		if (weaponSlot == 1) {
			primaryWeapon = std::move(weapon);
		} else if (weaponSlot == 2) {
			secondaryWeapon = std::move(weapon);
		}
	}
	
}

void ACharacter::DropWeapon(int weaponSlot){
	if (weaponSlot == 1) {
		if (GetWeaponInSlot(1)) {
			primaryWeapon.reset();
			std::cout << "MSG:Primary weapon are dropped.\n\n";
		}
		else {
			std::cout << "WARNING:Primary weapon are not valid for drop.\n\n";
		}
	}
	else if (weaponSlot == 2) {
		if (GetWeaponInSlot(2)) {
			secondaryWeapon.reset();
			std::cout << "MSG:Secondary weapon are dropped.\n\n";
		}
		else {
			std::cout << "WARNING:Secondary weapon are not valid for drop.\n\n";
		}
	}
	else if (weaponSlot == 3) {
		if (GetCurrentWeapon()) {
			currentWeapon.reset();
			std::cout << "MSG:Current weapon are dropped.\n\n";
		}
		else {
			std::cout << "WARNING:Current weapon are not valid for drop.\n\n";
		}
	}
}

void ACharacter::EquipWeapon(int weaponSlot){
	if (weaponSlot == 1) {
		currentWeapon = std::move(primaryWeapon);
		std::cout << "MSG:Primary weapon are equipped.\n\n";
	}
	else if (weaponSlot == 2) {
		currentWeapon = std::move(secondaryWeapon);
		std::cout << "MSG:Secondary weapon are equipped.\n\n";
	}
}

void ACharacter::UnequipWeapon(){
	if (GetCurrentWeapon()) {
		if (primaryWeapon.get() == nullptr) {
			primaryWeapon = std::move(currentWeapon);
			std::cout << "MSG:Current weapon are unequipped in primary slot.\n\n";
		}
		else if (secondaryWeapon.get() == nullptr) {
			secondaryWeapon = std::move(currentWeapon);
			std::cout << "MSG:Current weapon are unequipped in secondary slot.\n\n";
		}
		else {
			std::cout << "WARNING:Primary and Secondary slots are occupied. We can't unequip weapon.\n\n";
		}
	}
	else {
		std::cout << "WARNING:Current weapon not valid for unequip.\n\n";

	}
}

void ACharacter::SwapWeapon(int weaponSlot){
	if (GetCurrentWeapon()) {
		if (GetWeaponInSlot(weaponSlot)) {
			std::unique_ptr<AWeapon> tempWeapon;
			tempWeapon = std::move(currentWeapon);
			if (weaponSlot == 1) {
				currentWeapon = std::move(primaryWeapon);
				primaryWeapon = std::move(tempWeapon);
				std::cout << "MSG:Current weapon are swapped with the primary weapon.\n\n";
			}
			else if (weaponSlot == 2) {
				currentWeapon = std::move(secondaryWeapon);
				secondaryWeapon = std::move(tempWeapon);
				std::cout << "MSG:Current weapon are swapped with the secondary weapon.\n\n";
			}
		}
		else {
			std::cout << "WARNING:Primary and Secondary weapons not valid for swap.\n\n";
		}
	}
	else {
		std::cout << "WARNING:Current weapon not valid for swap.\n\n";
	}
}

AWeapon* ACharacter::GetWeaponInSlot(int weaponSlot) const {

	if (weaponSlot == 1) {
		return primaryWeapon.get();
	}
	else if (weaponSlot == 2) {
		return secondaryWeapon.get();
	}
}

AWeapon* ACharacter::GetCurrentWeapon() const{

	return currentWeapon.get();
}
