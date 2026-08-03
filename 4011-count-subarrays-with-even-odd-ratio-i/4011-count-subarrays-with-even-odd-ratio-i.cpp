class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int cnt_even=0;
        int cnt_odd=0;
        int n=nums.size();
        int counter=0;
        for(int i=0;i<n;i++){
            cnt_odd=0;
            cnt_even=0;
            for(int j=i;j<n;j++){
                if(nums[j]&1){
                    cnt_odd++;
                }
                else{
                    cnt_even++;
                }
                int x=cnt_even,y=cnt_odd;
                if(y>0 && x*b<=y*a){
                    counter++;
                }

            }
        }
        return counter;
    }
};