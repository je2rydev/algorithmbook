// 21. Merge Two Sorted Lists
// 30mins
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* cur = head->next;
        ListNode* prev = head;
        if(list1==NULL && list2==NULL)
            return list1;

        while(list1 != NULL || list2 != NULL){
            if(list1 == NULL && list2 != NULL){
                while(list2!=NULL){
                    cur = new ListNode(list2->val);
                    prev->next = cur;
                    prev = cur;
                    list2 = list2->next;
                }
                return head->next;
            }
            if(list2 == NULL && list1 != NULL){
                while(list1!=NULL){
                    cur = new ListNode(list1->val);
                    prev->next = cur;
                    prev = cur;
                    list1 = list1->next;
                }
                return head->next;
            }
            if(list1->val > list2->val){
                cur = new ListNode(list2->val);
                list2 = list2->next;
            }else{
                cur = new ListNode(list1->val);
                list1 = list1->next;
            }
            prev->next = cur;
            prev = cur;
        }
        return head->next;
    }
};