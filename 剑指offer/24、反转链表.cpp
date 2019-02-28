/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead)
    {
        if(pHead == nullptr) return nullptr;
        ListNode* pPre = nullptr;
        ListNode* pNode = pHead;
        
        while(pNode != nullptr)
        {
            ListNode* pNext = pNode->next;
            pNode->next = pPre;
            pPre = pNode;
            pNode = pNext;
        }
        return pPre;
    }
};
