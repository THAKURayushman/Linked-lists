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
void kthNodefromlast(node *head, int k, int &ans)
{
    node *p = head;
    node *q = head;

    if (head == nullptr)
    {
        cout << "list is empty" << endl;
        return;
    }
    if (k < 1)
    {
        cout << "Enter a valid k";
        return;
    }

    while (p->next != nullptr && k != 1)
    {
        p = p->next;
        k--;
    }
    if (p == nullptr || k != 1)
    {
        cout << "node not present" << endl;
        return;
    }
    while (p->next != nullptr)
    {
        p = p->next;
        q = q->next;
    }
    ans = q->data;
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
    int k;
    int ans = -1;
    cout << "insrt the value of k:";
    cin >> k;
    cout << "list is : ";
    printList(head);
    kthNodefromlast(head, k, ans);
    if (ans != -1)
    {
        cout << k << "th node from last is: " << ans;
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
