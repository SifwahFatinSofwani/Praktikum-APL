#include <iostream>
#include <iomanip>

using namespace std;

string choice, newUsername, newPassword, newRole, nama, role, mekanik, posisi, rolesekarang, username, password;

bool quit = false;
bool loginberhasil = false;
bool herotersedia = false;
bool ada = false;
bool moved = false;
bool ditemukan = false;
bool usernametersedia = false;

struct Akun {
    struct isiakun {
        string heromain;
        string mainrole;
        string rankakun;
    } isiakun;
    string username;
    string password;
    string role;
};

Akun user[30] = {
    {{"", "", ""}, "admin", "admin", "admin"},
    {{"Fanny", "Jungle", "Mythic"}, "user", "user", "user"}
};

string listhero[5][10][4] = {
    {
        {"Fanny", "Assassin", "Mekanik tinggi", "Jungle"},
        {"Ling", "Assassin", "Mekanik tinggi", "Jungle"},
        {"Nolan", "Assassin", "Mekanik tinggi", "Jungle"},
        {"Julian", "Assassin, Mage", "Mekanik sedang", "Jungle"},
        {"Hayabusa", "Assassin", "Mekanik tinggi", "Jungle"},
    },
    {
        {"Gatotkaca", "Tank, Fighter", "Mekanik mudah", "Roam"},
        {"Edith", "Tank", "Mekanik sedang", "Roam"},
        {"Chip", "Support, Tank", "Mekanik sedang", "Roam"},
        {"Angela", "Support", "Mekanik rendah", "Roam"},
        {"Mathilda", "Support", "Mekanik rendah", "Roam"},
        {"Grock", "Support", "Mekanik sedang", "Roam"},
    },
    {
        {"Valentina", "Mage", "Mekanik sedang", "Mid"},
        {"Yve", "Mage", "Mekanik sedang", "Mid"},
        {"Faramis", "Mage", "Mekanik sedang", "Mid"},
        {"Aurora", "Mage", "Mekanik rendah", "Mid"},
        {"Zhuxin", "Mage", "Mekanik sedang", "Mid"},
    },
    {
        {"Harith", "Mage", "Mekanik tinggi", "Gold"},
        {"Moskov", "Marksman", "Mekanik tinggi", "Gold"},
        {"Claude", "Marksman", "Mekanik tinggi", "Gold"},
        {"Nathan", "Marksman", "Mekanik tinggi", "Gold"},
        {"Roger", "Fighter, Marksman", "Mekanik tinggi", "Gold"},
        {"Lunox", "Mage", "Mekanik tinggi", "Gold"},
        {"Miya", "Marksman", "Mekanik tinggi", "Gold"},
    },
    {
        {"Ruby", "Fighter", "Mekanik sedang", "EXP"},
        {"Edith", "Tank, Fighter", "Mekanik sedang", "EXP"},
        {"Terizla", "Fighter", "Mekanik sedang", "EXP"},
        {"Arlott", "Fighter", "Mekanik sedang", "EXP"},
        {"Phoveus", "Fighter", "Mekanik sedang", "EXP"},
        {"Baxia", "Tank, Fighter", "Mekanik sedang", "EXP"},
    }
};

int jumlahAkun = 2;
int kesempatan = 0;

void tampilkanMenuUtama();
bool loginUser(string username, string password, string &rolesekarang);
void adminMenu();
void userMenu();
void tambahHero();
void editHero();
void hapusHero();
void tampilkanHero();
void lihatAkunUser();
bool registerUser(string newUsername, string newPassword, string newRole);
int posisiindex(string posisi);
string posisistr(int index);
void tampilkanHero();

void cls() {
    system("cls");
}

bool loginberhasil(int attempts) {
    if (attempts >= 3) {
        cls();
        cout << "Anda sudah mencoba login sebanyak 3 kali. Program berakhir." << endl;
        exit(0);
        return false;
    }
    
    cout << "Masukkan username: ";
    getline(cin, username);
    cout << "Masukkan password: ";  
    getline(cin, password);
    cls();
    
    if (loginUser(username, password, rolesekarang)) {
        return true;
    } else {
        cout << "Username atau password salah." << endl;
        return loginberhasil(attempts + 1);
    }
}

bool carihero(string heroName) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (listhero[i][j][0][0] != '\0') { 
                return true;
            }
        }
    }
    return false;
}

