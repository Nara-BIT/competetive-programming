class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int turns=0;
        map<char,char>nextSlot={
            {'0','1'},
            {'1','2'},
            {'2','3'},
            {'3','4'},
            {'4','5'},
            {'5','6'},
            {'6','7'},
            {'7','8'},
            {'8','9'},
            {'9','0'}
        };
        map<char,char>prevSlot={
            {'1','0'},
            {'2','1'},
            {'3','2'},
            {'4','3'},
            {'5','4'},
            {'6','5'},
            {'7','6'},
            {'8','7'},
            {'9','8'},
            {'0','9'}
        };
        queue<string>q;
        set<string>visit(deadends.begin(),deadends.end());
        if(visit.find("0000")!=visit.end()){
            return -1;
        }
        q.push("0000");
        visit.insert("0000");
        while(!q.empty()){
            for(int currNodeLevel=q.size();currNodeLevel>0;currNodeLevel--){
                string curr=q.front();
                q.pop();
                if(curr==target){
                    return turns;
                }
                for(int i=0;i<4;i++){
                    string newComb=curr;
                    newComb[i]=nextSlot[newComb[i]];
                    if(visit.find(newComb)==visit.end()){
                        q.push(newComb);
                        visit.insert(newComb);
                    }
                    newComb=curr;
                    newComb[i]=prevSlot[newComb[i]];
                    if(visit.find(newComb)==visit.end()){
                        q.push(newComb);
                        visit.insert(newComb);
                    }
                    
                }
            }
            turns++;
            
        }
        return -1;

    }
};