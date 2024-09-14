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

// insertion at the end
int main()
{
    node *head = NULL;
    node *ptr = head;

    while (true)
    {
        cout << "give the command (insert, print, stop):";
        string command;
        cin >> command;
        if (command == "insert")
        {
            cout << "enter the node to be inserted: ";
            int value;
            cin >> value;
            node *NEW = new node(value);

            if (head == NULL)
            {
                head = NEW;
            }
            else
            {
                node *p = head;
                while (p->next)
                {
                    p = p->next;
                }
                p->next = NEW;
            }
        }

        else if (command == "print")
        {
            while (ptr)
            {

                cout << ptr->data << " --> ";
                ptr = ptr->next;
            }
            cout << "NULL" << endl;
        }
        else if (command == "stop")
        {
            break;
        }
        else
        {
            cout << "wrong command! please select from insert, print, stop" << endl;
        }
    }
    ptr = head;
    while (ptr)
    {
        node *temp = ptr;
        ptr = ptr->next;
        delete temp;
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
