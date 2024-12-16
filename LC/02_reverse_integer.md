# 7. Reverse Integer

## Difficulty
- Medium

## Topics
- Math
- String Manipulation

---

## Problem Statement
Given a signed 32-bit integer `x`, return `x` with its digits reversed. If reversing `x` causes the value to go outside the signed 32-bit integer range `[-2^31, 2^31 - 1]`, then return `0`.

**Note:** Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

---

## Examples

| **Input**   | **Output** | **Explanation**                |
|-------------|------------|--------------------------------|
| `x = 123`   | `321`      | The digits of `123` reversed. |
| `x = -123`  | `-321`     | The digits of `-123` reversed.|
| `x = 120`   | `21`       | The digits of `120` reversed. |

---



## Constraints
- `-2^31 <= x <= 2^31 - 1`


# -----------------------------

```python
class Solution:
    def reverse(self, x: int) -> int:
        INT_MIN, INT_MAX = -2**31, 2**31 - 1
        sign=-1 if x<0 else 1
        x=abs(x)
        d=0
        while x!=0:
            b=x%10
            x=x//10
            d=d*10+b
            if d>INT_MAX: 
             return 0
        return sign*d
```