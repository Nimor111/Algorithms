import math


def num_to_word():
    return {
        0: 'zero',
        1: 'one',
        2: 'two',
        3: 'three',
        4: 'four',
        5: 'five',
        6: 'six',
        7: 'seven',
        8: 'eight',
        9: 'nine'
    }


def get_word_by_num(num):
    return num_to_word()[num]


def get_num_by_word(word):
    return [key for key, value in num_to_word().items() if value == word][0]


def validate_nums(word_nums):
    if len(word_nums) == 0:
        return False

    for word in word_nums:
        if word not in num_to_word().values():
            return False

    return True


def average(lst):
    if len(lst) == 0:
        return 0

    return sum(lst) / len(lst)


def average_string(words):
    word_nums = words.split()
    if not validate_nums(word_nums):
        return "n/a"

    nums = [get_num_by_word(word) for word in word_nums]

    return get_word_by_num(math.floor(average(nums)))
