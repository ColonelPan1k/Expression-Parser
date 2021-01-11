# The translator portion of the expression evaluator


def processOp(stack, output, operator, precedence):
    opTop = stack.pop()
    topPrecedence = 0

    if opTop == '*' or opTop == '/':
        topPrecedence = 2
    elif opTop == '+' or opTop == '-':
        topPrecedence = 1
        print(topPrecedence)
    else:
        print("python u suck")

    if precedence > topPrecedence:
        print("PRECEDENCE")
        stack.append(opTop)
        stack.append(operator)
    elif precedence < topPrecedence:

        output.append(opTop)
        stack.append(operator)
    else:
        print("ELSE")


def translate(expression):
    stack = []
    output = ""

    for token in expression:
        if token == '+' or token == '-':
            if not stack:

                stack.append(token)
            else:
                processOp(stack, output, token, 1)

        elif token == '*' or token == '/':
            if not stack:

                stack.append(token)
            else:
                processOp(stack, output, token, 2)

        elif token == '(':
            stack.append('(')

        elif token == ')':
            while stack.pop() != '(':
                output += stack.pop()

        else:
            output += token

    # dump stack to output
    while stack:
        output += stack.pop()
        print(output)

    return ''.join(output)