bool carihero(string heroName, int &posIndex, int &heroIndex) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (listhero[i][j][0][0] != '\0') { 
                posIndex = i;
                heroIndex = j;
                return true;
            }
        }
    }
    return false;
}

int main() {
    cls();

    while (true) {
        tampilkanMenuUtama();
        getline(cin, choice);

        if (choice == "1") {
            kesempatan = 0; 
            quit = false;
            if (loginberhasil(0)) {
                if (rolesekarang == "admin") {
                    adminMenu();
                } else {
                    userMenu();
                }
            }
        } else if (choice == "2") {
            usernametersedia = false;
            if (jumlahAkun >= 30) {
                cls();
                cout << "Kapasitas akun penuh. Tidak bisa menambah akun baru." << endl;
                continue;
            }

            cls();
            cout << "Masukkan username baru: ";
            getline(cin, newUsername);

            for (int i = 0; i < jumlahAkun; ++i) {
                if (user[i].username == newUsername) {
                    usernametersedia = true;
                    break;
                }
            }

            if (usernametersedia) {
                cout << "Username sudah ada. Silakan coba username lain." << endl;
                continue;
            }

            cout << "Masukkan password baru: ";
            getline(cin, newPassword);
            cout << "Masukkan role (1: admin, 2: user): ";
            cin >> role;
            cin.ignore();
            
            if (role == "1") {
                newRole = "admin";
            } else if (role == "2") {
                newRole = "user";
            } else {
                cout << "Role tidak valid." << endl;
                continue;
            }
            
            registerUser(newUsername, newPassword, newRole);
            cls();
            cout << "Registrasi berhasil." << endl;
        } else if (choice == "3") {
            cout << "Exit" << endl;
            break;
        } else {
            cls();
            cout << "Pilihan tidak valid" << endl;
        }
    }

    return 0;
}

void tampilkanMenuUtama() {
    cout << "Selamat datang di program manajemen hero Mobile Legends" << endl;
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "3. Exit" << endl;
    cout << "Masukkan pilihan anda: ";
}

bool loginUser(string username, string password, string &rolesekarang) {
    for (int i = 0; i < jumlahAkun; ++i) {
        if (user[i].username == username && user[i].password == password) {
            rolesekarang = user[i].role;
            return true;
        }
    }
    return false;
}

void adminMenu() {
    while (true) {
        cout << "Admin Menu:" << endl;
        cout << "1. Tambah Hero" << endl;
        cout << "2. Edit Hero" << endl;
        cout << "3. Hapus Hero" << endl;
        cout << "4. Lihat Hero" << endl;
        cout << "5. Lihat akun user" << endl;
        cout << "6. Logout" << endl;
        cout << "Masukkan pilihan anda: ";
        getline(cin, choice);
        cls();
        
        if (choice == "1") {
            tambahHero();
        } else if (choice == "2") {
            editHero();
        } else if (choice == "3") {
            hapusHero();
        } else if (choice == "4") {
            tampilkanHero();
        } else if (choice == "5") {
            lihatAkunUser();
        } else if (choice == "6") {
            quit = true;
            break;
        } else {
            cls();
            cout << "Pilihan tidak valid." << endl;
        }
    }
}

void userMenu() {
    while (true) {
        cout << "Login berhasil sebagai user." << endl;
        cout << "1. Lihat list hero" << endl;
        cout << "2. Logout" << endl;
        cout << "Masukkan pilihan anda: ";
        getline(cin, choice);
        cls();

        if (choice == "1") {
            tampilkanHero();
        } else if (choice == "2") {
            quit = true;
            break;
        } else {
            cls();
            cout << "Pilihan tidak valid." << endl;
        }
    }
}

void tambahHero() {
    herotersedia = false;
    ada = false;
    cout << "Masukkan nama hero: ";
    getline(cin, nama);
    
    herotersedia = carihero(nama);

    if (herotersedia) {
        cls();
        cout << "Hero sudah ada." << endl;
        return;
    }

    cout << "Masukkan role hero: ";
    getline(cin, role);
    cout << "Masukkan tingkat mekanik hero: ";
    getline(cin, mekanik);
    cout << "Masukkan posisi hero: ";
    cout << "\n1. Jungle" << endl;
    cout << "2. Roam" << endl;
    cout << "3. Mid" << endl;
    cout << "4. Gold" << endl;
    cout << "5. EXP" << endl;
    cout << "Masukkan pilihan anda: ";
    getline(cin, posisi);

    int posisiIndex = posisiindex(posisi);
    string posisiStr = posisistr(posisiIndex);
    
    if (posisiIndex == -1) {
        cls();
        cout << "Posisi tidak valid." << endl;
        return;
    }

    for (int j = 0; j < 10; ++j) {
        if (listhero[posisiIndex][j][0][0] != '\0') {
            listhero[posisiIndex][j][0] = nama;
            listhero[posisiIndex][j][1] = role;
            listhero[posisiIndex][j][2] = mekanik;
            listhero[posisiIndex][j][3] = posisiStr;
            cls();
            cout << "Hero berhasil ditambahkan." << endl;
            ada = true;
            break;
        }
    }
    
    if (!ada) {
        cls();
        cout << "Kategori penuh, tidak bisa menambah hero baru." << endl;
    }
}


