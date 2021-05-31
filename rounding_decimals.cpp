// Copyright (c) 2021 Caylee Annett All rights reserved
//
// Created by Caylee Annett
// Created on May 2021
// This program rounds decimal numbers and passes values by reference

#include <iostream>
#include <string>
#include <cmath>

void RoundDecimals(float &numberFloat, int &decimalPlacesInteger) {
    // This function rounds the number

    numberFloat = numberFloat * pow(10, decimalPlacesInteger);
    numberFloat = numberFloat + 0.5;
    numberFloat = static_cast<int>(numberFloat);
    numberFloat = numberFloat * (1 / pow(10, decimalPlacesInteger));
}


main() {
    // This function gets the number and decimal places to round by
    std::string numberString;
    float numberFloat;
    std::string decimalPlacesString;
    int decimalPlacesInteger;

    // Input
    std::cout << "This program rounds decimal numbers." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Enter a decimal number to round: ";
    std::cin >> numberString;
    std::cout << "Enter the number of decimal places to round by: ";
    std::cin >> decimalPlacesString;

    // Process
    while (true) {
        try {
            numberFloat = std::stof(numberString);

            break;
        } catch (std::invalid_argument) {
                std::cout << numberString << " is not a valid input. "
                    "Enter a decimal number: ";
                std::cin >> numberString;
        }
    }
    while (true) {
        try {
            decimalPlacesInteger = std::stoi(decimalPlacesString);

            if (decimalPlacesInteger >= 0) {
                break;
            } else {
                std::cout << "Must be a positive integer. Enter the number "
                    "of decimal places to round by: ";
                std::cin >> decimalPlacesString;
            }
        } catch (std::invalid_argument) {
                std::cout << decimalPlacesString << " is not a valid input. "
                    "Enter the number of decimal places to round by: ";
                std::cin >> decimalPlacesString;
        }
    }

    // Call functions
    RoundDecimals(numberFloat, decimalPlacesInteger);

    // Output
    std::cout << "" << std::endl;
    std::cout << "The rounded number is: " << numberFloat << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Done." << std::endl;
}
