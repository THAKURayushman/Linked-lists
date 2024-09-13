#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node(int value, node *nextNode)
    {
        data = value;
        next = nextNode;
    }
};

int main()
{
    // static creation
    // node head;
    // head.data = 1;
    // head.next = NULL;

    // dynamic creation
    node *third = new node(5, NULL);
    node *second = new node(4, third);
    node *first = new node(3, second);
    node *head = new node(2, first); //----> inn dynamic creation we create a pointer that points to the memory location in the heap.
    node *ptr = head;

    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        node *ptr2 = ptr;
        ptr = ptr->next;
        delete ptr2;
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
