#include <iostream>
#include <string>>

using namespace std;

class Cat
{
  int id;
	string name;
  int age;
	int flat;

public:
	void setAge(int age)
	{
		if (age > 15)
		{
			age = 15;
		}
		this->age = age;
	}

	void setName(string name)
	{
		this->name = name;
	}

	void setFlat(int flat)
	{
		this->flat = flat;
	}

	void setID(int id)
	{
		this->id = id;
	}

	int getAge()
	{
		return age;
	}

	string getName() const
	{
		return name;
	}

	int getFlat()
	{
		return flat;
	}


	Cat(int id, string name, int age, int flat)
	{
		setID(id);
		setFlat(flat);
		setName(name);
		setAge(age);
	}

	// Cat(int id, string name, int age) 
	// {
	// 	setID(id);
	// 	setFlat(0);
	// 	setName(name);
	// 	setAge(age);
	// }

  Cat(int id, string name, int age) : Cat(id, name, age, 0)
  {}

  Cat() : Cat(0, "", 0, 0)
  {}

  ~Cat(){};

};


int main()
{
  Cat mc(1,"Барсик", 2, 25);

  cout << mc.getName() << " " << mc.getAge();
 
  
	return 0;
}