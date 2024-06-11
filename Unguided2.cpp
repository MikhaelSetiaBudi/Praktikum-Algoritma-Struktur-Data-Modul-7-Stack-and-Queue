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