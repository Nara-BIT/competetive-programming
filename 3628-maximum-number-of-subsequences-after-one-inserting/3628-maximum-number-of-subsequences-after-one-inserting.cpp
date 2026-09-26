class Solution {
public:
    long long numOfSubsequences(string s) {
        int n=s.size();
        long long l=0;
        long long lc=0;
        long long lct=0;
        vector<long long>prevL(n+1);
        vector<long long>prevLC(n+1);
        for(int i=0;i<n;i++){
            if(s[i]=='L'){
                l++;
            }
            else if(s[i]=='C'){
                lc=lc+l;
            }
            else if(s[i]=='T'){
                lct=lct+lc;
            }
            prevL[i+1]=l;
            prevLC[i+1]=lc;
        }
        vector<long long>sufT(n+5);
        vector<long long>sufCT(n+5);
        long long t=0;
        long long ct=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='T'){
                t++;
            }
            else if(s[i]=='C'){
                ct=ct+t;
            }
            sufT[i+1]=t;
            sufCT[i+1]=ct;
        }
        long long ans1,ans2,ans3=0;
      
        ans1=sufCT[1]+lct;
        ans2=prevLC[n]+lct;
        for(int i=1;i<=n;i++){
            ans3=max(ans3,lct+(prevL[i]*sufT[i+1]));
        }
        return max(ans1,max(ans2,ans3));
    }
};