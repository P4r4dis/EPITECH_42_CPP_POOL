# 42_cpp
Ce projet de l'école 42 contient 9 modules qui permettent de découvir le langage C++. Chaque module permet d'apprendre de nouvelles notions liées à l'orienté objet.
Tous les exercices doivent respectés **la forme canonique de Coplien**

# 💡 Notions
* Module 0 : Comprendre les spécificités du **langage C++** par rapport au C
* Module 1 : Aborde **Allocation mémoire**, **les références**, **les pointeurs** vers les membres et l'utilisation des **switch**
* Module 2 : Aborde le **polymorphisme ad hoc**, **les surcharges** et **les classes canoniques orthodoxes**
* Module 3 : Aborde **l'héritage**
* Module 4 : Aborde le **polymorphisme par sous-typage**, **les classes abstraites** et **les interfaces**
* Module 5 : Aborde les **Try/Catch et les exceptions**
* Module 6 : Aborde les différents **casts**
* Module 7 : Aborde **les templates**
* Module 8 : Aborde **les containeurs, les itérateurs et les algorithmes basés sur des templates**
* Module 9 : Aborde **les containeurs** et **les algorithmes**

___
## Polymorphisme ad hoc / surcharge de fonctions:
La surcharge de fonction permet de définir plusieurs fonctions ayant le même nom mais prenant des paramètres différents.

```CPP
class Sample 
{
 public:
  Sample(void);
  ~Sample(void);

 // 4 surcharges
 void bar(char const c) const;
 void bar(int const c) const;
 void bar(float const z) const;
 void bar(Sample const &i) const;
}
```

La surcharge de fonction est également possible sur des fonctions qui ne sont pas des fonctions de classe / d’instance.

## Surcharge d’opérateur
Il existe plusieurs types d’opérateurs (les opérateurs arithmétique +, les opérateurs d’assignation =, les opérateurs de redirection <<, etc...).

De plus, il existe des opérateurs unaires (pré incrémentation ou post incrémentation), binaires (assignation, arithmétique) et ternaires (les ternaires n’étant pas surchargeables).

```CPP
#include <iostream>

class Sample
{
 public:
  Sample(int const n);
  ~Sample(void);

  int getValue(void) const;
  //Le mot clé operator permet d'indiquer qu'il s'agit d'une surcharge d'opérateur
  
  //Operateur d'assignation (binaire) - notation sous forme de fonction membre
  Sample &operator=(Sample const &rhs);//deux params (this, instance courante)
  Sample operator+(Sample const &rhs) const;

 private:
  int _n;
}
std::ostream &operator<<(std::ostream &o, Sample const &rhs);
```

```CPP
// Nous devons retourner une reference sur l'instance courante pour permettre de chainer les assignations
// a = b = c = d;
Integer &Integer::operator=(Integer const &rhs)
{
 this->_n = rhs.getValue();
 return *this;//Une référence est toujours déréférencée
}

// Nous devons uniquement retourner une copie du résultat ici
Integer Integer::operator+(Integer const &rhs) const
{
 return Integer(this->_n + rhs.getValue());
}

// Autre opérateur binaire mais ni de classe ni d'instance
// surcharge de fonction 
// on retourne une reference sur ostream pour pouvoir effectuer des chaînages
std::ostream &operator<<(std::ostream &o, Integer const &rhs)
{
 o << rhs.getValue();
 return (o);
}
```

Il est plutôt recommandé d’éviter de réaliser des surcharges d’opérateurs, en particulier pour les débutants. Il existe de réels cas d’usage qui les rendent nécessaires, mais ils sont relativement limités.

Cette notion est cependant particulièrement pertinente pour écrire une classe de façon canonique.

## Classe canonique
Il est recommandé d’écrire ses classes de manière canonique. Il s’agit plutôt d’une bonne pratique / respect d’une convention plutôt que d’une nécessité technique.

```CPP
#include <iostream>

class Sample 
{
 public:
  // Default Constructor (without parameters)
  Sample(void); // -> Canonical

  // Custom Constructor
  Sample(int a);

  // Copy Constructor (take an instance of Sample class as parameter) 
  Sample(Sample const &src); // -> Canonical

  // Virtaul Destructor
  virtual ~Sample(void); // -> Canonical

  // Assignment Operator
  Sample &operator=(Sample const &rhs); // -> Canonical
}
```
Lorsque l’on implémentera des fonctions via le polymorphisme par sous typage, on préférera souvent utiliser le mot clé __virtual__.

On appellera aussi ces fonctions des méthodes.

Le mot clé __virtual__ va permettre d’avoir un linkage dynamique et non plus statique / à la compilation (”at runtime” / à l’exécution).

Notez que l’utilisation de __virtual__ vous permettra d’éviter d’avoir des fuites de mémoire (leaks) dans ce cas précis (problèmes au niveau du destructeur appelé si la résolution est statique).