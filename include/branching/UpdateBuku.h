void update()
{
    ifstream db;

    db.open("database/DataBuku.csv");
    if (db.is_open())
    {
        readData();
        crud();
    }
    else
    {
        ifDatabaseIsEmpty();
    }
    db.close();
}