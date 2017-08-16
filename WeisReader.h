//
// Created by ericpqmor on 16/08/17.
//

#ifndef WEIS_AWARD_WEISREADER_H
#define WEIS_AWARD_WEISREADER_H

class WeisReader {
public:
    WeisReader();

    ~WeisReader();

    int ReadReferenceClass();

    std::vector<std::string> InitializeProfVector();

    std::vector<std::string> DetermineInput();

private:
    int refClass;
    std::vector<std::string> prof;
    std::vector<std::string> inputFiles;
};

#endif //WEIS_AWARD_WEISREADER_H
