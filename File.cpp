#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ofstream outputFile("example.txt"); 
    if (!outputFile) {
        std::cerr << "Error opening output file." << std::endl;
        return 1;
    }

    outputFile << "Hello, this is a sample file!" << std::endl;
    outputFile << "C++ file I/O operations are easy to use." << std::endl;
    outputFile.close(); 

    std::ifstream inputFile("example.txt"); 
    if (!inputFile) {
        std::cerr << "Error opening input file." << std::endl;
        return 1;
    }

    std::string line;
    while (getline(inputFile, line)) {
        std::cout << line << std::endl; 
    }

    inputFile.close(); 

    return 0;
}