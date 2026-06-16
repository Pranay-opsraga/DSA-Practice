class Solution {
	public:
	vector<int> solve(string& s) {
		int n = s.size();
		vector<int>Z(n, 0);
		int l = 0;
		int r = 0;
		
		for (int i = 1 ; i < n ; i++) {
			if (i <= r) {
				Z[i] = min(r - i + 1, Z[i - l]);
			}
			
			while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]])
				Z[i]++;
			
			if (i + Z[i] - 1 > r) {
				l = i;
				r = i + Z[i] - 1;
			}
		}
		
		return Z;
		
	}
	vector<int> search(string &txt, string &pat) {
		int p = pat.size();
		int n = txt.size();
		int i = 0;
		string s(p + n + 1, ' ');
		for (char ch : pat) {
			s[i] += ch;
			i++;
		}
		
		s[i] += '$';
		i++;
		
		for (char ch : txt) {
			s[i] += ch;
			i++;
		}
		
		vector<int>Z = solve(s);
		vector<int>res;
		for (int i = 0 ; i < Z.size() ; i++) {
			if (Z[i] == p) {
				res.push_back(i - p - 1);
			}
		}
		return res;
	}
};
