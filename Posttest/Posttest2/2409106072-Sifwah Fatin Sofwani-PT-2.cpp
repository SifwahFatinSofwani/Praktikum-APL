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
    string username;
    string password;
    string role;
};


Akun user[5] = {
    {"admin", "admin", "admin"},
    {"user", "user", "user"}
};

int kesempatan = 0;
int jumlahAkun = 2; // Jumlah akun yang sudah terdaftar

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

int main() {
    system("cls");

    while (true) {
        cout << "Selamat datang di program manajemen hero Mobile Legends" << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;
        cout << "Masukkan pilihan anda: ";
        getline(cin, choice);

        if (choice == "1") {
            kesempatan = 0; 
            while (kesempatan < 3) {
                
                cout << "Masukkan username: ";
                getline(cin, username);
                cout << "Masukkan password: ";  
                getline(cin, password);

                
       
                for (int i = 0; i < jumlahAkun; ++i) {
                    if (user[i].username == username && user[i].password == password) {
                        loginberhasil = true;
                        quit = false;
                        rolesekarang = user[i].role;
                        if (rolesekarang == "admin") {
                            while (true) {
                                cout << "Admin Menu:" << endl;
                                cout << "1. Tambah Hero" << endl;
                                cout << "2. Edit Hero" << endl;
                                cout << "3. Hapus Hero" << endl;
                                cout << "4. Lihat Hero" << endl;
                                cout << "5. Logout" << endl;
                                cout << "Masukkan pilihan anda: ";
                                getline(cin, choice);
                                system("cls");
                                if (choice == "1") {
                                    herotersedia = false;
                                    ada = false;
                                    cout << "Masukkan nama hero: ";
                                    getline(cin, nama);

                                    
                                    for (int i = 0; i < 5; ++i) {
                                        for (int j = 0; j < 10; ++j) {
                                            if (listhero[i][j][0] == nama) {
                                                herotersedia = true;
                                                break;
                                            }
                                        }
                                        if (herotersedia) break;
                                    }

                                    if (herotersedia) {
                                        system("cls");
                                        cout << "Hero sudah ada." << endl;
                                        continue;
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

                                    string posisiStr;
                                    int posisiIndex = -1;
                                    if (posisi == "1") {
                                        posisiIndex = 0;
                                        posisiStr = "Jungle";
                                    } else if (posisi == "2") {
                                        posisiIndex = 1;
                                        posisiStr = "Roam";
                                    } else if (posisi == "3") {
                                        posisiIndex = 2;
                                        posisiStr = "Mid";
                                    } else if (posisi == "4") {
                                        posisiIndex = 3;
                                        posisiStr = "Gold";
                                    } else if (posisi == "5") {
                                        posisiIndex = 4;
                                        posisiStr = "EXP";
                                    } else {
                                        system("cls");
                                        cout << "Posisi tidak valid." << endl;
                                        continue;
                                    }

                                    
                                    for (int j = 0; j < 10; ++j) {
                                        if (listhero[posisiIndex][j][0][0] == '\0') {
                                            listhero[posisiIndex][j][0] = nama;
                                            listhero[posisiIndex][j][1] = role;
                                            listhero[posisiIndex][j][2] = mekanik;
                                            listhero[posisiIndex][j][3] = posisiStr;
                                            system("cls");
                                            cout << "Hero berhasil ditambahkan." << endl;
                                            ada = true;
                                            break;
                                        }
                                    }
                                    if (!ada) {
                                        system("cls");
                                        cout << "Kategori penuh, tidak bisa menambah hero baru." << endl;
                                    }
                                } else if (choice == "2") {
                                    moved = false;
                                    ditemukan = false;
                                    cout << "+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+" << endl;
                                    cout << "| " << left << setw(18) << "Nama" << " | " << setw(18) << "Role" << " | " << setw(18) << "Mekanik" << " | " << setw(18) << "Posisi" << " |" << endl;

                                    for (int i = 0; i < 5; ++i) {
                                        cout << "+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+" << endl;

                                        for (int j = 0; j < 10; ++j) {
                                            if (listhero[i][j][0][0] != '\0') {
                                                cout << "| " << left << setw(18) << listhero[i][j][0] << " | " 
                                                    << setw(18) << listhero[i][j][1] << " | " 
                                                    << setw(18) << listhero[i][j][2] << " | " 
                                                    << setw(18) << listhero[i][j][3] << " |" << endl;
                                            }
                                        }
                                    }

                                    cout << "+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+" << endl;
                                    cout << "Masukkan nama hero yang ingin diedit: ";
                                    getline(cin, nama);
                                    
                                    for (int i = 0; i < 5; ++i) {
                                        for (int j = 0; j < 10; ++j) {
                                            if (listhero[i][j][0] == nama) {
                                                cout << "Masukkan role baru: ";
                                                getline(cin, listhero[i][j][1]);
                                                cout << "Masukkan tingkat mekanik baru: ";
                                                getline(cin, listhero[i][j][2]);
                                                cout << "Masukkan posisi baru: ";
                                                cout << "\n1. Jungle" << endl;
                                                cout << "2. Roam" << endl;
                                                cout << "3. Mid" << endl;
                                                cout << "4. Gold" << endl;
                                                cout << "5. EXP" << endl;
                                                cout << "Masukkan pilihan anda: ";
                                                getline(cin, choice);

                                                string posisinew;
                                                int posisibaru = -1;
                                                if (choice == "1") {
                                                   posisinew = "Jungle";
                                                    posisibaru = 0;
                                                } else if (choice == "2") {
                                                   posisinew = "Roam";
                                                    posisibaru = 1;
                                                } else if (choice == "3") {
                                                   posisinew = "Mid";
                                                    posisibaru = 2;
                                                } else if (choice == "4") {
                                                   posisinew = "Gold";
                                                    posisibaru = 3;
                                                } else if (choice == "5") {
                                                   posisinew = "EXP";
                                                    posisibaru = 4;
                                                } else {
                                                    cout << "Pilihan tidak valid." << endl;
                                                    continue;
                                                }
                                                
                                                for (int k = 0; k < 10; ++k) {
                                                    if (listhero[posisibaru][k][0][0] == '\0') {
                                                        listhero[posisibaru][k][0] = listhero[i][j][0];
                                                        listhero[posisibaru][k][1] = listhero[i][j][1];
                                                        listhero[posisibaru][k][2] = listhero[i][j][2];
                                                        listhero[posisibaru][k][3] = posisinew;

                                                        // Hapus data lama dengan menggeser elemen-elemen berikutnya ke depan
                                                        for (int l = j; l < 9; ++l) {
                                                            listhero[i][l][0] = listhero[i][l + 1][0];
                                                            listhero[i][l][1] = listhero[i][l + 1][1];
                                                            listhero[i][l][2] = listhero[i][l + 1][2];
                                                            listhero[i][l][3] = listhero[i][l + 1][3];
                                                        }
                                                

                                                        system("cls");
                                                        cout << "Hero berhasil dipindahkan." << endl;
                                                        moved = true;
                                                        break;
                                                    }
                                                }
                                                if (!moved) {
                                                    system("cls");
                                                    cout << "Kategori baru penuh, tidak bisa memindahkan hero." << endl;
                                                }
                                                ditemukan = true;
                                                break;
                                            }
                                        }
                                        if (ditemukan) break;
                                    }
                                    if (!ditemukan) {
                                        system("cls");
                                        cout << "Hero tidak ditemukan." << endl;
                                    }
                                } else if (choice == "3") {
                                    system("cls");
                                    int posisi, index;
                                    cout << "1. Jungle" << endl;
                                    cout << "2. Roam" << endl;
                                    cout << "3. Mid" << endl;
                                    cout << "4. Gold" << endl;
                                    cout << "5. EXP" << endl;
                                    cout << "Masukkan posisi hero yang akan dihapus (1-5): ";
                                    cin >> posisi;
                                    posisi--; // Sesuaikan dengan indeks array
                                    if (posisi < 0 || posisi >= 5) {
                                        cout << "Posisi tidak valid." << endl;
                                        continue;
                                    }

                                    // Tampilkan hero di posisi yang dipilih
                                    int panjang = 0;
                                    cout << "+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+" << endl;
                                    cout << "| " << left << setw(18) << "No" << " | " << setw(18) << "Nama" << " | " << setw(18) << "Role" << " | " << setw(18) << "Mekanik" << " | " << setw(18) << "Posisi" << " |" << endl;
                                    cout << "+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+" << endl;
                                    for (int j = 0; j < 10; ++j) {
                                        if (!listhero[posisi][j][0].empty()) {
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
                                            for (int j = index - 1; j < panjang - 1; ++j) {
                                                listhero[posisi][j][0] = listhero[posisi][j + 1][0];
                                                listhero[posisi][j][1] = listhero[posisi][j + 1][1];
                                                listhero[posisi][j][2] = listhero[posisi][j + 1][2];
                                                listhero[posisi][j][3] = listhero[posisi][j + 1][3];
                                                listhero[posisi][j][4] = listhero[posisi][j + 1][4];
                                            }
                                            system ("cls");
                                            cout << "Hero berhasil dihapus." << endl;
                                        } else {
                                            system("cls");
                                            cout << "Nomor hero tidak valid." << endl;
                                        }
                                    }
                                    cin.ignore();
                                } else if (choice == "4") {
                                    
                                    cout << "+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+" << endl;
                                    cout << "| " << left << setw(18) << "Nama" << " | " << setw(18) << "Role" << " | " << setw(18) << "Mekanik" << " | " << setw(18) << "Posisi" << " |" << endl;
                                
                                    for (int i = 0; i < 5; ++i) {
                                        cout << "+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+" << endl;

                                        for (int j = 0; j < 10; ++j) {
                                            if (listhero[i][j][0][0] != '\0') {
                                                cout << "| " << left << setw(18) << listhero[i][j][0] << " | " 
                                                    << setw(18) << listhero[i][j][1] << " | " 
                                                    << setw(18) << listhero[i][j][2] << " | " 
                                                    << setw(18) << listhero[i][j][3] << " |" << endl;
                                            }
                                        }
                                    }
                                    
                                    cout << "+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+" << endl;
                                } else if (choice == "5") {
                                    quit = true;
                                    break;
                                } else {
                                    system("cls");
                                    cout << "Pilihan tidak valid." << endl;
                                }
                            }
                        } else {
                            while (true) {
                                cout << "Login berhasil sebagai user." << endl;
                                cout << "1. Lihat list hero" << endl;
                                cout << "2. Logout" << endl;
                                cout << "Masukkan pilihan anda: ";
                                getline(cin, choice);
                                system("cls");

                                if (choice == "1") {
                                 
                                    cout << "+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+" << endl;
                                    cout << "| " << left << setw(18) << "Nama" << " | " << setw(18) << "Role" << " | " << setw(18) << "Mekanik" << " | " << setw(18) << "Posisi" << " |" << endl;
                                    
                                    for (int i = 0; i < 5; ++i) {
                                        cout << "+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+" << endl;
                                    
                                        for (int j = 0; j < 10; ++j) {
                                            if (listhero[i][j][0][0] != '\0') {
                                                cout << "| " << left << setw(18) << listhero[i][j][0] << " | " 
                                                    << setw(18) << listhero[i][j][1] << " | " 
                                                    << setw(18) << listhero[i][j][2] << " | " 
                                                    << setw(18) << listhero[i][j][3] << " |" << endl;
                                            }
                                        }
                                    }
                                    cout << "+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+-" << string(18, '-') << "-+" << endl;
                                } else if (choice == "2") {
                                    quit = true;
                                    break;
                                } else {
                                    system("cls");
                                    cout << "Pilihan tidak valid." << endl;
                                }
                            }
                        }
                        
                    } 
                    if (quit == true) {
                        break;
                    } 
                   
                } if (kesempatan < 3 && quit == false) {
                    system("cls");
                    cout << "Username atau password salah." << endl;
                    kesempatan++;
                }
                if (quit == true) {
                    break;
                }
                if (kesempatan == 3) {
                    system("cls");
                    cout << "Anda sudah mencoba login sebanyak 3 kali. Program berakhir." << endl;
                    return 0;
                }
            }
        } else if (choice == "2") {
            usernametersedia = false;
            if (jumlahAkun >= 5) {
                system("cls");
                system("cls");
                cout << "Kapasitas akun penuh. Tidak bisa menambah akun baru." << endl;
                continue;
            }

            system("cls");
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

            user[jumlahAkun] = {newUsername, newPassword, newRole};
            jumlahAkun++;
            system("cls");
            cout << "Registrasi berhasil." << endl;

        } else if (choice == "3") {
            cout << "Exit" << endl;
            break;
        } else {
            system("cls");
            cout << "Pilihan tidak valid" << endl;
        }
    }

    return 0;
}