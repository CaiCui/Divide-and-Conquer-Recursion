//Google Codejam apac-test Problem B. Beautiful Numbers
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll calc(int bit,ll base,ll n)//在指数为i，基数为base的情况下，计算1 + base + base^2 + base^3+...+base^(bit-1) = n
{
   ll result=1;
   ll t=1;
   for(int i=1;i<bit;i++)
   {
       t*=base;
       result +=t;
       if(result > n)
        return result;
   }
   return result;
}
int Search(int i, ll n)//在给定指数限制下进行二分枚举base，找到第一个>=n的数
{
    ll l,r;
    ll basepos;
    r=n;
    l=2;
    while(l<r)
    {
        ll mid;
        mid = (l+r)/2;
        if(calc(i,mid,n)< n)//计算和当前n比较
        {
            l = mid + 1;
            basepos= l;
        }
        else
        {
            r = mid;
            basepos=r;
        }

    }
    if(n==calc(i,basepos,n))
     return basepos;
    return -1;
}
ll solve(ll n)
{
    ll base = n-1;
    int i;
    for(i=60;i>=2;i--)
      {
          base =Search(i,n);
          if(base!=-1)
              break;
      }
    printf("1的个数:%d \n",i);
    return base;
}
int main()
{
    int t,m;
    ll n;
    scanf("%d",&t);
    m=0;
    while(t--)
    {
        scanf("%lld",&n);
        printf("Case #%d: %lld\n",++m,solve(n));
    }
    return 0;
}
*/
//Google Codejam apac-test Problem B. Beautiful Numbers  小规模数据集通过
#include<stdio.h>
typedef long long ll;
ll calc(int bit,ll base,ll n)//
{
   ll result=1;
   ll t=1;
   for(int i=1;i<bit;i++)
   {

       t=t*base;
       result =result+t;
       if(result > n)
        return result;
         /*
         result=(result-1)/base;
        if(result<=1)
    */

   }

   return result;
}
ll Search(int i, ll n)//
{

    ll l,r;
    ll basepos;
    r=n;
    l=2;
    while(l<r)
    {
        ll mid;
        mid = (l+r)/2;
        if(calc(i,mid,n)< n)//
        {
            l = mid + 1;
            basepos= l;
        }
        else
        {
            r = mid;
            basepos=r;
        }

    }
    if(n==calc(i,basepos,n))
     return basepos;
    return -1;
}
ll solve(ll n)
{
    ll base = n-1;
    int i;
    for(i=60;i>=2;i--)
      {
          base =Search(i,n);
          if(base!=-1)
              break;
      }
    return base;
}
int main()
{
    int t,m;
    ll n;
    freopen("D:\\B-small-practice.in","r",stdin);
    freopen("D:\\result.out","w",stdout);
    m=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        printf("Case #%d: %lld\n",++m,solve(n));
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
