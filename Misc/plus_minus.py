def plus_minus(xs):
    pos = neg = zero = 0
    for element in xs:
        if element == 0:
            zero += 1
        elif element > 0:
            pos += 1
        else:
            neg += 1
    print(pos, neg, zero)
    return [pos/len(xs), neg/len(xs), zero/len(xs)]


def main():
    xs = [-4, 3, -9, 0, 4, 1]
    res = plus_minus(xs)
    print(list(map(lambda x: round(x, 6), res)))


if __name__ == '__main__':
    main()
