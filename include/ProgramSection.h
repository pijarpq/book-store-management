void menu();
#include "UserAction.h"
#include "deeper.h"
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
    cout << "\n\n Tekan enter untuk melanjutkan....";
    getchar();
}

// Menu Aksi
void menu()
{
    string tindakan[] = {"Mengupdate data buku", "Membeli buku", "Menghapus data buku", "Keluar aplikasi"};
    string pil_tindakan = "";
    int action_choice = 0;
    bool repeat = true;

    while (repeat)
    {
        clearScreen();
        cout << "\t     Menu\n\t   ********\n\n";
        VariadicTable<int, string> vt({"No.", "Tindakan"});
        for (int i = 0; i < 4; i++)
        {
            vt.addRow(i + 1, tindakan[i]);
        }
        vt.print(cout);

        cout << "Masukkan pilihan: ";
        cin >> pil_tindakan;
        action_choice = strToInt(pil_tindakan);

        switch (action_choice)
        {
        case 1:
            update();
            repeat = false;
            break;
        case 2:
            repeat = false;
            break;
        case 3:
            repeat = false;
            break;
        case 4:
            repeat = false;
            break;
        default:
            notification("Masukkan angka sesuai dengan pilihan yang tersedia");
            pressEnter("kembali memilih");
            break;
        }
    }
}