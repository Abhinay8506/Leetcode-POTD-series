class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        //Two pointer approach
        /*ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
            if(fast->next!=NULL){
                fast=fast->next;
            }
        }
        return slow;*/

        int n=0;
        ListNode* t=head;
        while(t!=NULL){
            n++;
            t=t->next;
        }
        int mid=n%2==0?(n/2)+1:(n+1)/2;
        t=head;
        int pos=1;
        while(pos<mid){
            t=t->next;
            pos++;
        }
        return t;



    }
};
