/* menghapus database */
void resetDatabase()
{
    ifstream db("database/DataBuku.csv");
    /* jika terdapat database maka lanjutkan program */
    if (db.is_open())
    {
        while (true)
        {
            notification("Database akan terhapus");
            cout << "\n\nApakah anda yakin? (y/n): ";
            cin >> y_n;
            if (makeLowerCase(y_n)[0] == 'y')
            {
                commandConsole("hapus database");
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
        db.close();
    }
    /* jika tidak terdapat database maka kembali ke menu */
    else
    {
        notification("Tidak ada database saat ini");
        pressEnter("kembali ke menu");
        menu();
    }
}