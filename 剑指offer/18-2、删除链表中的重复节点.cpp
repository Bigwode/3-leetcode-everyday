/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == nullptr)
            return nullptr;
        ListNode* pNew = new ListNode(-1);
        pNew->next = pHead;
        ListNode* pPre = pNew;  // 指向被删除节点的上一个节点
        ListNode* pNode = pHead;
        ListNode* pNext = nullptr;
        
        while(pNode != nullptr && pNode->next != nullptr)
        {
            pNext = pNode->next;
            if(pNode->val == pNext->val)
            {
                while(pNext != nullptr && pNode->val == pNext->val)
                    pNext = pNext->next;
                pPre->next = pNext;
            }
            else
            {
                pPre = pNode;
            }
            pNode = pNext;
        }
        return pNew->next;
    }
};
