#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define len(vt) (int)vt.size()
#define vin(vt) for (auto &e : vt) cin >> e
#define all(xs) xs.begin(), xs.end()

class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        vector<vi> anums(2), atarget(2);
        ll ans = 0;
        for(auto v: nums) {
            v % 2 == 0 ? anums[0].push_back(v) : anums[1].push_back(v);
        }
        for(auto v: target) {
            v % 2 == 0 ? atarget[0].push_back(v) : atarget[1].push_back(v);
        }
        sort(all(anums[0]));
        sort(all(anums[1]));
        sort(all(atarget[0]));
        sort(all(atarget[1]));

        for(int i = 0; i < len(anums[0]); i++) {
            ans += abs(anums[0][i] - atarget[0][i]);
        }
        for(int i = 0; i < len(anums[1]); i++) {
            ans += abs(anums[1][i] - atarget[1][i]);
        }

        return ans / 4;
    }
};