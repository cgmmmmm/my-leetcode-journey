## LeetCode 3518: Smallest Palindromic Rearrangement II

Given `s`, where `s` is guaranteed to be a palindrome string.

**Task:** Return the $k$-th lexicographically smallest permutation formed by `s`.

---

### Properties of a Palindrome & Formula

A palindrome consists of 2 halves (first half & second half), where the second half is the mirrored version of the first half.

Therefore, the number of palindromic permutations the palindrome string `s` can generate is obtained by the multiset permutation formula:

$$\frac{\lfloor \text{length} / 2 \rfloor!}{r_1! \cdot r_2! \cdot \dots \cdot r_m!} = \frac{n!}{r_1! \cdot r_2! \cdot \dots \cdot r_m!}$$

$$\text{where } r_1 + r_2 + \dots + r_m = n$$

### Example

Imagine `s = "aabccccbaa"`, $\text{length} = 10$, $n = \lfloor 10 / 2 \rfloor = 5$.

We only have to construct the `first_half` of the result string `res`, since the `second_half` can be easily constructed by reverse iterating the first half.

`first_half` consists of:

* $r_1$ (`a`): 2
* $r_2$ (`b`): 1
* $r_3$ (`c`): 2

From this, we can calculate that the number of palindromic permutations generated from `s` is 30:

$$\frac{5!}{2! \cdot 1! \cdot 2!} = 30$$

---

### Issue: Integer Overflow

This method of verification fails as $21!$ already exceeds any built-in C++ integer type, and the problem constraint states that $n$ is up to $10^4$, so the greatest factorial that we need to compute is $5000!$.

To avoid integer overflow, the multinomial expression can be broken down into smaller multiplications using binomial coefficients:

$$\frac{n!}{a! \cdot b! \cdot c! \dots} = \binom{n}{a} \times \binom{n-a}{b} \times \binom{n-a-b}{c} \dots \quad \text{where } a + b + c + \dots = n$$

$$\binom{n}{m} = \prod_{i=1}^{m} \frac{n - m + i}{i}$$

### Example Breakdown

Consider this multinomial expression:

$$\frac{21!}{7! \cdot 7! \cdot 7!} = \binom{21}{7} \times \binom{14}{7} \times \binom{7}{7} = 116,280 \times 3,432 \times 1 = 399,073,080$$

But, computing $\binom{5000}{2500}$ still hits the `unsigned long long` limit.

---

### Optimization

Since problem constraints are provided where $1 \le k \le 10^6$, if during mid calculation the result of the calculation exceeds $10^6$, stop immediately. This already means that there is a valid $k$-th palindromic permutation, lexicographically sorted or not.

If calculated result at any point exceeds $k$, stop the calculation.

---

### Lexicographical Construction of `first_half`

Next, construct the $k$-th lexicographically smallest half-string, since forming the half-string can construct the full palindromic string.

### But how?

Imagine the first half has a length of 5, and $k = 500$:

```text
_ _ _ _ _

```

You have to find the smallest 500th ranked palindrome generated from `s`.

1. **If you start with `'a'`:** Suppose the number of permutations starting with `'a'` is $300 \; (< k)$. This means that the string starting with `'a'` only has up to 300 permutations. Therefore, starting with `'a'` will never get to the smallest 500th ranked permutation.

2. **If you start with `'b'`:** Suppose the number of permutations starting with `'b'` is $700 \; (> k)$. This means that the string starting with `'b'` has 700 permutations. Therefore, starting with `'b'` will get to the 500th lexicographically smallest permutation.

```text
b _ _ _ _

```

*(`'b'` frequency decrements by 1)*

Notice that in (1), starting with `'a'` gives 300 permutations. This means that the permutations starting with `'b'` are ranked 301st ... 1,000th permutation.

So to get the exact $k$-th permutation, reduce $k$ by all non-valid starting candidates.

---

### Calculating Sub-Permutations

Now, to find the number of permutations starting with 1 or more characters, use the permutation formula, but optimized as multinomial coefficient.

Consider `APPLE`: the number of permutations starting with `'A'` is:

$$\text{Permutation} = \frac{\text{remaining slots}!}{\text{Duplicate factorials}}$$

The same permutation formula can also get an integer overflow, so we can avoid the integer overflow using the same multinomial coefficient function again.

Do construction and calculate sub-permutations until all slots in `first_half` are filled.

---

### Final Assembly
1. Fill the middle character as the start of `second_half`, if any.
2. Reverse iterate the `first_half` and append the characters during the iteration into `second_half`.

Finally, return `first_half` + `second_half`.

---

## Techniques Learned

### Core Techniques

#### 1. Using GCD to Avoid Integer Overflow in `safe_binomial()`

##### Why Direct Multiplication Overflows

The binomial coefficient is mathematically defined as:

$$\binom{n}{m} = \frac{n \times (n-1) \times \dots \times (n - m + 1)}{m!}$$

* **Numerator Explosion:** If you attempt to calculate the numerator first by multiplying all terms $n \times (n-1) \times \dots$, the intermediate value overflows 64-bit integer limits (`unsigned long long` max $\approx 1.84 \times 10^{19}$) extremely fast. For example, computing $\binom{30}{15}$ involves a numerator product exceeding $10^{20}$, long before performing any division by $m!$.
* **Why Naive Iterative Division Fails:**
* Writing `res = (res * numerator) / denominator` still risks overflow during the intermediate `res * numerator` multiplication before division can shrink it back down.
* Writing `res = res * (numerator / denominator)` produces incorrect results because $(n - m + i) / i$ is usually not an integer in isolation.



##### How Step-by-Step GCD Reduction Prevents Overflow

