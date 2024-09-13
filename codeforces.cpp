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

int callBack(int p, int q)
{
    return p & q;
}

int higherOrder(int a, int b, function<int(int c, int d)> callBack)
{
    return callBack(a, b);
}

int _ceil(double x){
    if((double)(x - (int)x) > 0.0) return (int)x + 1;
    return (int)x;
}

// void solve(){
//     string s,t;
//     cin>>s;
//     cin>>t;

//     int n = s.length();
//     int m = t.length();
//     int j = 0;

//     for(int i = 0;i<n&&j<m;){
//         if(s[i] == t[j]){
//             i++;
//             j++;
//         }else if(s[i] == '?'){
//             s[i] = t[j];
//             i++;
//             j++;
//         }else{
//             i++;
//         }
//     }

//     if(j == m){
//         cout<<"Yes\n";
//         for(int i = 0;i<n;i++){
//             if(s[i] == '?') s[i] = 'x';
//         }
//         cout<<s<<endl;
//         return;
//     }
//     cout<<"No\n";
// }

int val[200001];

void solve()
{
    int l, r;
    cin >> l >> r;

    int ans = val[l] + val[r] - 2*val[l-1];

    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // cout<<higherOrder(1,2,callBack);

    function<void()> test = []() -> void
    {
        int cnt = 0;
        int x = 200000;
        while (x)
        {
            cnt++;
            x /= 3;
        }

        cout << cnt << endl;
    };
    // test();

    int t;
    cin >> t;

    // for(int i = 0;i*i<=1e6;i++){
    //     isSq[i*i] = 1;
    // }

    for(int i = 0;i<=200000;i++){
        int tmp = i;
        while(tmp){
            val[i]++;
            tmp /= 3;
        }
    }

    for(int i=1;i<=200000;i++){
        val[i] += val[i-1];
    }

    while (t--)
    {
        solve();
    }

    return 0;
}
