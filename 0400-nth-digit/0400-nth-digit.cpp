class Solution {
public:
    int findNthDigit(int n) {
        vector<long long>v;
        v.push_back(0);
        long long sum=0,p=1;
        for(int i=1;i<=16;i++){
            sum+=9*p*i;
            v.push_back(sum);
            p*=10;
        }
        v.push_back(sum);
        int idx=0;
        for(int i=0;i<v.size();i++){
            if(v[i]>=n){
                idx=i;
                break;
            }
        }
        n-=v[idx-1];
        n--;
        long long num=n/idx,d=n%idx;
        int b=1;
        for(int i=0;i<idx-1;i++){
            b*=10;
        }
        int val=b+num;
        string st=to_string(val);
        return st[d]-'0';
    }
};