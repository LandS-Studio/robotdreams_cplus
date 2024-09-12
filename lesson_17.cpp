#include "lesson_17.h"
#include "Building.h"

int newCommand = -1;

int buildingMaxAge = 0;
int buildingInitialCost = 0;

int toBuildingAge = 0;
int buildingID = -1;

std::vector<ABuilding> arrayBuildings;

void StartHomework_17() {

    while (newCommand == -1) {
        std::cout << "AVAILABLE COMMAND" << std::endl;
        std::cout << "'0' - create new building" << std::endl;
        std::cout << "'1' - get buildings current cost" << std::endl;
        std::cout << "'2' - add building age" << std::endl;
        std::cout << "'3' - quit" << std::endl;
        std::cout << std::endl;

        std::cout << "Enter new command: ";
        std::cin >> newCommand;

        switch (newCommand) {

        case 0:
            buildingMaxAge = 0;
            buildingInitialCost = 0;

            while (buildingMaxAge <= 0 && buildingInitialCost <= 0) {
                std::cout << "Enter building max age: ";
                std::cin >> buildingMaxAge;
                std::cout << "Enter initial building : ";
                std::cin >> buildingInitialCost;

                if (buildingMaxAge <= 0 && buildingInitialCost <= 0) {
                    std::cout << "ERROR:Enter the correct values!!!" << std::endl;
                }
                else {
                    ABuilding build(buildingMaxAge, buildingInitialCost);
                    std::cout << "New building ID: " << build.GetID() << " created" << std::endl;
                    std::cout << std::endl;
                    arrayBuildings.push_back(build);
                }
            }
            newCommand = -1;
            break;

        case 1:
            if (arrayBuildings.size() > 0) {
                for (const ABuilding& building : arrayBuildings) {
                    std::cout << "Building-" << building.GetID() << " is " << building.GetCurrentAge() << " years old and has a value of " << building.GetCost() << "UAH" << std::endl;
                }
            }
            else {
                std::cout << "WARNING:Buildings not valid!!!" << std::endl;
                std::cout << std::endl;
            }
            newCommand = -1;
            std::cout << std::endl;
            break;
        case 2:
            toBuildingAge = 0;
            buildingID = -1;

            while (buildingID < 0 && toBuildingAge <= 0) {
                std::cout << "Enter building ID: ";
                std::cin >> buildingID;

                if (buildingID < 0 || buildingID + 1 > arrayBuildings.size()) {
                    std::cout << "ERROR:Enter the correct values!!!" << std::endl;
                    break;
                }

                std::cout << "Enter the age to add: ";
                std::cin >> toBuildingAge;

                if (toBuildingAge <= 0) {
                    std::cout << "ERROR:Enter the correct values!!!" << std::endl;
                }
                else {
                    for (int i = 0; i < arrayBuildings.size(); ++i) {
                        if (arrayBuildings[i].GetID() == buildingID) {
                            arrayBuildings[i].ToAge(toBuildingAge);
                            if (arrayBuildings[i].CheckIsAlive()) {
                                std::cout << toBuildingAge << " years have been added to Building-" << arrayBuildings[i].GetID() << ". Age " << arrayBuildings[i].GetCurrentAge() << std::endl;
                                break;
                            }
                            else {
                                std::vector<ABuilding>::iterator localIterator = arrayBuildings.begin() + i;
                                arrayBuildings.erase(localIterator);
                                break;
                            }
                        }
                    }
                }
            }
            newCommand = -1;
            std::cout << std::endl;
            break;
        case 3:
            break;
        default:
            newCommand = -1;
            break;
        }


    }

}