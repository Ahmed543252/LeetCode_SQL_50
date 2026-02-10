class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int i = 0, n = words.size();
        while (i < n) {
            int cnt = 0;
            vector<string> tmp;
            while (i < n && cnt + words[i].size() + tmp.size() <= maxWidth) {
                tmp.push_back(words[i]);
                cnt += words[i].size();
                i++;
            }
            string cur ="";
            int gaps = tmp.size() - 1, diff = maxWidth - cnt;
             if (i == n || gaps == 0) {
                for (int j = 0; j < tmp.size(); j++) {
                    if (j) cur += ' ';
                    cur += tmp[j];
                }
                while (cur.size() < maxWidth) cur += ' ';
            }
            else {
                int all = diff / gaps;
                int extra = diff % gaps;

                for (int j = 0; j < tmp.size(); j++) {
                    cur += tmp[j];
                    if (j < gaps) {
                        for (int k = 0; k < all; k++) cur += ' ';
                        if (extra > 0) {
                            cur += ' ';
                            extra--;
                        }
                    }
                }
            }
                ans.push_back(cur);
        }
        return ans;
    }
};