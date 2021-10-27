
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

int gcd(int a, int b)					// Basic Euclidean
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

int gcdExtended(int a, int b, int* x, int* y)   // Extended Euclidean
{

	if (a == 0) {
		*x = 0, *y = 1;
		return b;
	}

	int x1, y1;
	int gcd = gcdExtended(b % a, a, &x1, &y1);

	*x = y1 - (b / a) * x1;
	*y = x1;

	return gcd;
}

void modInverse(int a, int m)
{
	int x, y;
	int g = gcdExtended(a, m, &x, &y);
	if (g != 1) cout << "Inverse doesn't exist";
	else {
		int res = (x % m + m) % m;
		cout << "Modular multiplicative inverse is " << res;
	}
}


int main()
{
	int a = 206, m = 11;

	modInverse(a, m);
	return 0;
}

