def kangaroos_meet(a, b, c, d):
    """
    Can the two kangaroos ever meet?
    """
    if c > a and d > b or c == a and d > b:
        return "NO"
    if c < a and b > d or c == a and d < b:
        return "NO"
    kang1, kang2 = a, c
    steps = 0

    while True:
        kang1 += b
        kang2 += d
        steps += 1
        if kang2 - kang1 > max(b, d) and steps > 2500 \
           or kang1 - kang2 > max(b, d) and steps > 2500:
            return "NO"
        if kang1 == kang2:
            return "YES"


def main():
    x1, v1, x2, v2 = input().strip().split(' ')
    x1, v1, x2, v2 = [int(x1), int(v1), int(x2), int(v2)]
    print(kangaroos_meet(x1, v1, x2, v2))


if __name__ == '__main__':
    main()
