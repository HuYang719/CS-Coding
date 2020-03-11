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
        stack<int> s1, s2, s3;
        int c1=0, c2=0;
        while(l1 != nullptr) {
            s1.push(l1->val);
            l1 = l1->next;
            c1++;
        }
        
         while(l2 != nullptr) {
            s2.push(l2->val);
            l2 = l2->next;
            c2++;
        }
        
        int diff = abs(c2-c1);
        int add = 0;
        int min_c = min(c2,c1);
     
        while(min_c--){
            int t1 = s1.top();
            s1.pop();
            int t2 = s2.top();
            s2.pop();
            int t3 = t1+t2+add;
            if(t3>=10){
                s3.push(t3-10);
                add = 1;
            }else{
                s3.push(t3);
                add = 0;
            }
        }
        if(diff>0 && c2>c1){
            while(!s2.empty()){
                int t2 = s2.top()+add;
                s2.pop();
                if(t2>=10){
                    s3.push(t2-10);
                    add = 1;
                }else{
                    s3.push(t2);
                    add = 0;
                }
            }
        }else if(diff>0 && c2<c1){
            while(!s1.empty()){
                int t1 = s1.top()+add;
                s1.pop();
                if(t1>=10){
                    s3.push(t1-10);
                    add = 1;
                }else{
                    s3.push(t1);
                    add = 0;
                }
            }
        }
        if(add == 1)
            s3.push(1);
        ListNode *l3 = new ListNode(0);
        ListNode *lhead = l3;
        while(!s3.empty()){
            l3->next = new ListNode(s3.top());
            s3.pop();
            l3 = l3->next;
        }
        return lhead->next;
           
            
        
        
    }
};