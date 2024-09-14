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

int main()
{
    node *head = NULL;

    vector<int> arr;
    cout << "enter the length of the ll: ";
    int length;
    cin >> length;
    arr.resize(length);
    cout << "enter the nodes to be inserted in the ll starting from the last node:";
    for (int i = 0; i < length; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < length; i++)
    {
        node *NEW = new node(arr[i]);
        if (head == NULL)
        {
            head = NEW;
        }
        else
        {
            NEW->next = head;
            head = NEW;
        }
    }
    node *ptr = head;
    while (ptr)
    {
        node *temp = ptr;
        cout << ptr->data << "->";
        ptr = ptr->next;
        delete temp;
    }
    cout << "NULL";

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
