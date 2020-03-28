#include <iostream>
#include <string>
using namespace std;
int day_num(int month,int day);  //默认2020年了 而且只考虑正月初一以后的天数
class DateTime {
private:
    int year, month, day;
    int hour, minute, second;
    int lunar_month,lunar_day;
    string lunar_month_switch;
public:
    DateTime();
    ~DateTime();
    void showTime();
    void showMoon();
};
int main() {

    DateTime dt;
    dt.showTime();
    dt.showMoon();
    return 0;
}
int day_num(int month,int day){                 //算出2020年已经过去的天数
    int sum=0;
    for(int i=1;i<month;i++){
        if (i==1||i==3||i==5||i==7||i==8||i==9||i==10) sum += 31;
        else if (i==2) sum+=29;
        else sum += 30;
    }
    sum+=day;
    return sum;
}
DateTime::DateTime()
{
    year = 2020; month = 3; day = 20;
    hour = 11; minute = 27; second = 55;
    cout << "请输入2020年过年后的一个日期(1.25之后 月份和日期用空格隔开）" << endl ;
    cin >> month >> day ;
}
DateTime::~DateTime()
{
    cout << " Go die, Ha~Ha~" << endl;
}
void DateTime::showTime()
{
    printf("now is %d/%d/%d %d:%d:%d\n", year, month, day, hour, minute, second);
}
void DateTime::showMoon(){
    //lunar 正月->29 2->30 3->30 4->30 闰四月->29 5->30 6->29 7->29 8->30 9->29 10->30 腊月->30
    //正月初一 2020.1.25
    int lunar[12]={29,30,30,30,29,30,29,29,30,29,30,30}; // 初始化农历每月月份
    lunar_month = 1;
    int lunar_day_num;
    lunar_day_num=day_num(month,day)-24;
    for(int i=0;lunar_day_num>lunar[i];i++){
        lunar_month+=1;
        lunar_day_num-=lunar[i];
    }
    lunar_day = lunar_day_num;
    switch (lunar_month){
        case 1: lunar_month_switch ="正月" ;
            break;
        case 2: lunar_month_switch ="二月" ;
            break;
        case 3: lunar_month_switch ="三月" ;
            break;
        case 4: lunar_month_switch ="四月" ;
            break;
        case 5: lunar_month_switch ="闰四月" ;
            break;
        case 6: lunar_month_switch ="五月" ;
            break;
        case 7: lunar_month_switch ="六月" ;
            break;
        case 8: lunar_month_switch = "七月";
            break;
        case 9: lunar_month_switch ="八月" ;
            break;
        case 10: lunar_month_switch ="九月" ;
            break;
        case 11: lunar_month_switch ="十月" ;
            break;
        case 12: lunar_month_switch ="腊月" ;
            break;
        default:  break;

    }
    cout << "农历是" << year << "年"<< lunar_month_switch  << lunar_day<<"号"<< endl;
}


