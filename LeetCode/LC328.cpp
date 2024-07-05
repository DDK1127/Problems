// LeetCode 328.Odd Even Linked List

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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !(head->next))
            return head;
        ListNode* origin = head;
        ListNode* oddlist = head; 
        ListNode* evenlist = head->next; 
        ListNode* secondhead = evenlist; 

        while(oddlist->next != nullptr && evenlist->next != nullptr){
            if(oddlist->next == nullptr){}
            else{
                oddlist->next = oddlist->next->next;
                oddlist = oddlist->next;
            }
            evenlist->next = evenlist->next->next;
            evenlist = evenlist->next;
        }
        oddlist->next = secondhead;

        return origin;
    }
};
