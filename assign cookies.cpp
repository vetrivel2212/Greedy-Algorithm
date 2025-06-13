class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = s.size();
        int n = g.size();
        int l=0,r=0;
        int count =0;
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        while(l<m && r <n)
        {
            if(g[r] <= s[l])
            {
                l++;
                r++;
                count+=1;
            }
            else
            {
                l++;
            }
        }
        return count;
    }
};
