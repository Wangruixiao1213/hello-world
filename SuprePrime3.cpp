//作业：大整数，比如9081321110693270343633073697474256143563558458718976746753830538032062222085722974121768604305613921745580037409259811952655310075487163797179490457039169594160088430571674960498834085812920457916453747019461644031395307920624947349951053530086146486307198155590763466429392673709525428510973272600608981219760099374675982933766845473509473676470788342281338779191792495900393751209539300628363443012 6538005862664913074813656220643842443844131905754565672075358391135537108795991638155474452610874309742867231360502542308382199053675592825240788613991898567277116881793749340807728335795394301261629479870548736450984003401594705923178314906195914825136973281314862289454100745237769034410057080703111299605127114594552921209928891515242515620324828055912854227507525717981351447473570262981491527798
//重新设计下面的代码，使其可以处理大整数的素数与超级素数
//同时仔细理解面向对象的编程方式
#include<iostream>
#include<string>
#define MAX 100
using namespace std;
class BigInt {
public:
    BigInt() {
    }
    BigInt(string num) {
        this->num.resize(num.size());
        for (int i = 0; i < num.length(); i++) {
            this->num[i] = num[i] - '0';
        }
    }
    BigInt(int lenth) {
        num.resize(num.size()+lenth);
        num.replace(0, lenth, lenth, 0);
    }
    ~BigInt() {
    }
    friend BigInt operator- (BigInt a,int b);
    friend BigInt operator* (BigInt a, BigInt b);
    friend BigInt operator/ (BigInt a, BigInt b);
    friend BigInt operator% (BigInt a, BigInt b);



