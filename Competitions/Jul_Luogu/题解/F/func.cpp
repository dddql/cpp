#include <bits/stdc++.h>
using namespace std;

const int Maxi = 1030, Maxn = 20005;
int n, m, ct, bloc, f[Maxn][Maxi], pos[Maxi], fac[Maxi];
pair<int, int> from[Maxn][Maxi];
long long d, p, goal, val[Maxn], arr[Maxn];
pair<int, long long> ans[Maxn];
map<int, int> Ma;
typedef pair<long long, long long> pll;
pll G;

pll operator*(const pll &x, const pll &y){
	return make_pair((x.first * y.second + x.second * y.first) % p, x.second * y.second % p);
}

long long gcd(long long x, long long y){
	return x == 0 ? y : gcd(y % x, x);
}

long long fast_pow(long long x, long long y){
	long long ans = 1, now = x;
	while (y){
		if (y & 1)
			ans = ans * now % p;
		now = now * now % p;
		y >>= 1;
	}
	return ans;
}

pll fast_pow(pll x, long long y){
	pll ans = make_pair(0, 1), now = x;
	while (y){
		if (y & 1)
			ans = ans * now;
		now = now * now;
		y >>= 1;
	}
	return ans;
}

void dp(void){
	int maxi = (1 << ct) - 1;
	memset(f, 0x3f, sizeof(f));
	f[0][maxi] = 0;
	for (int i = 1; i <= n; i++){
		int sta = 0;
		long long tmp_val = val[i] / gcd(val[i], goal);
		for (int j = 1; j <= ct; j++)
			if (tmp_val % fac[j] == 0)
				sta |= 1 << (j - 1);
		for (int j = 1; j <= maxi; j++)
			if (f[pos[j]][j] + 1 < f[pos[j & sta]][j & sta]){
				pos[j & sta] = i;
				f[i][j & sta] = f[pos[j]][j] + 1;
				from[i][j & sta] = make_pair(pos[j], j);
			}
	}
}

int get_unit(void){
	int maxi = sqrt(p - 1);
	for (int i = 2;; i++){
		for (int j = 2; j <= maxi; j++)
			if ((p - 1) % j == 0){
				if (fast_pow(i, j) == 1)
					goto END;
				if (fast_pow(i, (p - 1) / j) == 1)
					goto END;
			}
		return i;
	END:;
	}
}

void get_factor(void){
	int maxi = sqrt(p - 1), tmp = p - 1;
	for (int i = 2; i <= maxi; i++)
		if (tmp % i == 0){
			fac[++ct] = i;
			while (tmp % i == 0)
				tmp /= i;
		}
	if (tmp != 1)
		fac[++ct] = tmp;
	fac[++ct] = p;
}

pll exgcd(long long x, long long y){
	if (!x)
		return make_pair(0, 1);
	else{
		pll tmp = exgcd(y % x, x);
		return make_pair(tmp.second - tmp.first * (y / x), tmp.first);
	}
}

long long mod(__int128 x){
	return (x % (p * (p - 1)) + (p * (p - 1))) % (p * (p - 1));
}

void work(int lt, long long goal_now){
	long long g = p * (p - 1), div = gcd(goal_now, p * (p - 1));
	for (int i = lt + 1; i <= m; i++)
		g = gcd(g, arr[i]);
	div = gcd(g, arr[lt]);
	arr[lt] /= div, g /= div, goal_now /= div;
	pll result = exgcd(arr[lt], g);
	ans[lt].second = mod((__int128)result.first * goal_now);
	if (lt == m - 1){
		ans[m].second = mod((__int128)result.second * goal_now);
		return;
	}
	work(lt + 1, mod(mod((__int128)result.second * goal_now) * (__int128)g));
}

void BSGS_init(void){
	bloc = sqrt(n * p);
	long long now = 1;
	d = get_unit();
	for (int i = 0; i < bloc; i++){
		Ma[now] = i;
		now = now * d % p;
	}
}

long long BSGS(pll val_now){
	long long inv = fast_pow(fast_pow(d, bloc), p - 2), now_inv = 1;
	for (int j = 0; j < p / bloc + 1; j++){
		if (Ma[now_inv * val_now.second % p]){
			long long tmp = Ma[now_inv * val_now.second % p] + j * (long long)bloc;
			pll tmp_val = val_now * fast_pow(make_pair(1, d), p * (p - 1) - tmp);
			return ((p - 1) * (p - tmp_val.first * d % p) + tmp) % (p * (p - 1));
		}
		(now_inv *= inv) %= p;
	}
}

int main(){
	scanf("%d%lld%lld%lld", &n, &p, &G.first, &G.second);
	BSGS_init();
	get_factor();
	goal = BSGS(G);
	long long g = gcd(p * (p - 1), goal);
	for (int i = 1; i <= n; i++){
		pll x;
		scanf("%lld%lld", &x.first, &x.second);
		val[i] = BSGS(x), g = gcd(g, val[i]);
	}
	for (int i = 1; i <= n; i++)
		val[i] /= g;
	dp();
	if (f[pos[0]][0] > n){
		puts("-1");
		return 0;
	}
	pair<int, int> now = make_pair(pos[0], 0);
	while (now.first){
		arr[++m] = val[now.first];
		ans[m].first = now.first;
		now = from[now.first][now.second];
	}
	work(1, goal);
	printf("%d\n", m);
	for (int i = 1; i <= m; i++)
		printf("%d %lld\n", ans[i].first, ans[i].second);
	return 0;
}
