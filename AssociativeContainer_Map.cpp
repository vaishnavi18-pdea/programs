#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, long> statePopulation;

    statePopulation["Maharashtra"] = 39538223;
    statePopulation["Tamil Nadu"] = 29145505;
    statePopulation["Gujrat"] = 21538187;
    statePopulation["Kerala"] = 20201249;
    statePopulation["Odisha"] = 13002700;

    std::cout << "List of States and their populations:\n";
    for (const auto& entry : statePopulation) {
        std::cout << "State: " << entry.first << ", Population: " << entry.second << std::endl;
    }

    std::string stateName;
    std::cout << "\nEnter the name of a state: ";
    std::getline(std::cin, stateName);

    auto it = statePopulation.find(stateName);

    if (it != statePopulation.end()) {
        std::cout << "The population of " << stateName << " is: " << it->second << std::endl;
    } else {
        std::cout << "State not found in the map." << std::endl;
    }

    return 0;
}