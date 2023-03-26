#include<bits/stdc++.h>
using namespace std;
int Max = 10;
void print(int sal[],int length)
{
    int i;
    for(i=0;i<length;i++)
    {
        cout<<sal[i]<<" ";
    }
    cout<<"\n";
}
int linear_search(int sal[],int length,int key)
{
    int i;
    for(i=0;i<length;i++)
    {
        if(key==sal[i])
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int sal[Max];
    int l = 0;
    while(1)
    {

        cout<<"Max size of SAL is set to "<<Max<<"\n"<<"\n";
        cout<<"Menu"<<"\n"<<"1.Insert New Element\n"<<"2.Delete Element\n"<<"3.Search for an Element\n"<<"4.Print Current Array\n"<<"5.Exit\n";
        cout<<"\n";
        cout<<"Enter Choice: ";
        int choice;
        cin>>choice;
        cout<<"\n";
        if(choice==1)
        {
            cout<<"Enter Element to insert: ";
            int element;
            cin>>element;
            cout<<"\n";
            cout<<"Enter index position to insert (current array length is: "<<l<<",so choose an index between 0 and "<<l<<"): ";
            int pos;
            cin>>pos;
            cout<<"\n";
            if(l==Max)
            {
                cout<<"Array Size is Full"<<"\n";
            }
            else if(pos<0 || pos>l+1)
            {
                cout<<"incorrect positional value. the value cannot be inserted"<<"\n";
            }
            else
            {
                int i;
                for(i=l;i>pos;i--)
                {
                    sal[i] = sal[i-1];
                }
                sal[pos] = element;
                l++;
                cout<<element<<" inserted at position "<<pos<<"\n";
                cout<<"Current Array List is : ";
                print(sal,l);

            }
        }
        else if(choice==2)
        {
            cout<<"Current Array List is : ";
            print(sal,l);
            cout<<"Enter index to delete from: ";
            int p,temp,j;
            cin>>p;
            cout<<"\n";
            if(p<0 || p>l-1)
            {
                cout<<"Incorrect Positional Value"<<"\n";
            }
            else
            {
                temp = sal[p];
                for(j=p;j<=l-2;j++)
                {
                    sal[j]=sal[j+1];
                }
                l--;
                cout<<"Deleted from position "<<p<<"\n";
            }


        }
        else if(choice==3)
        {
            cout<<"Enter the search key: ";
            int k;
            cin>>k;
            cout<<"\n";
            int res = linear_search(sal,l,k);
            if(res==-1)
            {
                cout<<"The Search key is not in the array"<<"\n";
            }
            else
            {
                cout<<"The search key "<<k<<"is at index "<<res<<"\n";
            }
        }
        else if(choice==4)
        {
            cout<<"Current Array List is : ";
            print(sal,l);
        }
        else
        {
            break;
        }

    }
}
