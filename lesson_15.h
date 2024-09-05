#pragma once
#include <iostream>
#include <vector>

struct FUnitInfo {

	std::string UnitName;
	int ClanID;
	float UnitHealth;
	float UnitDamage;

};

void StartHomework_15();

void AddUnitToCombat();
void RemoveUnitFromCombat();

bool GetCanStartCombat(std::vector<FUnitInfo>);
int GetUnitAmountByClanID(int);

void StartCombat();