// robotdreams.cpp : This file contains the "main" function. This is where the execution of the programme starts and ends.

#include <iostream>

int main()
{
    float health;
    float item_distance;
    float item_impact;
    float result_impact;

    std::cout << "Enter character health: ";
    std::cin >> health;
    std::cout << "\n";

    while (health > 0) {
        std::cout << "Enter distance to damaging object: ";
        std::cin >> item_distance;
        std::cout << "Enter item impact: ";
        std::cin >> item_impact;

        if (item_distance < 100) {
            result_impact = item_impact * (1 - item_distance / 100);
            health += result_impact;

            if (health < 1 && health > 0) {
                health = 1;
            }

            std::cout << "\nResult item impact: " << result_impact << std::endl;
            
            if (health <= 0) {
                std::cout << "Character is DEAD" << std::endl;
            }
            else {
                std::cout << "Character health: " << health << "\n" << std::endl;
            }
        }
    }

    return 0;
}

