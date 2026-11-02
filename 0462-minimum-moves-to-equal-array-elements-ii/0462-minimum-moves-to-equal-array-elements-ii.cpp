class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int med=nums[n/2];
        long long moves=0;
        for(int num:nums){
            moves+=abs(num-med);
        }
        return moves;
    }
};