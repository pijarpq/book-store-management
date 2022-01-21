/* mengupdate data buku */
void update()
{
    ifstream db("database/DataBuku.csv");
    //jika terdapat database, maka tampilkan data buku dan pilihan tindakan yang dapat dipilih user lebih lanjut
    if (db.is_open())
    {
        db.close();
        readData();
        crud();
    }
    // jika tidak terdapat database, maka terdapat pilihan mau menambahkan database atau kembali ke menu tindakan
    else
    {
        ifDatabaseIsEmpty();
    }
}