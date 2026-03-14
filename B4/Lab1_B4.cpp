#include <iostream>
using namespace std;
 
struct Date{
    int day;
    int month;
    int year;
};

bool ktraNamNhuan(int year){
    if( year % 400 == 0) return true;
    if( year % 4 == 0 && year % 100 != 0) return true;
    return false;
}

int NgayTrongThang( int month, int year){
    switch(month){
        case 1: case 3: case 5: case 7:
        case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return ktraNamNhuan(year) ? 29 : 28;
 
    }
}

void addDate(Date &d, int numDays){
    d.day += numDays;
    while(d.day > NgayTrongThang(d.month, d.year)){
        d.day -= NgayTrongThang(d.month, d.year);
        d.month ++;
   
     while (d.month > 12){
        d.month -= 12;
        d.year ++;
        }
    }
}
 
int main()
{
    Date a;
    cin>> a.day>> a.month >> a.year;
    int days;
    cin>> days;
    addDate(a, days);
    cout<< a.day<< "/"<< a.month<<"/"<< a.year;
 
    return 0;
}
