//
// Created by ericpqmor on 16/08/17.
//

#include "WeisReader.h"
#include <string>

WeisReader::WeisReader() {

}

WeisReader::~WeisReader() {

}

/**
 * Serve para leitura da turma de referência (Turma de primeiro ano)
 */
int WeisReader::ReadReferenceClass() {
    int refClass;
    std::cout << "Insira a turma de primeiro ano: ";
    std::cin >> refClass;
    return refClass;
}

/**
 * Inicialização de vetores dos cursos do PROF
 */
std::vector<std::string> WeisReader::InitializeProfVector() {
    std::vector<std::string> prof;
    prof.push_back("AER");
    prof.push_back("AESP");
    prof.push_back("CIVIL");
    prof.push_back("COMP");
    prof.push_back("ELE");
    prof.push_back("MEC");

    return prof;
}

/**
 * Serve para leitura da turma de referência (Turma de primeiro ano)
 */
std::vector<std::string> WeisReader::DetermineInput() {
    std::vector<std::string> input;
    int refClass = ReadReferenceClass();
    std::vector<std::string> prof = InitializeProfVector();

    /**
     * Adicionando as turmas do FUND:
     * X_1, X_2, X_3, X_4
     * (X-1)_1, (X-1)_2, (X-1)_3, (X-1)_4
     */
    for(int num=refClass; num>refClass-2; num--)
        for(int subClass = 1; subClass <= 4; subClass++)
            input.push_back(std::to_string(num) + "_" + std::to_string(subClass) + ".txt");

    /**
     * Adicionando as turmas do PROF:
     * AER_(X-2), AESP_(X-2), CIVIL_(X-2), COMP_(X-2), ELE_(X-2), MEC_(X-2)
     * AER_(X-3), AESP_(X-3), CIVIL_(X-3), COMP_(X-3), ELE_(X-3), MEC_(X-3)
     * AER_(X-4), AESP_(X-4), CIVIL_(X-4), COMP_(X-4), ELE_(X-4), MEC_(X-4)
     */
    for(int num=refClass-2; num>refClass-5; num--)
        for(int course = 0; course<(int) prof.size(); course++)
            input.push_back(std::to_string(num) + "_" + prof[course]  + ".txt");

    return input;
}