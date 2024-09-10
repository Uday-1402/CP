#include <bits/stdc++.h>

#define int long long
#define x first
#define y second
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define vpi vector<pair<int, int>>
#define pii pair<int, int>
#define all(a) a.begin(), a.end()
#define mkp(a, b) make_pair(a, b);
#define in(a)         \
    for (auto &i : a) \
    {                 \
        cin >> i;     \
    }

using namespace std;

bool secondSmall_firstLarge(pair<int, int> &a, pair<int, int> &b)
{
    if (a.x != b.x)
        return (a.x > b.x);
    return a.y < b.y;
}
bool firstSmall_secondLarge(pair<int, int> &a, pair<int, int> &b)
{
    if (a.x != b.x)
        return (a.x < b.x);
    return a.y > b.y;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    // cout<<a<<" "<<b<<endl;
    return gcd(b, a % b);
}
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}

// O(n^2) approach
// void solve()
// {
//     int n,q;
//     cin>>n>>q;

//     vector<string> a(n);
//     for(int i = 0;i<n;i++){
//         cin>>a[i];
//     }

//     map<char,int> mp;
//     mp['B'] = 0;
//     mp['G'] = 1;
//     mp['R'] = 2;
//     mp['Y'] = 3;

//     vector<set<int>> b(4);
//     for(int i = 0;i<n;i++){
//         b[mp[a[i][0]]].insert(i);
//         b[mp[a[i][1]]].insert(i);
//     }
//     vvi qry(q,vi(2));
//     for(int i = 0;i<q;i++){
//         int x,y;
//         cin>>x>>y;

//         qry[i][0] = --x;
//         qry[i][1] = --y;

//         // cout<<qry[i][0]<<" "<<qry[i][1]<<endl;
//     }

//     vector<vector<int>> dp(n,vi(n,1e9));
//     for(int i = 0;i<n;i++){
//         dp[i][i] = 0;
//     }
//     vi vis(n,0);

//     function<int(int node,int dest)> dfs = [&](int node,int dest)->int{
//         if(dp[node][dest] != 1e9) return dp[node][dest];
//         int cx1 = a[node][0],cx2 = a[node][1], cy1 = a[dest][0], cy2 = a[dest][1];

//         if(cx1 == cy1 || cx1 == cy2 || cx2 == cy1 || cx2 == cy2){
//             return abs(node - dest);
//         }
//         if(vis[node]) return 1e9;

//         vis[node] = 1;
//         int ans = 1e9;
//         for(int i = 0;i<2;i++){
//             for(auto adjNode:b[mp[a[node][i]]]){
//                 if(adjNode != node && !vis[adjNode]){
//                     ans = min(ans,abs(node - adjNode) + dfs(adjNode,dest));
//                 }
//             }
//         }
//         vis[node] = 0;

//         dp[node][dest] = ans;
//         dp[dest][node] = ans;
//         return ans;
//     };

//     for(int i = 0;i<q;i++){
//         int x = qry[i][0], y = qry[i][1];

//         int cx1 = a[x][0],cx2 = a[x][1], cy1 = a[y][0], cy2 = a[y][1];

//         if(cx1 == cy1 || cx1 == cy2 || cx2 == cy1 || cx2 == cy2){
//             dp[x][y] = abs(x - y);
//             dp[y][x] = abs(x - y);
//             cout<<abs(x-y)<<endl;
//         }else{
//             if(dp[x][y] != 1e9){
//                 cout<<dp[x][y]<<endl;
//             }else if(dp[y][x] != 1e9){
//                 cout<<dp[y][x]<<endl;
//             }else{
//                 int ans = dfs(x,y);
//                 if(ans >= 1e9) cout<<-1<<endl;
//                 else cout<<ans<<endl;
//             }
//         }
//     }
// }

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<string> a(n);

    vector<vector<int>> mp(6);
    vector<string> cases = {"BR", "BG", "BY", "GR", "GY", "RY"};

    for(int i = 0;i<n;i++){
        cin>>a[i];
        if(a[i] == "BR") mp[0].push_back(i);
        if(a[i] == "BG") mp[1].push_back(i);
        if(a[i] == "BY") mp[2].push_back(i);
        if(a[i] == "GR") mp[3].push_back(i);
        if(a[i] == "GY") mp[4].push_back(i);
        if(a[i] == "RY") mp[5].push_back(i);
    }

    while (q--)
    {
        int p, q;
        cin >> p >> q;

        p--;
        q--;

        if (p > q)
            swap(p, q);

        set<char> st;
        for (auto i : a[p])
            st.insert(i);
        for (auto i : a[q])
            st.insert(i);

        if (st.size() < 4)
        {
            cout << q - p << endl;
            continue;
        }

        int l = -1, r = n;
        for (int e = 0;e<6;e++)
        { 
            string str = cases[e];
            if (str == a[p] || str == a[q])
                continue;
            vector<int> st = mp[e];

            auto it = upper_bound(all(st),p);
            if(it != st.end()){
                r = min(r,*it);
            }
            if(it != st.begin()){
                it--;
                l = max(l,*it);
            }
        }
        if (l == -1 && r == n)
        {
            cout << -1 << endl;
        }
        else if (l == -1)
        {
            cout << abs(r - q) + abs(r - p) << endl;
        }
        else if (r == n)
        {
            cout << abs(l - p) + abs(l - q) << endl;
        }
        else
        {
            cout << min(abs(l - p) + abs(l - q), abs(r - p) + abs(r - q)) << endl;
        }
    }
}


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;

    // for(int i = 0;i*i<=1e6;i++){
    //     isSq[i*i] = 1;
    // }

    while (t--)
    {
        solve();
    }

    return 0;
}
