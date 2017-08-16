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

    for(int fileNum = 0; fileNum < (int)inputFiles.size(); fileNum++)
    {
        std::string inputFile = inputFiles[fileNum];
        std::string outputFile = "Result_" + inputFile;

        if(inputFile != "20_4.txt") continue;
        std::cout << inputFile << std::endl;

        input.open(GenerateWritable(inputFile));
        output.open(GenerateWritable(outputFile));

        std::cout << inputFile << " exists" << std::endl;

        while(true)
        {

            input >> vote;

            if(vote == "fim") break;

            if(vote[vote.length()-1] == ',')
                vote.erase(vote.begin()+vote.length()-1);

            if (teachers["vote"] >= 0) teachers["vote"]++;
            else teachers["vote"] = 1;

            for(auto it = teachers.begin(); it != teachers.end(); ++it)
                output << it->first << ": " << it->second << std::endl;
        }
    }
}

