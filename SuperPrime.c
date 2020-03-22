//超级素数：它本身，各位数字的和，各位数字的平方和，都是素数。
//求 100~10000 内的所有超级素数，及它们的平均数。

#include<stdio.h>
int isPrime(int n){
    if (n==0||n==1) return 0;
    else for(int i=2;i<n;i++) if(n%i==0) return 0;
    return 1;
}
int mysum(int n){
    int i=0;
    while(n!=0){
        i+=n%10;
        n/=10;
    }
    return i;
}
int mysqr(int n){
    int i=0;
    while(n!=0){
        i+=((n%10)*(n%10));
        n/=10;
    }
    return i;
}
int main ( ){
    int i,j;
    int sum,sqr,prime[1000],prime_num=0,prime_sum=0;
    float prime_avg;
    for(j=100;j<=10000;j++){
        sum=mysum(j);
        sqr=mysqr(j);
        if(isPrime(j)&&isPrime(sum)&&isPrime(sqr)){
            prime[prime_num]=j;
            prime_num++;
        }
    }
    for(i=0;i<prime_num;i++){
        prime_sum+=prime[i];
        printf("%d ",prime[i]);
    }
    prime_avg=(float)prime_sum/prime_num;
    printf("平均数为%f",prime_avg);
}
