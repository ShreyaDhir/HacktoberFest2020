class Solution {
public:
    string countAndSay(int n) {
        string s="1";
        string ans="";
        for(int i=1;i<n;i++)
        {
            int count=1;
            for(int j=0;j<s.size();j++)
            {
                if(s[j]==s[j+1])
                {
                    count++;
                }
                else
                {
                    ans+=to_string(count)+s[j];
                    count=1;
                }
            }
            s=ans;
            ans="";
        }
        return s;
    }
};
