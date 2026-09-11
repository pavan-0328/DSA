#include <stdio.h> 
#include <string.h>
int main(){
    char str[100];
    int n;
    scanf("%d",&n);
    while(n--){
        scanf("%s",str);
        size_t len = strlen(str);
        if(len > 10)
            printf("%c%d%c\n",str[0],(int)len-2,str[len-1]);
        else printf("%s\n",str);
    }
    return 0;
}