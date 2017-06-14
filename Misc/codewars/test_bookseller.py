import unittest
from bookseller import stock_list


class BooksellerTest(unittest.TestCase):

    def setUp(self):
        self.lib = ["ABAR 200", "CDXE 500", "BKWR 250", "BTSQ 890", "DRTY 600"]
        self.cats = ["A", "B"]

    def test_stock_list_works_correctly_for_setup_input(self):
        self.assertEqual(stock_list(self.lib, self.cats), "(A : 200) - (B : 1140)")


if __name__ == '__main__':
    unittest.main()
