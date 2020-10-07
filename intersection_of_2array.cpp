class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        set<int> s;
        int n=nums1.size();
        int m=nums2.size();
        set<int>v;
        for(auto i:nums1)
            s.insert(i);
            
        for(auto j:nums2)
        {
            if(s.find(j)!=s.end())
                v.insert(j);
        }
        vector<int> ans;
        for(auto i:v) ans.push_back(i);
        return ans;
        
    }
};
