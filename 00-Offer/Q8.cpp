/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead == nullptr)
            return nullptr;
        else if(pHead->next == nullptr)
            return nullptr;
        ListNode *slow, *fast;
        slow = pHead;
        fast = pHead;
        //求环中的一个点
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                break;
        }
        cout<<slow->val;
        
        //求入口
        if(!fast||!fast->next)return NULL;
        slow = pHead;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;

    }
};