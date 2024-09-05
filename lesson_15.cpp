#include "lesson_15.h"

std::vector<FUnitInfo> combatLobby;

void StartHomework_15() {

	int commandID = -1;
	combatLobby.reserve(10);

	//Перевірка введення команди 2 "Розпочати бій"
	//Можна безкінечно додавати/видаляти юнітів
	//Бій розрахується тільки один раз
	while (commandID != 2) {

		std::cout << "Enter command ID (0/1/2): ";
		std::cin >> commandID;
		std::cout << std::endl;

		switch (commandID) {

		case 0:
			AddUnitToCombat();
			break;

		case 1:
			RemoveUnitFromCombat();
			break;

		case 2:
			//Якщо хочаб в одній команді 0 юнітів, бій не можна розпочати
			if (GetCanStartCombat(combatLobby)) {
				StartCombat();
			} 
			else {
				std::cout << "WARNING:Not enough units for the battle!" << std::endl;
				std::cout << "Units Clan '0': " << GetUnitAmountByClanID(0) << std::endl;
				std::cout << "Units Clan '1': " << GetUnitAmountByClanID(1) << std::endl;
				commandID = -1;
			}
			break;

		default:
			break;
		}
	}
}

void AddUnitToCombat() {

	FUnitInfo addUnitInfo;
	int addClanID = -1;

	std::cout << "=ADD UNIT TO COMBAT=" << std::endl;
	std::cout << "Enter unit name: ";
	std::cin >> addUnitInfo.UnitName;

	//Перевірка коректного вводу Clan ID за умовою клан-тег 0 або 1
	while (addClanID != 0 && addClanID != 1) {
		std::cout << "Enter clan ID (0/1): ";
		std::cin >> addClanID;
	}

	addUnitInfo.ClanID = addClanID;
	std::cout << "Enter unit health: ";
	std::cin >> addUnitInfo.UnitHealth;
	std::cout << "Enter unit damage: ";
	std::cin >> addUnitInfo.UnitDamage;
	std::cout << std::endl;

	combatLobby.push_back(addUnitInfo);

}

void RemoveUnitFromCombat() {
	
	std::cout << "=REMOVE UNIT FROM COMBAT=" << std::endl;
	//Перевірка наявності хочаб одного юніта в клані по Clan ID 0 або 1
	if (GetUnitAmountByClanID(0) > 0 || GetUnitAmountByClanID(1) > 0) {
		int removeClanID = -1;
		std::string removeUnitName = "";
		while (removeClanID != 0 && removeClanID != 1) {
			std::cout << "Enter clan ID (0/1): ";
			std::cin >> removeClanID;
			if (GetUnitAmountByClanID(removeClanID) < 1) {
				std::cout << "WARNING:Missing units this clanID in the lobby" << std::endl;
				return;
			}
		}
		std::cout << "Enter unit name: ";
		std::cin >> removeUnitName;

		for (int i = 0; i < combatLobby.size(); ++i) {
			//Перевіряємо чи є у вказаному клані юніт з вказаним ім'ям
			//Якщо ім'я присутнє, ми видаляємо юніта з лоббі
			if (combatLobby[i].ClanID == removeClanID && combatLobby[i].UnitName == removeUnitName) {
				std::vector<FUnitInfo>::iterator localIterator = combatLobby.begin() + i;
				combatLobby.erase(localIterator);
				std::cout << "UNIT REMOVED" << std::endl;
			}
			//Якщо ім'я відсутнє, ми виводимо всі доступні імена юнітів у вказаному клані
			else {
				std::cout << "WARNING:Unit name invalid" << std::endl;
				std::cout << "WARNING:All units name clan '" << removeClanID << "' " << "{";
				for (FUnitInfo localUnitInfo : combatLobby) {
					if (localUnitInfo.ClanID == removeClanID) {
						std::cout << "'" << localUnitInfo.UnitName << "'";
					}
				}
				std::cout << "}" << std::endl;
			}
		}
	}
	//Якщо хочаб в одному клані відсутні юніти, виводимо повідомлення і йдемо на початок програми
	else {
		std::cout << "WARNING:Missing units in the lobby" << std::endl;
	}
}

bool GetCanStartCombat(std::vector<FUnitInfo> lobby) {

	//Перевірка можливості старту бою
	if (GetUnitAmountByClanID(0) > 0 && GetUnitAmountByClanID(1) > 0) {
		return 1;
	}
	else {
		return 0;
	}

}

int GetUnitAmountByClanID(int clanID) {

	//Перевірка кількості юнітів в клані по ID
	int unitAmount = 0;
	for (FUnitInfo localUnitInfo : combatLobby) {
		if (localUnitInfo.ClanID == clanID) {
			unitAmount++;
		}
	}
	return unitAmount;

}

