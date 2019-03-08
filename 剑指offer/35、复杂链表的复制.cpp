/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    void cloneNode(RandomListNode* pHead)
    {
        RandomListNode* pNode = pHead;
        
        while(pNode != nullptr)
        {
            RandomListNode* pCloneNode = new RandomListNode(-1);  // 创建新节点
            pCloneNode->label = pNode->label;
            pCloneNode->next = pNode->next;
            pCloneNode->random = nullptr;  //　注意这里容易遗漏
            pNode->next = pCloneNode;
            pNode = pCloneNode->next;
        }
    }
    
    void cloneRandom(RandomListNode* pHead)
    {
        RandomListNode* pNode = pHead;
        while(pNode != nullptr)
        {
            RandomListNode* pClone= pNode->next;  //　
            if(pNode->random != nullptr)
            {
                pClone->random = pNode->random->next;
            }
            pNode = pClone->next;
        }
    }
    
    RandomListNode* splitNode(RandomListNode* pHead)
    {
        RandomListNode* pNode = pHead;
        RandomListNode* pCloneHead = nullptr;
        RandomListNode* pCloneNode = nullptr;
        if(pNode != nullptr) //　初始化
        {
            pCloneHead = pCloneNode = pNode->next;
            pNode->next = pCloneNode->next;
            pNode = pNode->next;
        }
        
        while(pNode != nullptr)
        {
            pCloneNode->next = pNode->next;
            pCloneNode = pCloneNode->next;
            pNode->next = pCloneNode->next;
            pNode = pNode->next;
        }
        return pCloneHead;
    }
    
    RandomListNode* Clone(RandomListNode* pHead)
    {
        cloneNode(pHead);
        cloneRandom(pHead);
        return splitNode(pHead);
    }
};
