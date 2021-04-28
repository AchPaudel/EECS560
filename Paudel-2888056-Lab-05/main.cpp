/*
@author Achyut Paudel
@file main
@date December 12, 2019
@brief
*/
#include <iostream>
#include <string>
#include <fstream>
#include "Exec.h"
using namespace std;

int main(int argc, char** argv)
{
    ifstream inFile;
    if(argc > 1)
    {
        inFile.open(argv[1]);
        if(inFile.is_open())
        {
            inFile.close();
            string File = argv[1];
            ifstream fileStream(File);

            Exec myExec;
            myExec.run(fileStream);
        }
        else
        cout<<"Error - enter a valid input file.\n";
    }
    else
        cout<<"Error - enter an input file name.\n";

    return(0);
}
