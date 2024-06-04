// g++ -o ops ops.cpp

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string>
#include <cmath>
// #include <sstring>

void arithmaticSolver(double &pipedInput, std::string operatorArg, double valueArg, double &outputValue)
{
    if (operatorArg == "+")
    {
        outputValue = pipedInput + valueArg;
    }
    else if (operatorArg == "-")
    {
        outputValue = pipedInput - valueArg;
    }
    else if (operatorArg == "X")
    {
        outputValue = pipedInput * valueArg;
    }
    else if (operatorArg == "/")
    {
        outputValue = pipedInput / valueArg;
    }
    else if (operatorArg == "%")
    {
        // Need to convert to integers
        if (pipedInput - round(pipedInput) != 0 || valueArg - round(valueArg) != 0)
        {
            std::cout << "ERROR: Modulo is only possible with integers" << std::endl;
            outputValue = -1;
        }
        else
        {
            int intPipedInput = pipedInput;
            int intValueInput = valueArg;
            outputValue = intPipedInput % intValueInput;
        }
    }
    else if (operatorArg == "==" && pipedInput == valueArg)
    {
        outputValue = pipedInput;
    }
    else if (operatorArg == "!=" && pipedInput != valueArg)
    {
        outputValue = pipedInput;
    }
    else if (operatorArg == "le")
    {
        if (pipedInput <= valueArg)
        {
            outputValue = pipedInput;
        }
    }
    else if (operatorArg == "lt")
    {
        if (pipedInput < valueArg)
        {
            outputValue = pipedInput;
        }
    }
    else if (operatorArg == "ge")
    {
        if (pipedInput >= valueArg)
        {
            outputValue = pipedInput;
        }
    }
    else if (operatorArg == "gt")
    {
        if (pipedInput > valueArg)
        {
            outputValue = pipedInput;
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc < 3) // Error Catch
    {
        std::cout << " Too many arguments enterd. Max 3." << std::endl;
        return 1;
    }

    double outputValue;
    double pipedInput;
    double valueArg;

    std::string operatorArg = argv[1];
    valueArg = std::atof(argv[2]);
    outputValue = -9999;

    while (std::cin >> pipedInput)
    {
        arithmaticSolver(pipedInput, operatorArg, valueArg, outputValue);
        if (outputValue != -9999)
            std::cout << outputValue << std::endl;
    }

    return 0;
}
