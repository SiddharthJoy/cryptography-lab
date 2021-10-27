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
ll private_key;
ll C1, C2;
string cipher1 = "";
string cipher2 = "";
string retrieved = "";

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
    ll d = 3;
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
    ll r = 10;
    C1 = fastExp(e1, r, p);
    C2 = (P % p * fastExp(e2, r, p)) % p;

    cipher1 += char(C1 % 26 + 'A');
    cipher2 += char(C2 % 26 + 'A');

    // cout << C1 << " " << C2 << endl;


}

void Elgamal_decryption(ll p)
{
    ll d = private_key;
    ll P = ((C2 % p) * modInverse(fastExp(C1, d, p), p)) % p;
    retrieved += char(P + 'a');
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
        Elgamal_key_generation(p);

        string s;
        cin >> s;

        // cout << "Plallext in Number:" << endl;

        forr(i, 0, s.size()) {
            P = s[i] - 'a';
            Elgamal_encryption(P);
            Elgamal_decryption(p);
        }

        cout << cipher1 << endl;
        cout << cipher2 << endl;
        cout << retrieved << endl;

    }
    return 0;
}
