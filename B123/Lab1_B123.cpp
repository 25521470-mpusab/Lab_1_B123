#include <iostream>
#include <cmath>
using namespace std;

struct PhanSo{
    int tu;
    int mau;
};

void nhapSo(int &x){
    while(!(cin >> x)){
        cout << "Loi! Nhap so nguyen: ";
        cin.clear();
        cin.ignore(1000,'\n');
    }
}

void nhap(PhanSo &ps){
    cout << "Nhap tu: ";
    nhapSo(ps.tu);

    cout << "Nhap mau: ";
    nhapSo(ps.mau);

    while(ps.mau == 0){
        cout << "Mau phai khac 0. Nhap lai: ";
        nhapSo(ps.mau);
    }
}

int gcd(int a, int b){
    a = abs(a);
    b = abs(b);
    while(b){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void rutGon(PhanSo &ps){
    if(ps.mau < 0){
        ps.tu = -ps.tu;
        ps.mau = -ps.mau;
    }

    int g = gcd(ps.tu, ps.mau);
    ps.tu /= g;
    ps.mau /= g;
}

void xuat(PhanSo ps){
    cout << ps.tu << "/" << ps.mau;
}

bool lonHon(PhanSo a, PhanSo b){
    return a.tu * b.mau > b.tu * a.mau;
}

PhanSo tong(PhanSo a, PhanSo b){
    PhanSo kq;
    kq.tu = a.tu*b.mau + b.tu*a.mau;
    kq.mau = a.mau*b.mau;
    rutGon(kq);
    return kq;
}

PhanSo hieu(PhanSo a, PhanSo b){
    PhanSo kq;
    kq.tu = a.tu*b.mau - b.tu*a.mau;
    kq.mau = a.mau*b.mau;
    rutGon(kq);
    return kq;
}

PhanSo tich(PhanSo a, PhanSo b){
    PhanSo kq;
    kq.tu = a.tu*b.tu;
    kq.mau = a.mau*b.mau;
    rutGon(kq);
    return kq;
}

PhanSo thuong(PhanSo a, PhanSo b){
    PhanSo kq;
    kq.tu = a.tu*b.mau;
    kq.mau = a.mau*b.tu;
    rutGon(kq);
    return kq;
}

int main(){
    PhanSo ps1, ps2, ps3;

    // BÀI 1 
    cout << "RUT GON PHAN SO \n";
    nhap(ps1);
    rutGon(ps1);

    cout << "Ket qua: ";
    xuat(ps1);
    cout << endl;

    // BÀI 2, 3 
    cout << "\n SO SANH 2 PHAN SO \n";

    cout << "Nhap phan so thu 1:\n";
    nhap(ps2);

    cout << "Nhap phan so thu 2:\n";
    nhap(ps3);

    rutGon(ps2);
    rutGon(ps3);

    // So sánh
    cout << "Phan so lon hon: ";
    if(lonHon(ps2, ps3)) xuat(ps2);
    else xuat(ps3);

    // Tính toán
    cout << "\nTong: ";
    xuat(tong(ps2, ps3));

    cout << "\nHieu: ";
    xuat(hieu(ps2, ps3));

    cout << "\nTich: ";
    xuat(tich(ps2, ps3));

    cout << "\nThuong: ";
    if(ps3.tu == 0)
        cout << "Khong the chia";
    else
        xuat(thuong(ps2, ps3));

    cout << endl;

    return 0;
}
