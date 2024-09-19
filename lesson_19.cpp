#include "lesson_19.h"
#include "Character.h"

void StartHomework_19(){

	int commandID = -1;
	ACharacter playerPawn;
	std::cout << "PLAYER CREATED\n";
	
	while (commandID != 0) {
		std::cout << "ENTER THE COMMAND\n" << "1 - create and pickup new weapon\n" << "2 - equip weapon\n" << "3 - unequip weapon\n" << "4 - swap weapon\n" << "5 - drop weapon\n" << "0 - quit\n";
		std::cout << std::endl;
		std::cin >> commandID;

		if (commandID == 1) {

			int weaponID = -1;
			std::cout << "ENTER THE WEAPON ID:\n" << "1 - Knife:\n" << "2 - Pistol:\n" << "3 - Assault rifle:\n" << "4 - Sniper rifle:\n\n";
			std::cin >> weaponID;
			if (weaponID >= 1 && weaponID <= 4) {
				int weaponSlot = -1;
				std::cout << "ENTER THE WEAPON SLOT (1 or 2): ";
				std::cin >> weaponSlot;
				if (weaponSlot == 1 || weaponSlot == 2) {
					if (weaponID == 1) {
						std::unique_ptr<Knife> newWeapon(new Knife);
						playerPawn.SetWeapon(weaponSlot, std::move(newWeapon));
					}
					else if (weaponID == 2) {
						std::unique_ptr<Pistol> newWeapon(new Pistol);
						playerPawn.SetWeapon(weaponSlot, std::move(newWeapon));
					}
					else if (weaponID == 3) {
						std::unique_ptr<AssaultRifle> newWeapon(new AssaultRifle);
						playerPawn.SetWeapon(weaponSlot, std::move(newWeapon));
					}
					else if (weaponID == 4) {
						std::unique_ptr<SniperRifle> newWeapon(new SniperRifle);
						playerPawn.SetWeapon(weaponSlot, std::move(newWeapon));
					}
				}
				else {
					std::cout << "ERR:Enter the correct SLOT value (1 or 2)\n";
				}
			}
			else {
				std::cout << "ERR:Enter the correct ID value (1-4)\n";
			}

		} 
		else if (commandID == 2) {
			if (playerPawn.GetCurrentWeapon()) {
				if (playerPawn.GetWeaponInSlot(1) && playerPawn.GetWeaponInSlot(2)) {
					std::cout << "WARNING:Current weapon are already valid.\n";
					std::cout << "WARNING:All weapon slots are occupied\n";
					int weaponSlot = -1;
					std::cout << "ENTER THE SLOT YOU WANT TO SWAP (1 or 2): ";
					std::cin >> weaponSlot;
					if (weaponSlot == 1 || weaponSlot == 2) {
						playerPawn.SwapWeapon(weaponSlot);
					}
					else {
						std::cout << "ERR:Enter the correct SLOT value (1 or 2)\n";
					}
				}
				else if (playerPawn.GetWeaponInSlot(1)) {
					std::cout << "WARNING:Current weapon are already valid.\n";
					playerPawn.SwapWeapon(1);
				}
				else if (playerPawn.GetWeaponInSlot(2)) {
					std::cout << "WARNING:Current weapon are already valid.\n";
					playerPawn.SwapWeapon(2);
				}
				else {
					std::cout << "WARNING:No weapons for swap.\n\n";
				}
			}
			else {
				if (playerPawn.GetWeaponInSlot(1) && playerPawn.GetWeaponInSlot(2)) {
					int weaponSlot = -1;
					std::cout << "ENTER THE WEAPON SLOT (1 or 2): ";
					std::cin >> weaponSlot;
					if (weaponSlot == 1 || weaponSlot == 2) {
						playerPawn.EquipWeapon(weaponSlot);
					}
					else {
						std::cout << "ERR:Enter the correct SLOT value (1 or 2)\n";
					}
				}
				else if (playerPawn.GetWeaponInSlot(1)) {
					playerPawn.EquipWeapon(1);
				}
				else if (playerPawn.GetWeaponInSlot(2)) {
					playerPawn.EquipWeapon(2);
				}
				else {
					std::cout << "WARNING:No weapons for equip.\n\n";
				}
			}
		}
		else if (commandID == 3) {

			playerPawn.UnequipWeapon();

		}
		else if (commandID == 4) {

			if (playerPawn.GetCurrentWeapon()) {

				if (playerPawn.GetWeaponInSlot(1) && playerPawn.GetWeaponInSlot(2)) {
					int weaponSlot = -1;
					std::cout << "ENTER THE SLOT YOU WANT TO SWAP (1 or 2): ";
					std::cin >> weaponSlot;
					if (weaponSlot == 1 || weaponSlot == 2) {
						playerPawn.SwapWeapon(weaponSlot);
					}
					else {
						std::cout << "ERR:Enter the correct SLOT value (1 or 2)\n";
					}
				}
				else if (playerPawn.GetWeaponInSlot(1)) {
					playerPawn.SwapWeapon(1);
				}
				else if (playerPawn.GetWeaponInSlot(2)) {
					playerPawn.SwapWeapon(2);
				}
				else {
					std::cout << "WARNING:No weapons for swap.\n\n";
				}
			}
			else {
				std::cout << "WARNING:Current weapon not valid for swap.\n\n";
			}
	
		}
		else if (commandID == 5) {

			if (playerPawn.GetCurrentWeapon() || playerPawn.GetWeaponInSlot(1) || playerPawn.GetWeaponInSlot(2)) {
				int weaponSlot = -1;
				std::cout << "ENTER THE WEAPON SLOT (1 or 2 or 3):\n" << "1 - primary weapon\n" << "2 - secondary weapon\n" << "3 - current weapon in hand\n\n";
				std::cin >> weaponSlot;
				if (weaponSlot >= 1 && weaponSlot <= 3) {
					playerPawn.DropWeapon(weaponSlot);
				}
				else {
					std::cout << "ERR:Enter the correct SLOT value (1 or 2 or 3)\n";
				}
			}
			else {
				std::cout << "WARNING:No weapons for drop.\n\n";
			}

		}
		else if (commandID == 0) {
			return;
		}
		else {
			std::cout << "ERR:Enter the correct command\n";
		}

		if (playerPawn.GetWeaponInSlot(1)) {
			std::cout << "MSG:Primary Weapon: " << playerPawn.GetWeaponInSlot(1)->GetName() << std::endl;
		}
		else {
			std::cout << "MSG:Primary Weapon: NULL\n";
		}

		if (playerPawn.GetWeaponInSlot(2)) {
			std::cout << "MSG:Secondary Weapon: " << playerPawn.GetWeaponInSlot(2)->GetName() << std::endl;
		}
		else {
			std::cout << "MSG:Secondary Weapon: NULL\n";
		}

		if (playerPawn.GetCurrentWeapon()) {
			std::cout << "MSG:Current Weapon: " << playerPawn.GetCurrentWeapon()->GetName() << std::endl;
		}
		else {
			std::cout << "MSG:Current Weapon: NULL\n";
		}
		std::cout << std::endl;

		commandID = -1;
	}
}
