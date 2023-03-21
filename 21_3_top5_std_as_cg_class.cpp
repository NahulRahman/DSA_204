#include<iostream>
using namespace std;

class student{
public:
    long long int id;
    float cg;
};

int main(){
    int i,n;
    cout<<"Enter number of students:";
    cin>>n;
    student s[n];
    float maximum;
    int b;
    for(int i=0;i<n;i++){
        cout<<"Enter ID for student"<<i+1<<": ";
        cin>>s[i].id;
        cout<<"Enter CGPA"<<": ";
        cin>>s[i].cg;
    }
    }cout<<"The maximum CGPA was : "<<maximum<<", axhieved by student no: "<<b;
    return 0;
}


