class Solution {
public:
    int maxProduct(int n) {
        if(n==10){
            return 0;
        }
        int firstMax=0,secondMax=0;
        int m=n;
        vector<int>nums;
        while(m>0){
            int unit=m%10;
            m=m/10;
            nums.push_back(unit);
        }
        sort(nums.begin(),nums.end());
        int k=nums.size();
        int a=nums[k-1];
        int b=nums[k-2];
        return a*b;
        
    }
};