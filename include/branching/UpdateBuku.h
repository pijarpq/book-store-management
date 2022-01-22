void userActions();
void ifDatabaseIsEmpty();

/* mengupdate data buku */
void update()
{
    ifstream db("database/DataBuku.csv");
    // jika terdapat database, maka tampilkan data buku dan pilihan tindakan yang dapat dipilih user lebih lanjut
    if (db)
    {
        db.close();
        readData();
        userActions();
    }
    // jika tidak terdapat database, maka terdapat pilihan mau menambahkan database atau kembali ke menu tindakan
    else
    {
        ifDatabaseIsEmpty();
    }
}

/* menambah dan menghapus data */
void userActions()
{
    bool repeat = true;

    while (repeat)
    {
        cout << "Pilihan:\n[1] Menambah buku\n[2] Menghapus buku\n[3] Kembali\n\nSilahkan pilih: ";
        cin >> pilihan;
        choice = strToInt(pilihan);
        switch (choice)
        {
        case 1:
            createData();
            update();
            repeat = false;
            break;
        case 2:
            deleteData();
            update();
            repeat = false;
            break;
        case 3:
            repeat = false;
            menu();
            break;
        default:
            notification("Masukkan angka sesuai dengan pilihan yang tersedia");
            pressEnter("memasukkan pilihan kembali");
            readData();
            break;
        }
    }
}

/* menentukan pilihan akan membuat database baru atau tidak */
void ifDatabaseIsEmpty()
{
    while (true)
    {
        notification("Database kosong");
        cout << "\n\nTambahkan data? (y/n): ";
        cin >> to;
        if (makeLowerCase(to)[0] == 'y')
        {
            createData();
            update();
            break;
        }
        else if (makeLowerCase(to)[0] == 'n')
        {
            menu();
            break;
        }
        else
        {
            notification("Silahkan masukkan y/n");
            pressEnter("kembali memilih y/n");
        }
    }
}
