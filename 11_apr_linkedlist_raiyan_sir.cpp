//SLL.c
#include<stdio.h>
#include<stdlib.h>
struct node{
	int value;
	struct node *next;
};
struct node *head;

void printList()
{
  if (head==NULL)   // no list at all
	  return;
  struct node *temp =  head;
  while (temp != NULL)
  {
       printf("%d ->", temp->value);
	temp = temp->next;
  }
  printf("END (for now!)");
}

void insertHead(int num){
   //create a new node
   struct node *newItem;
   newItem=(struct node *)malloc(sizeof(struct node));
   newItem->value = num;
   newItem->next = NULL;
   //insert the new node at the head
   newItem->next = head;
   head = newItem;
}

void insertTail(int num){
   //create a new node to be inserted
   struct node *newItem;
   newItem=(struct node *)malloc(sizeof(struct node));
   newItem->value = num;
   newItem->next = NULL;
   // set prev to point to the last node of the list
   struct node *prev = head;
   while (prev->next != NULL)
       prev = prev->next;
   //newItem->next = NULL;
   prev->next = newItem;
}


void insertatPosition(int num, int pos){
   //create a new node to be inserted
   struct node *newItem;
   newItem=(struct node *)malloc(sizeof(struct node));
   newItem->value = num;
   newItem->next = NULL;
   // set prev to point to the desired node of the list
   struct node *prev = head;
   for (int i=0;i<pos-1;i++)
   {
       prev = prev->next;
   }

   newItem->next = prev->next;
   prev->next = newItem;
}


void insertAfterValue(int num, int val){
   //create a new node to be inserted
   struct node *newItem;
   newItem=(struct node *)malloc(sizeof(struct node));
   newItem->value = num;
   newItem->next = NULL;
   // set prev to point to the desired node of the list
   struct node *prev = head;
   while (prev->value != val){
       prev = prev->next;
   }
   newItem->next = prev->next;
   prev->next = newItem;
}


void deleteHead()
{
   struct node *cur;
   if (head==NULL)  //list empty
	   return;
   cur = head;  // save head pointer
   head = head->next; //advance head
   free(cur);
}

void deleteTail(){
   if (head==NULL)       //list empty
	   return;
   struct node *cur = head;
   struct node *prev = NULL;
   while (cur->next != NULL){
	   prev = cur;
	   cur=cur->next;
   }
   if (prev != NULL)
  	   prev->next = NULL;
   free(cur);
}


void deletefromPosition(int pos){
   if (head==NULL)       //list empty
	   return;
   struct node *cur = head;
   struct node *prev = NULL;

   for(int i=0;i<pos;i++)
   {
       prev = cur;
	   cur=cur->next;
   }

 if (prev != NULL)
  	   prev->next = cur->next;
 free(cur);
}

void deleteVal(int x){
   if (head==NULL)       //list empty
	   return;
   struct node *cur = head;
   struct node *prev = NULL;
   while (cur->value != x){
	   prev = cur;
	   cur=cur->next;
   }
 if (prev != NULL)
  	   prev->next = cur->next;
 free(cur);
}



int main()
{

    head=NULL;

    printf("\t\tImplementation of a Single Linked List\n\t\tCheck the slide for Explanation\n\t\tCSE 203, Lec Raiyan");
    while(1)
    {
        int ch, num, pos, val;
        printf("\n\n1.Insert First\n2.Insert Last\n3.Insert Middle (Any other pos)\n4.Insert After a Target Val\n5.Delete Head\n6.Delete Tail\n7. Delete from a Position\n8.Delete a Value\n9.Print\n10. Add a function for practice \n11.Exit\n\nEnter Choice: ");
        scanf("%d", &ch);

        if(ch==1)
        {
            printf("\nEnter val to insert: ");
            scanf("%d", &num);
            insertHead(num);
        }
        else if (ch==2)
        {
            printf("\nEnter val to insert: ");
            scanf("%d", &num);
            insertTail(num);
        }
        else if (ch==3)
        {
            printf("\nEnter val to insert: ");
            scanf("%d", &num);
            printf("\nEnter Position to insert: ");
            scanf("%d", &pos);
            insertatPosition(num, pos);
        }

        else if(ch==4)
        {
            printf("\nEnter val to insert: ");
            scanf("%d", &num);
            printf("\nEnter Value to insert after: ");
            scanf("%d", &val);
            insertAfterValue(num, val);
        }

        else if(ch==5)
        {
            deleteHead();
        }
        else if(ch==6)
        {
            deleteTail();
        }
        else if(ch==7)
        {
            printf("\nEnter Position to Delete from: ");
            scanf("%d", &pos);
            deletefromPosition(pos);
        }
        else if (ch==8)
        {
            printf("\nEnter Value to delete: ");
            scanf("%d", &val);
            deleteVal(val);
        }

        else if(ch==9)
        {
            printList();
        }

        else if(ch==10)
        {
            //ADD YOUR OWN FUNCTION - PRACTICE
        }

        else
        {
            printf("\n\n\t\tProgram Terminated\n\n");
            break;
        }
    }
    return 0;
}
