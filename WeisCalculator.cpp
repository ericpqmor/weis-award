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

    //Initialize statistics output file
    std::ofstream specialOutput("Weis_Statistics.txt");

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

            int totalVotes = 0;

            while (getline(input,line)) {
                totalVotes++;
                std::istringstream iss(line);

                while (iss >> vote) {
                    if (vote[vote.length() - 1] == ',')
                        vote.erase(vote.begin() + vote.length() - 1);

                    if (teachers[vote] >= 0) teachers[vote]++;
                    else teachers[vote] = 1;
                }
            }

            //Special output
            specialOutput << inputFile.substr(0,inputFile.length()-4) << " - ";

            for (auto it = teachers.begin(); it != teachers.end(); ++it) {
                output << it->first << ": " << it->second << " (" << std::setprecision(2) << 100.0*(it->second)/totalVotes << "%)" << std::endl;

                //Weis Statistics Output
                int numVotes = it->second;
                std::cout << "numVotes " << numVotes << " totalVotes" << totalVotes << std::endl;
                if(numVotes >= 0.85*totalVotes)
                    specialOutput << "*" << it->first << "*" << " (" << std::setprecision(2) << 100.0*numVotes/totalVotes << "%) ";
                else if(numVotes >= 0.65*totalVotes)
                    specialOutput << it->first << " (" << std::setprecision(2) << 100.0*numVotes/totalVotes << "%) ";
            }

            //Class statistics
            output << std::endl;
            output << "Alunos que votaram: " << totalVotes << std::endl;


            output.close();
        }

        else
            std::cout << inputFile << " could not be found" << std::endl;

        //Separate years by blank line
        if(fileNum%4 == 3) specialOutput << std::endl;
    }
}

