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

## Fixed Point Value
Les Fixed Point Values (valeurs en virgule fixe) sont une alternative aux nombres en virgule flottante (float, double). Ils sont souvent utilisés dans les systèmes embarqués, les jeux vidéo et les calculs nécessitant plus de précision et de performance.

__Qu'est-ce qu'un Fixed Point Value ?__
Un Fixed Point Value représente un nombre avec une précision fixe. Contrairement aux nombres en virgule flottante, où la position de la virgule peut changer (1.23 devient 123.0 * 10^-2), les Fixed Point Values utilisent une position fixe pour la virgule.

Exemple avec une base 2 :
  * En binaire, 1010.101 représente 10.625 en décimal.
  * Si on fixe la position de la virgule après 3 bits, ce nombre sera toujours interprété de la même façon.

__Pourquoi utiliser les Fixed Point Values ?__
| Avantage |	Explication |
|----------|--------------|
|Performance | Pas de conversion flottante, les opérations sont plus rapides sur certains processeurs. |
|Précision | Pas de problèmes d’arrondi comme avec les float et double. |
|Contrôle | La précision est fixe, ce qui évite les erreurs liées à la représentation des nombres flottants. |
| Compatibilité | Utilisé dans les systèmes embarqués où les unités FPU (Floating Point Unit) ne sont pas disponibles. |
	
	
__Représentation en C++__
Les Fixed Point Values sont souvent stockées sous forme d'entiers (int, long, int64_t). On choisit un nombre de bits pour la partie entière et la partie fractionnaire.

Exemple : 
  * représentation en Q8.8
  * Q8.8 signifie 8 bits pour la partie entière et 8 bits pour la partie fractionnaire.
  * Un entier de 16 bits est utilisé : xxxx xxxx . xxxx xxxx
  * Pour stocker 3.75 :
    * 3 → 00000011
    * 0.75 → 11000000 (0.75 × 256 = 192)
    * En mémoire : 00000011 11000000 (soit 0x03C0 en hexadécimal)

__Implémentation en C++__
```CPP
// Fixed.hpp
#include <ostream>
class               Fixed
    {
        public:
            Fixed(void); // Default constructor -> Canonical
            Fixed(const int intValue); // Custom CTOR
            Fixed(const float floatValue); // Custom CTOR
            Fixed(const Fixed &src); // Copy constructor -> Canonical
            virtual ~Fixed(void); // Virtaul Destructor -> Canonical

            Fixed               &operator=(const Fixed &src); // Assignation operator -> Canonical

            int                 getRawBits(void) const;
            static int          getFractionalBits(void);
            void                setRawBits(int const raw);

            float               toFloat(void) const;
            int                 toInt(void) const;

        private:
            int                 _fixedPointValue;
            static const int    _fractionalBits;
    };
#endif
std::ostream                    &operator<<(std::ostream &os,
                                            Fixed const &rhs);
```
```CPP
// Fixed.cpp
const int    Fixed::_fractionalBits = 8;

Fixed::Fixed(void)  : _fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

// int to fixed point value
Fixed::Fixed(const int intValue)  
            : _fixedPointValue(intValue << _fractionalBits)
{
    std::cout << "Int constructor called"<< std::endl;
}

// float to fixed point value
Fixed::Fixed(const float floatValue)
            : _fixedPointValue(roundf(floatValue * (1 << _fractionalBits)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}
Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

Fixed               &Fixed::operator=(const Fixed &src)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &src)
        this->_fixedPointValue = src.getRawBits();

    return *this;
}

int     Fixed::getRawBits(void) const
{
    return _fixedPointValue;
}

void    Fixed::setRawBits(int const raw)
{
    _fixedPointValue = raw;
}

int     Fixed::getFractionalBits(void)
{
    return _fractionalBits;
}

// fixedPointValue to float
float   Fixed::toFloat(void) const
{
    return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}

// fixedPointValue to int
int     Fixed::toInt(void) const
{
    return _fixedPointValue >> _fractionalBits;
}

std::ostream    &operator<<(std::ostream &os, Fixed const &rhs)
{
    return os << rhs.toFloat();
}
```

```CPP
// main.cpp
int     main(void)
{
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);
    
    a = Fixed(1234.4321f);

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    return 0;
}
```
__Explication__
* On stocke la valeur entière et fractionnaire en Q8.8.
* Décalage à gauche (<< FRACTIONAL_BITS) pour convertir un entier en Fixed Point.
* Multiplication par (1 << FRACTIONAL_BITS) pour convertir un float.

