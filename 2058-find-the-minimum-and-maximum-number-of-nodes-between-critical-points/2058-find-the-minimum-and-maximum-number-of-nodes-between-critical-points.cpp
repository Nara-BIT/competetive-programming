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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>indices;
        if(head->next==NULL || head->next->next==NULL){
            return {-1,-1};
        }
        ListNode* prev=head;
        ListNode* curr=head->next;
        ListNode* front=head->next->next;
        int i=1;

        while(front!=NULL){
            int pval=prev->val;
            int val=curr->val;
            int nval=front->val;
            if(pval<val && nval<val){
                indices.push_back(i);
            }
            if(pval>val && nval>val){
                indices.push_back(i);
            }
            i++;
            prev=prev->next;
            curr=curr->next;
            front=front->next;
        }
        int n=indices.size();
        if(n==0 || n==1){
            return {-1,-1};
        }
        int min_dist=INT_MAX;
        int max_dist=0;
        for(int i=0;i<n-1;i++){
            min_dist=min(min_dist,indices[i+1]-indices[i]);
        }
        max_dist=indices[n-1]-indices[0];
        return {min_dist,max_dist};

    }
};