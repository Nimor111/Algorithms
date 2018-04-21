def get(lst, idx):
    try:
        return lst[idx]
    except IndexError:
        return None


def return_correct_state_for_zero_to_three(length, lst):
    return {
        0: "no one",
        1: "{}".format(get(lst, 0)),
        2: "{}".format(get(lst, 0)) + " and " + "{}".format(get(lst, 1)),
        3: "{}".format(get(lst, 0)) + ", " + "{}".format(get(lst, 1))
        + " and " + "{}".format(get(lst, 2)),
    }


def more_than_three(length, lst):
    return lst[0] + ", " + lst[1] + " and {} others".format(length - 2)


def append_likes_this(string):
    return string + " likes this"


def append_like_this(string):
    return string + " like this"


def likes(names):
    if type(names) != list:
        return None

    result = ""
    length = len(names)

    if length <= 3:
        state = return_correct_state_for_zero_to_three(length, names)[length]
        result += state
    else:
        result += more_than_three(length, names)

    if len(names) <= 1:
        result = append_likes_this(result)
    else:
        result = append_like_this(result)

    return result
