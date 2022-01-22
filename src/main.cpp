/* define OS condition */
#ifdef WIN32
#define OS_WINDOWS 1
#else
#define OS_WINDOWS 0
#endif

/* import standard library */
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <sstream>
#include <sys/stat.h>
using namespace std;

/* declaration global variables */
char y_n[] = ""; // variabel menampung pilihan y/n

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
    /* main program */
    welcome();
    menu();

    commandConsole("bersihkan layar");
    return 0;
}