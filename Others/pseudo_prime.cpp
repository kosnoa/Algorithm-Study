#include<stdio.h>
#include<stdlib.h>
#include<cassert>

typedef long long ll;

ll mul(ll n, ll m, ll M){
	if( !m ) return 0;
	if( m&1 ) return (n + mul(n*2%M, m/2, M)) % M;
	else return mul(n*2%M, m/2, M);
}

ll pw(ll n, ll m, ll M){
	ll ans = 1;
	while(m){
		if( m%2 == 1 ) ans = mul(ans, n, M);
		n = mul(n, n, M); m /= 2;
	}
	printf("%d\n", ans);
	return ans;
}

int main()
{
	ll n, m;
	assert(scanf("%lld%lld", &n, &m) == 2);
	assert( 500 < n && n <= 1e15 && 2 <= m && m < n && n%m == 0);
	for(int i = 2; i <= 500; i++){
		assert( pw(i, n-1, n) == 1 );
	}
	return 0;
}

