/*Given a linked list, remove the n-th node from the end of list and return its head.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *curr=head;
    int i=0;
    while(i<n)
    {
        curr=curr->next;
        i++;
    }
    if(curr==NULL)
    {
        head=head->next;
        return head;
    }
    curr=curr->next;
    struct ListNode *prev=head;
    while(curr!=NULL)
    {
        curr=curr->next;
        prev=prev->next;
    }
    prev->next=prev->next->next;
    return head;
    
    

}


