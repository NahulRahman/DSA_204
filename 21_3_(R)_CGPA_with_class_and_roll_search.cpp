#include<iostream>
using namespace std;


class student {

public:
    int id; //these are what needs to be stored for a user type "student" in my system
    float CGPA;
    //int waiver;
    int check_waiver()  //this is a "feature" or "functionality" of the student users.
    {
        if(CGPA>=3.8)
            return 1;
        else
            return 0;
    }

};

int LinearSearch(student [], int, int);

int main()
{
    int n, res, roll, i=0, choice;

    cout<<"Enter total num of Students in class: ";
        cin>>n;

        student s1[n];

    while(1)
    {


    cout<<"\n\nMenu: \n1.Enter Student Data\n2.Search Student Data\n3.Exit\nEnter Choice: ";
    cin>>choice;

    if(choice==1)
    {

            if(i>=n)
            {
                cout<<"\nStudent Max Limit Reached";
                goto exit;
            }
            cout<<"\n\nEnter ID of student "<<i+1 <<": ";
            cin>>s1[i].id;

            cout<<"\nEnter CGPA of student "<<i+1 <<": ";
            cin>>s1[i].CGPA;

            cout<<"\n"<<s1[i].id<<" has CGPA: " << s1[i].CGPA;

            res=s1[i].check_waiver(); //see how we can call dedicated feature for student with that student's data
            if(res==1)
                cout<<"\nCongrats! You've got waiver.";
            else if(res==0)
                cout<<"\nSorry, you didn't receive a waiver. :( ";

            i++;

    }

    else if(choice==2)
    {
            cout<<"\nSearch for an ID: ";
            cin>>roll;
            int found_at=LinearSearch(s1,roll,n);

            if(found_at!=-1)
                cout<<"\nID "<<roll<<" was found, CGPA: " <<s1[found_at].CGPA;
            else if(found_at==-1)
                cout<<"\nThe ID was not found";
    }


    else
    {
        exit:
        cout<<"\n\nC++ Program Terminated\n"<<endl;
        break;
        return 0;
    }

    }

}


int LinearSearch (student b[ ], int skey, int n) {
int i;

for (i=0; i < n; i++)
{
    if(b[i].id==skey)
        return i;

}

    return -1;

}
