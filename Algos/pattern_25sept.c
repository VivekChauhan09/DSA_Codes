/*

1
8  2
14 9  3
19 15 10 4
23 20 16 11 5
26 24 21 17 12 6
28 27 25 22 18 13 7



#include<stdio.h>
int main(){
    int i,j=0,n;
    printf("Enter a number : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            printf("%d",j);
        }
        printf("\n");
    }
    return 0;
}
*/


/*

     A
    B B
   C   C
  D     D
 E       E
F         F
 E       E
  D     D
   C   C
    B B
     A

*/

#include<stdio.h>
int main(){
    char ch;
    int space;
    int i,j,K,n;
    for(int i=0;i<11;i++){
        for(int k=n;k<=0;k++){
            printf(" ");
            for(int j=0;j<i;j++){
                printf("%d",j);
            }
            printf("\n");
        }
    }
    return 0;
}
