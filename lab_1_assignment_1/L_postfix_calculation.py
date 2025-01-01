def evaluate_postfix(input_expression):
    expression_list = input_expression.split()
    astack = []
    operators = ("^", "*", "/", "-", "+")
    for item in expression_list:
        if item not in operators:
            astack.append(item)
        else:
            op1 = float(astack.pop())
            op2 = float(astack.pop())
            if item == "*":
                result = op2 * op1
            elif item == "+":
                result = op2 + op1
            elif item == "-":
                result = op2 - op1
            elif item == "^":
                result = op2**op1
            astack.append(result)
        
    return result


user_input = input("Enter an Expression : ")
result = evaluate_postfix(user_input)
print(f"Result of the expression is : {result}")

# 2 3 4 + 5*
