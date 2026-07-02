class Solution {
public:
    void backtrack(int index,vector<int>&nums,vector<vector<int>>&res,vector<int>& temp,vector<bool>freq){
        if(index==nums.size()){
            res.push_back(nums);
        }
        /*for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                freq[i]=true;
                temp.push_back(nums[i]);
                backtrack(nums,res,temp,freq);
                freq[i]=false;
                temp.pop_back();
            }
        }*/
        for(int i=index;i<nums.size();i++){
            
                swap(nums[i],nums[index]);
                backtrack(index+1,nums,res,temp,freq);
                swap(nums[i],nums[index]);
           
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp;
        vector<vector<int>>res;
        vector<bool>freq(n,false);
        backtrack(0,nums,res,temp,freq);
        return res;
    }
};