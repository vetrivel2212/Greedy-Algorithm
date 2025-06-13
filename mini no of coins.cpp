#include <bits/stdc++.h>
using namespace std;
vector<int> minimum_coins(vector<int> deno,int v)
{
    vector<int> ans;
    for(int i=deno.size()-1;i>=0;i--)
    {
        while(v>= deno[i])
        {
            v-=deno[i];
            ans.push_back(deno[i]);
        }
    }
    return ans;
}
int main()
{
    vector<int> deno ={1,2,5,10,20,50,100,500,1000};
    int v = 49;
    vector<int> ans = minimum_coins(deno,v);
    for(auto it : ans)
    {
        cout<<it<<" ";
    }
}