void editHero() {
    moved = false;
    ditemukan = false;
    tampilkanHero();
    
    cout << "Masukkan nama hero yang ingin diedit: ";
    getline(cin, nama);
    
    int posIndex, heroIndex;
    if (carihero(nama, posIndex, heroIndex)) {
        cout << "Masukkan role baru: ";
        getline(cin, listhero[posIndex][heroIndex][1]);
        cout << "Masukkan tingkat mekanik baru: ";
        getline(cin, listhero[posIndex][heroIndex][2]);
        cout << "Masukkan posisi baru: ";
        cout << "\n1. Jungle" << endl;
        cout << "2. Roam" << endl;
        cout << "3. Mid" << endl;
        cout << "4. Gold" << endl;
        cout << "5. EXP" << endl;
        cout << "Masukkan pilihan anda: ";
        getline(cin, choice);

        int posisibaru = posisiindex(choice);
        string posisinew = posisistr(posisibaru);
        
        if (posisibaru == -1) {
            cout << "Pilihan tidak valid." << endl;
            return;
        }
        

        for (int k = 0; k < 10; ++k) {
            if (listhero[posisibaru][k][0][0] != '\0') {
                listhero[posisibaru][k][0] = listhero[posIndex][heroIndex][0];
                listhero[posisibaru][k][1] = listhero[posIndex][heroIndex][1];
                listhero[posisibaru][k][2] = listhero[posIndex][heroIndex][2];
                listhero[posisibaru][k][3] = posisinew;

                for (int l = heroIndex; l < 9; ++l) {
                    listhero[posIndex][l][0] = listhero[posIndex][l + 1][0];
                    listhero[posIndex][l][1] = listhero[posIndex][l + 1][1];
                    listhero[posIndex][l][2] = listhero[posIndex][l + 1][2];
                    listhero[posIndex][l][3] = listhero[posIndex][l + 1][3];
                }
                
                listhero[posIndex][9][0] = "";
                listhero[posIndex][9][1] = "";
                listhero[posIndex][9][2] = "";
                listhero[posIndex][9][3] = "";

                cls();
                cout << "Hero berhasil dipindahkan." << endl;
                moved = true;
                break;
            }
        }
        
        if (!moved) {
            cls();
            cout << "Kategori baru penuh, tidak bisa memindahkan hero." << endl;
        }
        ditemukan = true;
    }
    
    if (!ditemukan) {
        cls();
        cout << "Hero tidak ditemukan." << endl;
    }
}

