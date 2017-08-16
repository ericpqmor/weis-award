//
// Created by ericpqmor on 16/08/17.
//

#include <vector>
#include "WeisCalculator.cpp"
#include "WeisReader.cpp"


int main()
{
    WeisReader weisReader;
    WeisCalculator weisCalculator(weisReader.DetermineInput());
    weisCalculator.Run();
}