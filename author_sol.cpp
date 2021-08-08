#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		int q[k];
		for (int i = 0; i < k; i++) {
			cin >> q[i];
		}
		// calculate the initial distance of the 1st and last particle
		int sum = 0;
		for (int i = 0; i < n - 1; i++) {
			if (s[i] == s[i + 1]) {
				sum += 2;
			} else {
				sum += 1;
			}
		}
		// for every 'k'-th update, the elements that will be only affected  
		// are the current, previous, and next adjacent elements
		for (int i = 0; i < k; i++) {
			--q[i];
			// update the particle
			s[q[i]] = (s[q[i]] == '1' ? '0' : '1');
			// check if the current particle is the not the last one
			if (q[i] < n - 1) {
				// if yes, then check if current particle is equal to the next particle
				if (s[q[i]] == s[q[i] + 1]) {
					// if yes, then increment 'sum'
					sum++;
				} else {
					// otherwise, decrement 'sum'
					sum--;
				}
			}
			// check if the current particle is the not the first one
			if (q[i] > 0) {
				// if yes, then check if current particle is equal to the previous particle
				if (s[q[i]] == s[q[i] - 1]) {
					// if yes, then increment 'sum'
					sum++;
				} else {
					// otherwise, decrement 'sum'
					sum--;
				}
			}
			// output the updated 'sum'
			cout << sum << '\n';
		}
	}
	return 0;
}

