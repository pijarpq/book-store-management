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
            notification("Database kosong");
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
                notification("Silahkan masukkan y/n");
                pressEnter("kembali memilih y/n");
            }
        }
    }
    db.close();
}