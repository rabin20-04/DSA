def convert_to_postfix(infix_input):
    precedence = {"^": 3, "*": 2, "/": 2, "+": 1, "-": 1}
    stack = []
    output = []

    for item in infix_input:
        if item.isalnum():
            output.append(item)
        elif item == "(":
            stack.append(item)
        elif item == ")":
            while stack and stack[-1] != "(":
                output.append(stack.pop())
            stack.pop()
        elif item in precedence:
            while (
                stack
                and stack[-1] in precedence
                and precedence[item] <= precedence[stack[-1]]
            ):
                output.append(stack.pop())
            stack.append(item)

    while stack:
        output.append(stack.pop())

    return "".join(output)


inp = input("Enter your expression: ")
output = convert_to_postfix(inp)
print("Postfix Expression:", output)


