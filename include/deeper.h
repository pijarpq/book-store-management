void crud()
{
    int choice;
    string pilihan;
    while (true)
    {
        cout << "Pilihan:\n[1] Menambah data\n[2] Menghapus data\n\nSilahkan pilih: ";
        cin >> pilihan;
        choice = strToInt(pilihan);
        if (!isStringAllDigit(pilihan) || (choice != 1 && choice != 2))
        {
            notification("Masukkan angka sesuai dengan pilihan yang tersedia");
            pressEnter("memasukkan pilihan kembali");
            readData();
        }
        else
        {
            if (choice == 1)
            {
                createData();
            }
            else
            {
                //! CAPEK, KURANG HAPUS BUKU :)
            }

            break;
        }
    }
}

void ifDatabaseIsEmpty()
{
    while (true)
    {
        notification("Database kosong");
    insert:
        cout << "\n\nTambahkan data? (y/n): ";
        cin >> y_n;
        if (makeLowerCase(y_n)[0] == 'y')
        {
            createData();
            goto insert;
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
