#include "bst.cpp"

int main(int argc, char* argv[])
{
    Bst<int> bst(5);
    bst.insert(4);
    bst.insert(6);
    bst.insert(3);
    bst.insert(7);
    bst.insert(9);
    bst.insert(8);
    bst.insert(2);
    bst.print();

    /* bst.remove(2); */
    /* bst.remove(4); */

    /* std::cout << bst.depth() << std::endl; */
    /* std::cout << bst.get_root()->lsize << std::endl; */
    /* std::cout << bst.get_root()->size << std::endl; */
    /* std::cout << bst.select(3) << std::endl; */
    /* std::cout << bst.select(4) << std::endl; */
    /* std::cout << bst.select(6) << std::endl; */
    /* std::cout << bst.rank(3) << std::endl; */
    /* std::cout << bst.rank(4) << std::endl; */
    /* std::cout << bst.rank(5) << std::endl; */
    /* std::cout << bst.rank(6) << std::endl; */
    /* std::cout << bst.rank(8) << std::endl; */
    /* std::cout << bst.rank(9) << std::endl; */

    return 0;
}
