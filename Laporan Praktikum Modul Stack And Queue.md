# <h1 align="center">Laporan Praktikum Modul Stack And Queue</h1>
<p align="center">Mikhael Setia Budi</p>

## Dasar Teori

### STACK
Stack adalah struktur data sederhana yang digunakan untuk menyimpan data (mirip dengan Linked Lists). Dalam tumpukan, urutan kedatangan data penting.
Sebuah tumpukan piring di kafetaria adalah contoh bagus dari tumpukan. Sebuah tumpukan adalah daftar terurut di mana penyisipan dan penghapusan dilakukan di satu ujung, disebut atas. Elemen terakhir yang
dimasukkan adalah yang pertama dihapus. Oleh karena itu, disebut daftar Last in First out (LIFO).
Operasi pada stack melibatkan beberapa fungsi dasar yang dapat dilakukan pada
struktur data ini. 

Berikut adalah beberapa operasi umum pada stack:

a. Push (Masukkan): Menambahkan elemen ke dalam tumpukan pada posisi paling
atas atau ujung.

b. Pop (Keluarkan): Menghapus elemen dari posisi paling atas atau ujung tumpukan.

c. Top (Atas): Mendapatkan nilai atau melihat elemen teratas pada tumpukan tanpa
menghapusnya.

d. IsEmpty (Kosong): Memeriksa apakah tumpukan kosong atau tidak.

e. IsFull (Penuh): Memeriksa apakah tumpukan penuh atau tidak (terutama pada
implementasi tumpukan dengan kapasitas terbatas).

f. Size (Ukuran): Mengembalikan jumlah elemen yang ada dalam tumpukan.

g. Peek (Lihat): Melihat nilai atau elemen pada posisi tertentu dalam tumpukan
tanpa menghapusnya.

h. Clear (Hapus Semua): Mengosongkan atau menghapus semua elemen dari
tumpukan.

i. Search (Cari): Mencari keberadaan elemen tertentu dalam tumpukan.

### QUEUE
Queue adalah struktur data yang digunakan untuk menyimpan data dengan metode FIFO (First-In First-Out). First-In First-Out (FIFO) adalah sebuah metode pemecahan dalam masalah antrian yang dapat diterapkan dengan cara laporan pengaduan yang pertama kali masuk diasumsikan keluar pertama kali [1]. Data yang pertama dimasukkan ke dalam queue akan
menjadi data yang pertama pula untuk dikeluarkan dari queue. Queue mirip dengan konsep antrian pada kehidupan sehari-hari, dimana konsumen yang datang lebih dulu akan dilayani terlebih dahulu.Perbedaan antara stack dan queue terdapat pada aturan penambahan dan penghapusan elemen. Pada stack, operasi penambahan dan penghapusan elemen dilakukan di satu ujung. Elemen yang terakhir diinputkan akan berada paling dengan dengan ujung atau dianggap paling atas sehingga pada operasi penghapusan, elemen teratas tersebut akan dihapus paling awal, sifat demikian dikenal dengan LIFO.

