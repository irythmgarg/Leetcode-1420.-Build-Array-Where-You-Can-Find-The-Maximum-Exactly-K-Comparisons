// 💡 C++ Solution: Count the Number of Arrays With Exactly K Comparisons (Search Cost)
// 📌 Author: Ridham Garg (Thapar Institute of Engineering and Technology)
// 📧 Email: Ridhamgarg000@gmail.com

class Solution {
public:
    // DP memoization table: dp[position][max_so_far][search_cost]
    int dp[51][101][52];
    const int mod = 1e9 + 7; // Modulo for large numbers

    // 🔁 Recursive helper function
    // n: total size of array
    // m: max possible value in the array
    // k: required search cost
    // anstill: current search cost
    // i: current index in array
    // prevelement: current max element in array so far
    int hlo(int n, int m, int k, int anstill, int i, int prevelement) {
        // ✅ Base case: if full array is built
        if (i >= n) {
            // Check if we reached exactly k comparisons
            return (anstill == k) ? 1 : 0;
        }

        // 🔁 Return cached result if already computed
        if (dp[i][prevelement][anstill] != -1)
            return dp[i][prevelement][anstill];

        int ans = 0;

        // 🔢 Try placing every number from 1 to m
        for (int j = 1; j <= m; j++) {
            if (j > prevelement) {
                // 📈 New max found, increase search cost
                ans = (ans + hlo(n, m, k, anstill + 1, i + 1, j)) % mod;
            } else {
                // ➡️ Continue with current max
                ans = (ans + hlo(n, m, k, anstill, i + 1, prevelement)) % mod;
            }
        }

        // 💾 Store and return answer
        return dp[i][prevelement][anstill] = ans;
    }

    // 🔃 Main function
    int numOfArrays(int n, int m, int k) {
        // Initialize memoization table with -1
        memset(dp, -1, sizeof(dp));

        // Start recursion from index 0 with initial max as 0 and cost as 0
        return hlo(n, m, k, 0, 0, 0);
    }
};
