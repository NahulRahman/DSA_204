#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key,level;
    Node *left, *right, *parent;
};

Node *root;

void init(){
    root = NULL;
}

void insertRoot(int val){

    root=new Node;
    root->key=val;
    root->left=NULL  ;
    root->right=NULL;
    root->parent=NULL;

}

void insertOther(int val){

    Node *temp=root;
    Node *prev=NULL;///prev pointer is used to keep trac of previos poiter of temp
    while(temp!=NULL)
    {
        prev=temp;
        if(val<temp->key)
        {
            temp=temp->left;
        }
        else
        {
            temp=temp->right;
        }

    } ///while loop finish

    temp=new Node;
    temp->key=val;
    temp->left=NULL;
    temp->right=NULL;
    temp->parent=prev;

    if(val<prev->key)
    {
        prev->left=temp;
    }
    else{
        prev->right=temp;
    }



}

void insert(int val){
    if(root==NULL)
    {
        insertRoot(val);
    }
    else{
        insertOther(val);
    }
}

Node* findNode(int val){
    Node *temp=root;
    while(temp!=NULL)
    {
        if(temp->key==val)
        {
            return temp;
        }
        else if(val<temp->key)
        {
            temp=temp->left;
        }
        else
        {
            temp=temp->right;
        }
    }
    return temp;

}


Node* findSuccessor(Node *node){
Node *temp=node->right;
while((temp->left)!=NULL)
{
    temp=temp->left;
}
return temp;
}

void delete0Child(Node *node){
Node *temp=node->parent;
if(node->key<temp->key)
node->left=NULL;
else node->right=NULL;
free(node);
}

void delete1Child(Node *node){
    Node *prev=node->parent,*child;
    if(node->right==NULL)
    {
        child=node->left;
    }
    else child=node->right;
    if(node->key<prev->key)
    {
        child->parent=prev;
        prev->left=child;
    }
    else
    {
        child->parent=prev;
        prev->right=child;
    }
    free(node);
}

void delete2Child(Node *node){
Node *success=findsuccessor(*node);
node->key=success->key;
if(success->right==NULL)
    delete0Child(success);
else  delete1Child(success);
}

bool deleteNode(int val)
{
    Node *t=findNode(val);
    if(t==NULL)return false;
    else
    {
        if(t->left==NULL && t->right==NULL)
        {
            delete0Child(t);
        }
        else if(t->left==NULL || t->right==NULL)
        {
            delete1Child(t);
        }
        else delete2Child(t);
    }
    return true;
}



int main(){
    init();


    while(1){
        cout<<"1. Insert\n2. Search\n3. Delete\n\n";
        int x;
        cin>>x;

        if(x==1){
            cout<<"Insert Value: ";
            int y;
            cin>>y;
            insert(y);
        }

        else if(x==2){
            cout<<"Enter the value you want to search ";
            int s;
            cin>>s;
            Node* t=findNode(s);
            if(t==NULL)
                cout<<"Not found"<<endl;
            else
                cout<<"Found"<<endl;
        }

        else if(x==3){
            cout<<"Delete Value: ";
            int y;
            cin>>y;
            bool b = deleteNode(y);
            if(b)   cout<<"Deleted"<<endl;
            else    cout<<y<<" not found"<<endl;
        }


    }
}

/*
1
44

1
17

1
88

1
32

1
65

1
97

1
28

1
54

1
82

1
29

1
76

1
80
*/
