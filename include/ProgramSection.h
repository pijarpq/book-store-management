/* welcome screen */
void welcome()
{
    commandConsole("bersihkan layar");
    VariadicTable<string> vt({"Toko Buku Cakrawala"});
    vt.addRow("Membaca Adalah Kunci Kesuksesan");
    vt.print(cout);
    cout << "\n\n Tekan enter untuk melanjutkan....";
    getchar();
}

/* menu aksi */
void menu()
{
    string tindakan[] = {"Mengupdate data buku", "Membeli buku", "Menghapus data buku", "Keluar aplikasi"};
    bool repeat = true;

    while (repeat)
    {
        commandConsole("bersihkan layar");
        cout << "\t     Menu\n\t   ********\n\n";
        VariadicTable<int, string> vt({"No.", "Tindakan"});
        for (int i = 0; i < 4; i++)
        {
            vt.addRow(i + 1, tindakan[i]);
        }
        vt.print(cout);

        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        choice = strToInt(pilihan);

        switch (choice)
        {
        case 1:
            update();
            repeat = false;
            break;
        case 2:
            buyBook();
            repeat = false;
            break;
        case 3:
            resetDatabase();
            repeat = false;
            break;
        case 4:
            commandConsole("bersihkan layar");
            exit(0);
            repeat = false;
            break;
        default:
            notification("Masukkan angka sesuai dengan pilihan yang tersedia");
            pressEnter("kembali memilih");
            break;
        }
    }
}