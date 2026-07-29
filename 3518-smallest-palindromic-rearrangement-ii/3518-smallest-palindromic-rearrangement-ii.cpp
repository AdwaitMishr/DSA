class Solution {
private:
    long long comb(long long n, long long m, long long k) {
        long long res = 1;
        m = min(m, n - m);
        for (long long i = 1; i <= m; i++) {
            res = res * (n - i + 1) / i;
            if (res > k) {
                return k + 1;
            }
        }
        return res;
    }

    long long getPerms(int rem, std::vector<int>& bkt, long long k) {
        long long w = 1;
        for (int i = 0; i < 26; i++) {
            if (bkt[i] == 0) {
                continue;
            }
            w *= comb(rem, bkt[i], k);
            if (w > k) {
                break;
            }
            rem -= bkt[i];
        }
        return w;
    }

public:
    string smallestPalindrome(std::string s, long long k) {
        int part = s.length() / 2;
        vector<int> bkt(26, 0);

        for (int i = 0; i < part; i++) {
            bkt[s[i] - 'a'] += 1;
        }

        string lStr = "";
        long long stIdx = 1;

        for (int p = 0; p < part; p++) {
            for (int i = 0; i < 26; i++) {
                if (bkt[i] == 0) {
                    continue;
                }

                bkt[i] -= 1;

                long long w = getPerms(part - p - 1, bkt, k);
                if (stIdx + w > k) {
                    lStr += (char)(i + 'a');
                    break;
                }

                bkt[i] += 1;
                stIdx += w;
            }
        }

        if (lStr.length() < part) {
            return "";
        }

        string mStr = s.length() % 2 != 0 ? std::string(1, s[part]) : "";
        string rStr = lStr;
        reverse(rStr.begin(), rStr.end());

        return lStr + mStr + rStr;
    }
};