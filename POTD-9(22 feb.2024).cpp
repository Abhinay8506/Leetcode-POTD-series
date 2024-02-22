class Solution {
public:

    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> independent(n + 1); 
        vector<int> dependent(n + 1);
		for (auto a : trust) {
			++dependent[a[0]];
			++independent[a[1]];
		}
		for (int i = 1; i <= n; i++) {
			if (independent[i] == n - 1 && dependent[i] == 0) return i;
		}
		return -1; 
    }
};
