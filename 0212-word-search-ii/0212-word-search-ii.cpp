struct Node{
    Node* list[26];
    bool flag=false;
    string str;
    Node() {
        for (int i = 0; i < 26; i++) {
            list[i] = nullptr;
        }
    }
    bool containsKey(char ch){
        return list[ch-'a']!=nullptr;
    }
    void put(char ch,Node* node){
        list[ch-'a']=node;
    }
    Node* get(char ch){
        return list[ch-'a'];
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }

};
class Solution {
    Node* root;
public:
    void dfs(vector<vector<char>>& board,int r,int c,Node* node,vector<string> &res){
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        int m=board.size();
        int n=board[0].size();
        if(r<0 || r>=m || c<0 || c>=n || board[r][c] == '#'){
            return;
        }
        char orgchar=board[r][c];
        
        if(!node->containsKey(orgchar)){
            return;
        }
        Node* nextNode=node->get(orgchar);
        if(nextNode->isEnd()){
            res.push_back(nextNode->str);
            nextNode->flag=false;
        }
        board[r][c]='#';
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            dfs(board,nr,nc,nextNode,res);
        }
        board[r][c]=orgchar;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root=new Node();
        vector<string>ans;
        for(string word: words){
            insert(word);
        }
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dfs(board,i,j,root,ans);
            }
        }
        return ans;

    }
    void insert(string word){
        int strlen=word.size();
        Node* node=root;
        for(int i=0;i<strlen;i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
        node->str=word;
    }
    bool search(string word){
        int strlen=word.size();
        Node* node=root;
        for(int i=0;i<strlen;i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node->get(word[i]);
        }
        return true;
    }
};