
#include "core/object.hpp"
#include <iostream>

namespace game
{
    unsigned int Object::idCounter_ = 0;

    Object::Object() : id_(++idCounter_)
    {
        std::cout << id_ << " Creating " << typeid(*this).name() << " ";
    }

    Object::~Object()
    {
        std::cout << typeid(*this).name() << std::endl;
    }
}