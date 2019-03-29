/*
 * 题目18：O（1）时间内删除列表中的节点
 * 需要考虑：如果删除的节点位于链表末尾；如果删除的节点是链表中的唯一元素；其他情况。
 * */

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};


void deleteNode(ListNode** pNode, ListNode* delNode)
{
    if(pNode== nullptr || delNode== nullptr)
        return;

    if(delNode->next != nullptr)  // 要删除的节点不是尾节点
    {
        ListNode* pNext = delNode->next;
        delNode->val    = pNext->val;
        delNode->next   = pNext->next;

        delete pNext;
        pNext = nullptr;  // delete一个指针之后，一定要设为空指针，否则指针悬浮容易出问题。
    }
    else if(*pNode == delNode)  // 要删除的节点是唯一节点
    {
        delete delNode;
        delNode = nullptr;
        *pNode = nullptr;
    }
    else  //要删除的节点是尾节点
    {
        ListNode* p = *pNode;
        while(p->next != delNode)
        {
            p = p->next;
        }
        p->next = nullptr;
        delete delNode;
        delNode = nullptr;
    }
}

int main()
{
    return 0;
}
