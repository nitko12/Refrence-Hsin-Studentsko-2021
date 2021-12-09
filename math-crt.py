# Python 3.6
from functools import reduce


def chinese_remainder(m, a):
    sum = 0
    prod = reduce(lambda acc, b: acc*b, m)
    for m_i, a_i in zip(m, a):
        p = prod // m_i
        sum += a_i * mul_inv(p, m_i) * p
    return sum % prod


def mul_inv(a, b):
    b0 = b
    x0, x1 = 0, 1
    if b == 1:
        return 1
    while a > 1:
        q = a // b
        a, b = b, a % b
        x0, x1 = x1 - q * x0, x0
    if x1 < 0:
        x1 += b0
    return x1


# x ≡ 1 (mod 3)
# x ≡ 1 (mod 4)
# x ≡ 0 (mod 7)
if __name__ == '__main__':
    m = [3, 4, 7]
    a = [1, 1, 0]
    print(chinese_remainder(m, a))  # 49
