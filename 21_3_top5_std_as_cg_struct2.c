#include<stdio.h>
struct student{
    long long int id;
    float cg;
};


int main(){
    int n,i,j,b;
    float maximum=0;
    printf("Enter the number of students: ");
    scanf("%d",&n);
    struct student s[n];
    for(i=0;i<n;i++){
            printf("enter the ID number: ");
            scanf("%lld",&s[i].id);
            printf("Enter the CGPA: ");
            scanf("%f",&s[i].cg);
    }
    for(i=0;i<n;i++){
            if(s[i].cg>maximum){
                    maximum=s[i].cg;
                    b=s[i].id;
            }
        }
    printf("The maximum CGPA was %f , achieved by %lld",maximum,b);
    return 0;
}
