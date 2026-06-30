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
    vector<int> nextLargerNodes(ListNode* head) {
        if (!head->next) return {0};

        int n = 0;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            n++;
        }

        std::vector<int> res(n, 0);
        int idx = n-1;
        res[idx] = 0;

        std::stack<int> ms; // monotonic stack

        ms.push(prev->val);
        idx--;
        prev = prev->next;

        while (prev)
        {
            while (!ms.empty() && (ms.top() <= prev->val)) ms.pop();
            
            if (!ms.empty() && prev->val < ms.top()) res[idx] = ms.top();
            else res[idx] = 0;

            ms.push(prev->val);
            idx--;
            prev = prev->next;
        }

        return res;
    }
};