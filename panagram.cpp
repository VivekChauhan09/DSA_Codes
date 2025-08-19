class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int>sol(26,0);
        for(int i=0;i<sentence.size();i++){
            sol[sentence[i]-'a']=1;
        }
        for(int i=0;i<26;i++){
            if(sol[i]==0){
                return false;
            }
        }
        return true;
    }
};