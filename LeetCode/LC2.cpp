// LeetCode 2.Add Two Numbers

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
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int l1_length = 0, l2_length = 0;
        ListNode *c1 = l1;
        ListNode *c2 = l2;
        ListNode *c3 = new ListNode();
        ListNode *top = c3;

        int sum, carry = 0;
        while (c1 != nullptr && c2 != nullptr)
        {
            sum = (c1->val + c2->val + carry);
            carry = sum / 10;
            c3->next = new ListNode(sum % 10);
            c1 = c1->next;
            c2 = c2->next;
            c3 = c3->next;
        }
        while (c1 != nullptr)
        {
            sum = c1->val + carry;
            carry = sum / 10;
            c3->next = new ListNode(sum % 10);
            c1 = c1->next;
            c3 = c3->next;
        }
        while (c2 != nullptr)
        {
            sum = c2->val + carry;
            carry = sum / 10;
            c3->next = new ListNode(sum % 10);
            c2 = c2->next;
            c3 = c3->next;
        }
        if (carry > 0)
            c3->next = new ListNode(carry);

        return top->next;
    }
};
