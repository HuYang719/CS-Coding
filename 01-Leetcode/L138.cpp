/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> hashMap;
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return NULL;
        if(hashMap.find(head) != hashMap.end())
            return hashMap[head];
        Node* node = new Node(head->val);
        hashMap[head] = node;
        node->next = copyRandomList(head->next);
        node->random = copyRandomList(head->random);
        return node;
        
        
    }
};