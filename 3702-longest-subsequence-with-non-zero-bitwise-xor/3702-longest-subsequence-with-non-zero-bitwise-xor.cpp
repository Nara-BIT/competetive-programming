class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        bool az=true;
        int txor=0;
        for(int x:nums){
            txor^=x;
            if(x>0){
                az=false;
            }
        }
        if(txor>0){
            return n;
        }
        return az?0:n-1;
    }
};