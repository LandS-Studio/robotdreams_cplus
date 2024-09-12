#include "Building.h"

int ABuilding::globalID = 0;

ABuilding::ABuilding() {
	maxAge = 0;
	currentAge = 0;
	initialCost = 0;

	id = globalID;
	globalID++;
}

ABuilding::ABuilding(int _maxAge, int _initCost) {
	maxAge = _maxAge;
	currentAge = 0;
	initialCost = _initCost;
	
	id = globalID;
	globalID++;
}

ABuilding::~ABuilding() {
	
}

float ABuilding::GetCost() const {
	
	float currentCost = (float)initialCost - (((float)initialCost / (float)maxAge) * currentAge);
	return currentCost;

}

int ABuilding::GetID() const {
	return id;
}

int ABuilding::GetCurrentAge() const {
	return currentAge;
}

bool ABuilding::CheckIsAlive() const{
	return currentAge < maxAge;
}

void ABuilding::ToAge(int years) {

	currentAge += years;

	if (currentAge >= maxAge) {
		ABuilding::Destroy();
	}

}

void ABuilding::Destroy(){

	std::cout << "The building " << id << " was destroyed!!!" << std::endl;
	ABuilding::~ABuilding();

}
