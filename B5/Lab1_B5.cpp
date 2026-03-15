#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

struct HocSinh{
    string hoten;
    float toan;
    float van;
};

int main(){

    HocSinh hs;

    cout<<"Nhap ho ten: ";
    getline(cin,hs.hoten);

    cout<<"Nhap diem toan: ";
    cin>>hs.toan;

    cout<<"Nhap diem van: ";
    cin>>hs.van;

    float dtb=(hs.toan+hs.van)/2;

    cout<<"Ho ten: "<<hs.hoten<<endl;
    cout<<"Diem trung binh: "<<dtb;

}
