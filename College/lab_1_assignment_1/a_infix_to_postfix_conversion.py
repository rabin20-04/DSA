def convert_to_postfix(infix_input):
    precedence_operators = {"$": 3, "^": 3, "*": 2, "/": 2, "+": 1, "-": 1}
    stack = []
    output = []

    for item in infix_input:
        if item == "(":
            stack.append(item)
        elif item.isalnum():
            output.append(item)
        elif item == ")":
            while stack[-1] != "(":
                pop_element = stack.pop()
                output.append(pop_element)
            if stack[-1] == "(":
                stack.pop()
        else:
            while (
                stack and stack[-1] != "("
                and precedence_operators[item] <= precedence_operators[stack[-1]]
            ):
                pop_elem = stack.pop()
                output.append(pop_elem)
            stack.append(item)

    while stack:
        output.append(stack.pop())

    return "".join(output)


inp = input("Enter your expression: ")
output = convert_to_postfix(inp)
print("Postfix Expression:", output)
