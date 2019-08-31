/**

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l1head = l1;
        ListNode* l2head = l2;
        ListNode* resulthead = new ListNode(0);
        ListNode* result = resulthead;
        
        int carry = 0;
        while ( l1head != NULL || l2head != NULL || carry == 1)
        {   
            int digit1=0,digit2=0;
            if (l1head != NULL) {
                digit1 = l1head -> val; 
                l1head = l1head -> next;
            }
            if (l2head != NULL) {
                digit2 = l2head -> val; 
                l2head = l2head -> next;
            }
            
            result -> val = (digit1 + digit2 + carry)%10;

            if ((digit1+digit2+carry) >= 10)
            {
                carry = 1;
            } else {
                carry = 0;
            }
            
            if (l1head != NULL || l2head != NULL || carry == 1) 
            {
                result -> next = new ListNode(0);
                result = result -> next;
            }
            
        }
        return resulthead;
        
    }
};
