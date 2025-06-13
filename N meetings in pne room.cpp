#include<bits/stdc++.h>
using namespace std;

struct meet {
    int start;
    int finish;
    int pos;
};

bool comp(meet m1, meet m2) {
    return m1.finish < m2.finish;
}

class Solution {
public:
    vector<int> meeting(vector<int> start_array, vector<int> end_array) {
        int n = start_array.size();
        vector<meet> m(n);
        for(int i = 0; i < n; i++) {
            m[i].start = start_array[i];
            m[i].finish = end_array[i];
            m[i].pos = i + 1;
        }

        sort(m.begin(), m.end(), comp);

        vector<int> res;
        res.push_back(m[0].pos);
        int freetime = m[0].finish;

        for(int i = 1; i < n; i++) {
            if(m[i].start > freetime) {
                freetime = m[i].finish;
                res.push_back(m[i].pos);
            }
        }

        return res;
    }
};

int main() {
    vector<int> a = {0, 3, 1, 5, 5, 8};
    vector<int> b = {5, 4, 2, 9, 7, 9};

    Solution obj;
    vector<int> c = obj.meeting(a, b);

    for(auto it : c) {
        cout << it << " ";
    }
}
