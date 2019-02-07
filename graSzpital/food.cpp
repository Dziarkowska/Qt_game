#include "food.h"
#include "patient.h"
#include "pineapple.h"
#include "grapes.h"
#include "peach.h"

Food::Food() :name(""){

}

Food::~Food(){

}

Food *Food::getFood(QString name)
{
    if (name == QString("pineapple"))
        return new Pineapple();
    else if (name == "peach")
        return new Peach();
    else if(name == "grapes")
        return new Grapes();
    else
        return 0;
}
