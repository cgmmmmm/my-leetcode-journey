# Intuition
Problem states that a program is executed on a **single-threaded** CPU and has `n` functions, each function calls are stored in a **call stack**.

The problem statement is obviously telling us to mimic the call stack (or execution stack) in OS, by processing a string collection of inputs `logs`.

As the program is executed on a **single-threaded** CPU, when a new function starts while another is running, the currently running function is paused. CPU stops calculating its active time, switches to the new function, and only resumes timing on the original function once the interrupting function finishes.

The problem wants us to return the exclusive time of each function, so we need to simulate CPU profiling, handling a process' ***inclusive time*** and ***exclusive time***.

---

# Approach
### 1. Parsing the inputs 
We are given a collection of strings `logs`, we need to *parse* and extract 3 crucial information to solve this problem:
1. Function ID
2. Function Status
3. Function's Timestamp

To parse the string efficiently, we avoid dynamic heap memory allocations by leveraging C++17 `std::string_view` and `std::from_chars`.

**Parsing steps**:
1. Wrap `log` inside a `std::string_view` to read memory directly.
2. Read digits (Function ID) until it hits the first colon delimiter using `std::from_chars`, and write to `id`
3. Using pointer arithmetic, since the pointer `ptr` points to the first colon from step 2, the next character's pointer (`ptr+1`) would point to either `'s'` or `'e'`, representing `"start"` or `"end"` respectively.
4. De-reference `ptr` to get the character, if the character is `'e'`, it means the end of a function. Set `status` to `0`.
5. Locate the second colon delimiter by creating another `std::string_view` starting at `ptr` from step 2.
6. Read digits (Timestamp) from `time_start` pointer until `time_end` pointer, and write to `time`.
7. Return a structured-bind `{id, status, time}`. 
```cpp
    std::tuple<int, int, int> parseLog(const std::string& log)
    {
        std::string_view view(log);

        int id=0, status=1, time=0;

        auto res1 = std::from_chars(view.data(), view.data() + view.size(), id);
        
        std::string_view remainder(res1.ptr, view.data() + view.size() - res1.ptr);
        if (*(res1.ptr + 1) == 'e') status = 0;

        size_t last_colon = remainder.find_last_of(':');
        const char* time_start = remainder.data() + last_colon + 1;
        const char* time_end = view.data() + view.size();

        auto res2 = std::from_chars(time_start, time_end, time);

        return {id, status, time};
    }
```

#### *Why this approach over other parsing method?*

1. `std::stringstream` + `getline`;
    * High allocation overhead.
    * Require constructing stream objects and stream buffers.
2. `std::string::substr` + `std::stoi`:
    * Require copying string to heap.
    * Incurs memory copying overhead.

Using `std::string_view` and `std::from_chars` require  ***zero*** heap allocations, and executes in CPU registers and stack memory, no runtime overhead, making it extremely fast and efficient.

### 2. Simulating the Call Stack
As the name suggest, the data structure for this problem utilizes a stack. But let's actually understand why.

A function has a start and an end, and function calls are naturally nested. When Function A calls Function B, Function A is paused (preempted). Function B must fully execute and return before Function A can resume. This Last-In, First-Out (LIFO) behavior perfectly mirrors the operating system call stack.

To accurately track exclusive time across these interruptions, we maintain a running timestamp `prev_time` alongside `std::stack<int> stk`.

#### Handing a `start` event:
1. If the stack is not empty, the active function at the *top* of the call stack is being interrupted by a new call.
2. Credit the elapsed CPU units.
3. Push the new `id` onto `stk`, now the pushed function is active.
4. Update `prev_time` to reflect when this new function took over.

#### Handling an `end` event:
1. Hitting an `end` event means the function at the top of the stack has completed. Credit the elapsed CPU units.
2. Pop the completed function off `stk`, parent function immediately resumes.
3. Update `prev_time` to the start of the next execution window.

```cpp
    auto [id, sts, time] = parseLog(log);
    if (sts)
    {
        if (!stk.empty())
        {
            res[stk.top()] += time - prev_time;
        }
        stk.push(id);
        prev_time = time;
    }
    else
    {
        res[stk.top()] += time - prev_time + 1;
        stk.pop();
        prev_time = time + 1;
    }
```


---

# Complexity
- Time complexity: $$O(L)$$
    * iterate through the logs array of length $L$ exactly once.
    * parsing each log string takes $O(1)$ time because string lengths are small and bounded
    * `push`, `pop`, `top` take $O(1)$ time per entry.

- Space complexity: $$O(N)$$
    * output vector `res` takes $O(N)$ space to store exclusive times for $n$ functions.
    * `stk`[]() takes $O(D)$ auxiliary space, where $D$ is the maximum call stack depth ($D \le N$).

# Code
```cpp []
class Solution {
public:
    std::tuple<int, int, int> parseLog(const std::string& log)
    {
        std::string_view view(log);

        int id=0, status=1, time=0;

        auto res1 = std::from_chars(view.data(), view.data() + view.size(), id);
        
        std::string_view remainder(res1.ptr, view.data() + view.size() - res1.ptr);
        if (*(res1.ptr + 1) == 'e') status = 0;

        size_t last_colon = remainder.find_last_of(':');
        const char* time_start = remainder.data() + last_colon + 1;
        const char* time_end = view.data() + view.size();

        auto res2 = std::from_chars(time_start, time_end, time);

        return {id, status, time};
    }

    vector<int> exclusiveTime(int n, vector<string>& logs) 
    {
        // if std::get<1>(tup) == 1 meaning start, else end

        std::vector<int> res(n, 0);
        std::stack<int> stk;
        int prev_time = 0;
        for (const auto& log : logs)
        {
            auto [id, sts, time] = parseLog(log);
            if (sts)
            {
                if (!stk.empty())
                {
                    res[stk.top()] += time - prev_time;
                }
                stk.push(id);
                prev_time = time;
            }
            else
            {
                res[stk.top()] += time - prev_time + 1;
                stk.pop();
                prev_time = time + 1;
            }
        }
        return res;
    }
};
```

![Screenshot 2026-08-25 185916.png](https://assets.leetcode.com/users/images/c5195871-3683-40ab-acb3-6b27ead21566_1787655577.5905046.png)


#### Upvote if you find this helpful.
Just another CS student trying to survive in this job market, I'm trying to improve and any feedback is appreciated :)

What today's job market feels like:
![dining_philosophers.png](https://assets.leetcode.com/users/images/c2a7d8bc-46f7-4b1f-a62e-38e983083f00_1787656033.6942017.png)
*Image Source: LeetCode problem 1226. The Dining Philosophers*

