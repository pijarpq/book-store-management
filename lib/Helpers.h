/*  fungsi tempat command console berada */
void commandConsole(string command)
{
    if (OS_WINDOWS)
    {
        if (command == "bersihkan layar")
            system("cls");
        else if (command == "hapus database")
            system("del database\\DataBuku.csv");
    }
    else
    {
        if (command == "bersihkan layar")
            system("clear");
        else if (command == "hapus database")
            system("rm database/DataBuku.csv");
    }
}

/* fungsi untuk menampilkan notifikasi */
void notification(string errorKind)
{
    int mid = 55 - errorKind.size();

    commandConsole("bersihkan layar");
    for (int i = 0; i < 110; i++)
    {
        cout << '-';
        if (i == 54)
        {
            cout << "\n!";
            for (int j = 0; j < (mid - 2); j++)
            {
                cout << " ";
                if (j == mid / 2 - 1)
                {
                    cout << errorKind;
                }
            }
            cout << "!\n";
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
vector<vector<string>> fetchData()
{
    string line, word;
    vector<vector<string>> data;
    ifstream db;
    db.open("database/DataBuku.csv");
    while (getline(db, line))
    {
        vector<string> row;
        stringstream stream(line);
        while (getline(stream, word, ','))
        {
            row.push_back(word);
        }
        data.push_back(row);
    }
    db.close();
    return data;
}

/* fungsi untuk memeriksa apakah dalam angka terdapat huruf 
    - akan true jika inputan tidak ada string (all int)
    - akan false jika inputan terdapat string (sekali dapat) */
bool isStringAllDigit(const string &str)
{
    //inisialisasi awal dari iterator
    string::const_iterator it = str.begin();
    //jika iterator bukan digit, maka hentikan loop
    while (it != str.end() && isdigit(*it))
        ++it;
    //mengembalikan kondisi apakah iterator sudah mencapai akhir
    return !str.empty() && it == str.end();
}

/* fungsi untuk mengubah string ke lowercase */
string makeLowerCase(const string &str)
{
    string result = str;
    for (int i = 0; i < str.size(); i++)
    {
        if (result[i] > 64 && result[i] < 91)
            result[i] = result[i] + 32;
    }
    return result;
}

/* fungsi untuk mengkonversi string ke integer */
int strToInt(string str)
{
    int is_int;
    stringstream to_int(str);
    to_int >> is_int;
    return is_int;
}

/* fungsi untuk mengkonversi integer ke string */
string intToString(int num)
{
    ostringstream stream;
    stream << num;
    return stream.str();
}

/* fungsi untuk me-format harga supaya mudah dibaca */
string formatPrice(string price)
{
    int count = 0;
    for (int i = price.size(); i > 0; i -= 3)
    {
        //tiap 3 karakter dari belakang maka string akan di tambahkan titik
        if (count > 0)
            price.insert(i, ".");
        count++;
    }
    // mengembalikan harga yang sudah diformat dengan currency IDR
    return "Rp" + price;
}