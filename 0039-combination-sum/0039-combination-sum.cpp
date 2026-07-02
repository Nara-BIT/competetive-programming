class Solution {
public:
    vector<vector<int>>res;
    vector<int>temp;
    void backtrack(int ind, int target,vector<int>& nums){
        if(target==0){
            res.push_back(temp);
            return;
        }
        if(target<0 || ind>=nums.size())
            return;
        temp.push_back(nums[ind]);
        backtrack(ind,target-nums[ind],nums);
        temp.pop_back();
        backtrack(ind+1,target,nums);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(0,target,candidates);
        return res;
    }
};