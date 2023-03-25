#include <bits/stdc++.h>
using namespace std;

void insert(int SAL[], int &MAX, int &size, int &element, int index);
void delete_element(int SAL[], int &MAX, int &size, int index);
void print_array(int SAL[], int size);
void linear_search(int SAL[], int size, int element);
int main()
{
    int MAX;
    cout << "Enter the number of elements in the array: ";
    cin >> MAX;
    int SAL[MAX];
    int size = 0;
    while (1)
    {
        cout << "Max Size of SAL is set to " << MAX << endl;
        cout << endl;
        cout << "Menu \n 1. Insert New Element \n 2. Delete Element \n 3. Search for an Element \n 4. Print Current Array \n 5. Exit \n";
        cout << "Enter Choice: ";
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            int element, index;
            cout << "Enter the element to be inserted: ";
            cin >> element;
            cout << "Enter the index at which the element is to be inserted (current array length is:" << size << ", so choose an index between " << 0 << " and " << size << "): ";
            cin >> index;
            insert(SAL, MAX, size, element, index);
            cout << element << " inserted at index " << index << endl;
            cout << "The current array list is: ";
            print_array(SAL, size);
        }
        else if (choice == 2)
        {
            int index;
            cout << "The current array list is: ";
            print_array(SAL, size);
            cout << "Enter index to delete from: ";
            cin >> index;
            delete_element(SAL, MAX, size, index);
            cout << "Deleted from position " << index << endl;
            cout << "The current array list is: ";
            print_array(SAL, size);
        }
        else if (choice == 3)
        {
            int element;
            cout << "Enter the element to be searched: ";
            cin >> element;
            linear_search(SAL, size, element);
        }
        else if (choice == 4)
            print_array(SAL, size);

        else
            break;
    }
    return 0;
}
void right_shift(int SAL[], int index, int size)
{
    for (int i = size; i > index; i--)
    {
        SAL[i] = SAL[i - 1];
    }
}

void insert(int SAL[], int &MAX, int &size, int &element, int index)
{
    if (size == MAX)
    {
        cout << "Array is full. Cannot insert new element." << endl;
        return;
    }
    else if (index > size)
    {
        cout << "Incorrect positional value. The value can not be inserted." << endl;
        return;
    }
    else if (index < 0)
    {
        cout << "Incorrect positional value. The value can not be inserted." << endl;
        return;
    }
    right_shift(SAL, index, size);
    SAL[index] = element;
    size++;
}

void left_shift(int SAL[], int index, int size)
{
    for (int i = index; i < size; i++)
    {
        SAL[i] = SAL[i + 1];
    }
}

void delete_element(int SAL[], int &MAX, int &size, int index)
{
    if (size == 0)
    {
        cout << "size is zero" << endl;
        return;
    }
    else if (index > size)
    {
        cout << "Incorrect pos value" << endl;
        return;
    }
    else if (index < 0)
    {
        cout << "Incorrect pos value" << endl;
        return;
    }
    left_shift(SAL, index, size);
    size--;
}

void print_array(int SAL[], int size)
{
    cout << "The current array list is: ";
    for (int i = 0; i < size; i++)
    {
        cout << SAL[i] << " ";
    }
    cout << endl;
}

void linear_search(int SAL[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (SAL[i] == element)
        {
            cout << "The search key " << element << " is at index " << i << endl;
            return;
        }
    }
    cout << "The search key is not in the array. " << endl;
}
