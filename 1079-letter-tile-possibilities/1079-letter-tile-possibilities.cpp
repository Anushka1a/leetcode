class Solution {
public:
    int ans = 0;

    void solve(vector<int>& freq) {
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0)
                continue;

            ans++;
            freq[i]--;

            solve(freq);

            freq[i]++;
        }
    }

    int numTilePossibilities(string tiles) {
        vector<int> freq(26, 0);

        for (char c : tiles)
            freq[c - 'A']++;

        solve(freq);

        return ans;
    }
};