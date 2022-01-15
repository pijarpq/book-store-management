/* fungsi untuk membersihkan layar console */
void clearScreen()
{
    if (OS_Windows)
    {
        system("cls");
    }
    else
    {
        system("clear");
    }
}

/* fungsi untuk memeriksa apakah dalam angka terdapat huruf 
    - akan true jika inputan tidak ada string (all int)
    - akan false jika inputan terdapat string (sekali dapat) */
bool isStringAllDigit(const string &str)
{
    //inisialisasi instansi dari iterator string
    string::const_iterator it = str.begin();
    //jika iterator bukan digit, maka hentikan loop
    while (it != str.end() && isdigit(*it))
        ++it;
    //mengembalikan kondisi apakah iterator sudah mencapai akhir
    return !str.empty() && it == str.end();
}

/* fungsi untuk mengkonversi string ke integer */
int strToInt(string str)
{
    int isInt;
    stringstream ToInt(str);
    ToInt >> isInt;
    return isInt;
}

/* fungsi untuk mengubah string ke lowercase */
char makeLowerCase(const char &chr)
{
    char result = chr;
    if (result > 64 && result < 91)
    {
        result = result + 32;
    }
    return result;
}

/* fungsi untuk menampilkan error */
void errorNotif(string errorKind)
{
    string error = "ERROR: " + errorKind;
    cout << endl;
    for (int i = 0; i < 150; i++)
    {
        cout << "!";
        if (i == 74)
        {
            cout << "\n"
                 << error << "\n";
        }
    }
    cout << endl;
}

/* fungsi untuk memberi keterangan tekan enter */
void pressEnter(string information)
{
    cout << "\nTekan ENTER untuk " + information + "...";
    cin.ignore();
    cin.get();
}

/* mendapatkan data buku */
vector<vector<string>> fetchDatas()
{
    string baris, kata;
    vector<vector<string>> data;
    ifstream db;
    db.open("database/DataBuku.csv");
    while (getline(db, baris))
    {
        vector<string> row;
        stringstream stream(baris);
        while (getline(stream, kata, ','))
        {
            row.push_back(kata);
        }
        data.push_back(row);
    }
    return data;
}
