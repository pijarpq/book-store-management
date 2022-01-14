#ifdef WIN32
#define OS_Windows 1
#else
#define OS_Windows 0
#endif

#include <iostream>

using namespace std;

#include "../lib/VariadicTable.h"
#include "../lib/helpers.h"

int main()
{
    // Welcome Screen
    clear();
    VariadicTable<string> vt({"Toko Buku Cakrawala"});
    vt.addRow({"Membaca Adalah Kunci Kesuksesan"});
    vt.print(cout);
    cout << "\n\nTekan sembarang tombol untuk melanjutkan...";
    getchar();
    clear();
}