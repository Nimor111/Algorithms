def primary_diagonal(matrix):
    s = 0
    for i in range(len(matrix)):
        for j in range(len(matrix)):
            if i == j:
                s += matrix[i][j]

    return s


def secondary_diagonal(matrix):
    s = 0
    for i in range(len(matrix)):
        for j in range(len(matrix), -1, -1):
            if i + j == len(matrix) - 1:
                s += matrix[i][j]

    return s


def sum_of_diagonals(matrix):
    return abs(primary_diagonal(matrix) - secondary_diagonal(matrix))


def main():
    matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    print(sum_of_diagonals(matrix))


if __name__ == '__main__':
    main()
