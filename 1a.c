#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define CEIL(m,n) 1 + ((m-1)/n)
#define FLOOR(m,n) (m/n) - ((m%n != 0) && ((m^n) < 0))
int main(){
    long long int n,m,a;
    scanf("%lld%lld%lld",&n,&m,&a);
    long long int c,r;
    c = FLOOR(m,a) + ((m%a == 0)? 0:1);
    r = FLOOR(n,a) + ((n%a == 0)?0:1);
    //printf("%lld%lld",c,r);
    printf("%lld",(long long)c*r);
    return 0;
}