Operasi pada Queue
1. enqueue() : menambahkan data ke dalam queue.
2. dequeue() : mengeluarkan data dari queue.
3. peek() : mengambil data dari queue tanpa menghapusnya.
4. isEmpty() : mengecek apakah queue kosong atau tidak.
5. isFull() : mengecek apakah queue penuh atau tidak.
6. size() : menghitung jumlah elemen dalam queue.
   
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
#include <iostream>
using namespace std;
```
kode diatas digunakan untuk mendefinisikan header file iostream yang berisi definisi objek input dan output standar seperti cin, dan cout. 
using namespace std digunakan untuk menggunakan namespace std.

**Code 2**
```C++
string arrayBuku[5];
int maksimal = 5, top = 0;
```
kode diatas digunakan untuk mendeklarasikan variabel arrayBuku dengan tipe data string dan kapasitas 5 yang digunakan untuk menyimpan elemen stack. variabel maksimal adalag batas maksimum ukuran stack yaitu 5. variabel top digunakan untuk menunjukkan posisi elemen teratas di stack. awalnya diatur ke 0.

**Code 3**
```C++
bool isFull() {
    return (top == maksimal);
}
```
Fungsi isFull digunakan untuk mengembalikan true jika stack penuh, artinya variabel top sama dengan maksimal, dan false jika tidak penuh.

**Code 4**
```C++
bool isEmpty() {
    return (top == 0);
}
```
fungsi isEmpty digunakan untuk mengembalikan true jika stack kosong yang artinya top sama dengan 0, dan false jika tidak kosong.

**Code 5**
```C++
void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuku[top] = data;
        top++;
    }
}
```
fungsi pushArrayBuku digunakan untuk mengembalikan elemen baru (data) ke stack jika stack tidak penuh. jika stack penuh maka akan mencetak pesan "Data telah penuh".

**Code 6**
```C++
void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] = "";
        top--;
    }
}
```
fungsi popArrayBuku digunakan untuk menghapus elemen teratas dari stack jika stack tidak kosong, jika stack kosong maka akan mencetak pesan "Tidak ada data yang dihapus".

**Code 7**
```C++
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
```
fungsi peekArrayBuku digunakan untuk menampilkan elemen pada posisi tertentu dari puncak stack jika stack tidak kosong. jika stack kosong maka akan menampilkan pesan "Tidak ada data yang bisa dilihat".

**Code 8**
```C++
int countStack() {
    return top;
}
```
fungsi coutStack digunakan untuk mengembalikan jumlah elemen dalam stack.

**Code 9**
```C++
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
```
fungsi changeArrayBuku digunakan untuk mengganti elemen pada posisi tertentu dari puncak stack dengan data baru jika posisi valid yang artinya tidak melebihi jumlah elemen dalam stack. jika posisi tidak valid maka akan menampilkan pesan "Posisi melebihi data yang ada".

**Code 10**
```C++
void destroyArraybuku() {
    for (int i = top; i >= 0; i--) {
        arrayBuku[i] = "";
    }
    top = 0;
}
```
fungsi destroyArraybuku digunakan untuk menghapus semua elemen dalam stack dan mengatur top kembali ke 0.

**Code 11**
```C++
void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}
```
fungsi cetakArrayBuku digunakan untuk mencetak semua elemen dalam stack dari atas ke bawah jika stack tidak kosong, tetapi jika stack kosong makan akan menampilkan "Tidak ada data yang dicetak".

**Code 12**
```C++
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
fungsi main merupakan fungsi utama dimana fungsi ini melakukan beberapa operasi pada stack yaitu menambahkan lima buku ke stack, mencetak semua buku dalam stack, mengecek apakah stack penuh atau kosong, melihat buku pada posisi ke-2 dari atas. menghapus elemen teratas dari stack, menampilkan jumlah elemen dalam stack, mengubah buku pada posisi ke-2 dari atas menjadi Bahasa Jerman, mencetak ulang semua buku dalam stack setelah perubahan, menghapus semua elemen dalam stack, dan menampilkan jumlah elemen setelah dihapus dan mencoba mencetak ulang semua buku.

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
menampilkan banyaknya data yaitu 5, lalu mengganti posisi kedua menjadi Bahasa Jerman.

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
#include <iostream>
using namespace std;
```
kode diatas digunakan untuk mendefinisikan header file iostream yang berisi definisi objek input dan output standar seperti cin, dan cout. 
using namespace std digunakan untuk menggunakan namespace std.

**Code 2**
```C++
const int maksimalQueue = 5; // Maksimal antrian
int front = 0; // Penanda depan antrian
int back = 0; // Penanda belakang antrian
string queueTeller[5]; // Array untuk menyimpan antrian
```
mendeklarasikan variabel maksimalQueue yang digunakan untuk kapasitas maksimum antrian yaitu 5. variabel front digunakan untuk penanda indeks depan antrian, awalnya diatur ke 0. variabel back digunakan untuk penanda indeks belakang antrian, awalnya diatur ke 0. queueTeller merupakan array string dengan ukuran 5 yang digunakan untuk menyimpan elemen antrian.

**Code 3**
```C++
bool isFull() { // Pengecekan antrian penuh atau tidak
    if (back == maksimalQueue) {
        return true; // =1
    } else {
        return false;
    }
}
```
fungsi isFull digunakan untuk mengecek antrian penuh atau tidak. fungsi ini akan mengembalikan true jika antrian penuh yaitu back sama dengan maksimalQueue, dan akan mengembalikan false jika tidak penuh.

**Code 4**
```C++
bool isEmpty() { // Antrian kosong atau tidak
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}
```
fungsi isEmpety akan mengembalikan true jika antrian kosong yaitu back sama dengan 0, dan akan mengembalikan false jika antrian tidak kosong.


**Code 5**
```C++
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
```
fungsi enqueueAntrian digunakan untuk menambahkan elemen baru (data) ke dalam antrian jika antrian tidak penuh. jika antrian penuh maka akan mencetak pesan "Antrian penuh". ketika antrian kosong maka data dimasukkan ke posisi 0 dan front serta back dinaikan, tetapi jika antrian tidak kosong maka data yang dimasukkan akan ke posisi back dan back dinaikan.


**Code 6**
```C++
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
```
fungsi dequeueAntrian digunakan untuk menghapus elemen terdepan dari antrian tidak kosong. jika antrian kosong maka akan mencetak pesan "Antrian kosong". setiap elemen antrian digeser satu posisi ke depan untuk menghapus elemen terdepan, dan back kemudian dikurangi satu.

**Code 7**
```C++
int countQueue() { // Menghitung jumlah antrian
    return back;
}
```
fungsi coutQueue digunakan untuk mengembalikan jumlah elemen dalam atrian yaitu nailai back.

**Code 8**
```C++
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
```
fungsi clearQueue digunakan untuk menghapus semua elemen dalam antrian jika antrian terisi atau tidak kosong, tetapi jika antrian kosong maka akan mencetak pesan "Antrian kosong". setiap elemen antrian diatur menjadi string kosong. back dan front diatur kenbali ke 0.

**Code 9**
```C++
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
```
fungsi viewQueue digunakan untuk menampilkan isi antrian. jika suatu elemen tidak kosong maka akan mencetak elemen tersebut beserta indeksnya (dimulai dari 1), tetapi jika elemen kosong maka akan mencetak "(kosong)" beserta indeksnya.

**Code 10**
```C++
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
fungsi main merupakan fungsi utama dalam program dimana fungsi ini akan melakukan beberapa operasi pada antrian yaitu menambahlan Andi dan Maya ke antrian, menampilkan isi antrian, menampilkan jumlah elemen dalam antrian, menghapus elemen terdepan dari antrian, menampilkan isi antrian setelah penghapusan, menampilkan jumlah elemen dalam antrian, menghapus semua elemen dari antrian, menampilkan isi antrian setelah semua elemen dihapus, dan menampilkan jumlah elemen dalam antrian setelah semua elemen dihapus.

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
menampilkan daftar antrian dengan data maksimal yaitu 5. lalu terdapat dua nama dalam antrian yaitu andi dan maya, dan menampilkan jumlah antrian. program akan berjalan sampai daftar antrian habis.

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
#include <stack>
#include <string>
#include <algorithm>

