#include<iostream>
#define N 5
using namespace std;
int q[N];
int fr=-1,rear=-1;
void enqueue(int x){
    if(rear==N-1) cout<<"Overflow"<<endl;
    else if(fr==-1&&rear==-1){
        fr=rear=0;
        q[rear]=x;
    }else{
        rear++;
        q[rear]=x;
    }
}
void dequeue(){
    if(fr==-1&&rear==-1) cout<<"Underflow"<<endl;
    else if(fr==rear) fr=rear=-1;
    else{
        cout<<"The deleted elemnet in queue was "<<q[fr]<<endl;
        fr++;
    }
}
void display(){
    if(fr==-1&&rear==-1) cout<<"The queue is empty"<<endl;
    else for(int i=fr;i<rear+1;i++) cout<<q[i]<<endl;;
}
void peek(){
     if(fr==-1&&rear==-1) cout<<"The queue is empty"<<endl;
     else cout<<"the front element is "<<q[fr]<<endl;
}
int main(){
    enqueue(2);
    enqueue(5);
    enqueue(-1);
    display();
    peek();
    dequeue();
    peek();
    display();
    return 0;
}
