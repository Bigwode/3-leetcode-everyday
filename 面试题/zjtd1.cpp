/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (1 -> 4 -> 3) + (5 -> 6 -> 4)

Output: 6 -> 0 -> 8

*/

#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(nullptr){}
};

ListNode* addTwoList(ListNode* head1, ListNode* head2)
{
    if(!head1) return head2;
    if(!head2) return head1;

    ListNode* res = new ListNode((head1->val + head2->val)%10);

    ListNode* p1 = head1->next;
    ListNode* p2 = head2->next;
    ListNode* p3 = res;
    int sum = 0;
    int carry = (head1->val + head2->val)/10;  // 进位

    while(p1 && p2)
    {
        sum = p1->val + p2->val + carry;
        if(sum >= 10)
        {
            sum -= 10;
            carry = 1;
        }
        else
            carry = 0;

        ListNode* p = new ListNode(sum);
        p3->next = p;
        p1 = p1->next;
        p2 = p2->next;
        p3 = p3->next;
    }

    if(p1)
    {
        p1->val += carry;
        p3->next = p1;
        p3 = p3->next;
        carry = 0;
    }

    if(p2)
    {
        p2->val += carry;
        p3->next = p2;
        p3 = p3->next;
        carry = 0;
    }

    if(carry != 0)
    {
        ListNode* p = new ListNode(carry);
        p3->next = p;
    }

    return res;
}

int main() {
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(4);

    ListNode* l4 = new ListNode(5);
    ListNode* l5 = new ListNode(6);
    ListNode* l6 = new ListNode(4);

    l1->next = l2;
    l2->next = nullptr;

    l4->next = l5;
    l5->next = l6;
    l6->next = nullptr;

    ListNode* res = addTwoList(l1, l4);

    return 0;
}
