#include<stdio.h>

int main(){
    int k=0, a=0, b=0, instance[5],availibility[5], allocated[10][5], MAX[10][5],need[10][5], process, P[10], noofresources, cnt=0, i, j, op[10];
    printf("Enter the number of resources: ");
    scanf("%d", &noofresources);
    printf("\nenter the max instances of each resources: ");
    for(i=0; i<noofresources; i++){
        availibility[i]=0;
        printf("%c: ", (i+97));
        scanf("%d", &instance[i]);
    }
    printf("\nenter the number of processes: ");
    scanf("%d", &process);
    printf("\nenter the allocation matrix: ");
    for(i=0; i<noofresources; i++){
        printf("%c ", (i+97));
        printf("\n");
    }
    for(i=0; i<process; i++){
        P[i]=i;
        printf("P%d: ", i);
        for(j=0; j<noofresources; j++){
            scanf("%d", &allocated[i][j]);
            availibility[j]+=allocated[i][j];
        }
    }
    printf("\nenter the MAX matrix: ");
    for(i=0; i<noofresources; i++){
        printf("%c ", (i+97));
        availibility[i]=instance[i]-availibility[i];
    }
    printf("\n");
    for(i=0; i<process; i++){
        printf("P%d: ", i);
        for(j=0; j<noofresources; j++){
            scanf("%d", &MAX[i][j]);
        }
    }
    printf("\n");
    A: a=-1;
    for(i=0; i<process; i++){
        cnt=0;
        b=P[i];
        for(j=0; j<noofresources; j++){
            need[b][j]=MAX[b][j]-allocated[b][j];
            if(need[b][j]<=availibility[j]){
                cnt++;
            }
        }
        if(cnt==noofresources){
            op[k++]=P[i];
            for(j=0; j<noofresources; j++){
                availibility[j]+=allocated[b][j];
            }
        }
        else{
            P[++a]=P[i];
        }
    }
    if(a!=-1){
        process=a+1;
        goto A;
    }
    printf("\nThe safe sequence is: ");
    for(i=0; i<k; i++){
        printf("P%d ", op[i]);
    }
    return 0;
}