#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int value, node *nextNode = NULL)
    {
        this->data = value;
        this->next = nextNode;
    }
};

int main()
{
    int value;
    node *third = new node(5);
    node *akshu = new node(4, third);
    node *rishab = new node(3, akshu);
    node *head = new node(2, rishab); // in dynamic creation we create a pointer that points to the memory location in the heap.
    cout << "Enter the node to be inserted at the beginning:";
    cin >> value;
    node *NEW = new node(value, head);
    head = NEW;
    node *p = head;
    while (p != NULL)
    {
        cout << p->data << " ";
        node *temp = p;
        p = p->next;
        delete temp;
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
