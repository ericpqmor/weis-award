//
// Created by ericpqmor on 16/08/17.
//

#ifdef __linux__
#include <unistd.h>
#endif
#ifdef _WIN32
#include <direct.h>
#endif

#include <vector>
#include "WeisCalculator.cpp"
#include "WeisReader.cpp"

int main()
{
    #ifdef __linux__
        chdir(PROJECT_DIRECTORY);
    #endif
    #ifdef _WIN32
        _chdir(PROJECT_DIRECTORY);
    #endif

    WeisReader weisReader;
    WeisCalculator weisCalculator(weisReader.DetermineInput());
    weisCalculator.Run();
}