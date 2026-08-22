class Solution {
public:
    bool checkDivisibility(int n) {
        int mul=1;
        int sum=0;
        int t_sum=0;
        int m=n;
        while(n>0){
            int unit=n%10;
            mul*=unit;
            sum+=unit;
            n=n/10;
        }
        t_sum=sum+mul;
        return m%t_sum==0;
    }
};