#include <iostream>
using namespace std;

#define SIZE 10

int hashTable[SIZE];

void insert(int x)
{
    int index = x % SIZE;
    int start = index;

    while (hashTable[index] != -1)
    {
        index = (index + 1) % SIZE;

        if (index == start)
        {
            cout << "Hash table is full" << endl;
            return;
        }
    }

    hashTable[index] = x;
    cout << x << " inserted" << endl;
}

void search(int x)
{
    int index = x % SIZE;
    int start = index;

    while (hashTable[index] != -1)
    {
        if (hashTable[index] == x)
        {
            cout << x << " found at index " << index << endl;
            return;
        }

        index = (index + 1) % SIZE;

        if (index == start)
            break;
    }

    cout << x << " not found" << endl;
}

void display()
{
    cout << "Hash Table:" << endl;

    for (int i = 0; i < SIZE; i++)
    {
        cout << i << " : ";

        if (hashTable[i] == -1)
            cout << "Empty";
        else
            cout << hashTable[i];

        cout << endl;
    }
}

int main()
{
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    insert(25);
    insert(35);
    insert(15);

    search(35);
    search(50);

    display();

    return 0;
}
