// This is code for 3 sum

#include<bits/stdc++.h>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>res;
        if(n<3)
            return {};
        sort(nums.begin(),nums.end());
        for(int k=0;k<n;k++){
            if(k>0 && nums[k]==nums[k-1]){
                continue;
            }
            int i=k+1,j=n-1;
            int n1=nums[k];
            int target=-(n1);
            while(i<j){
                if(nums[i]+nums[j]==target){
                    res.push_back({n1,nums[i],nums[j]});
                    while(i<j && nums[i]==nums[i+1])
                        i++;
                    while(i<j && nums[j]==nums[j-1])
                        j--;
                    i++,j--;
                }
                else if(nums[i]+nums[j]>target){
                    j--;
                }
                else if(nums[i]+nums[j]<target){
                    i++;
                }
            }
        }
        return res;
    }
};
