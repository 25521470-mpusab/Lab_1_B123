#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct HocSinh {
    string hoten;
    float toan;
    float van;
};

// kiểm tra nhập vào họ tên 
bool hopLeTen(string s) {
    if (s.length() == 0) {
        return false;
    }
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        if (isdigit(c)) {
            return false;
        }
    }
    return true;
}

// Kiểm tra nhập điểm
float nhapDiem(string mon) {
    float x;
    while (true) {
        cout << "Nhap diem " << mon << ": ";
        cin >> x;

        if (cin.fail()) {
            cout << "❌ Loi: Vui long nhap so!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } 
        else if (x < 0 || x > 10) {
            cout << "❌ Diem phai tu 0 den 10!\n";
        } 
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return x;
        }
    }
}

// nhập thông tin học sinh
void nhapHocSinh(HocSinh &hs) {
    do {
        cout << "Nhap ho ten: ";
        getline(cin, hs.hoten);

        if (!hopLeTen(hs.hoten)) {
            cout << "Ten khong hop le (khong duoc chua so)\n";
        }

    } while (!hopLeTen(hs.hoten));

    hs.toan = nhapDiem("Toan");
    hs.van = nhapDiem("Van");
}

// tính điểm trung bình
float tinhDTB(HocSinh hs) {
    return (hs.toan + hs.van) / 2;
}

// xếp loại
string xepLoai(float dtb) {
    if (dtb >= 8) return "Gioi";
    else if (dtb >= 6.5) return "Kha";
    else if (dtb >= 5) return "Trung binh";
    else return "Yeu";
}

// xuất thông tin
void xuatHocSinh(HocSinh hs) {
    float dtb = tinhDTB(hs);

    cout << "\nThong tin hoc sinh\n";
    cout << "Ho ten: " << hs.hoten << endl;
    cout << "Diem Toan: " << hs.toan << endl;
    cout << "Diem Van: " << hs.van << endl;
    cout << "Diem trung binh: " << dtb << endl;
    cout << "Xep loai: " << xepLoai(dtb) << endl;
}

// main
int main() {
    HocSinh hs;

    nhapHocSinh(hs);
    xuatHocSinh(hs);

    return 0;
}
