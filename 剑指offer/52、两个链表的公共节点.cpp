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
    int lenofNode(ListNode* pHead)
    {
        int len = 0;
        ListNode* pNode = pHead;
        while(pNode != nullptr)
        {
            pNode = pNode->next;
            len++;
        }
        return len;
    }
    
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
    {
        int len1 = lenofNode(pHead1);
        int len2 = lenofNode(pHead2);
        
        ListNode* pNode1 = pHead1;
        ListNode* pNode2 = pHead2;
        while(len1<len2 && pNode2 != nullptr)
        {
            pNode2 = pNode2->next;
            --len2;
        }
        while(len1>len2 && pNode1 != nullptr)
        {
            pNode1 = pNode1->next;
            --len1;
        }
        while(pNode1 != nullptr && pNode2 != nullptr && pNode1 != pNode2)
        {
            pNode1 = pNode1->next;
            pNode2 = pNode2->next;
        }
        return pNode1;
    }
};
