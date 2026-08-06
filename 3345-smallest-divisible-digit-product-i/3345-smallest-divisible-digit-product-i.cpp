class Solution {
public:

    int smallestNumber(int n, int t) {
        int prd=1;
        int m=n+t;
        int ans=0;
        for(int i=n;i<=m;i++){
            int k=i;
            while(k>0){
                int unit=k%10;
                prd*=unit;
                k=k/10;
            }
            
            if(prd%t==0){
                ans=i;
                break;
            }
            prd=1;
            
        }
        return ans;
    }
};