#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MIN(a,b) (a<b)?a:b
#define FLOOR(m,n) ((m/n) - ((m%n != 0) && (m^n < 0)))
int main(){
    int n,m,a,b;
    scanf("%d%d%d%d",&n,&m,&a,&b);
    int ans = MIN(n/m *b + MIN((n%m) * a, b) , n*a);
    printf("%d",ans);
    return 0;
}