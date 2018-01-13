def stock_list(list_of_art, list_of_cat):
    if not list_of_cat or not list_of_art:
        return ""
    arts_in_cats = {cat: 0 for cat in list(map(lambda s: s.split(" ")[0][0], list_of_art))
                    if cat in list_of_cat}
    prices = ""
    for art in list_of_art:
        s = art.split(" ")
        if s[0][0] in list_of_cat:
            if s[0][0] in arts_in_cats.keys():
                arts_in_cats[s[0][0]] += int(s[1])
            else:
                arts_in_cats[s[0][0]] = int(s[1])
    for cat in list_of_cat:
        prices += "({} : {})".format(cat, arts_in_cats[cat])
        prices += " - "

    return prices.strip(" - ")
