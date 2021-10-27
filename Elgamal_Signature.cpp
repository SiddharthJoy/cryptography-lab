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

vector<ll> public_key;
pair<ll, ll> sign;
ll private_key;
ll C1, C2;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

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


void Elgamal_key_generation(ll p)
{
    ll d = 127;
    ll e1 = 2;

    ll e2 = fastExp(e1, d, p);

    public_key.pb(e1);
    public_key.pb(e2);
    public_key.pb(p);

    private_key = d;
}

ll Elgamal_encryption(ll P)
{
    ll e1 = public_key[0];
    ll e2 = public_key[1];
    ll p = public_key[2];
    ll r = 307;
    C1 = fastExp(e1, r, p);
    C2 = (P % p * fastExp(e2, r, p)) % p;

    // cout << e1 << " " << e2 << endl;

    // cout << C1 << " " << C2 << endl;
}

void Elgamal_decryption(ll p)
{
    ll d = private_key;
    ll P = ((C2 % p) * modInverse(fastExp(C1, d, p), p)) % p;
    cout << P << endl;
}

void signing(ll M)
{
    ll r = 307;
    ll e1 = public_key[0];
    ll e2 = public_key[1];
    ll p = public_key[2];
    ll d = private_key;

    ll s1 = fastExp(e1, r, p);

    // cout << s1 << endl;

    ll tmp = M % (p - 1) - (d * s1) % (p - 1);
    if (tmp < 0) tmp += (p - 1);

    // cout << tmp << endl;
    ll s2 = (tmp % (p - 1) * modInverse(r, p - 1)) % (p - 1);

    // cout << s2 << endl;

    sign = {s1, s2};
}

void verifying(ll M)
{
    ll e1 = public_key[0];
    ll e2 = public_key[1];
    ll p = public_key[2];
    ll s1 = sign.F;
    ll s2 = sign.S;

    // cout << s1 << " " << s2 << endl;

    if (s1 > 0 && s1 < p && s2 > 0 && s2 < p - 1) {
        ll v1 = fastExp(e1, M, p);
        ll v2 = (fastExp(e2, s1, p) * fastExp(s1, s2, p)) % p;
        if (v1 == v2) {
            cout << "Accepted" << endl;
        }
        else cout << "Denied!" << endl;
    }
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
        // cin >> q;

        // n = p * q;

        // cout << "Plallext in Number:" << endl;
        cin >> P;

        Elgamal_key_generation(p);
        Elgamal_encryption(P);
        Elgamal_decryption(p);

        signing(P);
        verifying(P);
        // cout << modInverse(fastExp(5, 3, 11), 11) << endl;

    }
    return 0;
}
