/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex06/test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Thu Jan 30 5:26:48 PM 2025 Paradis
** Last update Wed Feb 4 4:28:33 PM 2025 Paradis
*/

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include "../../include/KoalaBot.hpp"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}


///////////////////////////////////////////////////////////////////////////////
//                                      Arms                                 //
///////////////////////////////////////////////////////////////////////////////
Test(Parts_Arms_class, Test_CTOR_isDefined, .init = redirect_all_stdout)
{
    Arms    arms;
    cr_assert_not_null(&arms);
}

Test(Parts_Arms_class,
Test_isFunctionnal_func_Catch_functionnal_default_parameter_of_CTOR,
.init = redirect_all_stdout)
{
    Arms    arms;
    
    cr_assert(arms.isFunctionnal() == true);
}

Test(Parts_Arms_class,
Test_isFunctionnal_func_Catch_functionnal_parameter_of_CTOR,
.init = redirect_all_stdout)
{
    Arms    arms("A-01", true);
    
    cr_assert(arms.isFunctionnal() == true);
}

Test(Parts_Arms_class,
Test_isFunctionnal_func_Catch_functionnal_parameter_of_CTOR_return_false,
.init = redirect_all_stdout)
{
    Arms    arms("A-01", false);
    
    cr_assert(arms.isFunctionnal() == false);
}

Test(Parts_Arms_class,
Test_serial_func_Catch_functionnal_default_parameter_of_CTOR,
.init = redirect_all_stdout)
{
    Arms    arms;
    
    cr_assert(arms.serial() == "A-01");
}

Test(Parts_Arms_class,
Test_serial_func_Catch_functionnal_parameter_of_CTOR,
.init = redirect_all_stdout)
{
    Arms    arms("A-01", true);
    
    cr_assert(arms.serial() == "A-01");
}

Test(Parts_Arms_class,
Test_information_func_print_functionnal_msg_on_stdout_with_tabulation,
.init = redirect_all_stdout)
{
    Arms    arms("A-01", true);
    
    arms.informations();
    cr_assert_stdout_eq_str(
        ("\t[Parts] Arms " + arms.serial() + " status : OK\n").c_str()
    );
}

Test(Parts_Arms_class,
Test_information_func_print_not_functionnal_msg_on_stdout_with_tabulation,
.init = redirect_all_stdout)
{
    Arms    arms("A-01", false);
    
    arms.informations();
    cr_assert_stdout_eq_str(
        ("\t[Parts] Arms " + arms.serial() + " status : KO\n").c_str()
    );
}

///////////////////////////////////////////////////////////////////////////////
//                                      Legs                                 //
///////////////////////////////////////////////////////////////////////////////
Test(Parts_Legs_class, Test_CTOR_isDefined, .init = redirect_all_stdout)
{
    Legs    legs;
    cr_assert_not_null(&legs);
}

Test(Parts_Legs_class,
Test_isFunctionnal_func_Catch_functionnal_default_parameter_of_CTOR,
.init = redirect_all_stdout)
{
    Legs    legs;
    
    cr_assert(legs.isFunctionnal() == true);
}

Test(Parts_Legs_class,
Test_isFunctionnal_func_Catch_functionnal_parameter_of_CTOR,
.init = redirect_all_stdout)
{
    Legs    legs("L-01", true);
    
    cr_assert(legs.isFunctionnal() == true);
}

Test(Parts_Legs_class,
Test_isFunctionnal_func_Catch_functionnal_parameter_of_CTOR_return_false,
.init = redirect_all_stdout)
{
    Legs    legs("L-01", false);
    
    cr_assert(legs.isFunctionnal() == false);
}

Test(Parts_Legs_class,
Test_serial_func_Catch_functionnal_default_parameter_of_CTOR,
.init = redirect_all_stdout)
{
    Legs    legs;
    
    cr_assert(legs.serial() == "L-01");
}

Test(Parts_Legs_class,
Test_serial_func_Catch_functionnal_parameter_of_CTOR,
.init = redirect_all_stdout)
{
    Legs    legs("L-01", true);
    
    cr_assert(legs.serial() == "L-01");
}

Test(Parts_Legs_class,
Test_information_func_print_functionnal_msg_on_stdout_with_tabulation,
.init = redirect_all_stdout)
{
    Legs    legs("L-01", true);
    
    legs.informations();
    cr_assert_stdout_eq_str(
        ("\t[Parts] Legs " + legs.serial() + " status : OK\n").c_str()
    );
}

Test(Parts_Legs_class,
Test_information_func_print_not_functionnal_msg_on_stdout_with_tabulation,
.init = redirect_all_stdout)
{
    Legs    legs("L-01", false);
    
    legs.informations();
    cr_assert_stdout_eq_str(
        ("\t[Parts] Legs " + legs.serial() + " status : KO\n").c_str()
    );
}

