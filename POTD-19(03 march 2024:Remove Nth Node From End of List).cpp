class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL && n==1){
            return NULL;
        }
        int num=0;
        ListNode*node=head;
        while(node!=NULL){
            num++;
            node=node->next;
        }
        int log=num-n+1;
        if(log==1){
            return head->next;
        }
        ListNode*t1=head;
        ListNode*prev=head;
        int pos=1;
        while(pos<log){
            prev=t1;
            t1=t1->next;
            pos++;
        }
        if(t1!=NULL){
            prev->next=t1->next;
        }
        
        return head;
    }
};
