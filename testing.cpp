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
    node head(2);
    cout << head.data;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
