// C++ implementation of Dynamic Array
#include <iostream>
#include<stdio.h>
using namespace std;

//template <class T> // this is a template class. It's helpful since we don't know what's the data of of the DAL that the user wants (int, float or some user-def Data type
class DynamicArray {
private:
    int * d_array; //a pointer that we'll use to store whatever data we need
    int max_size; //to store the current array's max possible size (it doubles, remember?)
    int length; //to store array's current length
public:
    DynamicArray() //a constructor function, it's called whenever a object of this class is created

    {
        // initially allocate a single memory block
        max_size = 2;
        d_array = new int[max_size];   // like int * a = new int [10], this is static
        length = 0;
    }

    // insert a new item to the end of the d_array
    void add(int item) {
        if (isFull()) {
            // create temporary array with double the size of the previous array
            max_size = 2 * max_size;
            int * temp_d_array = new int[max_size];
            cout<<"\nDAL Limit reached, new array created, values copied\n"<<endl;
            // move all the elements to the temporary d_array
            for (int i = 0; i < length; i++) {
                temp_d_array[i] = d_array[i];
            }

            // delete the old d_array
            delete [] d_array;

            // assign temp d_array's ptr to d_array
            d_array = temp_d_array;

           // delete [] temp_d_array;
        }

        // add the new item at the end of the d_array
        //the following portion is out of the if condition, since this will happen for both the cases
        //the if portion contains only the new array declaration and copying portion
        d_array[length] = item;

        length++;
    }

    void printd_array() {
        for (int i = 0; i < length; i++) {
            cout<<d_array[i]<<' ';
        }
        cout<<endl;
    }

    // check if the d_array is full
    bool isFull() {
        return length == max_size;

    }

    ~DynamicArray() //a destructor function, deallocates memory when the program closes/object is no longer needed
    {
        delete [] d_array;
    }


};

int main() {

    DynamicArray dal;

    int a, choice;
    printf("\t\tDynamic Array d_array Implementation using Template Class.\n\t\t\tDo menu options 3-7 on your own.");


   while (1)
{


    printf("\n1.Add an element\n2.See current Elements\n3-7.write code for menu options 3-7 as per the assignment\n8.Exit");
    //printf("\n3.Delete element from a particular position\n4.Insert at a particular position\n5.Delete matching values\n6.Replace matching values\n7. A unique function that you think can be beneficial for DALs\n\nPress any other key to terminate the program. ");
    printf("\n\nEnter your choice: ");
    scanf("%d", &choice);



    if(choice==1)
    {
        printf("\nEnter a num to add: ");
        scanf("%d", &a);
        dal.add(a);

        cout<<"The current dynamic array is: ";
        dal.printd_array();
    }

    else if (choice==2)
    {
        cout<<"The current dynamic array is: ";
        dal.printd_array();
    }

     else if (choice==3)
    {
       //do by yourself
       //Let the user delete the value from a particular position in the DAL.
    }

    else if (choice==4)
    {
       //do by yourself
       //Let the user insert a value into a particular position in the DAL.
    }
    else if (choice==5)
    {
       //do by yourself
       //Delete ALL matching values. Resize the Dynamic array as per the algorithm shown in class
       //think when it�ll be resized carefully

    }
    else if (choice==6)
    {
       //do by yourself
       //Replace ALL matching values.

       //There may be two cases as shown in the sample input-output.

    }
    else if (choice==7)
    {
       //do by yourself
       /*A unique function that you think can be beneficial for DALs.
        Write appropriate comments on top of your function. */
    }

    else
    {
        printf("\n\t\tProgram Terminated\n\n");
        break;
    }


}



    return 0;
}
