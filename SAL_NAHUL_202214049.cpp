#include<iostream>
using namespace std;
#define MAX 10
void print(int a[],int l){
    for(int i=0;i<l;i++) cout<<a[i]<<" ";
    cout<<endl;
    return;
}

void insert_obj(int arr[],int pos,int &l)

{
   cout<<"Enter Element to insert: ";
            int a;
            cin>>a;
            cout<<endl;
            cout<<"Enter index position to insert (current array length is: "<<l<<",so choose an index between 0 and "<<l<<"): ";
            cin>>pos;
            cout<<endl;


    if(l==MAX) {cout<<"Array Size is Full"<<"\n"; return;}
            else if(pos<0 || pos>l+1) { cout<<"Incorrect positional value. The value can not be inserted."<<endl; return;}
            else
            {
                int i;
                for(i=l-1;i>=pos;i--)
                {
                    arr[i+1] = arr[i];
                }
                arr[pos] = a;
                l++;
                cout<<a<<" inserted at index "<<pos<<endl<<"Current Array List is : ";
                print(arr,l);
            }

    return;

}
void  delete_obj(int arr[],int p,int &l)
{
    cout<<"\n";
            if(p<0 || p>l-1){
                cout<<"Incorrect pos value "<<endl; return;
            }
            else{

                for(int j=p;j<=l-2;j++){
                    arr[j]=arr[j+1];
                }
                cout<<"Deleted from position "<<p<<"\n";
            }
            l--;
            print(arr,l);
    return;

}

int search_obj(int a[],int l,int e){
    for(int i=0;i<l;i++) if(e==a[i]) return i;
    return -1;
}

int main(){
    int arr[MAX];
    int l = 0,pos;
    while(1){
        cout<<"Max Size of SAL is set to "<<MAX<<"\n"<<"\n";
        cout<<"Menu"<<endl<<"1.Insert New Element"<<endl<<"2.Delete Element"<<endl<<"3.Search for an Element"<<endl<<"4.Print Current Array"<<endl<<"5.Exit"<<endl;
        cout<<endl;
        cout<<"Enter Choice: ";
        int x;
        cin>>x;
        cout<<endl;

        if(x==1)
        {

            insert_obj(arr,pos,l);

        }



        else if(x==2)
        {

            cout<<"The current array list is: ";
            print(arr,l);
            cout<<"Enter index to delete from: ";
            int p,temp,j;
            cin>>p;
            delete_obj(arr,p,l);

        }


        else if(x==3){
            cout<<"Enter the search key: ";
            int e;
            cin>>e;
            cout<<"\n";
            int res = search_obj(arr,l,e);
            if(res==-1) cout<<"The Search key is not in the array"<<"\n";
            else cout<<"The search key "<<e<<"is at index "<<res<<"\n";
        }

        else if(x==4){
            cout<<"Current Array List is : ";
            print(arr,l);
        }
        else break;
    }
}
