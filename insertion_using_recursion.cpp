#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int value, node *nextNode = NULL)
    {
        data = value;
        next = nextNode;
    }
};

node *createLinkedList(vector<int> arr, int size, int index)
{
    int n = size;
    // base case
    if (index == n)
    {
        return NULL; // array ended, so the next of the previous node should be null, thus return null
    }
    node *currentNode = new node(arr[index], createLinkedList(arr, size, index + 1));
    return currentNode; // return the created node
}

// insertion at the end
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    node *head = createLinkedList(arr, arr.size(), 0);
    node *ptr = head;
    while (ptr)
    {
        node *temp = ptr;
        cout << ptr->data << " --> ";
        ptr = ptr->next;
        delete temp;
    }
    cout << "NULL" << endl;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
