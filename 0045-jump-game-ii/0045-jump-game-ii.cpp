class Solution {
public:
    int jump(vector<int>& nums) {
        int curr_end=0;
        int n=nums.size();
        int jump=0;
        int farthest=0;
        for(int i=0;i<n-1;i++){
            farthest=max(farthest,i+nums[i]);
            if(i==curr_end){
                jump++;
                curr_end=farthest;
            }
        }

        return jump;
    }
};