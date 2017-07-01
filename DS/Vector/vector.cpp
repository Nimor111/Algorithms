#include "vector.hpp"

Vector::Vector()
{
    this->_capacity = 15;
    this->currentSize = 0;
    this->array = new int[this->_capacity];
}

Vector::~Vector()
{
    delete[] this->array;
}

Vector::Vector(Vector const & other)
{
    this->_capacity = other._capacity;
    this->currentSize = other.currentSize;
    this->array = new int[this->_capacity];
    for ( int i = 0; i < this->currentSize; i++ )
        this->array[i] = other.array[i];
}

Vector& Vector::operator=(Vector const & other)
{
    if ( this != &other )
    {
        delete[] this->array;
        this->_capacity = other._capacity;
        this->currentSize = other.currentSize;
        this->array = new int[this->_capacity];
        for ( int i = 0; i < this->currentSize; i++ )
            this->array[i] = other.array[i];
    }

    return *this;
}

bool Vector::checkCapacity() const
{
    return this->currentSize >= this->_capacity;
}

void Vector::addCapacity()
{
    this->_capacity = this->_capacity + 5;
}

int Vector::size() const
{
    return this->currentSize;
}

void Vector::insert(int index, int value)
{
    this->currentSize++;
    if ( this->checkCapacity() )
    {
        this->addCapacity();
    }
    for (int i = index + 1; i < this->currentSize; ++i)
    {
        this->array[i] = this->array[i - 1];
    }

    this->array[index] = value;
}

void Vector::print() const
{
    for ( int i = 0; i < this->currentSize; ++i )
    {
        std::cout << this->array[i] << " ";
    }
    std::cout << "\n";
}

void Vector::add(int value)
{
    this->array[this->currentSize++] = value;
    if ( this->checkCapacity() )
    {
        this->addCapacity();
    }
}

int Vector::capacity() const
{
    return this->_capacity;
}

int Vector::get(int index) const
{
    if ( index >= currentSize )
    {
        std::cerr << "No such element.\n";
    }
    return this->array[index];
}

int Vector::pop()
{
    if ( this->currentSize == 0 )
        std::cerr << "Vector is empty!\n";
    int element = this->array[this->currentSize - 1];
    this->currentSize--;
    return element;
}

void Vector::remove(int index)
{
    if ( index < 0 || index >= this->currentSize )
        std::cerr << "Index out of range!";
    for ( int i = index; i < this->currentSize; ++i )
        this->array[index] = this->array[index + 1];

    this->currentSize--;
}
