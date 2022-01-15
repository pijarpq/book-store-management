#ifdef WIN32
#define OS_Windows 1
#else
#define OS_Windows 0
#endif

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

char y_n[] = "";

#include "../lib/VariadicTable.h"
#include "../lib/Helpers.h"
#include "../include/ProgramSection.h"

int main()
{
    /* membuat folder tempat menyimpan database dan hasil exort */
    system("mkdir database & mkdir export");

    /* main program */
    welcome();
    menu();
    return 0;
}