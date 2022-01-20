/* mengupdate data buku */
void update()
{
    ifstream db("database/DataBuku.csv");
    string check;
    db >> check;
    //jika terdapat database, maka tampilkan data buku dan pilihan tindakan yang dapat dipilih user lebih lanjut
    if (db.is_open() && !db.eof())
    {
        readData();
        crud();
        db.close();
    }
    // jika tidak terdapat database, maka terdapat pilihan mau menambahkan database atau kembali ke menu tindakan
    else
    {
        ifDatabaseIsEmpty();
    }
}