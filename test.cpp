#include <type_traits>

class Base { };

template <typename T>
class A
{
public:
    template <typename U> requires(std::is_base_of_v<Base, U>)
    void foo(U obj);
};

template <typename T>
template <typename U> requires(std::is_base_of_v<Base, U>)
void A<T>::foo(U obj)
{
    /* ... */
}

int main()
{
    A<int> a;
    return 0;
}
