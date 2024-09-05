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
    int n,k;
    cin>>n>>k;

    int l = 1;
    int r = n;

    int idx = 1;

    function<pair<int,int>(int mid)> val = [&](int mid)->pair<int,int>{
        int s = (n*(2*k + n - 1))/2;
        int s1 = (mid*(2*k + mid - 1))/2;
        int s2 = s - s1;

        return {s1,s2};
    };

    while(l<=r){
        int mid = l + (r-l)/2;
        
        pair<int,int> p = val(mid);
        int s1 = p.first;
        int s2 = p.second;
        if(s1 <= s2){
            idx = mid;
            l = mid+1;
        }else{
            r = mid -1 ;
        }
    }

    auto p1 = val(idx);
    auto p2 = val(idx+1);

    cout<<min(abs(p1.first-p1.second),abs(p2.first-p2.second))<<endl;

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
