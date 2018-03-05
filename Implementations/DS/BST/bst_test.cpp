#include "catch.hpp"
#include "bst.cpp"

TEST_CASE("it creates a bst", "[bst]")
{
    Bst<int> bst(5);

    REQUIRE(bst.get_root()->size == 1);
    REQUIRE(bst.get_root()->lsize == 0);
    REQUIRE(bst.get_root()->right == nullptr);
    REQUIRE(bst.get_root()->left == nullptr);

    SECTION("it inserts values correctly")
    {
        bst.insert(4);

        REQUIRE(bst.get_root()->size == 2);
        REQUIRE(bst.get_root()->lsize == 1);

        bst.insert(6);

        REQUIRE(bst.get_root()->size == 3);
        REQUIRE(bst.get_root()->lsize == 1);
    }

    SECTION("it removes values correctly")
    {
        bst.insert(4);
        bst.insert(3);

        REQUIRE(bst.get_root()->size == 3);
        REQUIRE(bst.get_root()->lsize == 2);

        bst.remove(4);

        REQUIRE(bst.get_root()->size == 2);
        REQUIRE(bst.get_root()->lsize == 1);
    }

    SECTION("it selects elements correctly")
    {
        REQUIRE(bst.select(0) == 5);

        bst.insert(6);
        bst.insert(4);

        REQUIRE(bst.select(1) == 5);
        REQUIRE(bst.select(0) == 4);
        REQUIRE(bst.select(2) == 6);
    }

    SECTION("it ranks elements correctly")
    {
        REQUIRE(bst.rank(5) == 0);

        bst.insert(6);
        bst.insert(4);

        REQUIRE(bst.rank(4) == 0);
        REQUIRE(bst.rank(5) == 1);
        REQUIRE(bst.rank(6) == 2);

        bst.remove(5);

        REQUIRE(bst.rank(6) == 1);
    }
}
