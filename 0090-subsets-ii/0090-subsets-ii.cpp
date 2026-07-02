class Solution {
public:
    void backtrack(int ind,vector<vector<int>>&res,vector<int>&arr,vector<int>&nums,int n){
        if(ind==n){
            res.push_back(arr);
            return;
        }
        arr.push_back(nums[ind]);
        backtrack(ind+1,res,arr,nums,n);
        arr.pop_back();
        while(ind+1<n&&nums[ind]==nums[ind+1]){
            ind++;
        }
        backtrack(ind+1,res,arr,nums,n);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ind=0;
        vector<int>arr;
        backtrack(ind,res,arr,nums,n);
        //sort(res.begin(),res.end());
        return res;
    }
};