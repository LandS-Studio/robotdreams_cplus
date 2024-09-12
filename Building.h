#pragma once
#include <iostream>

class ABuilding {
public:
	ABuilding();
	ABuilding(int _maxAge, int _initCost);
	~ABuilding();

	void ToAge(int years);
	float GetCost() const;
	int GetID() const;

	int GetCurrentAge() const;
	bool CheckIsAlive() const;
	
private:
	static int globalID;

	int id;
	int currentAge;
	int maxAge;
	int initialCost;

	void Destroy();

};

