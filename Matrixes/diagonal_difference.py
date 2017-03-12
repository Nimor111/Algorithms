
def primary_diagonal(matrix):
    """
    Return the sum of elements in the primary diagonal of a matrix
    """
    s = 0
    for i in range(len(matrix)):
        for j in range(len(matrix)):
            if i == j:
                s += matrix[i][j]

    return s


def secondary_diagonal(matrix):
    """
    Return the sum of elements in the secondary diagonal of a matrix
    """
    s = 0
    for i in range(len(matrix)):
        for j in range(len(matrix), -1, -1):
            if i + j == len(matrix) - 1:
                s += matrix[i][j]

    return s


def sum_of_diagonals(matrix):
    """
    Return absolute sum of two diagonals of a matrix
    """
    return abs(primary_diagonal(matrix) - secondary_diagonal(matrix))


def main():
    matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    print(sum_of_diagonals(matrix))


if __name__ == '__main__':
    main()
