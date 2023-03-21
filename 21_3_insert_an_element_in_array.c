#include<stdio.h>
#define MAX 1000
int main(){
    int i,size,num,pos,a[MAX];
    printf("Enter the size of array: ");
    scanf("%d",&size);
    printf("Enter the elements of array: ");
    for(i=0;i<size;i++){
        scanf("%d",&a[i]);
    }printf("Enter element to insert: ");
    scanf("%d",&num);
    printf("Enter position where the element should be inserted: ");
    scanf("%d",&pos);
    if(pos>size-1||pos<=0) return -1;
    else{
        for(i=size;i>=pos;i--){
            a[i+1]=a[i];
        }a[pos]=num;
        size++;
    }
    for(i=0;i<size;i++){
        printf("%d ",a[i]);
    }return 0;
}

