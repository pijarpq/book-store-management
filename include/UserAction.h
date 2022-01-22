/* membaca inputan dari user dan menyimpannya ke database */
void createData()
{
    ofstream db;
    string penampung[11];
    bool repeat = true;
    bool dont_use_goto = true;

insert:
    commandConsole("bersihkan layar");

    // memasukkan detail buku ke dalam vector sebagai penyimpanan sementara
    cout << "MASUKKAN DETAIL BUKU\n\n";
    for (int i = 0; i < 11; i++)
    {
        cout << detail_buku[i];
        if (i == 0 && dont_use_goto)
            cin.ignore();
        getline(cin, penampung[i]);
    }

    // memverifikasi apakah user menginputkan integer di detail harga
    if (!isStringAllDigit(penampung[10]))
    {
        dont_use_goto = false;
        notification("Harga harus diisi dan berupa angka");
        cout << "\nTekan ENTER untuk kembali menginputkan data buku...";
        getchar();
        goto insert;
    }

    // membuat direktori database
    struct stat info;
    if (stat("database", &info) != 0)
        system("mkdir database");

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
    cin >> to;
    if (makeLowerCase(to)[0] == 'y')
    {
        dont_use_goto = true;
        goto insert;
    }
    else if (!makeLowerCase(to)[0] == 'n')
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

    // jika terdapat data buku dalam database, maka baca database
    if (data_buku.size() != 0)
    {
        commandConsole("bersihkan layar");
        VariadicTable<int, string, string> vt({"No.", "Judul buku", "Harga"});
        for (int i = 0; i < data_buku.size(); i++)
        {
            vt.addRow(i + 1, data_buku[i][0], formatPrice(data_buku[i][10]));
        }
        vt.print(cout);
    }
    // jika tidak terdapat data buku dalam database, maka kembali ke menu
    else
    {
        notification("Tidak ada buku saat ini");
        pressEnter("kembali ke menu");
        menu();
    }
}

/* menghapus data indeks buku dalam database */
void deleteData()
{
    vector<vector<string>> data_buku = fetchData();
    string check = "";
    ofstream db_out;
    ifstream db_in;

    cout << "\nMasukkan nomor indeks buku yang mau dihapus: ";
    cin >> pilihan;
    choice = strToInt(pilihan);
    // buku yang dipilih harus ada dalam daftar yang ditampilkan
    if ((choice > 0) && (choice <= data_buku.size()) && isStringAllDigit(pilihan))
    {
        while (true)
        {
            // konfirmasi penghapusan data
            notification("Buku yang anda pilih akan terhapus");
            cout << "\n\nApakah anda yakin? (y/n): ";
            cin >> to;
            if (makeLowerCase(to)[0] == 'y')
            {
                choice = choice - 1;

                // perintah untuk menghapus data buku yang dipilih
                data_buku[choice].erase(data_buku[choice].begin(), data_buku[choice].end());

                // memasukkan data baru ke dalam database
                db_out.open("database/DataBuku.csv");
                for (int i = 0; i < data_buku.size(); i++)
                {
                    for (int j = 0; j < data_buku[i].size(); j++)
                    {
                        db_out << data_buku[i][j];
                        if (j != 10)
                            db_out << ',';
                        else
                            db_out << '\n';
                    }
                }
                db_out.close();

                // jika database kosong maka hapus file database
                db_in.open("database/DataBuku.csv");
                db_in >> check;
                db_in.close();
                if (db_in.eof())
                    commandConsole("hapus database");

                break;
            }
            else if (makeLowerCase(to)[0] == 'n')
            {
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