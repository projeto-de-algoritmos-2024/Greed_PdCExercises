#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<pll> vll;
typedef vector<ll> vl;

auto solve()
{
    ll n, k, q;
    cin >> n >> k >> q;

    vector<vl> grid(n, vl(k));
    // value, country
    vector<vector<ll>> region(k);
    for(ll i = 0; i < n; i++)
    {
        for(ll j = 0; j < k; j++)
        {
            cin >> grid[i][j];

            if(i > 0)
                grid[i][j] |= grid[i - 1][j];

            region[j].emplace_back(grid[i][j]);
        }
    }

    while(q--)
    {
        ll left = 0, right = n - 1;
        ll m;
        cin >> m;

        while(m--)
        {
            ll reg, c;
            char tp;
            cin >> reg >> tp >> c;

            --reg;

            if(tp == '<')
            {
                auto r = lower_bound(region[reg].begin(), region[reg].end(), c);

                ll v = distance(region[reg].begin(), r - 1);

                right = min(right, v);
            }
            else
            {
                auto l = lower_bound(region[reg].begin(), region[reg].end(), c + 1);
                ll v = distance(region[reg].begin(), l);

                left = max(left, v);
            }
        }

        cout << (left > right ? -1 : left + 1) << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
