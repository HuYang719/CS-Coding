/**
 * A little trick:
 * 两个指针，各自遍历完后交换定向
 * 关键在于，运行两遍后，两个指针走过的节点数一致
 * 且如果遇到val相同的节点，如果不是同时碰到，则一定不在同一个节点上  
 * 注意list使用时不用带*,->已经表示了*+.
 * 不是方法不要带括号
 * error1:没有考虑最后没有重叠的情况
 * error2:比较的是指针本身是否一致好吗？？？
 */

/**
 * 
 * 方法2，可以先分别统计二者的长度，然后先走差数个再统一走
 */

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr)
            return nullptr;
        ListNode *pA = headA, *pB = headB;
        int k = 0;
        while(pA != pB) {
            if(pA->next == nullptr) {
                pA = headB;
                k++;
            }
            else pA = pA->next;
            // printf("pA->val=%d\n",pA->val);
            
            if(pB->next == nullptr){
                pB = headA;
                k++;
            }
            else pB = pB->next;
              // printf("pB->val=%d\n",pB->val);
            if(k>=4)
                break;
        }
        if(k==4)
            return nullptr;
        else
            return pA;
        
    }
};

/**
 * 时间复杂度分析
 * O(m+n) 二者长度最大值
 * 空间复杂度分析
 * O(1) 开了两个指针
 */