// 2. Add Two Numbers
// 1hour
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int sum = 0;
        int l1Val = 0;
        int l2Val = 0;
        ListNode* cur = new ListNode(0);
        ListNode* head = cur;
        while(l1!=NULL || l2!=NULL){
            if(l1 != NULL)
                l1Val = l1->val;
            else
                l1Val = 0;
            if(l2 != NULL)
                l2Val = l2->val;
            else
                l2Val = 0;
            sum = l1Val + l2Val + carry;
            if(sum>=10){
                carry = 1;
                sum -= 10;
            }else{
                carry = 0;
            }
            ListNode* next = new ListNode(sum);
            cur->next = next;
            cur = next;
            if(l1 != NULL)
                l1 = l1->next;
            if(l2 != NULL)
                l2 = l2->next;
        }
        if(carry > 0){
            ListNode* next = new ListNode(carry);
            cur->next = next;
            cur = next;
        }


        return head->next;

    }
};