void StartCombat() {

	int combatMode = -1;

	bool isDeadClan_0 = 0;
	bool isDeadClan_1 = 0;
	float hpClan_0 = 0;
	float hpClan_1 = 0;
	float dmgClan_0 = 0;
	float dmgClan_1 = 0;

	std::cout << "=START COMBAT=" << std::endl;
	//Перевірка коректності вводу режиму бою
	while (combatMode != 0 && combatMode != 1) {
		std::cout << "Enter combat mode (0-simple/1-stepper): ";
		std::cin >> combatMode;
	}

	//Простий режим з порівнянням сили та здоров'я кланів
	if (combatMode == 0) {
		for (FUnitInfo combatUnitInfo : combatLobby) {
			if (combatUnitInfo.ClanID == 0) {
				hpClan_0 += combatUnitInfo.UnitHealth;
				dmgClan_0 += combatUnitInfo.UnitDamage;
			}
			if (combatUnitInfo.ClanID == 1) {
				hpClan_1 += combatUnitInfo.UnitHealth;
				dmgClan_1 += combatUnitInfo.UnitDamage;
			}
		}

		std::cout << "CLAN '0': HP = " << hpClan_0 << " DMG = " << dmgClan_0 << std::endl;
		std::cout << "CLAN '1': HP = " << hpClan_1 << " DMG = " << dmgClan_1 << std::endl;

		if (dmgClan_0 > hpClan_1) {
			isDeadClan_1 = 1;
		}

		if (dmgClan_1 > hpClan_0) {
			isDeadClan_0 = 1;
		}
	}
	
	//Режим з зірочкою. Кроковий
	if (combatMode == 1) {

		int step = 1;
		int activeClanID = 0;

		FUnitInfo attackUnit = { "", -1, 0, 0 };
		FUnitInfo targetUnit = { "", -1, 0, 0 };

		std::vector<FUnitInfo> arrayClan_0;
		std::vector<FUnitInfo> arrayClan_1;
		arrayClan_0.reserve(10);
		arrayClan_1.reserve(10);

		for (FUnitInfo combatUnitInfo : combatLobby) {
			if (combatUnitInfo.ClanID == 0) {
				hpClan_0 += combatUnitInfo.UnitHealth;
				dmgClan_0 += combatUnitInfo.UnitDamage;
			}
			if (combatUnitInfo.ClanID == 1) {
				hpClan_1 += combatUnitInfo.UnitHealth;
				dmgClan_1 += combatUnitInfo.UnitDamage;
			}
		}

		for (FUnitInfo localUnitInfo : combatLobby) {
			if (localUnitInfo.ClanID == 0) {
				arrayClan_0.push_back(localUnitInfo);
			}

			if (localUnitInfo.ClanID == 1) {
				arrayClan_1.push_back(localUnitInfo);
			}
		}

		while (isDeadClan_0 == 0 && isDeadClan_1 == 0) {

			std::cout << "CLAN '0' | POWER: " << dmgClan_0 << " | HP: " << hpClan_0 << std::endl;
			for (FUnitInfo unitInfoClan_0 : arrayClan_0) {
				std::cout << unitInfoClan_0.UnitName << " HP: " << unitInfoClan_0.UnitHealth << " DMG: " << unitInfoClan_0.UnitDamage << std::endl;
			}

			std::cout << "CLAN '1' | POWER: " << dmgClan_1 << " | HP: " << hpClan_1 << std::endl;
			for (FUnitInfo unitInfoClan_1 : arrayClan_1) {
				
				std::cout << unitInfoClan_1.UnitName << " HP: " << unitInfoClan_1.UnitHealth << " DMG: " << unitInfoClan_1.UnitDamage << std::endl;
			}

			std::cout << std::endl << "=STEP '" << step << "'=" << std::endl;

			if (activeClanID == 0) {

				attackUnit = {"", -1, 0, 0};
				targetUnit = {"", -1, 0, 0};

				for (FUnitInfo attackUnitInfoClan_0 : arrayClan_0) {
					if (attackUnit.UnitDamage == 0) {
						attackUnit = attackUnitInfoClan_0;
					}
					if (attackUnitInfoClan_0.UnitDamage > attackUnit.UnitDamage) {
						attackUnit = attackUnitInfoClan_0;
					}
				}
				std::cout << "CLAN '0' | " << attackUnit.UnitName << " POWER: " << attackUnit.UnitDamage << " HP: " << attackUnit.UnitHealth << std::endl;
				std::cout << "ATTACK TO" << std::endl;
				for (FUnitInfo targetUnitInfoClan_1 : arrayClan_1) {
					if (targetUnit.UnitHealth == 0) {
						targetUnit = targetUnitInfoClan_1;
					}
					if (targetUnitInfoClan_1.UnitHealth < targetUnit.UnitHealth) {
						targetUnit = targetUnitInfoClan_1;
					}
				}
				std::cout << "CLAN '1' | " << targetUnit.UnitName << " POWER: " << targetUnit.UnitDamage << " HP: " << targetUnit.UnitHealth << std::endl;
				
				for (int i = 0; i < arrayClan_1.size(); ++i) {
					if (targetUnit.ClanID == arrayClan_1[i].ClanID && targetUnit.UnitName == arrayClan_1[i].UnitName) {
						targetUnit.UnitHealth -= attackUnit.UnitDamage;
						arrayClan_1[i].UnitHealth -= attackUnit.UnitDamage;
						hpClan_1 -= attackUnit.UnitDamage;
					}
				}

				if (targetUnit.UnitHealth <= 0) {
					dmgClan_1 -= targetUnit.UnitDamage;
					std::cout << "CLAN '1' | " << targetUnit.UnitName << " IS DEAD" << std::endl;
					for (int i = 0; i < arrayClan_1.size(); ++i) {
						if (arrayClan_1[i].ClanID == targetUnit.ClanID && arrayClan_1[i].UnitName == targetUnit.UnitName) {
							std::vector<FUnitInfo>::iterator clanIterator = arrayClan_1.begin() + i;
							arrayClan_1.erase(clanIterator);
						}
					}
					
					for (int i = 0; i < combatLobby.size(); ++i) {
						if (combatLobby[i].ClanID == targetUnit.ClanID && combatLobby[i].UnitName == targetUnit.UnitName) {
							std::vector<FUnitInfo>::iterator combatIterator = combatLobby.begin() + i;
							combatLobby.erase(combatIterator);
						}
					}
				}
				std::cout << std::endl;
				activeClanID = 1;
			}
			else if (activeClanID == 1) {

				attackUnit = { "", -1, 0, 0 };
				targetUnit = { "", -1, 0, 0 };

				for (FUnitInfo attackUnitInfoClan_1 : arrayClan_1) {
					if (attackUnit.UnitDamage == 0) {
						attackUnit = attackUnitInfoClan_1;
					}
					if (attackUnitInfoClan_1.UnitDamage > attackUnit.UnitDamage) {
						attackUnit = attackUnitInfoClan_1;
					}
				}
				std::cout << "CLAN '1' | " << attackUnit.UnitName << " POWER: " << attackUnit.UnitDamage << " HP: " << attackUnit.UnitHealth << std::endl;
				std::cout << "ATTACK TO" << std::endl;
				for (FUnitInfo targetUnitInfoClan_0 : arrayClan_0) {
					if (targetUnit.UnitHealth == 0) {
						targetUnit = targetUnitInfoClan_0;
					}
					if (targetUnitInfoClan_0.UnitHealth < targetUnit.UnitHealth) {
						targetUnit = targetUnitInfoClan_0;
					}
				}

				std::cout << "CLAN '0' | " << targetUnit.UnitName << " POWER: " << targetUnit.UnitDamage << " HP: " << targetUnit.UnitHealth << std::endl;
				for (int i = 0; i < arrayClan_0.size(); ++i) {
					if (targetUnit.ClanID == arrayClan_0[i].ClanID && targetUnit.UnitName == arrayClan_0[i].UnitName) {
						targetUnit.UnitHealth -= attackUnit.UnitDamage;
						arrayClan_0[i].UnitHealth -= attackUnit.UnitDamage;
						hpClan_0 -= attackUnit.UnitDamage;
					}
				}

				if (targetUnit.UnitHealth <= 0) {
					dmgClan_0 -= targetUnit.UnitDamage;
					std::cout << "CLAN '0' | " << targetUnit.UnitName << " IS DEAD" << std::endl;
					for (int i = 0; i < arrayClan_0.size(); ++i) {
						if (arrayClan_0[i].ClanID == targetUnit.ClanID && arrayClan_0[i].UnitName == targetUnit.UnitName) {
							std::vector<FUnitInfo>::iterator clanIterator = arrayClan_0.begin() + i;
							arrayClan_0.erase(clanIterator);
						}
					}

					for (int i = 0; i < combatLobby.size(); ++i) {
						if (combatLobby[i].ClanID == targetUnit.ClanID && combatLobby[i].UnitName == targetUnit.UnitName) {
							std::vector<FUnitInfo>::iterator combatIterator = combatLobby.begin() + i;
							combatLobby.erase(combatIterator);
						}
					}
				}
				std::cout << std::endl;
				activeClanID = 0;
			}

			if (hpClan_1 <= 0) {
				isDeadClan_1 = 1;
			}

			if (hpClan_0 <= 0) {
				isDeadClan_0 = 1;
			}

			step++;
		}
	}

	if (isDeadClan_0 == 0 && isDeadClan_1 == 1) {
		std::cout << "CLAN '0' WON" << std::endl;
	}
	else if (isDeadClan_0 == 1 && isDeadClan_1 == 0) {
		std::cout << "CLAN '1' WON" << std::endl;
	}
	else {
		std::cout << "TIE" << std::endl;
	}
	
}

