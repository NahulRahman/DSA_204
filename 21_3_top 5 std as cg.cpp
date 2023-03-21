#include<iostream>
using namespace std;
int main(){
    int n,i,pos;
    float maximum=0;
    cout<<"Enter num of students";
    cin>>n;
    float a[n];
    for(int i=0;i<n;i++){
        cout<<"enter cgpa of student "<<i+1<<" :";
        cin>>a[i];
        if(a[i]>maximum){
            maximum=a[i];
            pos=i+1;
        }
    }cout<<"The max CGPA was "<<maximum<<endl<<"achieved by student no: "<<pos;
    return 0;

}
