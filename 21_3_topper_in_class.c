#include<stdio.h>
int main(){
    int i,n,pos;
    double max=0;
    printf("Enter Number of students: ");
    scanf("%d",&n);
    float a[n];
    for(int i=0;i<n;i++){
        printf("Enter CGPA for student %d: ",i+1);
        scanf("%f",&a[i]);
    }for(int i=0;i<n;i++){
        if(a[i]>max) {
            max=a[i];
            pos=i+1;
    }
    }printf("The max CGPA was %f Achieved by student number %d ",max,pos);
    return 0;
}
