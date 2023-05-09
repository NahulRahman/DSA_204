#include<iostream>
#define N 5
using namespace std;
int q[N];
int fr=-1,rear=-1;
void enqueue(int x){
    if(fr==-1&&rear==-1){
        fr=rear=0;
        q[rear]=x;
    }else if(((rear+1)%N)==fr) cout<<"queue is full"<<endl;
    else{
        rear=((rear+1)%N);
        q[rear]=x;
    }
}
void dequeue(){
    if(fr==-1&&rear==-1) cout<<"The queue is empty"<<endl;
    else if(fr==rear) fr=rear=-1;
    else{
        cout<<"The deleted elemnet in queue was "<<q[fr]<<endl;
        fr=((fr+1)%N);
    }
}
void display(){
    int i=fr;
     if(fr==-1&&rear==-1) cout<<"The queue is empty"<<endl;
     else{
        cout<<"Queue is : ";
        while(i!=rear){
            cout<<q[i]<<" ";
            i=(i+1)%N;
        }cout<<q[rear];
     }cout<<endl;
}
int main(){
    enqueue(2);
    enqueue(-1);
    enqueue(5);
    enqueue(6);
    enqueue(7);
    display();
    dequeue();
}
