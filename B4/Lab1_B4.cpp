#include <iostream>
using namespace std;

struct Ngay {
    int ngay;
    int thang;
    int nam;
};

// kiểm tra năm nhuận
bool ktraNamNhuan(int nam) {
    if (nam % 400 == 0) return true;
    if (nam % 4 == 0 && nam % 100 != 0) return true;
    return false;
}

// số ngày trong tháng
int soNgayTrongThang(int thang, int nam) {
    switch (thang) {
        case 1: case 3: case 5: case 7:
        case 8: case 10: case 12:
            return 31;

        case 4: case 6: case 9: case 11:
            return 30;

        case 2:
            if (ktraNamNhuan(nam)) return 29;
            else return 28;
    }
    return 0;
}

// kiểm tra ngày hợp lệ
bool KiemTraNgay(Ngay d) {
    if (d.thang < 1 || d.thang > 12) return false;
    if (d.ngay < 1 || d.ngay > soNgayTrongThang(d.thang, d.nam)) return false;
    return true;
}

// tính ngày kế tiếp
void ngayKeTiep(Ngay &d) {
    d.ngay++;

    if (d.ngay > soNgayTrongThang(d.thang, d.nam)) {
        d.ngay = 1;
        d.thang++;

        if (d.thang > 12) {
            d.thang = 1;
            d.nam++;
        }
    }
}

int main() {
    Ngay a;

    cout << "Nhap ngay thang nam: ";
    cin >> a.ngay >> a.thang >> a.nam;

    // kiểm tra hợp lệ
    if (!KiemTraNgay(a)) {
        cout << "Ngay khong hop le!";
        return 0;
    }

    // tính ngày kế tiếp
    ngayKeTiep(a);

    cout << "Ngay ke tiep: ";
    cout << a.ngay << "/" << a.thang << "/" << a.nam;

    return 0;
}
