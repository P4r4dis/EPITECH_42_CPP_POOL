/*
** DroidFactory.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_02/EPITECH/D08/ex05/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Thu Mar 20 7:28:32 PM 2025 Paradis
** Last update Sat Mar 21 5:40:25 PM 2025 Paradis
*/

#ifndef 			__DROIDFACTORY_HPP__
	# define 		__DROIDFACTORY_HPP__

    #include <cstddef>
    
    #define RATIO_BASE  2
class	DroidFactory
{
    public:
        explicit        DroidFactory(size_t ratio = 2);
        explicit        DroidFactory(const DroidFactory &dFactory);

        DroidFactory    &operator=(const DroidFactory &dFactory);

        ~DroidFactory(void);

        size_t          getRatio(void) const;
        size_t          getIron(void) const;
        size_t          getSilicon(void) const;
        size_t          getWreck(void) const;

    protected:
    private:
        size_t          _ratio;
        size_t          _Iron;
        size_t          _Silicon;
        size_t          _Wreck;
};

#endif 				/* !__DROIDFACTORY_HPP___ */