///////////////////////////////////////////////////////////////////////////////
//                                      Head                                 //
///////////////////////////////////////////////////////////////////////////////
Test(Parts_Head_class, Test_CTOR_isDefined, .init = redirect_all_stdout)
{
    Head    head;
    cr_assert_not_null(&head);
}

Test(Parts_Head_class,
Test_isFunctionnal_func_Catch_functionnal_default_parameter_of_CTOR,
.init = redirect_all_stdout)
{
    Head    head;
    
    cr_assert(head.isFunctionnal() == true);
}

Test(Parts_Head_class,
Test_isFunctionnal_func_Catch_functionnal_parameter_of_CTOR,
.init = redirect_all_stdout)
{
    Head    head("H-01", true);
    
    cr_assert(head.isFunctionnal() == true);
}

Test(Parts_Head_class,
Test_isFunctionnal_func_Catch_functionnal_parameter_of_CTOR_return_false,
.init = redirect_all_stdout)
{
    Head    head("H-01", false);
    
    cr_assert(head.isFunctionnal() == false);
}

Test(Parts_Head_class,
Test_serial_func_Catch_functionnal_default_parameter_of_CTOR,
.init = redirect_all_stdout)
{
    Head    head;
    
    cr_assert(head.serial() == "H-01");
}

Test(Parts_Head_class,
Test_serial_func_Catch_functionnal_parameter_of_CTOR,
.init = redirect_all_stdout)
{
    Head    head("H-01", true);
    
    cr_assert(head.serial() == "H-01");
}

Test(Parts_Head_class,
Test_information_func_print_functionnal_msg_on_stdout_with_tabulation,
.init = redirect_all_stdout)
{
    Head    head("H-01", true);
    
    head.informations();
    cr_assert_stdout_eq_str(
        ("\t[Parts] Head " + head.serial() + " status : OK\n").c_str()
    );
}

Test(Parts_Head_class,
Test_information_func_print_not_functionnal_msg_on_stdout_with_tabulation,
.init = redirect_all_stdout)
{
    Head    head("H-01", false);
    
    head.informations();
    cr_assert_stdout_eq_str(
        ("\t[Parts] Head " + head.serial() + " status : KO\n").c_str()
    );
}

///////////////////////////////////////////////////////////////////////////////
//                                      KoalaBot                             //
///////////////////////////////////////////////////////////////////////////////
Test(KoalaBot_class, Test_CTOR_isDefined, .init = redirect_all_stdout)
{
    KoalaBot    koalabot;
    cr_assert_not_null(&koalabot);
}

Test(KoalaBot_class,
Test_getSerial_func_Catch_default_parameter_of_CTOR,
.init = redirect_all_stdout)
{
    KoalaBot    koalabot;
    
    cr_assert(koalabot.getSerial() == "Bob-01");
}

Test(KoalaBot_class,
Test_getSerial_func_Catch_parameter_of_CTOR,
.init = redirect_all_stdout)
{
    KoalaBot    koalabot("C-3PO");
    
    cr_assert(koalabot.getSerial() == "C-3PO");
}

Test(KoalaBot_class,
Test_getArms_func_return_arms_variable_not_nullptr,
.init = redirect_all_stdout)
{
    KoalaBot    koalabot;
    
    cr_assert_not_null(koalabot.getArms());
}

Test(KoalaBot_class,
Test_getLegs_func_return_legs_variable_not_nullptr,
.init = redirect_all_stdout)
{
    KoalaBot    koalabot;
    
    cr_assert_not_null(koalabot.getLegs());
}

Test(KoalaBot_class,
Test_getHead_func_return_head_variable_not_nullptr,
.init = redirect_all_stdout)
{
    KoalaBot    koalabot;
    
    cr_assert_not_null(koalabot.getHead());
}
//////////////////////////////////////////////////////////////
    // cr_assert_stdout_eq_str((
    //     "Soldier " + skat.name() + " reporting " 
    //     + std::to_string(skat.stimPaks()) 
    //     + " stimpaks remaining sir!\n").c_str()
    // );
///////////////////////////////////////////////////////////////////////////////
//                                      MAIN                                 //
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
Test(main, test_main, .init = redirect_all_stdout)
{
    {
        // KoalaBot kb;
        // std::cout << std::boolalpha << kb.status() << std::endl;
        // kb.informations();
    }
    cr_assert_stdout_eq_str
    (
        "true\n"
        "[KoalaBot] Bob-01\n"
        "     [Parts] Head A-01 status : OK\n"
        "     [Parts] Head L-01 status : OK\n"
        "     [Parts] Head H-01 status : OK\n"
    );
}
