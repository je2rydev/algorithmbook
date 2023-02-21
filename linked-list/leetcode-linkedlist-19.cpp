/*
19. Remove Nth Node From End of List
50mins
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // store n of values
        vector<ListNode*> nodeStore;
        if(head->next == NULL)
            return NULL;
        
        ListNode* cur = head;
        while(cur){
            if(nodeStore.size() == n+1){
                nodeStore.erase(nodeStore.begin());
                nodeStore.push_back(cur);
            }else{
                nodeStore.push_back(cur);
            }
            cur = cur->next;
        }

        if(nodeStore.size()==n)
            return head->next;
        if(nodeStore.size()>2)
            nodeStore[0]->next = nodeStore[2];
        else
            nodeStore[0]->next = NULL;

        return head;

    }
};