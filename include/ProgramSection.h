void menu();
#include "UserAction.h"
#include "branching/BeliBuku.h"
#include "branching/ResetDatabase.h"
#include "branching/UpdateBuku.h"

// Welcome Screen
void welcome()
{
    clearScreen();
    VariadicTable<string> vt({"Toko Buku Cakrawala"});
    vt.addRow("Membaca Adalah Kunci Kesuksesan");
    vt.print(cout);
    cout << "\n\n   Press any key to continue....";
    getchar();
}

// Menu Aksi
void menu()
{
    string tindakan[] = {"Mengupdate data buku", "Membeli buku", "Menghapus data buku"};
    string pil_tindakan = "";
    int action_choice = 0;

input:
    clearScreen();
    cout << "\t     Menu\n\t   ********\n\n";
    VariadicTable<int, string> vt({"No.", "Tindakan"});
    for (int i = 0; i < 3; i++)
    {
        vt.addRow(i + 1, tindakan[i]);
    }
    vt.print(cout);

    cout << "Masukkan pilihan: ";
    cin >> pil_tindakan;
    action_choice = strToInt(pil_tindakan);
    if (isStringAllDigit(pil_tindakan) && (action_choice >= 1 && action_choice <= 3))
    {
        switch (action_choice)
        {
        case 1:
            update();
            break;
        default:
            break;
        }
    }
    else
    {
        errorNotif("masukkan angka sesuai dengan pilihan yang tersedia");
        pressEnter("kembali memilih.");
        goto input;
    }
}