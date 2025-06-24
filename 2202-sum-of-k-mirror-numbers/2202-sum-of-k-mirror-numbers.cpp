class Solution {
private:
    int digits[100];

    bool isPalindrome(long long num, int base) {
        int len = -1;
        while (num) {
            digits[++len] = num % base;
            num /= base;
        }
        for (int i = 0, j = len; i < j; ++i, --j) {
            if (digits[i] != digits[j]) return false;
        }
        return true;
    }

public:
    long long kMirror(int base, int target_count) {
        int start = 1, total = 0;
        long long result = 0;

        while (total < target_count) {
            int end = start * 10;

            for (int mode = 0; mode < 2; ++mode) {
                for (int num = start; num < end && total < target_count; ++num) {
                    long long candidate = num;
                    int rem = (mode == 0) ? num / 10 : num;
                    while (rem) {
                        candidate = candidate * 10 + rem % 10;
                        rem /= 10;
                    }

                    if (isPalindrome(candidate, base)) {
                        ++total;
                        result += candidate;
                    }
                }
            }

            start = end;
        }

        return result;
    }
};
