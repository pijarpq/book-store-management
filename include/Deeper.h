/* menambah dan menghapus data */
void crud()
{
    int choice;
    string pilihan;
    bool repeat = true;

    while (repeat)
    {
        cout << "Pilihan:\n[1] Menambah data\n[2] Menghapus data\n[3] Kembali\n\nSilahkan pilih: ";
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
        cin >> y_n;
        if (makeLowerCase(y_n)[0] == 'y')
        {
            createData();
            update();
            break;
        }
        else if (makeLowerCase(y_n)[0] == 'n')
        {
            pressEnter("kembali ke menu");
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
