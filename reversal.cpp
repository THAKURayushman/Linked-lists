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

void insertEnd(node *&head, int value)
{
    node *newNode = new node(value);
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(node *head)
{
    node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void freeList(node *head)
{
    while (head != nullptr)
    {
        node *temp = head;
        head = head->next;
        delete temp; // Free the memory
    }
}

node *reversal(node *head)
{
    node *q = nullptr;
    node *p = head;
    node *r = nullptr;

    while (p)
    {
        // increment
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }

    head = q;
    return head;
}
int main()
{
    node *head = nullptr;
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);
    insertEnd(head, 6);
    cout << "before reversal: ";
    printList(head);
    head = reversal(head);
    cout << "after reversal: ";
    printList(head);
    freeList(head);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
