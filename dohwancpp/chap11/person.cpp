#include "person.h"

Person::Person()
:identity(0)
{
}
Person::Person(long id)
:identity(id)
{
	assert(identity >= 100000000 && identity <= 999999999);
}
Person::Person(const Person& person)
:identity(person.identity)
{
}
Person::~Person(){}

void Person::print() const{
	cout << "identity : "<< identity <<endl;
}
