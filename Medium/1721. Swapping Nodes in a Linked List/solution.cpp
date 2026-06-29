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
    ListNode* swapNodes(ListNode* head, int k) {
        int n = 0;
        ListNode* mv = head;
        while (mv)
        {
            n++;
            mv = mv->next;
        }
        int endIdx = n - k;

        int cnt = 0;
        ListNode* start = head;
        ListNode* end = head;
        ListNode* curr = head;
        while (curr)
        {
            if (cnt == k-1) start = curr;
            if (cnt == endIdx) end = curr; 
            curr = curr->next;
            cnt++;
        }

        std::swap(start->val, end->val);

        return head;
    }
};