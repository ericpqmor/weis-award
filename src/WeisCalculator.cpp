//
// Created by ericpqmor on 16/08/17.
//

#include "WeisCalculator.h"
#include <iostream>

WeisCalculator::WeisCalculator() {
    std::cout << "Weis Calculator pode ser inicializado apenas com inputFiles" << std::endl;
}

/**
 * Construtor do modulo.
 * As variaveis 'win' e 'bigWin' podem ser alteradas para ditar
 * os professores ganhadores e destacados
 */
WeisCalculator::WeisCalculator(std::vector <std::string> input) {
    this->inputFiles = input;
    this->win = 0.65;
    this->bigWin = 0.85;
}

WeisCalculator::~WeisCalculator() {
    inputFiles.clear();
    teachers.clear();
}

std::string WeisCalculator::PrettyPrint() {
    return " _  _ ____ __ ____     __  _  _  __  ____ ____ \n"
            "/ )( (  __|  ) ___)   / _\\/ )( \\/ _\\(  _ (    \\\n"
            "\\ /\\ /) _) )(\\___ \\  /    \\ /\\ /    \\)   /) D (\n"
            "(_/\\_|____|__|____/  \\_/\\_(_/\\_)_/\\_(__\\_|____/\n"
            "------------------------------------------------\n\n";

}

void WeisCalculator::Run() {

    //Initialize statistics output file
    std::ofstream specialOutput("Weis_Statistics.txt");
    specialOutput << PrettyPrint();

    for(int fileNum = 0; fileNum < (int)inputFiles.size(); fileNum++) {
        std::string inputFile = inputFiles[fileNum];
        std::string outputFile = "Result_" + inputFile;

        //std::cout << "inputFile: " << inputFile << std::endl
        // << "outputFile: " << outputFile << std::endl;

        std::ifstream input (inputFile);

        if(input.is_open()) {

            std::cout << inputFile << " foi encontrado" << std::endl;

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
                output << it->first << ": " << it->second << " (";
                if(it->second == totalVotes) output << 100.0;
                else output << std::setprecision(2) << 100.0*(it->second)/totalVotes;
                output << "%)" << std::endl;

                //Weis Statistics Output - In case of win, prints
                int numVotes = it->second;

                if(numVotes >= win*totalVotes) {
                    if(numVotes >= bigWin*totalVotes) specialOutput << "*" << it->first << "*";
                    else specialOutput << it->first;

                    specialOutput << " (";

                    if(numVotes == totalVotes) specialOutput << 100.0;
                    else specialOutput << std::setprecision(2) << 100.0 * numVotes / totalVotes;

                    specialOutput << "%) ";
                }
            }

            specialOutput << std::endl;

            //Class statistics
            output << std::endl;
            output << "Alunos que votaram: " << totalVotes << std::endl;

            teachers.clear();
            output.close();
        }

        else
            std::cout << inputFile << " nao foi encontrado" << std::endl;

    }
}