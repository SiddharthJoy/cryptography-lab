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

pair<ll, ll> public_key;
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

void RSA_key_generation(ll p, ll q)
{
    ll n;
    // p = 7, q = 11;

    n = p * q;
    ll phi = (p - 1) * (q - 1);

    ll e, d;

    forr(i, 2, phi) {
        if (__gcd(i, phi) == 1 && modInverse(i, n) != -1) {
            e = i;
            break;
        }
    }

    d = modInverse(e, phi);
    // cout << d << "   12234" << endl;

    public_key = {e, n};
    private_key = {d, n};
}

ll RSA_encryption(ll P)
{
    ll d, n;
    d = private_key.F;
    n = private_key.S;

    ll C = fastExp(P, d, n);

    return C;
}

ll RSA_decryption(ll C)
{
    ll e, n;
    e = public_key.F;
    n = public_key.S;

    ll P = fastExp(C, e, n);

    return P;
}

int main()
{
    faster_io

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll t = 1, n, p, q, P, C, M;

    // cin >> t;


    while (t--) {
        // cin >> n;

        // cout << "Choose p:" << endl;
        cin >> p;
        // cout << "Choose q:" << endl;
        cin >> q;

        // n = p * q;

        // cout << "Plallext in Number:" << endl;
        cin >> C;

        M = C;

        cout << "Actual Message: " << C << endl;

        RSA_key_generation(p, q);
        // cout << public_key.F << " " << public_key.S << endl;
        // cout << private_key.F << " " << private_key.S << endl;
        n = private_key.S;

        // cout << fastExp(2, 5, 7) << endl;
        P = RSA_decryption(C);
        // cout << P << endl;

        cout << "Signed Message: " << P << endl;
        C = RSA_encryption(P);
        cout << "Retrieved copy of the message from the signed message: " << C << endl;

        cout << "Result: ";

        if (C == M) cout << "Accepted" << endl;
        else cout << "Denied!" << endl;
    }

    return 0;
}
