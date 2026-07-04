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
    ListNode* sortList(ListNode* head) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
        ListNode* curr = head;
        while (curr)
        {
            min_heap.push(curr->val);
            curr = curr->next;
        }

        if (min_heap.empty()) return nullptr;

        ListNode* res = new ListNode(min_heap.top());
        ListNode* x = res;
        min_heap.pop();
        while (!min_heap.empty())
        {
            x->next = new ListNode(min_heap.top());
            x = x->next;
            min_heap.pop();
        }

        return res;
    }
};