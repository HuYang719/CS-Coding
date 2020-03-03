//需要考虑特殊情况 [1,2,2,2,3,3]时，每次p1和p2相等的时候，
//不止p2要后跳，还要把p1的next置为nullptr，不然在末尾上可能出错

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p1, *p2, *p;
        if(head == nullptr)
            return nullptr;
        p1 = head;
        p2 = head->next;
        p = p1;
        while(p2 != nullptr){
            if(p2->val == p1->val) {
                p2 = p2->next;
                p1->next = nullptr;
            }else {
                p1->next = p2;
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        return p;
        
    }
};