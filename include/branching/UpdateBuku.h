void update()
{
    ifstream db;

    db.open("database/DataBuku.csv");
    if (db.is_open())
    {
        readData();
    }
    else
    {
        while (true)
        {
            clearScreen();
            for (int i = 0; i < 90; i++)
            {
                cout << '-';
                if (i == 44)
                {
                    cout << "\n!";
                    for (int j = 0; j < 26; j++)
                    {
                        cout << " ";
                        if (j == 12)
                        {
                            cout << "Database Kosong!!";
                        }
                    }
                    cout << "!\n";
                }
            }
        insert:
            cout << "\n\nTambahkan data? (y/n): ";
            cin >> y_n;
            if (makeLowerCase(y_n) == 'y')
            {
                createData();
                goto insert;
            }
            else if (makeLowerCase(y_n) == 'n')
            {
                pressEnter("kembali ke menu");
                menu();
                break;
            }
            else
            {
                errorNotif("silahkan masukkan y/n, dilain itu salah.");
                pressEnter("kembali memilih y/n");
            }
        }
    }
    db.close();
}