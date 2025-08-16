class Solution {
public:
    int strStr(string haystack, string needle) {
        int l1=haystack.size();
        int l2=needle.size();
        if(l2>l1) return -1;
        for(int i=0;i<=l1-l2;i++){
            int j=0;
            while(j<l2 && haystack[i+j]==needle[j]){
                j++;
            }
            if(j==l2){
                return i;
            }
        }
        return -1;
    }
};
