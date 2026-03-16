#include <iostream>
using namespace std;

struct Ngay{
    int ngay;
    int thang;
    int nam;
};

bool ktraNamNhuan(int nam){
    if(nam % 400 == 0) return true;
    if(nam % 4 == 0 && nam % 100 != 0) return true;
    return false;
}

/*
Hàm trả về số ngày trong một tháng
Input: thang, nam
Output: số ngày của tháng đó
*/
int NgayMay(int thang, int nam){
    switch(thang){
        case 1: case 3: case 5: case 7:
        case 8: case 10: case 12:
            return 31;

        case 4: case 6: case 9: case 11:
            return 30;

        case 2:
            if(ktraNamNhuan(nam)) return 29;
            else return 28;
    }
    return 0;
}

/*
Hàm cộng thêm một số ngày vào ngày ban đầu
Input:
- d: ngày ban đầu
- soNgayThem: số ngày cần cộng

Output:
- cập nhật lại ngày mới
*/
void themNgay(Ngay &d, int soNgayThem){

    d.ngay += soNgayThem;

    while(d.ngay > NgayMay(d.thang, d.nam)){
        d.ngay -= NgayMay(d.thang, d.nam);
        d.thang++;

        if(d.thang > 12){
            d.thang = 1;
            d.nam++;
        }
    }
}

int main(){

    Ngay a;

    // Nhập ngày ban đầu
    cin >> a.ngay >> a.thang >> a.nam;

    int soNgay;
    cin >> soNgay;

    // Cộng thêm ngày
    themNgay(a, soNgay);

    // Xuất kết quả
    cout << a.ngay << "/" << a.thang << "/" << a.nam;

    return 0;
}
