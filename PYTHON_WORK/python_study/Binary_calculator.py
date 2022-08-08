def f(n: int):
    res = ''
    while n != 0:
        res = str(n % 2) + res
        n //= 2
    return res


if __name__ == '__main__':
    input_ = int(input("Please enter a decimal number:"))
    print(f(input_))
