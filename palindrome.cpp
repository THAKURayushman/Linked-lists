#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Checking linked list for palindrome

// Algorithm
// 1. Break the list into 2 halves
// 2. Reverse the Second Half
// 3. Compare the two lists

void insertEnd(ListNode *&head, int value)
{
    ListNode *newNode = new ListNode(value);
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        ListNode *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

ListNode *middleNode(ListNode *head)
{
    ListNode *p = head;
    ListNode *q = head;
    while (p->next != nullptr && p->next->next != nullptr)
    {
        q = q->next;
        p = p->next->next;
    }
    return q;
}

ListNode *reverseList(ListNode *head)
{
    ListNode *q = nullptr; // r->q->p
    ListNode *p = head;
    ListNode *r = nullptr;

    while (p != nullptr)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r; // reversing the list
    }
    head = q; // q will be at the last node of the loop i.e the head of the
              // reversed linked list
    return head;
}

bool compareLists(ListNode *head1, ListNode *head2)
{
    ListNode *p = head1;
    ListNode *q = head2;

    while (p != nullptr && q != nullptr)
    {
        if (p->val != q->val)
        {
            return false;
        }
        else
        {
            p = p->next;
            q = q->next;
        }
    }
    return true;
}

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {

        // finding the middle to break the list
        ListNode *mid = middleNode(head);

        // reversing the second half
        ListNode *head2 = mid->next;
        mid->next = nullptr;
        head2 = reverseList(head2);

        // comparing the lists
        return compareLists(head, head2);
    }
};

int main()
{
    // linked list

    ListNode *head = nullptr;
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 3);
    insertEnd(head, 2);
    insertEnd(head, 3);
    Solution s;
    cout << s.isPalindrome(head);
}