class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor) return 1;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (divisor == 1) return dividend;
        
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        
        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        long long sum = 0;
        long long cnt=0;
        while(sum+d<=n){
            sum+=d;
            cnt++;
        }
        if(cnt>INT_MAX && sign==-1){
            return INT_MIN;
        }
        if(cnt>INT_MAX && sign==1){
            return INT_MAX;
        }
        

        return sign * cnt;
    }
};