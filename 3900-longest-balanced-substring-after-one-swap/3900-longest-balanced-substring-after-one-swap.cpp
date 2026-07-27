class Solution {
public:
    int LB(string s){
        int c0=0;
        int c1=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                c0++;
            }
            else if(s[i]=='1'){
                c1++;
            }
        }
        if(c0==0 || c1==0){
            return 0;
        }
        map<int,int>trk;
        trk[0]=-1;
        int balance=0;
        int len=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                balance++;
                c1--;
            }
            else if(s[i]=='0'){
                balance--;
                c0--;
            }
            if(balance==0){
                len=i+1;
                continue;
            }
            
            int lt;
            if(trk.count(balance-2) &&  c0>0){
                lt=trk[balance-2];
                len=max(len,i-lt);
            }
            if(trk.count(balance+2) && c1>0){
                lt=trk[balance+2];
                len=max(len,i-lt);
            }
                
            if(!trk.count(balance)){
                trk[balance]=i;
            }
                
                
            
        }
        return len;
    }
    int longestBalanced(string s) {
        int len=0;
        len=LB(s);
        reverse(s.begin(),s.end());
        len=max(len,LB(s));
        return len;
    }
};