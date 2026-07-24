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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) 
    {
        if (!head->next->next) return {-1, -1};
        
        // imagine a new critical point in any arbitrary position, i
        // let first critical point appearance be pos1(min) and pos2(max)

        int minDist = INT_MAX; // i - pos1, for every new i, then update pos1 = i
        int maxDist = INT_MIN; // i - pos2, for every new i

        ListNode* prev = head;
        head = head->next;
        ListNode* curr = head;
        head = head->next;
        int idx = 1;
        int critCnt = 0;
        int pos1=-1, pos2=-1;
        while (head)
        {
            bool critMax = (curr->val > prev->val) && (curr->val > head->val);
            bool critMin = (curr->val < prev->val) && (curr->val < head->val);
            if (critMax || critMin)
            {
                critCnt++;
                if (pos1==-1) pos1 = idx;
                if (pos2==-1) pos2 = idx;

                if (critCnt >= 2)
                {
                    minDist = std::min(minDist, idx-pos1);
                    pos1 = idx;
                    maxDist = std::max(maxDist, idx-pos2);
                }
            }

            prev = prev->next;
            curr = curr->next;
            head = head->next;
            idx++;
        }

        if (critCnt < 2) return {-1, -1};
        return {minDist, maxDist};
    }
};