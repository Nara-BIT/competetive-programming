class Solution {
public:
    vector<int>temp;
    vector<vector<int>>res;
    void backtrack(int index,vector<int>&nums,vector<bool>&flag){
        if(index==nums.size()){
            res.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(flag[i] || (i>0 && nums[i]==nums[i-1] && !flag[i-1])){
                continue;
            }
            flag[i]=true;
            temp[index]=nums[i];
            backtrack(index+1,nums,flag);
            flag[i]=false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool>flag(nums.size(),false);
        temp.resize(nums.size());
        sort(nums.begin(),nums.end());
        backtrack(0,nums,flag);
        return res;
    }
};