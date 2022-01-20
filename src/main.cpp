/* define OS condition */
#ifdef WIN32
#define OS_WINDOWS 1
#else
#define OS_WINDOWS 0
#endif

/* import standard library */
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

/* declaration global variables */
char y_n[] = ""; // variabel menampung pilihan y/n

/* declaration function */
void update();
void resetDatabase();
void buyBook();

/* inport header file */
#include "../lib/VariadicTable.h"
#include "../lib/Helpers.h"
#include "../include/ProgramSection.h"
#include "../include/UserAction.h"
#include "../include/Deeper.h"
#include "../include/branching/BeliBuku.h"
#include "../include/branching/ResetDatabase.h"
#include "../include/branching/UpdateBuku.h"

int main()
{
    /* membuat folder tempat menyimpan database dan hasil exort */
    system("mkdir database & mkdir export");

    /* main program */
    welcome();
    menu();
    commandConsole("bersihkan layar");
    return 0;
}