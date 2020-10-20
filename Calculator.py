def addition():
    a = float(input("Enter First Number:-"))
    b = float(input("Enter Second Number:-"))
    print("Sum of Entered numbers is ", a+b)
    print("1.)To calculate Again.\n2.)To exit program.\n3.)For main menu.")
    a = int(input("Enter the Choice:-"))
    if a == 1:
        addition()
    elif a == 3:
        runner()
    else:
        print("See you later!!Have a Nice day.")


def substract():
    a = float(input("Enter First Number:-"))
    b = float(input("Enter Second Number:-"))
    print("Result of Substraction is ", a-b)
    print("1.)To calculate Again.\n2.)To exit program.\n3.)For main menu.")
    a = int(input("Enter the Choice:-"))
    if a == 1:
        substract()
    elif a == 3:
        runner()
    else:
        print("See you later!!Have a Nice day.")


def multiply():
    a = float(input("Enter First Number:-"))
    b = float(input("Enter Second Number:-"))
    print("Product of These numbers is ", a*b)
    print("1.)To calculate Again.\n2.)To exit program.\n3.)For main menu.")
    a = int(input("Enter the Choice:-"))
    if a == 1:
        multiply()
    elif a == 3:
        runner()
    else:
        print("See you later!!Have a Nice day.")


def division():
    a = float(input("Enter Numenator:-"))
    b = float(input("Enter Denominator:-"))
    print("the result of Division is ", a/b)
    print("Integral part is ", int(a/b))
    print("Remainder is", a % b)
    print("1.)To calculate Again.\n2.)To exit program.\n3.)For main menu.")
    a = int(input("Enter the Choice:-"))
    if a == 1:
        division()
    elif a == 3:
        runner()
    else:
        print("See you later!!Have a Nice day.")


def power():
    a = int(input("Enter Base:-"))
    b = int(input("Enter Power:-"))
    print("Result is ", pow(a, b))
    print("1.)To calculate Again.\n2.)To exit program.\n3.)For main menu.")
    a = int(input("Enter the Choice:-"))
    if a == 1:
        power()
    elif a == 3:
        runner()
    else:
        print("See you later!!Have a Nice day.")


def runner():
    print("1.)For Addition.\n2.)For Substraction.\n3.)For Multiplication\n"
          "4.)For Division\n5.)For Power Calculation\n6.)To get ASCII Code.\n7.)For Decimal to binary."
          "\n8.)For Decimal to Octal.\n9.)For Decimal to Hexadecimal.")
    k = int(input("Enter The Choice:-"))
    if k == 1:
        addition()
    elif k == 2:
        substract()
    elif k == 3:
        multiply()
    elif k == 4:
        division()
    elif k == 5:
        power()
    elif k == 6:
        asc()
    elif k == 7:
        binar()
    elif k == 8:
        octal()
    elif k == 9:
        hexadecimal()
    else:
        print("You Have Enter a Wrong Input!!")


def asc():
    a = input("Enter The Character:-")
    print("ASCII Value is ", ord(a))
    print("1.)To calculate Again.\n2.)To exit program.\n3.)For main menu.")
    a = int(input("Enter the Choice:-"))
    if a == 1:
        asc()
    elif a == 3:
        runner()
    else:
        print("See you later!!Have a Nice day.")


def binar():
    a = int(input("Enter Decimal Number:-"))
    b = bin(a)
    print("Binary Output for this decimal number is", b[2:])
    print("1.)To calculate Again.\n2.)To exit program.\n3.)For main menu.")
    a = int(input("Enter the Choice:-"))
    if a == 1:
        binar()
    elif a == 3:
        runner()
    else:
        print("See you later!!Have a Nice day.")


def octal():
    a = int(input("Enter Number in decimal number number system:-"))
    b = oct(a)
    print("Octal output for the given number is ", b[2:])
    print("1.)To calculate Again.\n2.)To exit program.\n3.)For main menu.")
    a = int(input("Enter the Choice:-"))
    if a == 1:
        octal()
    elif a == 3:
        runner()
    else:
        print("See you later!!Have a Nice day.")


def hexadecimal():
    a = int(input("Enter Number in Decimal number system:-"))
    b = hex(a)
    print("Hexadecimal output for this number is ", b[2:])
    print("1.)To calculate Again.\n2.)To exit program.\n3.)For main menu.")
    a = int(input("Enter the Choice:-"))
    if a == 1:
        hexadecimal()
    elif a == 3:
        runner()
    else:
        print("See you later!!Have a Nice day.")


runner()
