#include "vector.hpp"

int main(int argc, char *argv[])
{
    Vector v;

    for ( int i = 0; i < 15; i++ )
        v.add(i);

    /* for ( int i = 0; i < 16; i++ ) */
    /*     std::cout << v.get(i) << " "; */

    for ( int i = 0; i < 15; i++ )
    {
        std::cout << v.pop() << " ";
    }
    v.pop();

    /* v.print(); */

    return 0;
}
