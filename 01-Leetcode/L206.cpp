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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        stack<int> st;
        ListNode *reL, *reH;
        reH = new ListNode(0);
        reL = reH;
        while(head != nullptr) {
            st.push(head->val);
            head = head->next;
        }
        while(st.empty() == false){
            int Lval = st.top();
            st.pop();
            reH->next= new ListNode(Lval);
            reH = reH->next;
        }
        reL = reL->next;
        return reL;
        
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)