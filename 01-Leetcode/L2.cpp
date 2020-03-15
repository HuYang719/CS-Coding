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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *cur=NULL, *LBegin=NULL;
        int x=0;
        while(x || l1!=NULL || l2!=NULL){
            if(cur==NULL){
                cur=new ListNode(x);
                LBegin=cur;
            }else{
                cur->next=new ListNode(x);
                cur=cur->next;
            }
            if(l1!=NULL){
                cur->val+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                cur->val+=l2->val;
                l2=l2->next;
            }
            x=cur->val/10;
            cur->val =cur->val%10;
            
        }
     return LBegin; 
    }
};