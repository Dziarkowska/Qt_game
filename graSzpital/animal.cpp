#include "animal.h"
#include "dog.h"
#include "cat.h"

Animal::Animal() :species(""){

}

Animal::~Animal(){

}

Animal *Animal::getAnimal(QString species)
{
    if (species == QString("dog"))
        return new Dog();
    else if (species == "cat")
        return new Cat();
    else
        return 0;
}
