/* membaca inputan dari user dan menyimpannya ke database */
void createData()
{
    ofstream db;
    string detail_buku[] = {"Judul buku\t", "Penulis\t\t", "Tanggal terbit\t", "Bahasa\t\t", "Penerbit\t", "Berat\t\t", "Lebar\t\t", "Panjang\t\t", "Jumlah halaman\t", "ISBN\t\t", "Harga\t\t"};
    string penampung[11];
    bool repeat = true;
    bool dont_use_goto = true;
    int harga = 0;

insert:
    commandConsole("bersihkan layar");
    // memasukkan detail buku ke dalam vector sebagai penyimpanan sementara
    cout << "MASUKKAN DETAIL BUKU\n\n";
    for (int i = 0; i < 11; i++)
    {
        cout << detail_buku[i] << ": ";
        if (i == 0 && dont_use_goto)
            cin.ignore();
        getline(cin, penampung[i]);
    }
    // memverifikasi apakah user menginputkan integer di detail jumlah halaman, ISBN, dan harga
    for (int i = 8; i < 11; i++)
    {
        if (!isStringAllDigit(penampung[i]))
        {
            dont_use_goto = false;
            notification("Jumlah halaman, ISBN, dan harga harus berupa angka");
            cout << "\nTekan ENTER untuk kembali menginputkan data buku...";
            getchar();
            goto insert;
        }
    }

    // menulis data yang sudah terverifikasi ke dalam database
    db.open("database/DataBuku.csv", ios::app);
    for (int i = 0; i < 11; i++)
    {
        db << penampung[i];
        if (i != 10)
            db << ',';
        else
            db << '\n';
    }
    db.close();

again:
    // konfirmasi menambahkan data
    cout << "\n\nTambahkan data? (y/n): ";
    cin >> y_n;
    if (makeLowerCase(y_n)[0] == 'y')
    {
        dont_use_goto = true;
        goto insert;
    }
    else if (!makeLowerCase(y_n)[0] == 'n')
    {
        notification("Silahkan masukkan y/n");
        pressEnter("kembali memilih y/n");
        goto again;
    }
}

/* menampilkan data */
void readData()
{
    vector<vector<string>> data_buku = fetchData();
    commandConsole("bersihkan layar");
    cout << "Daftar Buku\n\n";
    VariadicTable<int, string, string> vt({"No.", "Judul buku", "Harga"});
    for (int i = 0; i < data_buku.size(); i++)
    {
        vt.addRow(i + 1, data_buku[i][0], data_buku[i][10]);
    }
    vt.print(cout);
}

// menghapus data indeks buku dalam database
void deleteData()
{
    vector<vector<string>> data_buku = fetchData();
    ofstream db;
    string pilihan = "";
    int choice = 0;

    cout << "Masukkan nomor indeks buku yang mau dihapus: ";
    cin >> pilihan;
    choice = strToInt(pilihan);
    if ((choice > 0) && (choice <= data_buku.size()) && isStringAllDigit(pilihan))
    {
        while (true)
        {
            notification("Buku yang anda pilih akan terhapus");
            cout << "\n\nApakah anda yakin? (y/n): ";
            cin >> y_n;
            if (makeLowerCase(y_n)[0] == 'y')
            {
                choice = choice - 1;
                data_buku[1].erase(data_buku[1].begin(), data_buku[1].end());
                db.open("database/DataBuku.csv");
                for (int i = 0; i < data_buku.size(); i++)
                {
                    for (int j = 0; j < data_buku[i].size(); j++)
                    {
                        db << data_buku[i][j];
                        if (j != 10)
                            db << ',';
                        else
                            db << '\n';
                    }
                }
                db.close();
                break;
            }
            else if (makeLowerCase(y_n)[0] == 'n')
            {
                pressEnter("kembali memilih");
                update();
                break;
            }
            else
            {
                notification("Silahkan masukkan y/n");
                pressEnter("kembali memilih y/n");
            }
        }
    }
    else
    {
        notification("Masukkan angka sesuai dengan pilihan yang tersedia");
        pressEnter("memasukkan pilihan kembali");
        update();
    }
}