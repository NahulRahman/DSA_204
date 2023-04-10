// C++ implementation of Dynamic Array
#include <iostream>
#include<memory>
#include<stdio.h>
using namespace std;
class DynamicArray {
private:
    int * d_array;
    int max_size;
    int length;
public:
    DynamicArray(){
        max_size = 2;
        d_array = new int[max_size];
        length = 0;
    }
    void add(int item) {
        if (isFull()) {
            max_size =2*max_size;
            int *temp_d_array= new int[max_size];
            cout<<"\nDAL Limit reached, new array created, values copied\n"<<endl;
            for (int i = 0; i < length; i++) {
                temp_d_array[i] = d_array[i];
            }
            delete [] d_array;
            d_array = temp_d_array;
        }
        d_array[length] = item;
        length++;
    }
    void delete_(int pos){
       if(length==max_size/2){
            max_size = max_size/2;
            int *temp_d_array = new int[max_size];
            cout<<"\nDAL Limit lessened, new array created, values copied\n"<<endl;
            for(int i =0;i<length;i++){
                temp_d_array[i] = d_array[i];
            }
            delete [] d_array;
            d_array = temp_d_array;
        }
        if(pos<0 || pos>length)  cout<<"Incorrect Positional Value\n";

        int temp = d_array[pos-1];
        for(int i = pos - 1 ;i<length;i++){
            d_array[i] = d_array[i+1];
        }
        length--;
    }
    void insert_value(int pos,int val){
        if(isFull()){
            max_size = 2 * max_size;
            int * temp_d_array = new int[max_size];
            cout<<"\nDAL Limit reached, new array created, values copied\n"<<endl;
            for (int i = 0; i < length; i++) {
                temp_d_array[i] = d_array[i];
            }
            delete [] d_array;
            d_array = temp_d_array;
        }
        if(pos<0 || pos>length)  cout<<"Incorrect Positional Value\n";
        for(int i = length+1;i>pos-1;i--){
            d_array[i] = d_array[i-1];
        }
        d_array[pos-1] = val;
        length++;
    }
    void delete_matching(int val){
        for(int i = 0;i<length;i++){
            if(d_array[i]==val) delete_(i+1);
        }
    }
    int return_current_value(int p){
        return d_array[p-1];
    }
    void reverse() {
        for (int i = 0; i < length / 2; i++) {
            std::swap(d_array[i], d_array[length - i - 1]);
        }
    }

    void printd_array() {
        for (int i = 0; i < length; i++) {
            cout<<d_array[i]<<' ';
        }cout<<endl;
    }

    void replace_value(int val,int rep){
        int f = 0,c=0;
        for(int i = 0;i<length;i++){
            if(d_array[i]==val){
                f=1;
                d_array[i] = rep;
                c++;
            }
        }
        if(f==0) cout<<"No occurrence of "<<val<<" was found. No Items were replaced.\n";
        else if(f==1) cout<<val<<" replaced with "<<rep<<".Total "<<c<<" replacement\n";
    }
    int count_array(int val){
        int c=0;
        for(int i=0;i<length;i++){
            if(d_array[i]==val) c++;
        }return c;
    }
    bool isFull() {
        return length==max_size;
    }
    ~DynamicArray(){
        delete [] d_array;
    }
};

int main() {
    DynamicArray dal;
    int a, choice;
    printf("\t\t\tDynamic Array d_array Implementation using Template Class.\n");
   while (1){
    printf("\n1.Add an element\n2.See current Elements\n3.Delete value from a specific position\n4.Insert value at a certain position\n5.Delete all matching values and resizing Array\n6.Replace all matching values\n7.Reverse the elements in an array\n8.Exit\n\n");
    cout<<"Enter Choice: ";
    cin>>choice;
    if(choice==1){
        printf("\nEnter a num to add: ");
        cin>>a;
        dal.add(a);

        cout<<"The current dynamic array is: ";
        dal.printd_array();
    }
    else if (choice==2){
        cout<<"The current dynamic array is: ";
        dal.printd_array();
    }
    else if (choice==3){
        //do by yourself
       //Let the user delete the value from a particular position in the DAL.
        cout<<"Enter position to delete from: ";
        int p;
        cin>>p;
        int r = dal.return_current_value(p);
        dal.delete_(p);
        cout<<"Deleted the value in position "<<p<<" which was "<<r<<"\n";
        cout<<"The current dynamic array is: ";
        dal.printd_array();
    }
    else if (choice==4){
        //do by yourself
       //Let the user insert a value into a particular position in the DAL.
        cout<<"Enter Position to Insert into: ";
        int p,v;
        cin>>p;
        cout<<"Enter The value to Insert: ";
        cin>>v;
        dal.insert_value(p,v);
        cout<<"Inserted "<<v<<" at position "<<p<<"\n";
        cout<<"The current dynamic array is: ";
        dal.printd_array();
    }
    else if (choice==5){
        //do by yourself
       //Delete ALL matching values. Resize the Dynamic array as per the algorithm shown in class
       //think when it�ll be resized carefully
        cout<<"Enter the value to delete: ";
        int v;
        cin>>v;
        int coun = dal.count_array(v);
        dal.delete_matching(v);
        cout<<"Deleted all occurrences of "<<v<<" .Total "<<coun<<" items were deleted.Array Resized\n";
        cout<<"The current dynamic array is: ";
        dal.printd_array();
    }
    else if (choice==6){
        //do by yourself
       //Replace ALL matching values.
       //There may be two cases as shown in the sample input-output.
        int val,r;
        cout<<"Enter the value to replace: ";
        cin>>val;
        cout<<"Enter the value to be replaced by: ";
        cin>>r;
        dal.replace_value(val,r);
        cout<<"The current dynamic array is: ";
        dal.printd_array();
    }
    else if (choice==7){
    //reverse the Dynamic array list elements of an array

        dal.reverse();
        cout<<"The reversed array list is"<<endl;
       dal.printd_array();

    }
    else{
        printf("\n\t\tProgram Terminated\n\n");
        break;
    }
}return 0;
}
