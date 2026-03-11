#include <iostream>
using namespace std;

/* Hàm nhập phân số
Input: tử số t, mẫu số m
Output: giá trị t và m được nhập từ bàn phím */
void Nhap(int &t, int &m){
    cin >> t >> m;
}
/* Hàm tìm UCLN
Input: t, m
Output: ước chung lớn nhất của t và m */
int UCLN(int a, int b){ //biến trung gian
    a = abs(a);
    b = abs(b);

    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

/* Hàm rút gọn phân số
Input: t, m
Output: phân số đã rút gọn */
void RutGon(int &t, int &m){

    int g = UCLN(t,m);

    t = t / g;
    m = m / g;

    // chuẩn hóa dấu
    if(m < 0){
        t = -t;
        m = -m;
    }
}
/* Hàm xuất phân số
Input: t, m
Output: in phân số ra màn hình */
void Xuat(int t, int m){
    cout << t << "/" << m;
}

int main(){

    int t, m;

    Nhap(t,m);

    if(m == 0){
        cout << "Mau so khong hop le";
        return 0;
    }

    RutGon(t,m);

    Xuat(t,m);

    return 0;
}
