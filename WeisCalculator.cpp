//
// Created by ericpqmor on 16/08/17.
//

#include "WeisCalculator.h"
#include <iostream>

WeisCalculator::WeisCalculator() {
    std::cout << "Weis Calculator pode ser inicializado apenas com inputFiles" << std::endl;
}

WeisCalculator::WeisCalculator(std::vector <std::string> input) {
    this->inputFiles = input;
}

WeisCalculator::~WeisCalculator() {
    inputFiles.clear();
    teachers.clear();
}

char *WeisCalculator::GenerateWritable(std::string file) {
    char *writable = new char[file.length() + 1];
    std::copy(file.begin(), file.end(), writable);
    writable[file.length()] = '\0';

    return writable;
}

void WeisCalculator::Run() {

    for(int fileNum = 0; fileNum < (int)inputFiles.size(); fileNum++) {
        std::string inputFile = inputFiles[fileNum];
        std::string outputFile = "Result_" + inputFile;

        //std::cout << "inputFile: " << inputFile << std::endl
        // << "outputFile: " << outputFile << std::endl;

        std::ifstream input (inputFile);

        if(input.is_open()) {

            std::ofstream output;
            output.open(outputFile);
            std::string line;

            int vote_counter = 0;

            while (getline(input,line)) {
                std::istringstream iss(line);

                while (iss >> vote) {
                    vote_counter ++;
                    if (vote[vote.length() - 1] == ',')
                        vote.erase(vote.begin() + vote.length() - 1);

                    if (teachers[vote] >= 0) teachers[vote]++;
                    else teachers[vote] = 1;
                }
            }

            for (auto it = teachers.begin(); it != teachers.end(); ++it)
                output << it->first << ": " << it->second << std::endl;
        }

        else
            std::cout << inputFile << " could not be found" << std::endl;

        output.close();
    }
}

