class Solution {
public:
    long long GCD(long long a,long long b){
        
        while(b!=0){
            int temp=b;
            b=a%b;
            a=temp;
        }
        return a;
    }
    long long maxPairStrength(vector<int>& nums) {
        int n=nums.size();
        int lr=1;
        int rr=0;
        long long ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long m1=nums[i];
                long long m2=nums[j];
                long long p=GCD(m1,m2);
                long long p2=p*p;
                long long res=(1LL*m1*m2)/p2;
                ans=max(res,ans);

            }
        }
        return ans;
    }
};