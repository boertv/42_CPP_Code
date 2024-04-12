#include <iostream>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int	main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
std::cout << "> learning 5th Materia ...\n";
	AMateria* ice = new Ice();
	src->learnMateria(ice);
	delete ice;

	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");
std::cout << "> using empty Materia slots ...\n";
	me->use(0, *bob);
	me->use(1, *bob);
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
std::cout << "> equiping 5th Materia ...\n";
	tmp = src->createMateria("ice");
	me->equip(tmp);

	me->use(0, *bob);
	me->use(1, *bob);
std::cout << "> swapping Materia ...\n";
	me->unequip(1);
	me->equip(tmp);
	me->use(1, *bob);
	me->unequip(1);
	me->unequip(2);

	delete bob;
	delete me;
	delete src;
}
