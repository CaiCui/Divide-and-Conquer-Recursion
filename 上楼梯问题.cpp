//楼梯有n阶台阶，上楼可以一步上1阶，也可以一步上2或3阶，编程序计算共有多少种不同的走法？
/*
设n阶台阶的走法数为f(n)。如果只有1个台阶，走法有1种（一步上1个台阶），即f(1)=1；如果有2个台阶，走法有2种（一种是上1阶，再上1阶，另一种是一步上2阶），即f(2)=2；当有n个台阶（n>3）时，我们缩小问题规模，可以这样想：最后是一步上1个台阶的话，之前上了n-1个台阶，走法为f(n-1)种，而最后是一步上2个台阶的话，之前上了n-2个台阶，走法为f(n-2)种，故而f(n)=f(n-1)+f(n-2)。列出的递归方程为：
f(1)=1;
f(2)=2;
f(3)=4;
f(n)=f(n-1)+f(n-2)+f(n-3)，当n>3
*/
#include<iostream>
using namespace std;
void Circul(const int n)
{
    int i;
    long long a[10000];
    a[1]=1;
    a[2]=2;
    a[3]=4;
   if (n==1){
   cout<<a[1]<< endl;
     return;
}else if(n==2){
   cout<< a[2]<<endl;
   return;
}else if(n==3){
   cout<< a[3]<<endl;
   return;
}else for(i=4;i<=n;i++){
   a[i]=a[i-3]+a[i-2]+a[i-1];
}
   cout<< a[n]<<endl;
}
int main()
{
    int n;
    cin>>n;
    Circul(n);
    return 0;
}