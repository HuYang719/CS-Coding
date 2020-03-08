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
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == NULL)
            return nullptr;
        ListNode *pNewHead = new ListNode(0);
        ListNode *p1, *p2;
        pNewHead->next = pHead; //忘记连接了
        p1 = pNewHead;
        p2 = pHead;
        
        while(p2 != nullptr && p2->next != nullptr) { //后面要用到p2
            if(p2->val == p2->next->val) {
                int val = p2->val;
                while(p2!= nullptr && p2->val == val) {
                    p2 = p2->next;
                }
                p1->next = p2;
                //保持了p2比p1往前一个的状态，进入下一次的循环
            }else {
                //则p1本身next就与p2进行了连接
                p1 = p2;
                p2 = p2->next;
            }
            
        }
        pNewHead = pNewHead->next;
        return pNewHead;
    }
};