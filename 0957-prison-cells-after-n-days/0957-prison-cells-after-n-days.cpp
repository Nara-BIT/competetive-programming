class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        vector<int>c=cells;
        vector<int>f_c,next_c(c.size(),0);
        int remaining_days=(n-1)%14+1;
        for(int day=0;day<remaining_days;day++){
            next_c[0]=0;
            next_c[7]=0;
            for(int i=1;i<7;i++){
                next_c[i]=c[i-1]==c[i+1]?1:0;
            }
            c=next_c;
        }
        return c;
    }
};