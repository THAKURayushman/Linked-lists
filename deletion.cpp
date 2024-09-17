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

void deletionAtStart(node *&head)
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    node *temp = head;
    head = head->next;
    delete temp;
}

void deletionAtEnd(node *&head)
{
    node *temp = head;

    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    else if (head->next == nullptr) // there is only one node in list
    {
        delete temp;
        head = nullptr;
        return;
    }
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    delete temp->next->next;
    temp->next = nullptr;
}

void deleteXNode(node *&head, int target)
{
    node *curr = head;
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    if (head->data == target)
    {
        head = head->next;
        delete curr;
        return;
    }

    node *prev = nullptr;

    while (curr->data != target && curr != nullptr)
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr == nullptr)
    {
        cout << "target is not present in the list" << endl;
        return;
    }

    prev->next = curr->next;
    delete curr;
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

int main()
{
    node *head = nullptr;
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);

    cout << "Linked list before deletion" << endl;
    printList(head);
    cout << "Linked List after deleting first node" << endl;
    deletionAtStart(head);
    printList(head);
    cout << "Linked list after deleting the last node" << endl;
    deletionAtEnd(head);
    printList(head);
    cout << "linked list after deleting the target node" << endl;
    deleteXNode(head, 3);
    printList(head);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
