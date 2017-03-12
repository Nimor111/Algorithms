from itertools import combinations


def mini_max(xs):
    combs = combinations(xs, 4)
    sums = [sum(x) for x in list(combs)]
    return [
        min(sums),
        max(sums)
    ]


def main():
    xs = range(1, 6)
    res = mini_max(list(xs))
    print(res[0], res[1])


if __name__ == '__main__':
    main()
