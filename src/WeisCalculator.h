//
// Created by ericpqmor on 16/08/17.
//

#ifndef WEIS_AWARD_AUTOWEIS_H
#define WEIS_AWARD_AUTOWEIS_H

#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <iomanip>

/**
 * WeisCalculator é o módulo de lógica do programa.
 * Ele recebe um vetor de strings com o nome do .txt de input
 * Ele realiza a leitura e cálculo do número de votos e gera os .txt de output
 */
class WeisCalculator {

public:
    WeisCalculator();

    WeisCalculator(std::vector<std::string> input);

    ~WeisCalculator();

    std::string PrettyPrint();

    void Run();

private:
    std::vector<std::string> inputFiles;
    std::map<std::string,int> teachers;
    std::string vote;

    //Determine the percentual of votes necessary to win (or big win) the award
    double bigWin;
    double win;


};

#endif //WEIS_AWARD_AUTOWEIS_H
