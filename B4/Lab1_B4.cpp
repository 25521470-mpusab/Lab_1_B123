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

void ngayKeTiep(Ngay &d){

    d.ngay++;

    if(d.ngay > NgayMay(d.thang, d.nam)){
        d.ngay = 1;
        d.thang++;

        if(d.thang > 12){
            d.thang = 1;
            d.nam++;
        }
    }
}

int main(){

    Ngay a;
    cin >> a.ngay >> a.thang >> a.nam;

    ngayKeTiep(a);

    cout << a.ngay << "/" << a.thang << "/" << a.nam;
    return 0;
}
