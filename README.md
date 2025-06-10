# Leetcode-1420.-Build-Array-Where-You-Can-Find-The-Maximum-Exactly-K-Comparisons
# 📊 Count the Number of Arrays With Exactly K Comparisons (Search Cost)

## 🧩 Problem Statement

Given three integers `n`, `m`, and `k`, return the number of arrays of length `n`, where each element is between `1` and `m` (inclusive), and exactly `k` comparisons are needed to find the maximum element **by the end of insertion**.

> The comparison is counted each time a new maximum is added to the array from left to right.

### ✨ Example

```

Input: n = 2, m = 3, k = 1
Output: 6
Explanation: The possible arrays are [1, 1], [2, 1], [2, 2], [3, 1], [3, 2] [3, 3]

```

---

## 🧠 Approach: Top-Down Dynamic Programming + Memoization

We use a recursive function with memoization to try building every possible valid array while tracking:

* 📏 current index `i`
* 📈 current max value so far `prevelement`
* 🔍 current search cost (comparisons) `anstill`

At each step, for every number `j` from `1` to `m`:

* If `j > prevelement` → increase `search cost`
* Else → continue with same cost

All results are stored in a 3D DP table `dp[i][prevelement][anstill]` to avoid recomputation.

---

## ⏱️ Time Complexity

* **O(n \* m \* k \* m)** → in the worst case, we make `m` choices at each state.
* Optimized via memoization.

## 💾 Space Complexity

* **O(n \* m \* k)** → for the 3D DP table.

---

## 🔍 Utility Table Representation

```
dp[i][max_so_far][search_cost] = # of valid ways
```

Where:

* `i` is the current index (0 to n-1)
* `max_so_far` is the current maximum element
* `search_cost` is the number of times a new maximum was inserted

---

## 🎨 Visual Insight

```
               +---+---+---+
Start:         | 0 | 0 | 0 |
               +---+---+---+
Insert 1 ➡️ [1] -> cost = 1
Insert 2 ➡️ [1,2] -> new max, cost = 2
Insert 1 ➡️ [1,2,1] -> no new max, cost = 2

Goal: Exactly k = 2 comparisons ✅
```

---

## 🧑‍💻 Author Info

> ✍️ Made with 💡 by **Ridham Garg**
> 🎓 **Thapar Institute of Engineering and Technology**
> 📧 [Ridhamgarg000@gmail.com](mailto:Ridhamgarg000@gmail.com)

---

> 🚀 "Every array tells a story, and this one is about optimal comparisons!" 🧮✨
