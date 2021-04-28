/*
@author Achyut Paudel
@file main
@date September 23, 2019
@brief takes in input file name from terminal args.
       Calls run from exec
*/
#include <iostream>
#include <string>
#include <fstream>
#include "Exec.h"
using namespace std;

int main(int argc, char** argv)
{
    ifstream inFile;
    if(argc > 2)
    {
        inFile.open(argv[1]);
        if(inFile.is_open())
        {
            inFile.close();
            string studentsFile = argv[1];
            string commandsFile = argv[2];
            ifstream studentStream(studentsFile);
            ifstream commandStream(commandsFile);
            Exec fileExec(studentStream);
            fileExec.run(studentStream, commandStream);
        }
        else
        cout<<"Error - enter a valid input file.\n";
    }
    else
        cout<<"Error - enter an input file name.\n";

    return(0);
}
