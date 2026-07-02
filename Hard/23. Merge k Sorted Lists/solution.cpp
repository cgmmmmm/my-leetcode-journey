/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if (lists.empty()) return nullptr;
        
        std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
        for (ListNode* list : lists)
        {
            while (list)
            {
                min_heap.push(list->val);
                list = list->next;
            }
        }

        if (min_heap.empty()) return nullptr;

        ListNode* ll = new ListNode(min_heap.top());
        min_heap.pop();
        ListNode* curr = ll;
        while (!min_heap.empty())
        {
            curr->next = new ListNode(min_heap.top());
            min_heap.pop();
            curr = curr->next;
        }

        return ll;
    }
};