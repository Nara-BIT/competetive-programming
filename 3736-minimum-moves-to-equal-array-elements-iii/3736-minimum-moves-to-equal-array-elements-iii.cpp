class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());
        int cnt=0;
        for(int y:nums){
            cnt+=abs(maxi-y);
        }
        return cnt;
    }
};