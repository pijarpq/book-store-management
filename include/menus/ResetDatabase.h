/* menghapus database */
void resetDatabase()
{
    ifstream db("database/DataBuku.csv");
    // jika terdapat database maka lanjutkan program
    if (db)
    {
        db.close();
        while (true)
        {
            warning("Database akan terhapus");
            cout << "\n\nApakah anda yakin? (y/n): ";
            cin >> to;
            if (makeLowerCase(to)[0] == 'y')
            {
                commandConsole("hapus database");
                break;
            }
            else if (makeLowerCase(to)[0] == 'n')
            {
                break;
            }
            else
            {
                notification("Silahkan masukkan y/n");
                pressEnter("kembali memilih y/n");
            }
        }
        menu();
    }
    // jika tidak terdapat database maka kembali ke menu
    else
    {
        notification("Tidak ada database saat ini");
        pressEnter("kembali ke menu");
        menu();
    }
}
