#include "Animal.h"

using namespace std;
class Animal
{
public:

	string TypeAnimal;
	string Name;
	int warehouse = 0;
	int warehouse2 = 0;
	string food;

	Animal()
	{

	}
	virtual void eat()
	{
		cout << "���� �������� ";
	}
	virtual ~Animal()
	{


	}
};
