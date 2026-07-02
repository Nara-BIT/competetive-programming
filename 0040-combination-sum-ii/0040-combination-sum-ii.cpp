class Solution {
public:
    vector<int>temp;
    vector<vector<int>>res;
    void backtrack(int index,int target,vector<int>& nums){
        if(target==0){
            res.push_back(temp);
            return;
        }
        if(index>=nums.size() || target<0)
            return;
        
        temp.push_back(nums[index]);
        backtrack(index+1,target-nums[index],nums);

        temp.pop_back();
        while(index+1<nums.size() && nums[index]==nums[index+1]){
            index++;
        }
        backtrack(index+1,target,nums);
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        backtrack(0,target,candidates);
        return res;
    }
};