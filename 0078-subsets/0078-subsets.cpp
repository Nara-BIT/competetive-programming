class Solution {
public:
    void backtrack(int index,vector<int>&temp,vector<int>&nums,int n,vector<vector<int>>& res){
        if(index==n){
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        backtrack(index+1,temp,nums,n,res);
        temp.pop_back();
        backtrack(index+1,temp,nums,n,res);
        return;

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>temp;
        backtrack(0,temp,nums,nums.size(),res);
        return res;
    }
};