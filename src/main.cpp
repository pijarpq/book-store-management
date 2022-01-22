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

/* global declaration */
char to[] = "";
string pilihan = "";
int choice = 0;
string detail_buku[] = {"Judul buku      : ", "Penulis         : ", "Jumlah halaman  : ",
                        "Bahasa          : ", "Penerbit        : ", "Tanggal terbit  : ",
                        "ISBN            : ", "Panjang         : ", "Lebar           : ",
                        "Berat           : ", "Harga           : "};

void update();
void resetDatabase();
void buyBook();

/* import header file */
#include "../lib/VariadicTable.h"
#include "../lib/Helpers.h"
#include "../include/ProgramSection.h"
#include "../include/CRUD.h"
#include "../include/branching/BeliBuku.h"
#include "../include/branching/ResetDatabase.h"
#include "../include/branching/UpdateBuku.h"

int main()
{
    /* main program */
    welcome();
    menu();

    return 0;
}