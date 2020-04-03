#include <iostream>
using namespace std;
class DateTime {
private:
    int seconds;
public:
    DateTime();
    ~DateTime();
    void showTime();
    void showSeconds();
    int year,month,day,hour,minute,second;
};

int main() {
    DateTime dt;
    dt.showTime();
    dt.showSeconds();
    return 0;
}
DateTime::DateTime()
{
    year = 2020; month = 3; day = 20;
    hour = 11; minute = 27; second = 55;
}
DateTime::~DateTime()
{
    cout << " Go die, Ha~Ha~" << endl;
}
void DateTime::showTime()
{
    printf("当前时间%d/%d/%d %d:%d:%d\n", year, month, day, hour, minute, second);
}
void DateTime::showSeconds(){
    int days=0;
    for (int i=1970;i<year;i++){
        if ((i%4) == 0) {
            days+=366;
        }
        else days+=365;
    }
    for (int j=1;j<month;j++){
        if (j==1||j==3||j==5||j==7||j==8||j==10||j==12){
            days+=31;
        }
        else if (j==4||j==6||j==9||j==11){
            days+=30;
        }
        else if (j==2 && (year%4) == 0){
            days+=29;
        }
        else {
            days+=28;
        }
        days += day;
        seconds = day * 24 *3600;
        seconds = seconds + hour*3600 + minute*60 + second;

    }

    cout << "距离1970.1.1 "<< seconds << "秒" << endl;
}