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
    void reorderList(ListNode* head) {
        ListNode *l1, *l2, *l3, *lp;
        if(head == nullptr)
            return;
        l1 = head;
        lp = l1;

        while(l1->next != nullptr) {
            l2 = l1->next;
            l3 = l2;
            cout<<"1:"<<l1->val<<l2->val<<l3->val<<endl;
            if(l3->next == nullptr){
                cout<<"True"<<endl;
                break;
                
            }else {
                ListNode *lpre;
                while(l3->next != nullptr){
                    lpre = l3;
                    l3 = l3->next; 
                }
                lpre->next = nullptr;
                
            }
            cout<<"2:"<<l1->val<<l2->val<<l3->val<<endl;
            l1->next = l3;
            l3->next = l2;
            l1 = l2;
            cout<<"3:"<<l1->val<<l2->val<<l3->val<<endl;
        }
        
    }
};



//
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
    void printfLN( ListNode* head) {
 
        while(head!=nullptr){
            printf("%d->",head->val);
            head = head->next;
        }
    }
    void reorderList(ListNode* head) {
        if(head == nullptr)
            return;
        else if(head->next == nullptr)
            return;
        ListNode *fast, *slow;
        fast = head;
        slow = head;
        ListNode *pre;
        
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }
        cout<<endl<<"slow:";
         printfLN(slow);
          pre->next = nullptr;
        fast = head;
       cout<<endl<<"fast:";
         printfLN(fast);
        cout<<endl<<endl;
        
        

      ListNode *p1 = nullptr;  //4
      ListNode *p2 = slow; //5
        while(p2!= nullptr){
            ListNode *tmp = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = tmp;
        }
        slow = p1;
        fast = head;
        //slow is the head of last part
        ListNode *Lnext, *Fpre;
       while(fast != nullptr){
           Lnext= slow;
           slow = slow->next;
           Lnext->next = fast->next;
           fast->next = Lnext;
           Fpre = fast->next;
           fast = fast->next->next;
       }
        Fpre->next= slow;
        
        
        

        
    }
};