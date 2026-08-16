class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        int cnt=INT_MAX;
        for(int k=0;k<n;k++){
            int curr=k;
            for(int i=0;i<n/2;i++){
                char c1=s[(k+i)%n];
                char c2=s[(n-i+k-1)%n];

                int diff=abs(c1-c2);
                curr+=min(diff,26-diff);
            }
            cnt=min(curr,cnt);
        }
        return cnt;
        
    }
};