/*
    1hour
    234. Palindrome Linked List
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> stackNode;
        vector<int> nodes;
        ListNode* cur = head;
        nodes.push_back(cur->val);
        if(cur->next == NULL)
            return true;
        cur = cur->next;
        while(cur != NULL){
            nodes.push_back(cur->val);
            cur = cur->next;
        }

        if(nodes.size()%2==0){
            for(int i=0; i<nodes.size()/2; i++){
                stackNode.push(nodes[i]);
            }
            for(int i=nodes.size()/2; i<nodes.size(); i++){
                if(stackNode.top() == nodes[i]){
                    stackNode.pop();
                }else
                    break;
                    
            }
        }else{
            for(int i=0; i<nodes.size()/2; i++){
                cout << i << endl;
                stackNode.push(nodes[i]);
            }
            for(int i=nodes.size()/2+1; i<nodes.size(); i++){
                if(stackNode.top() == nodes[i]){
                    stackNode.pop();
                }else
                    break;
            }
        }

        if(stackNode.empty())
            return true;
        else
            return false;
    }
};

/*

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* a = head;
        stack<int> s;
        while(head)
        {
            s.push(head->val);
            head = head->next;
        }
        while(a)
        {
            if(a->val != s.top())
                return false;
            a = a->next;
            s.pop();
        }
        return true;
    }
};

*/