#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace  __gnu_pbds;
using namespace std;
#define faster_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read(x) scanf("%d",&x)
#define llread(x) scanf("%lld",&x)
#define forr(i,x,n) for(ll i = x;i<n;i++)
#define fort(i,x,n) for(ll i = x;i>=n;i--)
#define ll long long
#define F first
#define S second
#define pb push_back
#define mod 1000000007
#define mxn 200005

ll public_key;
pair<ll, ll> private_key;

ll gcdExtended(ll a, ll b, ll* x, ll* y)
{

    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    // To store results of recursive call
    ll x1, y1;
    ll gcd = gcdExtended(b % a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

ll modInverse(ll a, ll m)
{
    ll x, y;
    ll g = gcdExtended(a, m, &x, &y);
    if (g != 1) return -1;
    else
    {

        // m is added to handle negative x
        ll res = (x % m + m) % m;
        return res;
    }
}

ll fastExp(ll b, ll e, ll m)
{
    ll result = e & 1 ? b : 1;
    while (e) {
        e >>= 1;
        b = (b * b) % m;
        if (e & 1) result = (result * b) % m;
    }
    return result;
}

ll chinese_reminder(ll a, ll b, ll m1, ll m2)
{
    ll M = m1 * m2, x;

    ll M1 = m2;
    ll M2 = m1;

    ll X1 = modInverse(M1, m1);
    ll X2 = modInverse(M2, m2);

    return x = (M1 * X1 * a + M2 * X2 * b) % M;
}

void Rabin_key_generation(ll p, ll q)
{
    ll n;
    n = p * q;
    public_key = n;
    private_key = {q, n};
}

ll Rabin_encryption(ll P)
{
    ll e, n;
    e = 2;
    n = public_key;

    ll C = fastExp(P, e, n);

    return C;
}

void Rabin_decryption(ll p, ll q, ll C)
{
    ll tmp, a1, a2, b1, b2;

    tmp = (p + 1) / 4;

    a1 = fastExp(C, tmp, p);
    a2 = (-a1 + p) % p;

    tmp = (q + 1) / 4;

    b1 = fastExp(C, tmp, q);
    b2 = (-b1 + q) % q;

    ll P1, P2, P3, P4;

    P1 = chinese_reminder(a1, b1, p, q);
    P2 = chinese_reminder(a1, b2, p, q);
    P3 = chinese_reminder(a2, b1, p, q);
    P4 = chinese_reminder(a2, b2, p, q);

    cout << a1 << " " << a2 << " " << b1 << " " << b2 << endl;
    cout << P1 << " " << P2 << " " << P3 << " " << P4 << endl;

}

int main()
{
    faster_io

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll t = 1, n, p, q, P, C;

    // cin >> t;


    while (t--) {
        // cin >> n;

        // cout << "Choose p:" << endl;
        cin >> p;
        // cout << "Choose q:" << endl;
        cin >> q;

        // n = p * q;

        // cout << "Plallext in Number:" << endl;
        cin >> P;

        Rabin_key_generation(p, q);
        ll C = Rabin_encryption(P);
        cout << C << endl;
        Rabin_decryption(p, q, C);


    }
    return 0;
}
