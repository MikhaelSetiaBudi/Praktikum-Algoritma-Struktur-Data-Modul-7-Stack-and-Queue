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