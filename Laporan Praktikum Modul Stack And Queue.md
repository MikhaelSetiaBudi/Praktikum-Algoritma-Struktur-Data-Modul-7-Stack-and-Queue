# <h1 align="center">Laporan Praktikum Modul Stack And Queue</h1>
<p align="center">Mikhael Setia Budi</p>

## Dasar Teori

### STACK
Stack adalah struktur data sederhana yang digunakan untuk menyimpan data (mirip dengan Linked Lists). Dalam tumpukan, urutan kedatangan data penting.
Sebuah tumpukan piring di kafetaria adalah contoh bagus dari tumpukan. Sebuah tumpukan adalah daftar terurut di mana penyisipan dan penghapusan dilakukan di satu ujung, disebut atas. Elemen terakhir yang
dimasukkan adalah yang pertama dihapus. Oleh karena itu, disebut daftar Last in First out (LIFO).

### QUEUE
Queue adalah struktur data yang digunakan untuk menyimpan data dengan metode FIFO (First-In First-Out). Data yang pertama dimasukkan ke dalam queue akan
menjadi data yang pertama pula untuk dikeluarkan dari queue. Queue mirip dengan konsep antrian pada kehidupan sehari-hari, dimana konsumen yang datang lebih dulu akan dilayani terlebih dahulu.


## Guided 

### 1. Stack

```C++
#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty() {
    return (top == 0);
}

void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] = "";
        top--;
    }
}

void peekArrayBuku(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

int countStack() {
    return top;
}

void changeArrayBuku(int posisi, string data) {
    if (posisi > top) {
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        arrayBuku[index] = data;
    }
}

void destroyArraybuku() {
    for (int i = top; i >= 0; i--) {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main() {
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";
    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;
    peekArrayBuku(2);
    popArrayBuku();
    cout << "Banyaknya data = " << countStack() << endl;
    changeArrayBuku(2, "Bahasa Jerman");
    cout << endl;
    cetakArrayBuku();
    cout << "\n";
    destroyArraybuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;
    cetakArrayBuku();

    return 0;
}
```

**Code 1**
```C++

```
kode diatas digunakan untuk mendefinisikan header file iostream yang berisi definisi objek input dan output standar seperti cin, dan cout. 
using namespace std digunakan untuk menggunakan namespace std.

**Code 2**
```C++

```


**Code 3**
```C++

```


**Code 4**
```C++

```


**Code 5**
```C++

```


#### Output
```C++
Inggris
Dasar Multimedia
Matematika Diskrit
Struktur Data
Kalkulus

Apakah data stack penuh? 1
Apakah data stack kosong? 0
Posisi ke 2 adalah Dasar Multimedia
Banyaknya data = 4

Dasar Multimedia
Bahasa Jerman
Struktur Data
Kalkulus

Jumlah data setelah dihapus: 0
Tidak ada data yang dicetak
```


