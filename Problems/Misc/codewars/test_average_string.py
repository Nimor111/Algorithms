import unittest
from average_string import average_string


class AverageStringTest(unittest.TestCase):
    def test_average_string_on_valid_data(self):
        nums = "zero nine five two"
        self.assertEqual(average_string(nums), "four")
        nums = "four six two three"
        self.assertEqual(average_string(nums), "three")
        nums = "one two three four five"
        self.assertEqual(average_string(nums), "three")
        nums = "five four"
        self.assertEqual(average_string(nums), "four")
        nums = "zero zero zero zero zero"
        self.assertEqual(average_string(nums), "zero")
        nums = "one one eight one"
        self.assertEqual(average_string(nums), "two")
        nums = "one"
        self.assertEqual(average_string(nums), "one")

    def test_average_string_on_invalid_data(self):
        nums = ""
        self.assertEqual(average_string(nums), "n/a")
        nums = "ten"
        self.assertEqual(average_string(nums), "n/a")
        nums = "pippi"
        self.assertEqual(average_string(nums), "n/a")


if __name__ == "__main__":
    unittest.main()
