#include <iostream>
using namespace std;

struct PhanSo{
    int tu;
    int mau;
};

int gcd(int a, int b){
    while(b!=0){
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}

void rutGon(PhanSo &ps){
    int g=gcd(ps.tu,ps.mau);
    ps.tu/=g;
    ps.mau/=g;
}

void nhap(PhanSo &ps){
    cin>>ps.tu>>ps.mau;
}

void xuat(PhanSo ps){
    cout<<ps.tu<<"/"<<ps.mau;
}

/*
Hàm so sánh hai phân số
Output: true nếu ps1 > ps2
*/
bool lonHon(PhanSo ps1, PhanSo ps2){
    return ps1.tu*ps2.mau > ps2.tu*ps1.mau;
}

/* Hàm cộng hai phân số */
PhanSo tong(PhanSo a, PhanSo b){
    PhanSo kq;
    kq.tu = a.tu*b.mau + b.tu*a.mau;
    kq.mau = a.mau*b.mau;
    rutGon(kq);
    return kq;
}

/* Hàm trừ hai phân số */
PhanSo hieu(PhanSo a, PhanSo b){
    PhanSo kq;
    kq.tu = a.tu*b.mau - b.tu*a.mau;
    kq.mau = a.mau*b.mau;
    rutGon(kq);
    return kq;
}

/* Hàm nhân hai phân số */
PhanSo tich(PhanSo a, PhanSo b){
    PhanSo kq;
    kq.tu = a.tu*b.tu;
    kq.mau = a.mau*b.mau;
    rutGon(kq);
    return kq;
}

/* Hàm chia hai phân số */
PhanSo thuong(PhanSo a, PhanSo b){
    PhanSo kq;
    kq.tu = a.tu*b.mau;
    kq.mau = a.mau*b.tu;
    rutGon(kq);
    return kq;
}

int main(){

    PhanSo a,b;

    cout<<"Nhap phan so thu 1: ";
    nhap(a);

    cout<<"Nhap phan so thu 2: ";
    nhap(b);

    rutGon(a);
    rutGon(b);

    cout<<"Phan so 1: ";
    xuat(a);

    cout<<"\nPhan so 2: ";
    xuat(b);

    cout<<"\nPhan so lon hon: ";
    if(lonHon(a,b))
        xuat(a);
    else
        xuat(b);

    cout<<"\nTong: ";
    xuat(tong(a,b));

    cout<<"\nHieu: ";
    xuat(hieu(a,b));

    cout<<"\nTich: ";
    xuat(tich(a,b));

    cout<<"\nThuong: ";
    xuat(thuong(a,b));

    return 0;
}
