// deklarasi fungsi
void getPaid(string total, int *diff, int *pay);
void outReceipt(vector<vector<string>> data, int index, int uang_masuk, int uang_keluar);

/* pembelian buku */
void buyBook()
{
    vector<vector<string>> data_buku = fetchData();
    string detail_buku[] = {"Judul buku\t", "Penulis\t\t", "Tanggal terbit\t", "Bahasa\t\t", "Penerbit\t", "Berat\t\t", "Lebar\t\t", "Panjang\t\t", "Jumlah halaman\t", "ISBN\t\t", "Harga\t\t"};
    string pilihan = "";
    int choice = 0;
    int bayar = 0;
    int kembalian = 0;
    char to[] = "";

daftar:
    readData();
    cout << "\nPilih buku nomor berapa: ";
    cin >> pilihan;
    choice = strToInt(pilihan);
    if ((choice > 0) && (choice <= data_buku.size()) && isStringAllDigit(pilihan))
    {
        choice = choice - 1;
        while (true)
        {
            commandConsole("bersihkan layar");
            cout << "Detail Buku\n\n";
            for (int i = 0; i < 11; i++)
            {
                if (i != 10)
                    cout << detail_buku[i] << ": " << data_buku[choice][i] << endl;
                else
                    cout << detail_buku[i] << ": " << formatPrice(data_buku[choice][i]) << endl;
            }
            cout << "\nPilihan:\n[y] Bila yakin\n[n] Bila ingin memilih kembali\n[b] Kembali ke menu\nMasukkan pilihan: ";
            cin >> to;

            if (makeLowerCase(to)[0] == 'y')
            {
                getPaid(data_buku[choice][10], &kembalian, &bayar);
                outReceipt(data_buku, choice, bayar, kembalian);
                break;
            }
            else if (makeLowerCase(to)[0] == 'n')
            {
                goto daftar;
            }
            else if (makeLowerCase(to)[0] == 'b')
            {
                menu();
                break;
            }
            else
            {
                notification("Silahkan masukkan y/n/b");
                pressEnter("kembali memilih");
            }
        }
    }
    else
    {
        notification("Masukkan angka sesuai dengan pilihan yang tersedia");
        pressEnter("memasukkan pilihan kembali");
        goto daftar;
    }
}

/* pembayaran */
void getPaid(string total, int *diff, int *pay)
{
    string pay_str;
    int bill;
    while (1)
    {
        commandConsole("bersihkan layar");
        cout << "Pembayaran\n\n";
        cout << "Total harga\t\t: " << formatPrice(total) << endl;
        cout << "Masukkan uang anda\t: ";
        cin >> pay_str;
        *pay = strToInt(pay_str);
        bill = strToInt(total);
        if (*pay > 0 && isStringAllDigit(pay_str))
        {
            if (*pay > bill)
            {
                *diff = *pay - bill;
                cout << "Uang anda kembali\t: " << formatPrice(intToString(*diff)) << endl;
                break;
            }
            else if (*pay < bill)
            {
                *diff = bill - *pay;
                cout << "Uang anda kurang\t: " << formatPrice(intToString(*diff)) << endl;
                pressEnter("mengulangi");
            }
            else
            {
                break;
            }
        }
        else
        {
            notification("Masukkan bilangan positif");
            pressEnter("mengulangi");
        }
    }
}

/* membuat bukti pembayaran */
void outReceipt(vector<vector<string>> data, int index, int uang_masuk, int uang_keluar)
{
    ofstream tulis;
    ifstream baca;
    string baris = "";
    int receipt_number = 1;

    // membuat folder export apabila direktori tidak ada
    struct stat info;
    if (stat("export", &info) != 0)
        system("mkdir export");

    // mengexport bukti pembayaran
    while (true)
    {
        baca.open("export/receipt" + intToString(receipt_number) + ".txt");
        if (baca)
        {
            receipt_number++;
            baca.close();
        }
        else
        {
            baca.close();
            break;
        }
    }

    tulis.open("export/receipt" + intToString(receipt_number) + ".txt");
    VariadicTable<string> bukti({"*** Bukti Pembayaran ***"});
    bukti.addRow("Judul buku      : " + data[index][0]);
    bukti.addRow("ISBN            : " + data[index][9]);
    bukti.addRow("Harga           : " + data[index][10]);
    bukti.addRow("-------------------------------------------------");
    bukti.addRow("Dibayarkan      : " + intToString(uang_masuk));
    bukti.addRow("Kembalian       : " + intToString(uang_keluar));
    bukti.print(tulis);
    tulis.close();
    pressEnter("menampilkan bukti pembayaran");
    commandConsole("bersihkan layar");

    baca.open("export/receipt" + intToString(receipt_number) + ".txt");
    commandConsole("bersihkan layar");
    while (getline(baca, baris))
    {
        cout << baris << "\n";
    }
    baca.close();
    cout << "\n\nNOTE: pembayaran telah tersimpan di folder export\n\n";
    cout << "\n\nTekan enter untuk kembali ke menu....";
    getchar();
    menu();
}
