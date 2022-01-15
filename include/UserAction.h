void createData()
{
    ofstream db;
    string detail_buku[] = {"Judul buku\t", "Penulis\t\t", "Tanggal terbit\t", "Bahasa\t\t", "Penerbit\t", "Berat\t\t", "Lebar\t\t", "Panjang\t\t", "Jumlah halaman\t", "ISBN\t\t", "Harga\t\t"};
    string penampung[11];
    bool repeat = true;
    int harga = 0;

    db.open("database/DataBuku.csv", ios::app);
    while (repeat)
    {
        clearScreen();
        cout << "MASUKKAN DETAIL BUKU\n\n";
        for (int i = 0; i < 11; i++)
        {
            cout << detail_buku[i] << ": ";
            if (i == 0)
                cin.ignore();
            getline(cin, penampung[i]);
        }
        for (int i = 8; i < 11; i++)
        {
            if (!isStringAllDigit(penampung[i]))
            {
                errorNotif("jumlah halaman, ISBN, dan harga harus berupa angka.");
                pressEnter("kembali menginputkan data buku");
                break;
            }
            else
            {
                repeat = false;
            }
        }
    }

    for (int i = 0; i < 11; i++)
    {
        db << penampung[i];
        if (i != 10)
            db << ',';
        else
            db << '\n';
    }
    db.close();
}

void readData()
{
    vector<vector<string>> data_buku = fetchData();

    clearScreen();
    cout << "Daftar Buku\n\n";

    VariadicTable<int, string, string> vt({"No.", "Judul buku", "Harga"});
    for (int i = 0; i < data_buku.size(); i++)
    {
        vt.addRow(i + 1, data_buku[i][0], data_buku[i][10]);
    }
    vt.print(cout);
}