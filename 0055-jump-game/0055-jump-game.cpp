class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_index=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i>max_index)
                return false;
            max_index=max(max_index,i+nums[i]);
        }
        return true;
    }
};