class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        int st=lower;
        vector<vector<int>>res;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<lower || upper<nums[i]){
                continue;
            }
            if(nums[i]>st){
                res.push_back({st,nums[i]-1});
            }
            st=nums[i]+1;
        }
        if(st<=upper){
            res.push_back({st,upper});
        }
        return res;
    }
};