    string num;
private:
    BigInt sub(BigInt a, BigInt b) {
        int len_a = a.num.size(), len_b = b.num.size();
        BigInt c(len_a);
        for (int i = 1; i <= len_a; i++) {
            if (i <= len_b) {
                if (a.num[len_a-i] < b.num[len_b-i]) {
                    c.num[len_a-i] = a.num[len_a-i]+10-b.num[len_b-i];
                    a.num[len_a-i-1] -= 1;
                } else {
                    c.num[len_a-i] = a.num[len_a-i]-b.num[len_b-i];
                }
            } else {
                c.num[len_a-i] = a.num[len_a-i];
            }
        }

        a.c_zero(c);
        return c;
    }
    int compare(BigInt &a, BigInt &b) {
        int len_a = a.num.size(), len_b = b.num.size();
        if (len_a > len_b) {
            return 1;
        } else if (len_a < len_b) {
            return -1;
        } else {
            int i = 0;
            while ((a.num[i] == b.num[i]) && i < len_a) {
                i += 1;
            }
            if (i == len_a) {
                return 0;
            } else if (a.num[i] < b.num[i]) {
                return -1;
            } else if (a.num[i] > b.num[i]) {
                return 1;
            }
        }
    }
    void c_zero(BigInt &r) {
        for (int i = 0; i <= r.num.size(); i++) {
            if (r.num[i] != 0) {
                r.num.erase(0, i);
                break;
            }
        }

    }
};
BigInt operator- (BigInt a, int b) {
    int len = a.num.length();
    while (a.num[len-1] == 0) {
        a.num[len-1] = 9;
        len -= 1;
    }
    a.num[len-1] -= 1;
    if (a.num[0] == 0) {
        a.num[0] = 9;
        a.num.resize(a.num.size()-1);
    }
    return a;
}
BigInt operator* (BigInt a, BigInt b) {
    int len_a, len_b, len;
    len_a = a.num.size();
    len_b = b.num.size();
    len = len_a + len_b;
    BigInt c(len);

    long long int array[len] ;
    for (int i = 1; i <= len_a; i++) {
        for (int j = 1; j <= len_b; j++) {
            array[len-i-j+1] += (a.num[len_a-i] * b.num[len_b-j]);
        }
    }

    for (int i = 1; i < len; i++) {
        array[len-i-1] += (array[len-i]/10);
        array[len-i] = (array[len-i] % 10);
    }
    for (int i = 0; i < len; i++) {
        c.num[i] = (char)array[i];
    }

    c.c_zero(c);

    return c;
}
BigInt operator% (BigInt a, BigInt b) {
    BigInt abcd(1), b1 = b;
    int i = 0, j = 0;
    int len_a = a.num.size(), len_b = b.num.size(), len;

    switch (abcd.compare(a, b)) {
        case -1: return a; break;
        case 0: return abcd; break;
        case 1: len = len_a-len_b; BigInt r(len+1); break;
    }
    len = len_a-len_b;
    BigInt r(len+1);

    for (j = 0; j < len; j++) {
        b.num += (char) 0;
    }
    while (abcd.compare(a, b1) > 0) {
        if (abcd.compare(a, b) > 0) {
            a = abcd.sub(a, b);
        }  else if (abcd.compare(a, b) == 0) {
            return abcd;
        } else if (abcd.compare(a, b) < 0) {
            b.num.erase(b.num.end()-1);
            i += 1;
        }
    }
    if (abcd.compare(a, b1) == 0) {
        return abcd;
    } else if (abcd.compare(a, b1) < 0) {
        return a;
    }
}
BigInt operator/ (BigInt a, BigInt b) {
    BigInt abcd(1), b1 = b;
    int i = 0, j = 0;
    int len_a = a.num.size(), len_b = b.num.size(), len;
    int result = abcd.compare(a,b);
    if (result == -1) return abcd;
    if (result == 0){
        abcd.num[0] = 1;
        return abcd;
    }
    len = len_a-len_b;
    BigInt bigint1(len+1);

    for (j = 0; j < len; j++) {
        b.num += (char) 0;
    }
    while (abcd.compare(a, b1) > 0) {
        if (abcd.compare(a, b) > 0) {
            a = abcd.sub(a, b);
            bigint1.num[i] += 1;
        }  else if (abcd.compare(a, b) == 0) {
            bigint1.num[i] += 1;
            abcd.c_zero(bigint1);
            return bigint1;
        } else if (abcd.compare(a, b) < 0) {
            b.num.erase(b.num.end()-1);
            i += 1;
        }
    }
    if (abcd.compare(a, b1) == 0) {
        bigint1.num[len] += 1;
        abcd.c_zero(bigint1);
        return bigint1;
    } else if (abcd.compare(a, b1) < 0) {
        abcd.c_zero(bigint1);
        return bigint1;
    }
}
class BigPrime : public BigInt{
public:
    BigPrime(string t) : BigInt(t){
        n.num = this->num;
    }
    virtual bool isPrime() {
        if (isprimee(n)) {
            return true;
        }
        return false;
    }
private:
    BigInt n;
    BigInt pow1(BigInt a, BigInt b, BigInt mod) {
        BigInt bigint2("1"), base = a, two("2");
        while (b.num[0] != 0) {
            int len_b;
            len_b = b.num.size();
            if (((int)b.num[len_b-1] % 2) != 0) {
                bigint2 = bigint2*base;
                bigint2 = bigint2%mod;
            }
            base = base*base;
            base = base%mod;
            b = b/two;
        }
        return bigint2;
    }
    bool isprimee(BigInt x)	{
        BigInt temp("30");
        for(int i = 2; i<=MAX; ++i) {
            if (((pow1(temp,x-1,x)%x).num.size() != 1) || ((pow1(temp,x-1,x)%x).num[0] != 1))
                return false;
            temp = temp-1;
        }
        return true;
    }

};
class BigSuperPrime : public BigPrime {
public:
    BigSuperPrime(string t) : BigPrime(t){
        int len = t.size(), i;
        for (i = 0; i < len; i++) {
            a[i] = t[i]-'0';
        }
        a[i] = -1;
    }
    virtual bool isPrime() {
        BigPrime a(sum()), b(Multi()), c(SquareSum());
        if (BigPrime::isPrime() && a.isPrime() && b.isPrime() && c.isPrime()) {
            return true;
        }
        return false;
    }
private:
    int a[2000];
    string sum() {
        int i = 0, sum = 0;
        while (a[i] >= 0) {
            sum += a[i];
            i += 1;
        }
        char t[2000];
        sprintf(t, "%d", sum);
        string r = t;
        return r;
    }
    string Multi() {
        BigInt Multi(1);
        Multi.num[0] = (char)1;
        int i = 0;
        while (a[i] >= 0) {
            BigInt temp(1);
            temp.num[0] = (char)a[i];
            Multi = Multi * temp;
            i += 1;
        }
        return Multi.num;
    }
    string SquareSum() {
        int i = 0, SquareSum = 0;
        while (a[i] >= 0) {
            SquareSum += (a[i]*a[i]);
            i += 1;
        }
        char t[1005];
        sprintf(t, "%d", SquareSum);
        string r = t;
        return r;
    }
};
class Set {
public:
    Set(int sz);
    ~Set();
    bool add(BigPrime *bp);
    bool remove(BigPrime *bp);
    int count() const {
        int ret = 0;
        for (int i = 0; i < index; i++) {
            if (pset[i]->isPrime())
                ret += 1;
        }
        return ret;
    }
    int sum() const {
        return 0;
    }
private:
    BigPrime **pset;
    int size, index;
};
int main() {
    Set set(1000);
    BigSuperPrime bp("256432154654564132145464"), bp1("3564321354564697894658974564");
    set.add(&bp);
    set.add(&bp1);
    cout << set.count() << endl;
    return 0;
}

Set::Set(int sz):size(sz) {
    index = 0;
    pset = new BigPrime*[size];
}

Set::~Set() {
    delete[] pset;
}
bool Set::add(BigPrime *bp) {
    pset[index++] = bp;
    return true;
}