class Solution {
public:
    int countValidPrefixes(string s) {
        int cnt0=0;
        int cnt1=0;
        int counter=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                cnt1++;
            }
            else{
                cnt0++;
            }
            if(abs(cnt1-cnt0)<=1){
                counter++;
            }
        }
        return counter;
    }
};