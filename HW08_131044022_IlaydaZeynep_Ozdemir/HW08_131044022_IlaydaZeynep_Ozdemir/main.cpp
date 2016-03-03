/* 
 * File:   main.cpp
 * Author: ilayda zeynep ozdemir
 *
 * Created on December 17, 2015, 1:19 PM
 */


#include <time.h>
#include <iostream>
#include "File.h"
#include "Directory.h"
#include "Executable.h"
#include "TextFile.h"

using namespace File__131044022;
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Directory Home1("Home1", "ilayda");
    //Directory Home2("Home2", "ilayda");

    Directory mydir1("mydir1", 10);
    //Directory mydir2("mydir2", 10);

    Directory mydirIci1("mydirIci1", 10);
    Directory mydirIci2("mydirIci2", 10);
    Directory mydirIciIci1("mydirIciIci1", 5);
    
    TextFile text;
    Executable exec;
    Directory dir;


    Home1.cp(mydir1);
    Home1.cd(mydir1);
    mydir1.cp(mydirIci1);
    mydir1.cp(mydirIci2);
    mydir1.cd(mydirIci1);
    mydirIci1.cp(mydirIciIci1);
    

    cout << endl << "-----Home1.ls(R)-----" << endl;
    Home1.ls("-R");
    cout << endl << "----- Home1.ls(l) -----" << endl;
    Home1.ls("-l");
    cout << endl << "----- mydir1.ls() -----" << endl;
    mydir1.ls();
    cout << endl << "----- mydirIci1.ls(l) -----" << endl;
    mydirIci1.ls("-l");
    cout << endl << "----- mydirIci1.ls(R) -----" << endl;
    mydirIci1.ls("-R");
    
    //mydirIci1.cd();
    

    return 0;
}

