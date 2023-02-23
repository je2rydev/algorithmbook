/*
    - 23. Merge k Sorted Lists
    30mins
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
private:
    bool checkNULLinLists(vector<ListNode*>& lists){
        for(int i=0; i<lists.size(); i++){
            if(lists[i] != NULL)
                return true;
        }
        return false;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(0);
        ListNode* prev = head;
        while(checkNULLinLists(lists)){
            ListNode* minNode = NULL;
            int min = 10001;
            int pos = 0;
            for(int i=0; i<lists.size(); i++){
                if(lists[i] == NULL)
                    continue;
                if(lists[i]->val < min){
                    min = lists[i]->val;
                    pos = i;
                    minNode = lists[i];
                }
            }
            lists[pos] = minNode->next;
            ListNode* cur = new ListNode(min);
            prev->next = cur;
            prev = cur;
        }

        return head->next;
    }
};