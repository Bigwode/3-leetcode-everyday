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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
    {
        if(pListHead==nullptr || k==0) return nullptr;
        ListNode* p1 = pListHead;
        ListNode* p2 = pListHead;
        for(int i=0; i<k-1; i++) // 快指针先走k-1步
        {
            if(p1->next == nullptr) return nullptr;　// 注意这里是p1->next，画图看结果
            else 
                p1 = p1->next;
        }

        while(p1->next != nullptr)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p2;
    }
};
