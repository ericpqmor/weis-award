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

/**
 * Função que imprime o cabeçalho do Prêmio
 * @return
 */

std::string WeisCalculator::PrettyPrint() {
    return " _  _ ____ __ ____     __  _  _  __  ____ ____ \n"
            "/ )( (  __|  ) ___)   / _\\/ )( \\/ _\\(  _ (    \\\n"
            "\\ /\\ /) _) )(\\___ \\  /    \\ /\\ /    \\)   /) D (\n"
            "(_/\\_|____|__|____/  \\_/\\_(_/\\_)_/\\_(__\\_|____/\n"
            "------------------------------------------------\n\n";

}

void WeisCalculator::Run() {

    //Inicializa o arquivo de output das estatísticas do prêmio
    std::ofstream specialOutput("Weis_Statistics.txt");
    specialOutput << PrettyPrint();

    for(int fileNum = 0; fileNum < (int)inputFiles.size(); fileNum++) {
        std::string inputFile = inputFiles[fileNum];
        std::string outputFile = "Result_" + inputFile;

        std::ifstream input (inputFile);

        //Depois de identificar os files de input, output e specialOutput, tenta localizá-los em ./in-out
        if(input.is_open()) {

            std::cout << inputFile << " foi encontrado" << std::endl;

            std::ofstream output;
            output.open(outputFile);
            std::string line;

            //Conta o numero total de votos de uma turma
            int totalVotes = 0;

            while (getline(input,line)) {
                totalVotes++;
                std::istringstream iss(line);

                //Usa String Stream para isolar os votos
                while (iss >> vote) {
                    if (vote[vote.length() - 1] == ',')
                        vote.erase(vote.begin() + vote.length() - 1);

                    //Atualiza o map de professores com os votos ganhos
                    if (teachers[vote] >= 0) teachers[vote]++;
                    else teachers[vote] = 1;
                }
            }

            //Output especial (Estatísticas do Prêmio)
            specialOutput << inputFile.substr(0,inputFile.length()-4) << " - ";

            //Apuração dos votos
            for (auto it = teachers.begin(); it != teachers.end(); ++it) {

                //No resultado individual das turmas, diz o professor, número de votos e porcentagem total
                output << it->first << ": " << it->second << " (";
                if(it->second == totalVotes) output << 100.0;
                else output << std::setprecision(2) << 100.0*(it->second)/totalVotes;
                output << "%)" << std::endl;

                int numVotes = it->second;

                //Se o professor obteve um ganho percentual, entra para os professores premiados
                if(numVotes >= win*totalVotes) {

                    //Destaque (*Nome_do_Professor*) para os professores destacados
                    if(numVotes >= bigWin*totalVotes) specialOutput << "*" << it->first << "*";
                    else specialOutput << it->first;

                    specialOutput << " (";

                    //Tenta evitar o erro do 1^e02%
                    if(numVotes == totalVotes) specialOutput << 100.0;
                    else specialOutput << std::setprecision(2) << 100.0 * numVotes / totalVotes;

                    specialOutput << "%) ";
                }
            }

            specialOutput << std::endl;

            //Estatisticas da turma
            output << std::endl;
            output << "Alunos que votaram: " << totalVotes << std::endl;

            teachers.clear();
            output.close();
        }

    }
}