#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const int MAX{200010};

vector<pll> adj[MAX];

ll prim(ll u, ll N) {
  set<ll> C;
  C.insert(u);

  priority_queue<pll, vector<pll>, greater<pll>> pq;

  for (auto [v, w] : adj[u]) pq.push(pll(w, v));

  ll mst = 0;

  while ((ll)C.size() < N) {
    ll v, w;

    do {
      w = pq.top().first, v = pq.top().second;
      pq.pop();
    } while (C.count(v));

    mst += w;
    C.insert(v);

    for (auto [s, p] : adj[v]) pq.push(pll(p, s));
  }

  return mst;
}

ll solve()
{
    ll n, m, index = 0;
    cin >> n >> m;

    vector<pll> price(n);
    for(auto &[p, i] : price)
    {
        cin >> p;
        i = ++index;
    }

    sort(price.begin(), price.end());

    auto [bw, bn] = price[0];
    for(auto [weight, node] : price)
    {
        if(bn == node)
            continue;

        adj[bn].emplace_back(node, weight + bw);
        adj[node].emplace_back(bn, weight + bw);
    }
    
    while(m--)
    {
        ll a, b, w;
        cin >> a >> b >> w;

        adj[a].emplace_back(b, w);
        adj[b].emplace_back(a, w);
    }

    return prim(1, n);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout << solve() << "\n";

    return 0;
}
