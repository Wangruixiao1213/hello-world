#include <iostream>
class SuperPrime {
public:
    int number;
    void _number(int n) {
        number = n;
    }
    bool isSuperPrime() {
        split();
        int a = sum();
        int b = multi();
        int c = squareSum();
        if (isPrime(number) && isPrime(a) && isPrime(b) && isPrime(c))
            return true;
        return false;
    }

private:
    int N[20], size_N;
    bool isPrime(int x) {
        int i = 2;
        if(x == 0 || x == 1) return false;
        for(i = 2; i < x; i++){
            if(x % i == 0){
                return false;
            }
        }
        return true;
    }
    void split() {
        int _number = number,i;
        for(i = 0; _number > 0; i++){
            N[i] = _number % 10;
            _number /= 10;
        }
        size_N = i;
    }
    int sum() {
        int sum_number = 0;
        for (int i=0;i<size_N;i++){
            sum_number+= N[i];
        }
        return sum_number;
    }
    int multi() {
        int multi_num = 1;
        int i;
        for(i = 0; i<size_N; i++)
            multi_num *= N[i];
        return multi_num;
    }
    int squareSum() {
        int square = 0;
        int i;
        for(i = 0; i < size_N; i++)
            square += (N[i] * N[i]);
        return square;
    }
};
class Set {
public:
    Set(int from, int to) {
        size = to - from;
        _from = from;
        _to = to;
    }
    ~Set() {
    }
    int count() {
        int count = 0;
        int i;
        for (i = 0; i < size; i++) {
            set[i]._number(i + _from);
            if(set[i].isSuperPrime()) count += 1;
        }
        return count;
    }
    int sum() {
        int sum = 0;
        int i;
        for (i = 0; i < size; i++) {
            set[i]._number(i + _from);
            if(set[i].isSuperPrime()){
                sum += set[i].number;
                //std::cout << set[i].number << std::endl;
            }

        }
        return sum;
    }
private:
    SuperPrime set[1000];
    int size;
    int _from, _to;
};
int main() {
    Set ss(100, 999);
    std::cout << "How Many: " << ss.count() << std::endl;
    std::cout << "Sum is " << ss.sum() << std::endl;
    return 0;
}
