#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int N, M, P[10];
vector<pair<int, int>> p;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> P[i];
		p.push_back({ P[i],i });
	}
	
	cin >> M;
	sort(p.begin(), p.end());
	string ret;
	
	if (N==1) {
		puts("0");
		return 0;
	}

	if (p[0].second!=0) {
		int cnt = M / p[0].first;
		for (int i = 0; i < cnt; i++) {
			ret += to_string(p[0].second);
		}
		M -= cnt * p[0].first;
	}
	else {
		int m = M - p[1].first;
		if (m < 0) {
			puts("0");
			return 0;
		}
		ret += to_string(p[1].second);
		int cnt = m / p[0].first;
		for (int i = 0; i < cnt; i++) {
			ret += to_string(p[0].second);
		}
		M = m - cnt * p[0].first;
	}
	for (int i = 0; i < ret.size(); i++) {
		bool ok = 0;
		int cur = P[ret[i] - '0'];
		for (int j = N-1; j >= 0; j--) {
			if (M - (P[j] - cur) >= 0) {
				M -= P[j] - cur;
				ok = 1;
				ret[i] = j + '0';
			}
			if (ok) {
				break;
			}
		}
		if (!ok) {
			break;
		}
	}
	cout << ret.c_str();
	
}