#### Full Code Screenshoot
![alt text](https://github.com/MikhaelSetiaBudi/Praktikum-Algoritma-Struktur-Data-Modul-7-Stack-and-Queue/blob/master/Modul%207%20Alstrukdat/Code%20Guided%201%20Stack%20and%20Queue.png?raw=true)

#### Output Screenshot
![alt text](https://github.com/MikhaelSetiaBudi/Praktikum-Algoritma-Struktur-Data-Modul-7-Stack-and-Queue/blob/master/Output%20Modul%207%20Alstrukdat/Output%20Guided%201%20Stack%20and%20Queue.png?raw=true)

### 2. Queue

```C++
#include <iostream>
using namespace std;

const int maksimalQueue = 5; // Maksimal antrian
int front = 0; // Penanda depan antrian
int back = 0; // Penanda belakang antrian
string queueTeller[5]; // Array untuk menyimpan antrian

bool isFull() { // Pengecekan antrian penuh atau tidak
    if (back == maksimalQueue) {
        return true; // =1
    } else {
        return false;
    }
}

bool isEmpty() { // Antrian kosong atau tidak
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian(string data) { // Menambahkan antrian
    if (isFull()) {
        cout << "Antrian penuh" << endl;
    } else {
        if (isEmpty()) { // Jika antrian kosong
            queueTeller[0] = data;
            front++;
            back++;
        } else { // Jika antrian ada isi
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() { // Mengurangi antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

int countQueue() { // Menghitung jumlah antrian
    return back;
}

void clearQueue() { // Menghapus semua antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue() { // Melihat isi antrian
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```

**Code 1**
```C++

```
kode diatas digunakan untuk mendefinisikan header file iostream yang berisi definisi objek input dan output standar seperti cin, dan cout. string digunakan untuk tipe data string. 
using namespace std digunakan untuk menggunakan namespace std.

**Code 2**
```C++

```


**Code 3**
```C++

```


**Code 4**
```C++

```


**Code 5**
```C++
   
```


**Code 6**
```C++

```


**Code 7**
```C++

```


#### Output
```C++
Data antrian teller:
1. Andi
2. Maya
3. (kosong)
4. (kosong)
5. (kosong)
Jumlah antrian = 2
Data antrian teller:
1. Maya
2. (kosong)
3. (kosong)
4. (kosong)
5. (kosong)
Jumlah antrian = 1
Data antrian teller:
1. (kosong)
2. (kosong)
3. (kosong)
4. (kosong)
5. (kosong)
Jumlah antrian = 0
```


#### Full Code Screenshoot
![alt text](https://github.com/MikhaelSetiaBudi/Praktikum-Algoritma-Struktur-Data-Modul-7-Stack-and-Queue/blob/master/Modul%207%20Alstrukdat/Code%20Guided%202%20Stack%20and%20Queue.png?raw=true)

#### Output Screenshot
![alt text](https://github.com/MikhaelSetiaBudi/Praktikum-Algoritma-Struktur-Data-Modul-7-Stack-and-Queue/blob/master/Output%20Modul%207%20Alstrukdat/Output%20Guided%202%20Stack%20and%20Queue.png?raw=true)

## Unguided 

### 1. Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.

```C++
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

bool isPolindrom(const string& input) {
    string filtered;
    // Menghapus karakter non-alfabet dan konversi ke huruf kecil
    for (char kalimat_2311110033 : input) {
        if (isalpha(kalimat_2311110033)) {
            filtered.push_back(tolower(kalimat_2311110033));
        }
    }

    // Mengecek apakah string adalah polindrome dengan membandingkan karakter dari depan dan belakang
    int left = 0;
    int right = filtered.length() - 1;
    while (left < right) {
        if (filtered[left] != filtered[right]) 
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    string kalimat;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    if (isPolindrom(kalimat)) {
        cout << "Kalimat tersebut adalah polindrom" << endl;
    } else {
        cout << "Kalimat tersebut bukan polindrom" << endl;
    }
    return 0;
}

// Mikhael Setia Budi
// 2311110033
// copyright@MikhaelS.B
```

**Code 1**
```C++
#include <iostream>
using namespace std;
```
kode diatas digunakan untuk mendefinisikan header file iostream yang berisi definisi objek input dan output standar seperti cin, dan cout. 
using namespace std digunakan untuk menggunakan namespace std. 

**Code 2**
```C++

```


**Code 3**
```C++

```


**Code 4**
```C++

  ```


**Code 5**
```C++

```


**Code 6**
```C++

```


#### Output:
```C++
Masukkan kalimat: Taat
Kalimat tersebut adalah polindrom
Masukkan kalimat: ini
Kalimat tersebut adalah polindrom
Masukkan kalimat: Telkom
Kalimat tersebut bukan polindrom
```


#### Full code Screenshot:
![alt text](https://github.com/MikhaelSetiaBudi/Praktikum-Algoritma-Struktur-Data-Modul-7-Stack-and-Queue/blob/master/Modul%207%20Alstrukdat/Code%20Unguided%201%20Stack%20and%20Queue.png?raw=true)

#### Output Screenshot
![alt text](https://github.com/MikhaelSetiaBudi/Praktikum-Algoritma-Struktur-Data-Modul-7-Stack-and-Queue/blob/master/Output%20Modul%207%20Alstrukdat/Output%20Unguided%201%20Stack%20and%20Queue.png?raw=true)

### 2. Ubah guided queue diatas agar menjadi program inputan user dan program menu.

```C++
#include <iostream>
using namespace std;

int maksimalQueue; 
int front = 0; 
int back = 0; 
string *queueTeller; // Pointer untuk array dinamis menyimpan antrian

bool isFull() { // Pengecekan antrian penuh atau tidak
    return back == maksimalQueue;
}

bool isEmpty() { // Antrian kosong atau tidak
    return back == 0;
}

void enqueueAntrian(string data_2311110033) { // Menambahkan antrian
    if (isFull()) {
        cout << "Antrian penuh" << endl;
    } else {
        queueTeller[back] = data_2311110033;
        back++;
    }
}

void dequeueAntrian() { // Mengurangi antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = front; i < back - 1; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

void viewQueue() { // Melihat isi antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        cout << "Isi Antrian:" << endl;
        for (int i = front; i < back; i++) {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        }
    }
}

int countQueue() { // Menghitung jumlah antrian
    return back;
}

int main() {
    cout << "Masukkan maksimal jumlah antrian: ";
    cin >> maksimalQueue;
    queueTeller = new string[maksimalQueue]; // Inisialisasi array dinamis

    int pilihan;
    string nama;

    do {
        cout << "Menu Antrian Teller:" << endl;
        cout << "1. Tambah Antrian" << endl;
        cout << "2. Kurangi Antrian" << endl;
        cout << "3. Tampilkan Antrian" << endl;
        cout << "4. Jumlah Antrian" << endl;
        cout << "5. Keluar" << endl;
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama: ";
                cin >> nama;
                enqueueAntrian(nama);
                break;
            case 2:
                dequeueAntrian();
                break;
            case 3:
                viewQueue();
                break;
            case 4:
                cout << "Jumlah antrian saat ini: " << countQueue() << endl;
                break;
            case 5:
                cout << "Terima kasih telah menggunakan program ini." << endl;
                break;
            default:
                cout << "Pilihan tidak valid, silakan coba lagi." << endl;
        }
    } while (pilihan != 5);
    delete[] queueTeller; 
    return 0;
}


// Mikhael Setia Budi
// 2311110033
// copyright@MikhaelS.B
```

#### Output:
```C++
Masukkan maksimal jumlah antrian: 3
Menu Antrian Teller:
1. Tambah Antrian
2. Kurangi Antrian
3. Tampilkan Antrian
4. Jumlah Antrian
5. Keluar
Masukkan pilihan Anda: 1
Masukkan nama: Rizal
Menu Antrian Teller:
1. Tambah Antrian
2. Kurangi Antrian
3. Tampilkan Antrian
4. Jumlah Antrian
5. Keluar
Masukkan pilihan Anda: 1
Masukkan nama: Fahmi
Menu Antrian Teller:
1. Tambah Antrian
2. Kurangi Antrian
3. Tampilkan Antrian
4. Jumlah Antrian
5. Keluar
Masukkan pilihan Anda: 1
Masukkan nama: Wisnu
Menu Antrian Teller:
1. Tambah Antrian
2. Kurangi Antrian
3. Tampilkan Antrian
4. Jumlah Antrian
5. Keluar
Masukkan pilihan Anda: 3
Isi Antrian:
1. Rizal
2. Fahmi
3. Wisnu
Menu Antrian Teller:
1. Tambah Antrian
2. Kurangi Antrian
3. Tampilkan Antrian
4. Jumlah Antrian
5. Keluar
Masukkan pilihan Anda: 2
Menu Antrian Teller:
1. Tambah Antrian
2. Kurangi Antrian
3. Tampilkan Antrian
4. Jumlah Antrian
5. Keluar
Masukkan pilihan Anda: 3
Isi Antrian:
1. Fahmi
2. Wisnu
Menu Antrian Teller:
1. Tambah Antrian
2. Kurangi Antrian
3. Tampilkan Antrian
4. Jumlah Antrian
5. Keluar
Masukkan pilihan Anda: 4
Jumlah antrian saat ini: 2
Menu Antrian Teller:
1. Tambah Antrian
2. Kurangi Antrian
3. Tampilkan Antrian
4. Jumlah Antrian
5. Keluar
Masukkan pilihan Anda: 5
Terima kasih telah menggunakan program ini.
```

#### Full code Screenshot:
![alt text](https://github.com/MikhaelSetiaBudi/Praktikum-Algoritma-Struktur-Data-Modul-7-Stack-and-Queue/blob/master/Modul%207%20Alstrukdat/Code%20Unguided%202%20Stack%20and%20Queue.png?raw=true)

#### Output Screenshot
![alt text](https://github.com/MikhaelSetiaBudi/Praktikum-Algoritma-Struktur-Data-Modul-7-Stack-and-Queue/blob/master/Output%20Modul%207%20Alstrukdat/Output%20Unguided%202%20Stack%20and%20Queue%20(1).png?raw=true)

![alt text](https://github.com/MikhaelSetiaBudi/Praktikum-Algoritma-Struktur-Data-Modul-7-Stack-and-Queue/blob/master/Output%20Modul%207%20Alstrukdat/Output%20Unguided%202%20Stack%20and%20Queue%20(2).png?raw=true)

![alt text](https://github.com/MikhaelSetiaBudi/Praktikum-Algoritma-Struktur-Data-Modul-7-Stack-and-Queue/blob/master/Output%20Modul%207%20Alstrukdat/Output%20Unguided%202%20Stack%20and%20Queue%20(3).png?raw=true)


## Kesimpulan
Variabel merupakan tempat untuk menyimpan data dengan tipe data tertentu. variabel tidak dapat menyimpan lebih dari 1 nilai, jika ingin menyimpan lebih dari 1 nilai maka perlu mendeklarasikan variabel sebagai array. variabel terbagi menjadi dua yaitu variabel lokal dan variabel global. struct terdiri dari tipe data standar maupun tipe data bentukan lainnya yang telah didefinisikan. terdapat 3 format dalam struct.

## Referensi
[1]	Q. Muhammad et al., “Penggunaan Bahasa C++ dalam Perkuliahan Jurusan Teknik Elektro Fakultas Teknik,” vol. 3, no. 1, pp. 143–151, 2024, [Online]. Available: http://jurnalilmiah.org/journal/index.php/majemuk