To compute $\binom{n}{m} = \prod_{i=1}^{m} \frac{n - m + i}{i}$ safely, the algorithm uses `std::gcd` to cancel out common factors **before** performing any multiplication:

```cpp
ull numerator = (n - m + i);
ull denominator = i;

// Step A: Reduce denominator against the accumulated result
ull g = std::gcd(res, denominator);
res /= g;
denominator /= g;

// Step B: Reduce denominator against the current term numerator
g = std::gcd(numerator, denominator);
numerator /= g;
denominator /= g;

// Step C: Multiply safely
res *= numerator;

```

1. **Step A (`res` vs `denominator`):** `std::gcd(res, denominator)` extracts shared prime factors between the existing total `res` and the current divisor $i$ (`denominator`), shrinking `denominator`.
2. **Step B (`numerator` vs `denominator`):** `std::gcd(numerator, denominator)` extracts remaining common factors between the step term $(n - m + i)$ (`numerator`) and the leftover `denominator`.
3. **Guaranteed Integer Property:** Mathematically, the product of any $i$ consecutive integers is always divisible by $i!$. Thus, `denominator` is **guaranteed to reduce to 1** at the end of Step B in every iteration.
4. **Safe Product (Step C):** Because `denominator` is reduced to $1$ prior to multiplication, `res *= numerator` executes without holding unsimplified factors, keeping `res` at its absolute minimal possible value at every loop iteration.

---

#### 2. Using Multinomial Coefficients to Avoid Integer Overflow for Factorials

Calculating multiset permutations using factorials $\frac{n!}{r_1! \cdot r_2! \dots r_m!}$ directly requires $n!$, which overflows 64-bit integers for $n > 20$.

* The expression is decomposed into a product of chained binomial coefficients:

$$\binom{n}{r_1} \times \binom{n - r_1}{r_2} \times \binom{n - r_1 - r_2}{r_3} \dots$$


* Since $k \le 10^6$, any intermediate permutation count exceeding $10^6$ (or $k$) is decision-equivalent to $\infty$. The loop safely breaks early (`if (calc > 1'000'000 || calc > k) break;`), eliminating overflow while preserving exact ranking logic.

---

#### 3. Finding the $k$-th Lexicographically Sorted Item Using Greedy Selection

To construct `first_half` from left to right character-by-character:

* Iterate through available characters `'a'` through `'z'` in lexicographical order for each position.
* Temporarily place character $i$ and calculate how many valid sub-permutations (`numOfPPChar`) can be formed with the remaining characters.
* **If $\text{numOfPPChar} < k$:** The target permutation does not lie in this branch. Backtrack the character count, subtract $\text{numOfPPChar}$ from $k$, and test the next character.
* **If $\text{numOfPPChar} \ge k$:** The target permutation lies within this character's branch. Place character $i$, move to the next position slot, and repeat.

---

### Complexity Analysis

* **Time Complexity:** $\mathcal{O}(n \cdot \vert{}\Sigma\vert{} \cdot n)$, where $n = \lfloor \text{length} / 2 \rfloor$ and $\vert{}\Sigma\vert{} = 26$. For each of the $n$ slots in `first_half`, we iterate through up to $\vert{}\Sigma\vert{}$ alphabet choices and calculate `multinomial_coefficient` which performs up to $n$ steps.
* **Space Complexity:** $\mathcal{O}(n + \vert{}\Sigma\vert{})$ auxiliary space for tracking character counts and constructing the resulting `first_half` and `second_half` strings.

---

### Solution Implementation

```cpp
using ull = unsigned long long;

class Solution {
public:
    ull safe_binomial(int n, int m)
    {
        if (m > n - m) 
            m = n - m;

        ull res = 1;
        for (int i = 1; i <= m; ++i)
        {
            ull numerator = (n - m + i);
            ull denominator = i;

            ull g = std::gcd(res, denominator);
            res /= g;
            denominator /= g;

            g = std::gcd(numerator, denominator);
            numerator /= g;
            denominator /= g;

            res *= numerator;
        }
        return res;
    }

    ull multinomial_coefficient(int n, std::vector<int>& counts, int k)
    {
        ull calc = 1;
        for (int f : counts)
        {
            if (f == 0) continue;
            if (n <= 0 || calc > 1'000'000 || calc > k) break;
            calc *= safe_binomial(n, f);
            n -= f;
        }

        return calc;
    }

    string smallestPalindrome(string s, int k) 
    {
        int fullLen = s.size();
        char mid = 0;
        if (fullLen % 2 == 1) mid = s[fullLen / 2];
        s = s.substr(0, fullLen / 2);

        std::vector<int> counts(26, 0);
        for (char ch : s) counts[ch - 'a']++;

        int n = s.size();
        ull numOfPP = multinomial_coefficient(n, counts, k); // number of palindromic permutations
        if (numOfPP < k) return "";

        int remaining_slots = n;
        std::string first_half = "";
        while (remaining_slots > 0)
        {
            for (int i = 0; i < 26; ++i)
            {
                if (counts[i] > 0)
                {
                    counts[i]--;
                    ull numOfPPChar = multinomial_coefficient(remaining_slots - 1, counts, k);
                    if (numOfPPChar < k)
                    {
                        counts[i]++;
                        k -= numOfPPChar;
                        continue;
                    }
                    first_half += (char)(i + 'a');
                    remaining_slots--;
                    break;
                }
            }
        }

        std::string second_half = "";
        if (mid) second_half += mid;
        for (int i = first_half.size() - 1; i >= 0; --i)
            second_half += first_half[i];

        return first_half + second_half;
    }
};

```
**Note:** This solution can be further optimized.