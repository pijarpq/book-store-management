/*
Copyright (c) 2022 Pijar Pahlawan 

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files Book Store Management Program, 
to deal in the Software without restriction, including without limitation 
the rights to use, copy, modify, merge, publish, distribute, sublicense, 
and/or sell copies of the Software, and to permit persons to whom the 
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

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
#include "../include/menus/BeliBuku.h"
#include "../include/menus/ResetDatabase.h"
#include "../include/menus/UpdateBuku.h"

int main()
{
    /* main program */
    welcome();
    menu();
}
