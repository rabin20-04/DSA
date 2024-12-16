# Sum Game

## Difficulty
- Medium

## Topics
- Game Theory
- String Manipulation

---

## Problem Statement
Alice and Bob take turns playing a game, with Alice starting first.

You are given a string `num` of even length consisting of digits and `'?'` characters. On each turn, a player will:

1. Choose an index `i` where `num[i] == '?'`.
2. Replace `num[i]` with any digit between `'0'` and `'9'`.

The game ends when there are no more `'?'` characters in `num`.

- Bob wins if the sum of the digits in the first half of `num` equals the sum in the second half.
- Alice wins if the sums are not equal.

### Example
- If the game ends with `num = "243801"`, Bob wins because `2+4+3 = 8+0+1`.
- If the game ends with `num = "243803"`, Alice wins because `2+4+3 != 8+0+3`.

Assuming Alice and Bob play optimally, return `true` if Alice will win and `false` if Bob will win.

---

## Examples

| **Input**             | **Output** | **Explanation**                                                                                                     |
|------------------------|------------|---------------------------------------------------------------------------------------------------------------------|
| `num = "5023"`        | `false`    | The sum of the first half is equal to the sum of the second half: `5 + 0 = 2 + 3`.                                   |
| `num = "25??"`        | `true`     | Alice can replace one of the `'?'`s with `9`, making it impossible for Bob to equalize the sums.                    |
| `num = "?3295???"`    | `false`    | Bob always wins, e.g.:<br>- Alice: `num = "93295???"`<br>- Bob: `num = "932959??"`<br>- Final: `93295927`.           |

---

## Constraints
- `2 <= num.length <= 10^5`
- `num.length` is even.
- `num` consists of only digits and `'?'`.
