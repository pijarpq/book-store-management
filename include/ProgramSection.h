// Welcome Screen
void welcome()
{
    clear();
    VariadicTable<string> vt({"Toko Buku Cakrawala"});
    vt.addRow({"Membaca Adalah Kunci Kesuksesan"});
    vt.print(cout);
    cout << "\n\nTekan sembarang tombol untuk melanjutkan...";
    getchar();
    clear();
}