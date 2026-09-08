class Solution {
public:
    int countCommas(int n) {
        int m=(n)/10;
        m*=10;
        string s=to_string(n);
        //m=pow(10,s.size()-1);
        m=1000;
        if(s.size()<=3){
            return 0;
        }
        return n-m+1;
    }
};