using namespace std;
```
kode diatas digunakan untuk mendefinisikan header file iostream yang berisi definisi objek input dan output standar seperti cin, dan cout. include stack merupakan header untuk menggunakan stack. include string digunakan untuk memanpulasi string. include algorithm digunakan untuk fungsi algoritma standar, seperti transform.
using namespace std digunakan untuk menggunakan namespace std. 

**Code 2**
```C++
bool isPolindrom(const string& input) {
    string filtered;
    // Menghapus karakter non-alfabet dan konversi ke huruf kecil
    for (char kalimat_2311110033 : input) {
        if (isalpha(kalimat_2311110033)) {
            filtered.push_back(tolower(kalimat_2311110033));
        }
    }
```
mendefinisikan fungsi isPolindrom yang menerima sebuah string sebagai argumen dan mengembalikan nilai boolean. mendeklarasikan variabel string filtered untuk menyimpan karakter yang sudah difilter. melakukan iterasi terhadap setiap karakter kalimat_2311110033 dalam string input. isalpha(kalimat_2311110033) digunakan untuk mengecek apakah kalimat_2311110033 adalah karakgter alfabet. tolower(kalimat_2311110033) digunakan untuk mengubah karakter alfabet kalimat_2311110033 menjadi huruf kecil. filtered.push_back digunakan untuk menambahkan karakter yang telah diubah menjadi huruf kecil ke string filtered.

**Code 3**
```C++
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
```
mendeklarasikan dua variabel left dan right untuk digunakan sebagai indeks. left diinisialisasi dengan nilai 0 (awal string). right diinisialisasi dengan nilai filterd.lenght() - 1 (akhir string). while (left < right) merupakan loop yang berjalan selama left kurang dari right. perulangan if digunakan untuk mengecek apakah karakter pada posisi left tidak sama dengan karakter pada posisi right. jika tidak sama maka fungsi akan mengembalikan false yang menandakan bahwa string bukan polindrom. left++ digunakan untuk meningkatkan indeks left untuk memeriksa karakter berikutnya dari depan. right-- digunakan mengurangi indeks right untuk memeriksa karakter berikutnya dari belakang. return true digunakan jika loop selesai tanpa menemukan ketidaksamaan maka fungsi mengembalikan true yang menandakan bahwa string adalah polindrom.

**Code 4**
```C++
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
```
fungsi main merupakan fungsi utama yang akan dijalankan dalam program. mendeklarasikan variabel kalimat untuk menyimpan input dari pengguna. mencetak pesan untuk meminta pengguna memasukkan kalimat. menggunakan getline(cin, kalimat) untuk membaca seluruh kalimat yang dimasukkan pengguna termasuk spasi. kode diatas memanggil fungsi isPolindrom dengan argumen kalimat, jika true maka akan mencetak "Kalimat terebut adalah polindrom", tetapi jika false maka akan mencetak "Kalimat tersebut bukan polindrom. mengembalikan nilai 0 menandakan bahwa program telah selesai dengan sukses.

#### Output:
```C++
Masukkan kalimat: Taat
Kalimat tersebut adalah polindrom
Masukkan kalimat: ini
Kalimat tersebut adalah polindrom
Masukkan kalimat: Telkom
Kalimat tersebut bukan polindrom
```
pengguna akan diminta untuk memasukkan kalimat. setelah pengguna memasukkan kalimat maka akan dicek apakah kalimat tersebut adalah polindrom atau bukan polindrom.

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

**Code 1**
```C++
#include <iostream>
using namespace std;
```
kode diatas digunakan untuk mendefinisikan header file iostream yang berisi definisi objek input dan output standar seperti cin, dan cout. 
using namespace std digunakan untuk menggunakan namespace std.

**Code 2**
```C++
int maksimalQueue; 
int front = 0; 
int back = 0; 
string *queueTeller; // Pointer untuk array dinamis menyimpan antrian
```
mendeklarasikan variabel maksimalQueue yang digunakan untuk menyimpan kapasitas maksimum antrian. variabel front digunakan untuk menunjuk elemen pertama pada antrian. variabel back digunakan untuk menunjuk elemen terakhir antrian. queueTeller adalah pointer untuk array dinamis yang akan digunakan sebagai antrian.

**Code 3**
```C++
bool isFull() { // Pengecekan antrian penuh atau tidak
    return back == maksimalQueue;
}
```
fungsi isFull digunakan untuk mengecek apakah antrian penuh dengan membandingkan nilai back dengan maksimalQueue.

**Code 4**
```C++
bool isEmpty() { // Antrian kosong atau tidak
    return back == 0;
}
```
Fungsi isEmpty digunakan untuk mengecek apakah antrian kosong dengan memeriksa apakah back bernilai 0.

**Code 5**
```C++
void enqueueAntrian(string data_2311110033) { // Menambahkan antrian
    if (isFull()) {
        cout << "Antrian penuh" << endl;
    } else {
        queueTeller[back] = data_2311110033;
        back++;
    }
}
```
fungsi enqueueAntrian digunakan untuk menambahkan elemen ke antrian. jika antrian penuh maka akan mencetak pesan "Antrian penuh", tetapi jika antrian tidak penuh maka menambahkan elemen data_2311110033 ke indeks back dan meningkatkan nilai back.

**Code 6**
```C++
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
```
fungsi dequeueAntrian digunakan untuk menghapus elemen dari antrian. jika antrian kosong maka akan mencetak pesan "Antrian kosong, tetapi jika antrian tidak kosong maka akan menggeser semua elemen ke kiri dan mengurangi nilai back.

**Code 7**
```C++
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
```
fungsi viewQueue digunakan untuk menampilkan semua elemen dalam antrian. jika antrian kosong maka akan mencetak pesan "Antrian kosong", tetapi jika antrian tidak kosong maka akan mencetak semua elemen antrian dengan indeksnya.

**Code 8**
```C++
int countQueue() { // Menghitung jumlah antrian
    return back;
```
fungsi countQueue digunakan untuk mengembalikan jumlah elemen dalam antrian dengan mengembalikan nilai back.

**Code 9**
```C++
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
```
fungsi main merupakan fungsi utama yang dijalankan dalam program. dimana dalam fungsi main terdaoat program yang meminta pengguna memasukkan kapasitas maksimum antrian dan menginisialisasi array dinamis queueTeller. menampilkan menu yang akan dipilih oleh pengguna dimana dalam menu terdapat 5 case. case 1 merupakan pilihan untuk menambahkan elemen ke antrian, case 2 merupakan pilihan untuk menghapus elemen dari antrian, case 3 merupakan pilihan untuk menampilkan elemen dalam antrian, case 4 merupakan pilihan untuk menampilkan jumlah elemen dalam antrian, dan case 5 merupakan pilihan untuk keluar dari program. default digunakan untuk menangani inputan yang tidak valid. menghapus array dinamis queueTeller setelah selesai digunakan untuk mencegah kebocoran memori. lalu mengembalikan nilai 0 untuk menandakan program telah selesai.

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
pengguna akan disuruh menginputkan berapa nilai maksimum array, lalu menambahkan data dalam antrian, pengguna juga bisa mengurangi data dalam antrian, setelah dapat menampilkan antrian, dan dapat melihat jumlah antrian.

#### Full code Screenshot:
![alt text](https://github.com/MikhaelSetiaBudi/Praktikum-Algoritma-Struktur-Data-Modul-7-Stack-and-Queue/blob/master/Modul%207%20Alstrukdat/Code%20Unguided%202%20Stack%20and%20Queue.png?raw=true)

#### Output Screenshot
![alt text](https://github.com/MikhaelSetiaBudi/Praktikum-Algoritma-Struktur-Data-Modul-7-Stack-and-Queue/blob/master/Output%20Modul%207%20Alstrukdat/Output%20Unguided%202%20Stack%20and%20Queue%20(1).png?raw=true)

![alt text](https://github.com/MikhaelSetiaBudi/Praktikum-Algoritma-Struktur-Data-Modul-7-Stack-and-Queue/blob/master/Output%20Modul%207%20Alstrukdat/Output%20Unguided%202%20Stack%20and%20Queue%20(2).png?raw=true)

![alt text](https://github.com/MikhaelSetiaBudi/Praktikum-Algoritma-Struktur-Data-Modul-7-Stack-and-Queue/blob/master/Output%20Modul%207%20Alstrukdat/Output%20Unguided%202%20Stack%20and%20Queue%20(3).png?raw=true)


## Kesimpulan
stack adalah struktur data sederhana yang digunakan untuk menyimpan data. dalam stack terdapat beberapa fungsi dasar yaitu push untuk menambahkan elemen, pop untuk menghapus elemen, top untuk mendapatkan nilai elemen teratas, IsEmpty untuk memeriksa apakah tumpukkan kosong atau tidak, IsFull untuk memeriksa apakah tumpukan penuh atau tidak, Size untuk mengembalikan jumlah elemen, Peek untuk melihat nilai atau elemen pada posisi tertentu, Clear untuk mengosongkan atau menghapus semua elemen, dan Search untuk mencari keberadaan elemen tertentu dalam tumpukan. Queue adalah struktur data yang digunakan untuk menyimpan data dengan metode FIFO (First-In First-Out). terdapat operasi queue yaitu enqueue digunakan untuk menambahkan data ke dalam queue, dequeue digunakan untuk mengeluarkan data dari queue, peek digunakan untuk mengambil data dari queue tanpa menghapusnya, isempty digunakan untuk mengecek apakah queue kosong, isfull digunakan untuk mengecek apakah queue penuh, dan size digunakan untuk menghitung jumlah elemen dalam queue.

## Referensi
[1]	Rizaldy Gunawan, H. Yuana, and S. Kirom, “Implementasi Metode Queue Pada Sistem Antrian Online Berbasis Web Studi Kasus Uptd Puskesmas Sananwetan,” JATI (Jurnal Mhs. Tek. Inform., vol. 7, no. 3, pp. 1538–1545, 2023, doi: 10.36040/jati.v7i3.6687.
