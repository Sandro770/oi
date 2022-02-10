/* autor: Alessandro Peria */
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define st first
#define nd second
#define pb push_back
#define FOR(_name, _upper) for(int _name = 1; (_name) <= (int)(_upper); ++(_name))
#define ull unsigned long long

const int maxn = (int)1e6 + 10;
const int maxz = (int) 1e5 + 10;

ull x[maxn];
pair<ull,ull> k[maxz];
pair<ull,ull> ans[maxz];

struct pozycja{
	ull lewy;
	ull p;
	ull q;
};
struct comparison{
	bool operator()(pozycja& a,pozycja& b){
		ull v1,v2;
		v1 = a.p * b.q;
		v2 = b.p * a.q;
		if(v1 < v2)
			return 1;
		if(v1 == v2 && a.lewy > b.lewy)
			return 1;
		return 0;
	}	
};
int main(){ 
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,z;
	ull X;
	cin >> n >> X >> z;
	priority_queue<pozycja,vector<pozycja>,comparison> pq;
	
	FOR(i,n)
		cin >> x[i];
	for(int i = 2; i <= n; i++){
		pozycja t;
		t.lewy = x[i - 1];
		t.p = x[i] - x[i - 1];
		t.q = 2;
		pq.push(t);
	}
	ull maxK=1;
	FOR(i,z){
		cin >> k[i].st;
		k[i].nd = i;
		maxK = max(maxK,k[i].st);
	}
	sort(k + 1, k + z + 1);
	ull past = 0;
	int queryPointer = 1;
	while(past <= maxK){
		pozycja act = pq.top();
		pq.pop();
		ull toAdd = act.q/(ull)2;
		while(queryPointer <= z && k[queryPointer].st <= past + toAdd){
			ull pozostali = k[queryPointer].st - past;
			ull up = act.lewy * act.q + act.p + (pozostali - (ull)1) * act.p * (ull)2;
			ull down = act.q;
			ull gcd = __gcd(up,down);
			int id = k[queryPointer].nd;
			ans[id].st = up / gcd;
			ans[id].nd = down / gcd;
			queryPointer++;
		}
		past += toAdd;
		if(past > maxK)
			break;
		act.q *= (ull)2;
		pq.push(act);
	}
	FOR(i,z)
		cout << ans[i].st << '/' << ans[i].nd << '\n';
	return 0;
}
