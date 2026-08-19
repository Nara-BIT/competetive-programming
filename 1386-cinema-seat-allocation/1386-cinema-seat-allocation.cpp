class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<long long,vector<int>>v;
        for(auto it:reservedSeats){
            v[it[0]].push_back(it[1]);
        }
        int ans=0;
        for(const auto& it1:v) {
            bool left_blocked =false;
            bool middle_blocked =false;
            bool right_blocked =false;
            for (int x : it1.second) {
                if(2<=x && x<=5) {
                    left_blocked= true;
                }
                if(4<=x && x<=7) {
                    middle_blocked= true;
                }
                if(6<=x && x<=9) {
                    right_blocked =true;
                }
            }
            if(!left_blocked && !right_blocked) {
                ans+= 2;
            } 
            else if(!left_blocked|| !middle_blocked || !right_blocked) {
                ans += 1;
            }
        }
        long long empty_rows =n - v.size();
        ans+=empty_rows*2;
        return ans;
    }
};