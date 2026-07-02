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
    /*ListNode* reverseList(ListNode* temp){
        ListNode* curr=temp;
        ListNode* prev=NULL;
        ListNode* NextItr=NULL;
        if(temp==NULL||temp->next==NULL)
            return temp;
        while(curr!=NULL){
            NextItr=curr->next;
            curr->next=prev;

            prev=curr;
            curr=NextItr;
        }
        return prev;
    }
    ListNode* kthGroup(ListNode* temp,int k1){
        k1--;
        while(temp!=NULL&&k1>0){
            temp=temp->next;
            k1--;
        }
        return temp;
    }*/
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* pro=head;
        int len=0;
        while(pro!=NULL){
            len++;
            pro=pro->next;
        }
        int limit=len-len%k;
        int pos=0;
        ListNode* first=new ListNode(0);
        first->next=head;
        head=first;
        ListNode* second=NULL;
        ListNode* prev=NULL;
        ListNode* front=NULL;
        ListNode* curr;
        while(first->next){
            int x=k;
            curr=first->next;
            second=first->next;
            prev=first;
            while(x && curr){
                front=curr->next;
                curr->next=prev;
                prev=curr;
                curr=front;
                x--;
                pos++;
            }
            first->next=prev;
            second->next=curr;
            first=second;
            if(pos>=limit){
                break;
            }
        }
        return head->next;

        /*ListNode* temp=head;
        ListNode* prevLast=NULL;
        while(temp!=NULL){
            ListNode* kth=kthGroup(temp,k);
            if(kth==NULL){
                if(prevLast){
                    prevLast->next=temp;
                    break;
                }
            }
            ListNode* nextNode=kth->next;
            kth->next=NULL;
            ListNode* reversedHead = reverseList(temp); 
            if (temp == head) {
                head = reversedHead;
            } 
            else {
                prevLast->next = reversedHead; 
            }
            prevLast=temp;
            temp=nextNode;

        }
        return head;*/
    }
};