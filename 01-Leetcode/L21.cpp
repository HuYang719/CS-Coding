/**
 *    注意新建一个节点的赋值方式，ListNode *L = new ListNode(val) 
**/

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2 == nullptr)
            return nullptr;
        else if(l1 == nullptr)
            return l2;
        else if(l2 == nullptr)
            return l1;
        ListNode *l3, *lhead;
        l3 = new ListNode(0);
        lhead = l3;
        int k = 0;
        while(l1!=nullptr || l2 != nullptr) {
            if(l1!=nullptr && l2!=nullptr) {
                if(l1->val > l2->val) {
                    l3->next = new ListNode(l2->val);
                    l2 = l2->next;
                    l3 = l3->next;
                } else {
                    l3->next = new ListNode(l1->val);
                    l1 = l1->next;
                    l3 = l3->next;
                }
            }
            else if (l1 == nullptr) {
                l3->next = l2;
                l2 = nullptr;
            } else if(l2 == nullptr) {
                l3->next = l1;
                l1 = nullptr;
            }
             
        }
        lhead = lhead->next;
        return lhead;
        
    }
};

// Time Complexity: O(m+n)
// Space Complexity: O(m+n)