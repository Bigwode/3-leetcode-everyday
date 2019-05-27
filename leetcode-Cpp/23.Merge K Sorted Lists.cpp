/*思路1：分治法*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        if(!l1) return l2;
        if(!l2) return l1;

        if(l1->val < l2->val)
        {
            l1->next = merge(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }
    
    ListNode* partition(vector<ListNode*>& lists, int low, int high)
    {
        if(low == high)
            return lists[low];  // 注意这里不能用0
        if(low < high)
        {
            int mid = low + (high-low)/2;
            ListNode* l1 = partition(lists, low, mid);
            ListNode* l2 = partition(lists, mid+1, high);
            return merge(l1, l2);
        }
        return nullptr;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        return partition(lists, 0, lists.size()-1);
    }
};


/*Method 2:优先队列*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    struct cmp{
        bool operator()(const ListNode* l1, const ListNode* l2)
        {
            return l1->val > l2->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        priority_queue<int, vector<ListNode*>, cmp> q;
        for (auto l : lists)
        {
            if(l)
                q.push(l);
        }
        if(q.empty()) return nullptr;
        
        ListNode* result = q.top();
        q.pop();
        if(result->next) q.push(result->next);
        ListNode* tail = result;
        while(!q.empty())
        {
            tail->next = q.top();
            q.pop();
            tail = tail->next;
            if(tail->next) q.push(tail->next);
        }
        return result;
    }
};
