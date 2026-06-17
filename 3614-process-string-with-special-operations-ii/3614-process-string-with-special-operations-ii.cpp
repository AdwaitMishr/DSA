class Solution {
private:
    long long getLen(const string& str) {
        long long len = 0;
        for (char ch : str) {
            if (ch == '*') {
                if (len) {
                    len--;
                }
            } else if (ch == '#') {
                len *= 2;
            } else if (ch != '%') {
                len++;
            }
        }
        return len;
    }

    char findChar(const string& str, long long k, long long len) {
        for (int i = str.size() - 1; i >= 0; i--) {
            if (str[i] == '*') {
                len++;
            } else if (str[i] == '#') {
                if (k + 1 > (len + 1) / 2) {
                    k -= len / 2;
                }
                len = (len + 1) / 2;
            } else if (str[i] == '%') {
                k = len - k - 1;
            } else {
                if (k + 1 == len) {
                    return str[i];
                } else {
                    len--;
                }
            }
        }
        return '.';
    }

public:
    char processStr(string str, long long k) {
        long long len = getLen(str);
        if (k + 1 > len) {
            return '.';
        }
        return findChar(str, k, len);
    }
};