#include<iostream>
using namespace std;
#define MAX 1000
int main(){
    int i,size,num,pos,a[MAX];
    cout<<"Enter the size of array: ";
    cin>>size;
    cout<<"Enter the elements of array: ";
    for(i=0;i<size;i++){
        cin>>a[i];
    }cout<<"Enter element to insert: ";
    cin>>num;
    cout<<"Enter position where the element should be inserted: ";
    cin>>pos;
    if(pos>size+1) return 1;
    else if(pos<=0) return -1;
    else{
        for(i=size+1;i>=pos;i--){
            a[i+1]=a[i];
        }a[pos]=num;
        size++;
    }
    for(i=0;i<size;i++){
       cout<<a[i];
    }return 0;
}

