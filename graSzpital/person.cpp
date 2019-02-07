#include "person.h"

Person::Person(QString n, int p, int m, int s, int w){
    name = n;
    php = p;
    mhp = m;
    strength = s;
    wisdom = w;
}

Person::Person(){

}

Person::~Person(){

}

QString Person::getName(){
    return name;
}

void Person::setName(QString newName){
    name = newName;
}

int Person::getPhp(){
    return php;
}

void Person::setPhp(int newphp){
    php = newphp;
}

int Person::getMhp(){
return mhp;
}

void Person::setMhp(int newmhp){
mhp = newmhp;
}

int Person::getStrength(){
    return strength;
}

void Person::setStrength(int newstrength){
    strength = newstrength;
}

int Person::getWisdom(){
return wisdom;
}

void Person::setWisdom(int newwisdom){
wisdom = newwisdom;
}

void Person::show(){

}

