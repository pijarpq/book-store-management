void bookDetails(vector<vector<string>> data);
void getPaid(string harga, int *diff, int *pay);
void outReceipt(vector<vector<string>> small_data, int uang_masuk, int uang_keluar);

/* pembelian buku */
void buyBook()
{
    vector<vector<string>> data = fetchData();

    while (true)
    {
        readData();
        cout << "\nPilih buku nomor berapa: ";
        cin >> pilihan;
        choice = strToInt(pilihan);
        // buku yang dipilih harus ada dalam pilihan
        if ((choice > 0) && (choice <= data.size()) && isStringAllDigit(pilihan))
        {
            choice = choice - 1;
            bookDetails(data);
            break;
        }
        else
        {
            notification("Masukkan angka sesuai dengan pilihan yang tersedia");
            pressEnter("memasukkan pilihan kembali");
        }
    }
}

/* menampilkan detail buku */
void bookDetails(vector<vector<string>> data)
{
    int bayar = 0;
    int kembalian = 0;

    while (true)
    {
        commandConsole("bersihkan layar");
        VariadicTable<string> detail({"DETAIL BUKU"});
        for (int i = 0; i < 11; i++)
        {
            if (i != 10)
                detail.addRow(detail_buku[i] + data[choice][i]);
            else
                detail.addRow(detail_buku[i] + formatPrice(data[choice][i]));
        }
        detail.print(cout);

        cout << "\nPilihan:\n[y] Bila yakin\n[n] Bila ingin memilih kembali\n[b] Kembali ke menu\nMasukkan pilihan: ";
        cin >> to;
        if (makeLowerCase(to)[0] == 'y')
        {
            getPaid(data[choice][10], &kembalian, &bayar);
            outReceipt(data, bayar, kembalian);
            break;
        }
        else if (makeLowerCase(to)[0] == 'n')
        {
            buyBook();
            break;
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

/* pembayaran */
void getPaid(string harga, int *diff, int *pay)
{
    string pay_str = "";
    int bill = 0;
    while (true)
    {
        commandConsole("bersihkan layar");
        cout << "Pembayaran\n\n";
        cout << "Total harga\t\t: " << formatPrice(harga) << endl;
        cout << "Masukkan uang anda\t: ";
        cin >> pay_str;
        *pay = strToInt(pay_str);
        bill = strToInt(harga);

        // input harus bilangan positif
        if (*pay > 0 && isStringAllDigit(pay_str))
        {
            // bila uang lebih maka tampilkan kembalian
            if (*pay > bill)
            {
                *diff = *pay - bill;
                cout << "Uang anda kembali\t: " << formatPrice(intToString(*diff)) << endl;
                break;
            }
            // bila uang kurang maka tampilkan kekurangan
            else if (*pay < bill)
            {
                *diff = bill - *pay;
                cout << "Uang anda kurang\t: " << formatPrice(intToString(*diff)) << endl;
                pressEnter("mengulangi");
            }
            else
                break;
        }
        else
        {
            notification("Masukkan bilangan positif");
            pressEnter("mengulangi");
        }
    }
}

/* membuat bukti pembayaran */
void outReceipt(vector<vector<string>> small_data, int uang_masuk, int uang_keluar)
{
    ofstream tulis;
    ifstream baca;
    string baris = "";
    int receipt_number = 1;

    // membuat folder export apabila direktori tidak ada
    struct stat info;
    if (stat("export", &info) != 0)
        system("mkdir export");

    // mengecek apakah sudah ada bukti pembayaran dengan nama yang sama
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

    // mengeksport bukti pembayaran
    tulis.open("export/receipt" + intToString(receipt_number) + ".txt");
    VariadicTable<string> bukti({"*** Bukti Pembayaran ***"});
    bukti.addRow(detail_buku[0] + small_data[choice][0]);
    bukti.addRow(detail_buku[6] + small_data[choice][9]);
    bukti.addRow(detail_buku[10] + formatPrice(small_data[choice][10]));
    bukti.addRow("Dibayarkan      : " + formatPrice(intToString(uang_masuk)));
    bukti.addRow("Kembalian       : " + formatPrice(intToString(uang_keluar)));
    bukti.print(tulis);
    tulis.close();
    pressEnter("menampilkan bukti pembayaran");
    commandConsole("bersihkan layar");

    // menampilkan bukti pembayaran ke layar
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
