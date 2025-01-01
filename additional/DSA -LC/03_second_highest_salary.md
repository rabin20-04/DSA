# 176. Second Highest Salary

## Problem Statement

Write a solution to find the second highest distinct salary from the `Employee` table. If there is no second highest salary, return `null` (or `None` in Pandas).

### Table: Employee

| Column Name | Type |
| ----------- | ---- |
| id          | int  |
| salary      | int  |

- `id` is the primary key (unique for each row).
- Each row contains salary information for an employee.

### Example 1

**Input:**
| id | salary |
|----|--------|
| 1 | 100 |
| 2 | 200 |
| 3 | 300 |

**Output:**
| SecondHighestSalary |
|---------------------|
| 200 |

### Example 2

**Input:**
| id | salary |
|----|--------|
| 1 | 100 |

**Output:**
| SecondHighestSalary |
|---------------------|
| null |

---

### i)

````python
    import pandas as pd

    def second_highest_salary(employee: pd.DataFrame) -> pd.DataFrame:
        df = employee.copy()
        df = df.drop_duplicates(subset='salary').sort_values('salary', ascending=False)
        if len(df) >=2:
            df = df.iloc[1]['salary']
            return pd.DataFrame(data=[df], columns=['SecondHighestSalary'])
        else:
            return pd.DataFrame(data=[None], columns=['SecondHighestSalary'])
           
````