void hapusHero() {
    cls();
    int posisi, index;
    cout << "1. Jungle" << endl;
    cout << "2. Roam" << endl;
    cout << "3. Mid" << endl;
    cout << "4. Gold" << endl;
    cout << "5. EXP" << endl;
    cout << "Masukkan posisi hero yang akan dihapus (1-5): ";
    cin >> posisi;
    posisi--; 
    
    if (posisi < 0 || posisi >= 5) {
        cout << "Posisi tidak valid." << endl;
        cin.ignore();
        return;
    }

    int panjang = 0;
    cout << "+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+" << endl;
    cout << "| " << left << setw(18) << "No" << " | " << setw(18) << "Nama" << " | " << setw(18) << "Role" << " | " << setw(18) << "Mekanik" << " | " << setw(18) << "Posisi" << " |" << endl;
    cout << "+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+" << endl;
    
    for (int j = 0; j < 10; ++j) {
        if (listhero[posisi][j][0][0] != '\0') { 
            cout << "| " << left << setw(18) << panjang + 1 << " | " << setw(18) << listhero[posisi][j][0] << " | " << setw(18) << listhero[posisi][j][1] << " | " << setw(18) << listhero[posisi][j][2] << " | " << setw(18) << listhero[posisi][j][3] << " |" << endl;
            panjang++;
        }
    }
    
    cout << "+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+" << endl;

    if (panjang == 0) {
        cout << "Belum ada hero untuk dihapus." << endl;
    } else {
        cout << "Masukkan nomor hero yang akan dihapus: ";
        cin >> index;
        
        if (index > 0 && index <= panjang) {
    
            int actualIndex = -1;
            int count = 0;
            
            for (int j = 0; j < 10; ++j) {
                if (listhero[posisi][j][0][0] != '\0') { 
                    count++;
                    if (count == index) {
                        actualIndex = j;
                        break;
                    }
                }
            }

            if (actualIndex != -1) {
                for (int j = actualIndex; j < 9; ++j) {
                    listhero[posisi][j][0] = listhero[posisi][j + 1][0];
                    listhero[posisi][j][1] = listhero[posisi][j + 1][1];
                    listhero[posisi][j][2] = listhero[posisi][j + 1][2];
                    listhero[posisi][j][3] = listhero[posisi][j + 1][3];
                }
                
                listhero[posisi][9][0] = "";
                listhero[posisi][9][1] = "";
                listhero[posisi][9][2] = "";
                listhero[posisi][9][3] = "";
                
                cls();
                cout << "Hero berhasil dihapus." << endl;
            }
        } else {
            cls();
            cout << "Nomor hero tidak valid." << endl;
        }
    }
    cin.ignore();
}

void tampilkanHero() {
    cout << "+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+" << endl;
    cout << "| " << left << setw(18) << "Nama" << " | " << setw(18) << "Role" << " | " << setw(18) << "Mekanik" << " | " << setw(18) << "Posisi" << " |" << endl;
    
    for (int i = 0; i < 5; ++i) {
        cout << "+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+" << endl;

        for (int j = 0; j < 10; ++j) {
            if (listhero[i][j][0][0] != '\0') { // Mengganti .empty() dengan listhero[i][j][0][0] != '\0'
                cout << "| " << left << setw(18) << listhero[i][j][0] << " | " 
                    << setw(18) << listhero[i][j][1] << " | " 
                    << setw(18) << listhero[i][j][2] << " | " 
                    << setw(18) << listhero[i][j][3] << " |" << endl;
            }
        }
    }
    
    cout << "+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+" << endl;
}

void lihatAkunUser() {
    cout << "+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+" << endl;
    cout << "| " << left << setw(18) << "Username" << " | " << setw(18) << "Role" << " | " << setw(18) << "Main Hero" << " | " << setw(18) << "Main Role" << " | " << setw(18) << "Rank Akun" << " |" << endl;
    cout << "+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+" << endl;
    
    for (int i = 0; i < jumlahAkun; ++i) {
        if (user[i].username != "" && user[i].role != "admin") {
            cout << "| " << left << setw(18) << user[i].username << " | " << setw(18) << user[i].role << " | " << setw(18) << user[i].isiakun.heromain << " | " << setw(18) << user[i].isiakun.mainrole << " | " << setw(18) << user[i].isiakun.rankakun << " |" << endl;
        }
    }
    
    cout << "+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+" << endl;
}

bool registerUser(string newUsername, string newPassword, string newRole) {
    if (newRole == "admin") {
        user[jumlahAkun] = {{"", "", ""}, newUsername, newPassword, newRole};
        jumlahAkun++;
        return true;
    } else if (newRole == "user") {
        string heromain, mainrole, rankakun;
        
        cout << "Masukkan hero main: ";
        getline(cin, heromain);
        
        cout << "Masukkan main role: ";
        getline(cin, mainrole);
        
        cout << "Masukkan rank akun: ";
        getline(cin, rankakun);
        
        user[jumlahAkun] = {{heromain, mainrole, rankakun}, newUsername, newPassword, newRole};
        jumlahAkun++;
        return true;
    }
    
    return false;
}

int posisiindex(string posisi) {
    if (posisi == "1") return 0;
    if (posisi == "2") return 1;
    if (posisi == "3") return 2;
    if (posisi == "4") return 3;
    if (posisi == "5") return 4;
    return -1;
}

string posisistr(int index) {
    switch (index) {
        case 0: return "Jungle";
        case 1: return "Roam";
        case 2: return "Mid";
        case 3: return "Gold";
        case 4: return "EXP";
        default: return "";
    }
}