/*
** IObject.hpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_05/EPITECH/D11/ex05/include
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Tue Jul 1 7:23:48 PM 2025 Paradis
** Last update Wed Jul 1 7:23:50 PM 2025 Paradis
*/

#ifndef 			    __IOBJECT_HPP__
	# define 		    __IOBJECT_HPP__

#include <iostream>
class	                IObject
{
    public:
        virtual ~IObject() = default;
        
        virtual void touch() = 0;

    protected:
    private:
};

class TestObject : public IObject {
public:
    TestObject(const std::string &name) : _name(name) {
        std::cout << _name << " is alive" << std::endl;
    }

    ~TestObject() override {
        std::cout << _name << " is dead" << std::endl;
    }

    void touch() override {
        std::cout << _name << " is touched" << std::endl;
    }

private:
    std::string _name;
};
#endif 				/* !_IOBJECT_HPP__ */
