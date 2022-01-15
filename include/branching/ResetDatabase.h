void resetDatabase()
{
    while (true)
    {
        notification("Database akan terhapus");
        cout << "\n\nApakah anda yakin? (y/n): ";
        cin >> y_n;
        if (makeLowerCase(y_n)[0] == 'y')
        {
            delFile();
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