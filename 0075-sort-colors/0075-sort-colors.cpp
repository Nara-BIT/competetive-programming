class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        int mid=0;
        int n=nums.size();
        while(mid<=r){
            if(nums[mid]==0){
                int temp=nums[mid];
                nums[mid]=nums[l];
                nums[l]=temp;
                l++;
                mid++;
            }
            else if(nums[mid]==2){
                int temp=nums[mid];
                nums[mid]=nums[r];
                nums[r]=temp;
                r--;
            }
            else{
                mid++;
            }
    
        }
        //return nums;
    }
};