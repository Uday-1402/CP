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

void solve(){
    int n,x;
    cin>>n>>x;

    int ans = 0;
    for(int a = 1;a<=n;a++){
        for(int b = 1;b<=n/a;b++){
            if(x - a - b > 0){
                ans += min((int)(n-(a*b))/(a+b),x - a - b);
            }
        }
    }

    cout<<ans<<endl;
}

int32_t main()
{
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
