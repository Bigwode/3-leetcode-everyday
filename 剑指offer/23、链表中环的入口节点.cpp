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
    ListNode* MeetingNode(ListNode* pHead)
    {
        if(pHead==nullptr) return nullptr;
        ListNode* pSlow = pHead->next;
        if(pSlow == nullptr) return nullptr;
        ListNode* pFast = pSlow->next;
        if(pFast == nullptr) return nullptr;
        while(pSlow != nullptr && pFast != nullptr)
        {
            pSlow = pSlow->next;
            pFast = pFast->next;
            if(pFast != nullptr)
                pFast = pFast->next;
            if(pFast == pSlow)
                return pFast;
        }
        return nullptr;
    }
    
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        ListNode* MeetNode = MeetingNode(pHead); // 判断是否有环
        if(MeetNode == nullptr) return nullptr;
        ListNode* MeetMark = MeetNode->next;
        int loopCount = 1;  // 计算环的长度
        while(MeetMark != MeetNode)
        {
            ++loopCount;
            MeetMark = MeetMark->next;
        }
        
        ListNode* p1 = pHead;
        ListNode* p2 = pHead;
        for(int i=0; i<loopCount; i++)
            p1 = p1->next;
        while(p1 != p2)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};
