/* autor: Alessandro Peria */
#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int dl = 5;
string s;

int zlicz[20][(int) 1e6 + 5];
int ile[100];
int powinno[100];

void add(int poc, int kon, bool add){
	int dl = kon - poc + 1;
	long long x = 0;
	for(int i = kon; i >= poc; i--){
		if(s[i] == '1')
			x += (1<<(kon - i));
	}
	if(add == 1)
		zlicz[dl][x]++;
	else
		zlicz[dl][x]--;
	int val = zlicz[dl][x];
	if(val == 0 && add == 0)
		ile[dl]--;
	if(val == 1 && add == 1)
		ile[dl]++;
}
void check(){
	for(int i = 1; i <= 19; i++)
		if(powinno[i] != ile[i]){
			cout << i << '\n';
			break;
		}
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	int n,m;
	cin >> n >> m;
	cin >> s;
	s = ' ' + s;
	
	for(int i = 1; i <= n; i++)
		for(int j = i; j <= min(i + 18,n); j++)
			add(i,j,1);
	for(int i = 1; i <= 19; i++)
		powinno[i] = (1<<i);
	for(int i = 1; i <= 18; i++)
		if(powinno[i] != ile[i]){
			cout << i << '\n';
			break;
		}
	while(m--){
		int poz;
		cin >> poz;
		for(int i = max(1,poz - 18); i <= poz; i++){
			for(int j = poz; j <= min(i + 18,n); j++){
				add(i,j,0);
			}
		}
		if(s[poz] == '0')
			s[poz] = '1';
		else
			s[poz] = '0';
		for(int i = max(1,poz - 18); i <= poz; i++){
			for(int j = poz; j <= min(i + 18,n); j++){
				add(i,j,1);
			}
		}
		check();
	}
	return 0;
}
