#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct HocSinh {
    string hoten;
    float toan;
    float van;
};

// hàm kiểm tra có phải chữ số ?
bool laChuSo(char c) {
    return (c >= '0' && c <= '9');
}

// kiểm tra họ tên hợp lệ 
bool hopLeTen(string s) {
    if (s.length() == 0) {
        return false;
    }

    for (int i = 0; i < s.length(); i++) {
        if (laChuSo(s[i])) {
            return false;
        }
    }

    return true;
}

// nhập điểm có kiểm tra
float nhapDiem(string mon) {
    float x;

    while (true) {
        cout << "Nhap diem " << mon << ": ";
        cin >> x;

        if (cin.fail()) {
            cout << "Loi! Phai nhap so.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if (x < 0 || x > 10) {
            cout << "Diem phai la so tu 0 den 10.\n";
        }
        else {
            return x;
        }
    }
}

// nhập thông tin học sinh
void nhapHocSinh(HocSinh &hs) {
    cin.ignore();
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

// xuất thông tin
void xuatHocSinh(HocSinh hs) {
    float dtb = tinhDTB(hs);

    cout << "\nThong tin hoc sinh\n";
    cout << "Ho ten: " << hs.hoten << endl;
    cout << "Diem Toan: " << hs.toan << endl;
    cout << "Diem Van: " << hs.van << endl;
    cout << "Diem trung binh: " << dtb << endl;
}

int main() {
    HocSinh hs;

    nhapHocSinh(hs);
    xuatHocSinh(hs);

    return 0;
}
