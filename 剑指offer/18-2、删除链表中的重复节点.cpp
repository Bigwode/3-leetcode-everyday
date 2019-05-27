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
        ListNode* pNew = new ListNode(-1); // 为了应对头结点需要删除的情况
        pNew->next = pHead;
        ListNode* pPre = pNew;  // 指向被删除节点的上一个节点
        ListNode* pNode = pHead;  //　指向当前节点
        ListNode* pNext = nullptr;  //　指向下一个节点
        
        while(pNode != nullptr && pNode->next != nullptr)
        {
            pNext = pNode->next;
            if(pNode->val == pNext->val)
            {
                while(pNext != nullptr && pNode->val == pNext->val)  // 下个节点存在并且和当前节点的值相等
                    pNext = pNext->next;
                pPre->next = pNext;
            }
            else
            {
                pPre = pNode;　　//
            }
            pNode = pNext;
        }
        return pNew->next;
    }
};
