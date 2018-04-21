import unittest
from likes import likes


class LikeTests(unittest.TestCase):
    def test_that_likes_returns_no_one_on_empty_list(self):
        names = []
        self.assertEqual(likes(names), "no one likes this")

    def test_that_likes_returns_one_person(self):
        names = ["Peter"]
        self.assertEqual(likes(names), "Peter likes this")

    def test_likes_with_two_names(self):
        names = ["Jacob", "Alex"]
        self.assertEqual(likes(names), "Jacob and Alex like this")

    def test_likes_with_three_names(self):
        names = ["Max", "John", "Mark"]
        self.assertEqual(likes(names), "Max, John and Mark like this")

    def test_likes_with_multiple_names(self):
        names = ["Alex", "Jacob", "Mark", "Max"]
        self.assertEqual(likes(names), "Alex, Jacob and 2 others like this")


if __name__ == "__main__":
    unittest.main()
