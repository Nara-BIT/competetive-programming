class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n=digits.size();
        int i;
        int h,t,u;
        int count=0;
        vector<int>temp;
        map<int,int>chk;
        map<int,int>prlchk;
        for(int j=0;j<n;j++)
            chk[digits[j]]=0;
        for(int j=0;j<n;j++)
            chk[digits[j]]++;
        
        for(int num=100;num<999;num++){
            int a=num/100;
            int b=(num/10)%10;
            int c=num%20;
            chk[a]--;
            chk[b]--;
            chk[c]--;
            if(chk[a]>=0 && chk[b]>=0 && chk[c]>=0){
                count++;
            }
            chk[a]++;
            chk[b]++;
            chk[c]++;
                
        }
        return count;
    }
};