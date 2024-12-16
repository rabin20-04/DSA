# Length of Last Word - E

## Topics
- String Manipulation

## Problem Statement
Given a string `s` consisting of words and spaces, return the length of the last word in the string.

A word is defined as a maximal substring consisting of non-space characters only.

---

## Examples

### Example 1
**Input:**  
`s = "Hello World"`  
**Output:**  
`5`  
**Explanation:**  
The last word is `"World"` with length `5`.

---

### Example 2
**Input:**  
`s = "   fly me   to   the moon  "`  
**Output:**  
`4`  
**Explanation:**  
The last word is `"moon"` with length `4`.

---

### Example 3
**Input:**  
`s = "luffy is still joyboy"`  
**Output:**  
`6`  
**Explanation:**  
The last word is `"joyboy"` with length `6`.

---

## Constraints
- `1 <= s.length <= 10^4`
- `s` consists of only English letters and spaces `' '`.
- There will be at least one word in `s`.


i)
```python 
    class Solution:
        def lengthOfLastWord(self, s: str) -> int:
            split_word=s.split()
            words_length=len(split_word[-1])
            return words_length
            
 ```

ii)
```python
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        words = s.strip().split()
        
        if not words:
            return 0
        
        return len(words[-1])
```