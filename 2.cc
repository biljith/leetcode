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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool is_head = true;
        ListNode* head;
        ListNode* temp;
        ListNode* temp1;
        int carry = 0;
        while(l1 != NULL && l2 != NULL) {
            if (is_head) {
                head = temp = new ListNode(0);
                int sum = l1 -> val + l2 -> val + carry;
                carry = sum / 10;
                head -> val = sum % 10;
                is_head = false;
                head -> next = NULL;
            } else {
                temp1 = new ListNode(0);
                int sum = l1 -> val + l2 -> val + carry;
                carry = sum / 10;
                temp1 -> val = sum % 10;
                temp1 -> next = NULL;
                temp -> next = temp1;
                temp = temp1;
            }
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        while (l1 != NULL) {
            temp1 = new ListNode(0);
            int sum = l1 -> val + carry;
            temp1 -> next = NULL;
            temp1 -> val = sum % 10;
            carry = sum / 10;
            temp-> next = temp1;
            temp = temp1;
            l1 = l1 -> next;
        }
        while (l2 != NULL) {
            temp1 = new ListNode(0);
            int sum = l2 -> val + carry;
            temp1 -> next = NULL;
            temp1 -> val = sum %10;
            carry = sum / 10;
            temp-> next = temp1;
            temp = temp1;
            l2 = l2 -> next;
        }
        if (carry) {
            temp1 = new ListNode(carry);
            temp1 -> next = NULL;
            temp -> next = temp1;
        }
        return head;
    }
};
