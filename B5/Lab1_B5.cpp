#include <iostream>
#include <string>
using namespace std;

struct HocSinh{
    string hoten;
    float toan;
    float van;
};

void nhapHocSinh(HocSinh &hs){
    cin.ignore();                
    getline(cin, hs.hoten);       
    cin >> hs.toan;
    cin >> hs.van;
}

float tinhDTB(HocSinh hs){
    return (hs.toan + hs.van) / 2;
}

void xuatHocSinh(HocSinh hs){
    cout << "Ho ten: " << hs.hoten << endl;
    cout << "Diem trung binh: " << tinhDTB(hs);
}

int main(){
    HocSinh hs;
    nhapHocSinh(hs);
    xuatHocSinh(hs);

    return 0;
}
