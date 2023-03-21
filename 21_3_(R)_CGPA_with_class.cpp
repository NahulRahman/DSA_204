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
    int n, res, roll;
    cout<<"Enter num of Students: ";
    cin>>n;

    student s1[n];

    for(int i=0;i<n;i++)
    {
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

    }

    cout<<"\nSearch for an ID: ";
    cin>>roll;
    int found_at=LinearSearch(s1,roll,n);

    if(found_at!=-1)
        cout<<"\n"<<roll<<" was found, CGPA: " <<s1[found_at].CGPA;
    else if(found_at==-1)
        cout<<"\nThe ID was not found";

    cout<<"\n\nC++ Program Terminated\nAND that's how it's done!"<<endl;
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
