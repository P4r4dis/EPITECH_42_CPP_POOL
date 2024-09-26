/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex03/test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Thu Sep 26 6:43:34 PM 2024 Paradis
** Last update Fri Sep 26 7:32:53 PM 2024 Paradis
*/

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include "../../include/Federation.hpp"
#include "../../include/WarpSystem.hpp"
#include "../../include/Borg.hpp"
#include "../../include/Destination.hpp"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}


///////////////////////////////////////////////////////////////////////////////
//                      Federation::Starfleet::Ship                          //
///////////////////////////////////////////////////////////////////////////////

Test(
Federation_Starfleet_Ship,
test_Federation_Starfleet_Ship_isDefined,
.init = redirect_all_stdout)
{
    Federation::Starfleet::Ship     UssKreog(289, 132, "Kreog", 6);
    Federation::Starfleet::Ship     UssKreog2(289, 132, "Kreog", 6, 10);

    cr_assert_not_null(&UssKreog);
    cr_assert_not_null(&UssKreog2);
}

Test(
Federation_Starfleet_Ship,
test_Federation_Starfleet_Ship_CTOR_std_output,
.init = redirect_all_stdout)
{
    {
        Federation::Starfleet::Ship     UssKreog(289, 132, "Kreog", 6);
        Federation::Starfleet::Ship     UssKreog2(289, 132, "Kreog", 6, 10);

    }
    cr_assert_stdout_eq_str
    (
        "The ship USS Kreog has been finished.\n"
        "It is 289 m in length and 132 m in width.\n"
        "It can go to Warp 6!\n"
        "The ship USS Kreog has been finished.\n"
        "It is 289 m in length and 132 m in width.\n"
        "It can go to Warp 6!\n"
        "Weapons are set: 10 torpedoes ready.\n"
    );
}

Test(
Federation_Starfleet_Ship,
test_Federation_Starfleet_Ship_setupCore_std_output,
.init = redirect_all_stdout)
{
    {
        Federation::Starfleet::Ship     UssKreog(289, 132, "Kreog", 6);
        WarpSystem::QuantumReactor QR;
        WarpSystem::Core core(&QR);

        UssKreog.setupCore(&core);
    }
    cr_assert_stdout_eq_str
    (
        "The ship USS Kreog has been finished.\n"
        "It is 289 m in length and 132 m in width.\n"
        "It can go to Warp 6!\n"
        "USS Kreog: The core is set.\n"
    );
}

Test(
Federation_Starfleet_Ship,
test_Federation_Starfleet_Ship_setupCore_with_NULLPTR_stderr_output,
.init = redirect_all_stdout)
{
    {
        Federation::Starfleet::Ship     UssKreog(289, 132, "Kreog", 6);

        UssKreog.setupCore(NULL);
    }
    cr_assert_stdout_eq_str
    (
        "The ship USS Kreog has been finished.\n"
        "It is 289 m in length and 132 m in width.\n"
        "It can go to Warp 6!\n"
    );
    cr_assert_stderr_eq_str
    (
        "USS Kreog: The core is not set.\n"
    );
}

Test(
Federation_Starfleet_Ship,
test_Federation_Starfleet_Ship_checkCore_is_stable_std_output,
.init = redirect_all_stdout)
{
    {
        Federation::Starfleet::Ship     UssKreog(289, 132, "Kreog", 6);
        WarpSystem::QuantumReactor QR;
        WarpSystem::Core core(&QR);

        UssKreog.setupCore(&core);
        UssKreog.checkCore();
    }
    cr_assert_stdout_eq_str
    (
        "The ship USS Kreog has been finished.\n"
        "It is 289 m in length and 132 m in width.\n"
        "It can go to Warp 6!\n"
        "USS Kreog: The core is set.\n"
        "USS Kreog: The core is stable at the time.\n"
    );
}

Test(
Federation_Starfleet_Ship,
test_Federation_Starfleet_Ship_checkCore_is_unstable_std_output,
.init = redirect_all_stdout)
{
    {
        Federation::Starfleet::Ship     UssKreog(289, 132, "Kreog", 6);
        WarpSystem::QuantumReactor QR;

        QR.setStability(false);
        WarpSystem::Core core(&QR);

        UssKreog.setupCore(&core);
        UssKreog.checkCore();
    }
    cr_assert_stdout_eq_str
    (
        "The ship USS Kreog has been finished.\n"
        "It is 289 m in length and 132 m in width.\n"
        "It can go to Warp 6!\n"
        "USS Kreog: The core is set.\n"
        "USS Kreog: The core is unstable at the time.\n"
    );
}

Test(
Federation_Starfleet_Ship,
test_Federation_Starfleet_Ship_promote_no_captain_stderr_output,
.init = redirect_all_stdout)
{
    {
        Federation::Starfleet::Ship     UssKreog(289, 132, "Kreog", 6);
        UssKreog.promote(nullptr);
    }
    cr_assert_stdout_eq_str
    (
        "The ship USS Kreog has been finished.\n"
        "It is 289 m in length and 132 m in width.\n"
        "It can go to Warp 6!\n"
    );
    cr_assert_stderr_eq_str
    (
        "Error: No Captain to promote.\n"
    );
}

Test(
Federation_Starfleet_Ship,
test_Federation_Starfleet_Ship_getName,
.init = redirect_all_stdout)
{
    {
        Federation::Starfleet::Ship     UssKreog(289, 132, "Kreog", 6);

        cr_assert(UssKreog.getName() == "Kreog");
    }
}

Test(
Federation_Starfleet_Ship,
test_Federation_Starfleet_Ship_getLocation,
.init = redirect_all_stdout)
{
    {
        Federation::Starfleet::Ship     UssKreog(289, 132, "Kreog", 6);

        cr_assert(UssKreog.getLocation() == Destination::EARTH);
    }
}

Test(
Federation_Starfleet_Ship,
test_Federation_Starfleet_Ship_getMaxWarp,
.init = redirect_all_stdout)
{
    {
        Federation::Starfleet::Ship     UssKreog(289, 132, "Kreog", 6);

        cr_assert(UssKreog.getMaxWarp() == 6);
    }
}

Test(
Federation_Starfleet_Ship,
test_Federation_Starfleet_Ship_promote_captain_stdout_output,
.init = redirect_all_stdout)
{
    {
        Federation::Starfleet::Ship     UssKreog(289, 132, "Kreog", 6);
        Federation::Starfleet::Captain  James("James T. Kirk");

        UssKreog.promote(&James);
        cr_assert_stdout_eq_str
        (
            (
                "The ship USS Kreog has been finished.\n"
                "It is 289 m in length and 132 m in width.\n"
                "It can go to Warp 6!\n"
                "James T. Kirk: I'm glad to be the captain of the USS " + UssKreog.getName() + ".\n"
            ).c_str()
        );
    }

}

Test(
Federation_Starfleet_Ship,
test_Federation_Starfleet_Ship_error_move_because_warp_superior_to_maxWarp,
.init = redirect_all_stdout)
{
    {
        Federation::Starfleet::Ship     UssKreog(289, 132, "Kreog", 6);
        WarpSystem::QuantumReactor QR;
        WarpSystem::Core core(&QR);
        
        UssKreog.setupCore(&core);
        cr_assert(UssKreog.move(30, Destination::VULCAN) == false);
        cr_assert(UssKreog.getLocation() != Destination::VULCAN);
        cr_assert(UssKreog.getLocation() == Destination::EARTH);
    }
}

Test(
Federation_Starfleet_Ship,
test_Federation_Starfleet_Ship_error_move_because_destination_is_not_different_of_the_current_location_of_the_ship,
.init = redirect_all_stdout)
{
    {
        Federation::Starfleet::Ship     UssKreog(289, 132, "Kreog", 6);
        WarpSystem::QuantumReactor QR;
        WarpSystem::Core core(&QR);

        UssKreog.setupCore(&core);
        cr_assert(UssKreog.move(30, Destination::VULCAN) == false);
        cr_assert(UssKreog.move(1, Destination::EARTH) == false);
        cr_assert(UssKreog.getLocation() != Destination::VULCAN);
        cr_assert(UssKreog.getLocation() == Destination::EARTH);
    }
}

Test(
Federation_Starfleet_Ship,
test_Federation_Starfleet_Ship_error_move_because_coreReactor_is_not_stable,
.init = redirect_all_stdout)
{
    {
        Federation::Starfleet::Ship     UssKreog(289, 132, "Kreog", 6);
        WarpSystem::QuantumReactor QR;
        WarpSystem::Core core(&QR);
        core.checkReactor()->setStability(false);
        UssKreog.setupCore(&core);
        cr_assert(UssKreog.move(30, Destination::VULCAN) == false);
        cr_assert(UssKreog.move(1, Destination::EARTH) == false);
        cr_assert(UssKreog.move(1, Destination::VULCAN) == false);

        cr_assert(UssKreog.getLocation() != Destination::VULCAN);
        cr_assert(UssKreog.getLocation() == Destination::EARTH);
    }
}

Test(
Federation_Starfleet_Ship,
test_Federation_Starfleet_Ship_function_move_with_warp_param_and_destination_param,
.init = redirect_all_stdout)
{
    {
        Federation::Starfleet::Ship     UssKreog(289, 132, "Kreog", 6);
        WarpSystem::QuantumReactor QR;
        WarpSystem::Core core(&QR);
        UssKreog.setupCore(&core);

        cr_assert(UssKreog.getLocation() == Destination::EARTH);
        cr_assert(UssKreog.move(1, Destination::VULCAN) == true);
        cr_assert(UssKreog.getLocation() == Destination::VULCAN);
    }
}

Test(
Federation_Starfleet_Ship,
test_Federation_Starfleet_Ship_function_move_with_warp_param,
.init = redirect_all_stdout)
{
    {
        Federation::Starfleet::Ship     UssKreog(289, 132, "Kreog", 6);
        WarpSystem::QuantumReactor QR;
        WarpSystem::Core core(&QR);
        UssKreog.setupCore(&core);

        cr_assert(UssKreog.getLocation() == Destination::EARTH);
        cr_assert(UssKreog.move(1, Destination::VULCAN) == true);
        cr_assert(UssKreog.getLocation() == Destination::VULCAN);
        cr_assert(UssKreog.move(1) == true);
    }
}

Test(
Federation_Starfleet_Ship,
test_Federation_Starfleet_Ship_function_move_with_destination_param,
.init = redirect_all_stdout)
{
    {
        Federation::Starfleet::Ship     UssKreog(289, 132, "Kreog", 6);
        WarpSystem::QuantumReactor QR;
        WarpSystem::Core core(&QR);
        UssKreog.setupCore(&core);

        cr_assert(UssKreog.getLocation() == Destination::EARTH);
        cr_assert(UssKreog.move(1, Destination::VULCAN) == true);
        cr_assert(UssKreog.getLocation() == Destination::VULCAN);
        cr_assert(UssKreog.move(1) == true);
        cr_assert(UssKreog.getLocation() == Destination::EARTH);
        cr_assert(UssKreog.move(Destination::VULCAN) == true);
    }
}

Test(
Federation_Starfleet_Ship,
test_Federation_Starfleet_Ship_function_move_without_param,
.init = redirect_all_stdout)
{
    {
        Federation::Starfleet::Ship     UssKreog(289, 132, "Kreog", 6);
        WarpSystem::QuantumReactor QR;
        WarpSystem::Core core(&QR);
        UssKreog.setupCore(&core);

        cr_assert(UssKreog.getLocation() == Destination::EARTH);
        cr_assert(UssKreog.move(1, Destination::VULCAN) == true);
        cr_assert(UssKreog.getLocation() == Destination::VULCAN);
        cr_assert(UssKreog.move() == true);
        cr_assert(UssKreog.getLocation() == Destination::EARTH);
    }
}

Test(
Federation_Starfleet_Ship,
test_Federation_Starfleet_Ship_getShield,
.init = redirect_all_stdout)
{
    {
        Federation::Starfleet::Ship     UssKreog(289, 132, "Kreog", 6);

        cr_assert(UssKreog.getShield() == 100);
    }
}

Test(
Federation_Starfleet_Ship,
test_Federation_Starfleet_Ship_setShield,
.init = redirect_all_stdout)
{
    {
        Federation::Starfleet::Ship     UssKreog(289, 132, "Kreog", 6);

        cr_assert(UssKreog.getShield() == 100);
        UssKreog.setShield(10);
        cr_assert(UssKreog.getShield() == 10);
    }
}

Test(
Federation_Starfleet_Ship,
test_Federation_Starfleet_Ship_getTorpedo,
.init = redirect_all_stdout)
{
    {
        Federation::Starfleet::Ship     UssKreog(289, 132, "Kreog", 6, 10);

        cr_assert(UssKreog.getTorpedo() == 10);
    }
}

Test(
Federation_Starfleet_Ship,
test_Federation_Starfleet_Ship_setTorpedo,
.init = redirect_all_stdout)
{
    {
        Federation::Starfleet::Ship     UssKreog(289, 132, "Kreog", 6, 10);

        cr_assert(UssKreog.getTorpedo() == 10);
        UssKreog.setTorpedo(1);
         cr_assert(UssKreog.getTorpedo() == 1);
       
    }
}
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//                      Federation::Starfleet::Captain                       //
///////////////////////////////////////////////////////////////////////////////

Test(
Federation_Starfleet_Captain,
test_Federation_Starfleet_Captain_isDefined,
.init = redirect_all_stdout)
{
    Federation::Starfleet::Captain James("James T. Kirk");
    cr_assert_not_null(&James);
}

Test(
Federation_Starfleet_Captain,
test_Federation_Starfleet_Captain_getName,
.init = redirect_all_stdout)
{
    Federation::Starfleet::Captain James("James T. Kirk");

    cr_assert(James.getName() == "James T. Kirk");
}


Test(
Federation_Starfleet_Captain,
test_Federation_Starfleet_Captain_setAge,
.init = redirect_all_stdout)
{
    Federation::Starfleet::Captain James("James T. Kirk");

    cr_assert(James.getAge() == 0);
    James.setAge(50);
    cr_assert(James.getAge() == 50);
}

Test(
Federation_Starfleet_Captain,
test_Federation_Starfleet_Captain_getAge,
.init = redirect_all_stdout)
{
    Federation::Starfleet::Captain James("James T. Kirk");
    cr_assert(James.getAge() == 0);
}

///////////////////////////////////////////////////////////////////////////////
//                      Federation::Starfleet::Ensign                        //
///////////////////////////////////////////////////////////////////////////////

Test(
Federation_Starfleet_Ensign,
test_Federation_Starfleet_Ensign_isDefined,
.init = redirect_all_stdout)
{
    Federation::Starfleet::Ensign Ensign("Pavel Chekov");
    cr_assert_not_null(&Ensign);
}
Test(
Federation_Starfleet_Ensign,
test_Federation_Starfleet_Ensign_CTOR_stdout_output,
.init = redirect_all_stdout)
{
    Federation::Starfleet::Ensign Ensign("Pavel Chekov");
    cr_assert_stdout_eq_str(
        "Ensign Pavel Chekov, awaiting orders.\n"
    );
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//                      WarpSystem::QuantumReactor                           //
///////////////////////////////////////////////////////////////////////////////

Test(
WarpSystem_QuantumReactor,
test_WarpSystem_QuantumReactor_isDefined,
.init = redirect_all_stdout)
{
    WarpSystem::QuantumReactor QR;
    cr_assert_not_null(&QR);
}

Test(
WarpSystem_QuantumReactor,
test_WarpSystem_QuantumReactor_isStable,
.init = redirect_all_stdout)
{
    WarpSystem::QuantumReactor QR;

    cr_assert(QR.isStable() == true);
}

Test(
WarpSystem_QuantumReactor,
test_WarpSystem_QuantumReactor_setStability,
.init = redirect_all_stdout)
{
    WarpSystem::QuantumReactor QR;

    cr_assert(QR.isStable() == true);
    QR.setStability(false);
    cr_assert(QR.isStable() == false);
}

Test(
WarpSystem_Core,
test_Warpsystem_Core_isDefined,
.init = redirect_all_stdout)
{
    WarpSystem::QuantumReactor QR;
    cr_assert_not_null(&QR);
    cr_assert(QR.isStable() == true);

    WarpSystem::Core core(&QR);
    cr_assert_not_null(&core);

}

Test(
WarpSystem_Core,
test_Warpsystem_Core_checkReactor_allow_provide_access_to_pointer_QuantumReactor,
.init = redirect_all_stdout)
{
    WarpSystem::QuantumReactor QR;
    WarpSystem::Core core(&QR);

    cr_assert(core.checkReactor()->isStable() == true);
    core.checkReactor()->setStability(false);
    cr_assert(core.checkReactor()->isStable() == false);
}
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//                             Federation::Ship                              //
///////////////////////////////////////////////////////////////////////////////

Test(
Federation_Ship,
test_Federation_Ship_isDefined,
.init = redirect_all_stdout)
{
    Federation::Ship     Independent(150, 230, "Greok");
    cr_assert_not_null(&Independent);
}

Test(
Federation_Ship,
test_Federation_Ship_CTOR_std_output,
.init = redirect_all_stdout)
{
    {
        Federation::Ship     Independent(150, 230, "Greok");
    }
    cr_assert_stdout_eq_str
    (
        "The independent ship Greok just finished its construction.\n"
        "It is 150 m in length and 230 m in width.\n"
    );
}

Test(
Federation_Ship,
test_Federation_Ship_getMaxWarp,
.init = redirect_all_stdout)
{
    {
        Federation::Ship     Independent(150, 230, "Greok");
        cr_assert(Independent.getMaxWarp() == 1);
    }
}

Test(
Federation_Ship,
test_Federation_Ship_setupCore_std_output,
.init = redirect_all_stdout)
{
    {
        Federation::Ship     Independent(150, 230, "Greok");
        WarpSystem::QuantumReactor QR;
        WarpSystem::Core core(&QR);

        Independent.setupCore(&core);
    }
    cr_assert_stdout_eq_str
    (
        "The independent ship Greok just finished its construction.\n"
        "It is 150 m in length and 230 m in width.\n"
        "Greok: The core is set.\n"
    );
}

Test(
Federation_Ship,
test_Federation_Ship_setupCore_with_NULLPTR_stderr_output,
.init = redirect_all_stdout)
{
    {
        Federation::Ship     Independent(150, 230, "Greok");

        Independent.setupCore(NULL);
    }
    cr_assert_stdout_eq_str
    (
        "The independent ship Greok just finished its construction.\n"
        "It is 150 m in length and 230 m in width.\n"
    );
    cr_assert_stderr_eq_str
    (
        "Greok: The core is not set.\n"
    );
}

Test(
Federation_Ship,
test_Federation_Ship_checkCore_is_stable_std_output,
.init = redirect_all_stdout)
{
    {
        Federation::Ship     Independent(150, 230, "Greok");
        WarpSystem::QuantumReactor QR;
        WarpSystem::Core core(&QR);

        Independent.setupCore(&core);
        Independent.checkCore();
    }
    cr_assert_stdout_eq_str
    (
        "The independent ship Greok just finished its construction.\n"
        "It is 150 m in length and 230 m in width.\n"
        "Greok: The core is set.\n"
        "Greok: The core is stable at the time.\n"
    );
}

Test(
Federation_Ship,
test_Federation_Ship_checkCore_is_unstable_std_output,
.init = redirect_all_stdout)
{
    {
        Federation::Ship     Independent(150, 230, "Greok");
        WarpSystem::QuantumReactor QR;

        QR.setStability(false);
        WarpSystem::Core core(&QR);

        Independent.setupCore(&core);
        Independent.checkCore();
    }
    cr_assert_stdout_eq_str
    (
        "The independent ship Greok just finished its construction.\n"
        "It is 150 m in length and 230 m in width.\n"
        "Greok: The core is set.\n"
        "Greok: The core is unstable at the time.\n"
    );
}


Test(
Federation_Ship,
test_Federation_Ship_getLocation,
.init = redirect_all_stdout)
{
    {
        Federation::Ship     Independent(150, 230, "Greok");

        cr_assert(Independent.getLocation() == Destination::VULCAN);
    }
}

Test(
Federation_Ship,
test_Federation_Ship_error_move_because_warp_superior_to_maxWarp,
.init = redirect_all_stdout)
{
    {
        Federation::Ship     Independent(150, 230, "Greok");
        WarpSystem::QuantumReactor QR;
        WarpSystem::Core core(&QR);
        
        Independent.setupCore(&core);
        cr_assert(Independent.move(30, Destination::UNICOMPLEX) == false);
        cr_assert(Independent.getLocation() == Destination::VULCAN);
        cr_assert(Independent.getLocation() != Destination::EARTH);
    }
}

Test(
Federation_Ship,
test_Federation_Ship_error_move_because_destination_is_not_different_of_the_current_location_of_the_ship,
.init = redirect_all_stdout)
{
    {
        Federation::Ship     Independent(150, 230, "Greok");
        WarpSystem::QuantumReactor QR;
        WarpSystem::Core core(&QR);

        Independent.setupCore(&core);
        cr_assert(Independent.move(30, Destination::VULCAN) == false);
        cr_assert(Independent.move(1, Destination::VULCAN) == false);
        cr_assert(Independent.getLocation() == Destination::VULCAN);
        cr_assert(Independent.getLocation() != Destination::EARTH);
    }
}

Test(
Federation_Ship,
test_Federation_Ship_error_move_because_coreReactor_is_not_stable,
.init = redirect_all_stdout)
{
    {
        Federation::Ship     Independent(150, 230, "Greok");
        WarpSystem::QuantumReactor QR;
        WarpSystem::Core core(&QR);
        core.checkReactor()->setStability(false);
        Independent.setupCore(&core);
        cr_assert(Independent.move(30, Destination::VULCAN) == false);
        cr_assert(Independent.move(1, Destination::EARTH) == false);
        cr_assert(Independent.move(1, Destination::VULCAN) == false);

        cr_assert(Independent.getLocation() == Destination::VULCAN);
        cr_assert(Independent.getLocation() != Destination::EARTH);
    }
}

Test(
Federation_Ship,
test_Federation_Ship_function_move_with_warp_param_and_destination_param,
.init = redirect_all_stdout)
{
    {
        Federation::Ship     Independent(150, 230, "Greok");
        WarpSystem::QuantumReactor QR;
        WarpSystem::Core core(&QR);
        Independent.setupCore(&core);

        cr_assert(Independent.getLocation() == Destination::VULCAN);
        cr_assert(Independent.move(1, Destination::EARTH) == true);
        cr_assert(Independent.getLocation() == Destination::EARTH);
    }
}

Test(
Federation_Ship,
test_Federation_Ship_function_move_with_warp_param,
.init = redirect_all_stdout)
{
    {
        Federation::Ship     Independent(150, 230, "Greok");
        WarpSystem::QuantumReactor QR;
        WarpSystem::Core core(&QR);
        Independent.setupCore(&core);

        cr_assert(Independent.getLocation() == Destination::VULCAN);
        cr_assert(Independent.move(1, Destination::EARTH) == true);
        cr_assert(Independent.getLocation() == Destination::EARTH);
        cr_assert(Independent.move(1) == true);
        cr_assert(Independent.getLocation() == Destination::VULCAN);

    }
}

Test(
Federation_Ship,
test_Federation_Ship_function_move_with_destination_param,
.init = redirect_all_stdout)
{
    {
        Federation::Ship     Independent(150, 230, "Greok");
        WarpSystem::QuantumReactor QR;
        WarpSystem::Core core(&QR);
        Independent.setupCore(&core);

        cr_assert(Independent.getLocation() == Destination::VULCAN);
        cr_assert(Independent.move(1, Destination::EARTH) == true);
        cr_assert(Independent.getLocation() == Destination::EARTH);
        cr_assert(Independent.move(1) == true);
        cr_assert(Independent.getLocation() == Destination::VULCAN);
        cr_assert(Independent.move(Destination::UNICOMPLEX) == true);
        cr_assert(Independent.getLocation() == Destination::UNICOMPLEX);
    }
}

Test(
Federation_Ship,
test_Federation_Ship_function_move_without_param,
.init = redirect_all_stdout)
{
    {
        Federation::Ship     Independent(150, 230, "Greok");
        WarpSystem::QuantumReactor QR;
        WarpSystem::Core core(&QR);
        Independent.setupCore(&core);

        cr_assert(Independent.getLocation() == Destination::VULCAN);
        cr_assert(Independent.move(1, Destination::EARTH) == true);
        cr_assert(Independent.getLocation() == Destination::EARTH);
        cr_assert(Independent.move() == true);
        cr_assert(Independent.getLocation() == Destination::VULCAN);
    }
}
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//                                 Borg::Ship                                //
///////////////////////////////////////////////////////////////////////////////

Test(Borg_Ship, Test_Borg_Ship_class_isDefinied, .init = redirect_all_stdout)
{
    Borg::Ship Cube;

    cr_assert_not_null(&Cube);
}

Test(Borg_Ship, Test_Borg_Ship_CTOR_std_output, .init = redirect_all_stdout)
{
    {
        Borg::Ship Cube;
    }

    cr_assert_stdout_eq_str(
        "We are the Borgs. "
        "Lower your shields and surrender yourselves unconditionally.\n"
        "Your biological characteristics and technologies will be assimilated.\n"
        "Resistance is futile.\n"
    );
}

Test(
Borg_Ship,
Test_Borg_Ship_setupCore_stdout_output,
.init = redirect_all_stdout)
{
    {
        Borg::Ship Cube;
        WarpSystem::QuantumReactor QR;
        WarpSystem::Core core(&QR);

        Cube.setupCore(&core);
    }
    cr_assert_stdout_eq_str
    (
        "We are the Borgs. "
        "Lower your shields and surrender yourselves unconditionally.\n"
        "Your biological characteristics and technologies will be assimilated.\n"
        "Resistance is futile.\n"
    );
}

Test(
Federation_Ship,
Test_Borg_Ship_setupCore_with_NULLPTR_stderr_output,
.init = redirect_all_stdout)
{
    {
        Borg::Ship Cube;

        Cube.setupCore(NULL);
    }
    cr_assert_stdout_eq_str
    (
        "We are the Borgs. "
        "Lower your shields and surrender yourselves unconditionally.\n"
        "Your biological characteristics and technologies will be assimilated.\n"
        "Resistance is futile.\n"
    );
    cr_assert_stderr_eq_str
    (
        "Borg ship: The core is not set.\n"
    );
}

Test(
Borg_Ship,
Test_Borg_Ship_checkCore_stable_stdout_output,
.init = redirect_all_stdout)
{
    {
        Borg::Ship Cube;
        WarpSystem::QuantumReactor QR;
        WarpSystem::Core core(&QR);

        Cube.setupCore(&core);
        Cube.checkCore();
    }
    cr_assert_stdout_eq_str
    (
        "We are the Borgs. "
        "Lower your shields and surrender yourselves unconditionally.\n"
        "Your biological characteristics and technologies will be assimilated.\n"
        "Resistance is futile.\n"
        "Everything is in order.\n"
    );
}

Test(
Borg_Ship,
Test_Borg_Ship_checkCore_unstable_tdout_output,
.init = redirect_all_stdout)
{
    {
        Borg::Ship Cube;
        WarpSystem::QuantumReactor QR;
        WarpSystem::Core core(&QR);
        
        core.checkReactor()->setStability(false);
        Cube.setupCore(&core);
        Cube.checkCore();
    }
    cr_assert_stdout_eq_str
    (
        "We are the Borgs. "
        "Lower your shields and surrender yourselves unconditionally.\n"
        "Your biological characteristics and technologies will be assimilated.\n"
        "Resistance is futile.\n"
        "Critical failure imminent.\n"
    );
}

Test(
Borg_Ship,
Test_Borg_Ship_checkCore_unstable_with_setupCore_NULLPTR_stdout_output,
.init = redirect_all_stdout)
{
    {
        Borg::Ship Cube;

        Cube.setupCore(NULL);
        Cube.checkCore();
    }
    cr_assert_stdout_eq_str
    (
        "We are the Borgs. "
        "Lower your shields and surrender yourselves unconditionally.\n"
        "Your biological characteristics and technologies will be assimilated.\n"
        "Resistance is futile.\n"
        "Critical failure imminent.\n"
    );
    cr_assert_stderr_eq_str
    (
        "Borg ship: The core is not set.\n"
    );
}


Test(
Borg_Ship,
test_Borg_Ship_error_move_because_warp_superior_to_maxWarp,
.init = redirect_all_stdout)
{
    {
        Borg::Ship Cube;
        WarpSystem::QuantumReactor QR;
        WarpSystem::Core core(&QR);
        
        Cube.setupCore(&core);
        cr_assert(Cube.move(30, Destination::VULCAN) == false);
        cr_assert(Cube.getLocation() != Destination::VULCAN);
        cr_assert(Cube.getLocation() == Destination::UNICOMPLEX);
    }
}

Test(
Borg_Ship,
test_Borg_Ship_error_move_because_destination_is_not_different_of_the_current_location_of_the_ship,
.init = redirect_all_stdout)
{
    {
        Borg::Ship Cube;
        WarpSystem::QuantumReactor QR;
        WarpSystem::Core core(&QR);

        Cube.setupCore(&core);
        cr_assert(Cube.move(30, Destination::VULCAN) == false);
        cr_assert(Cube.move(1, Destination::UNICOMPLEX) == false);
        cr_assert(Cube.getLocation() != Destination::VULCAN);
        cr_assert(Cube.getLocation() == Destination::UNICOMPLEX);
    }
}

Test(
Borg_Ship,
test_Borg_Ship_error_move_because_coreReactor_is_not_stable,
.init = redirect_all_stdout)
{
    {
        Borg::Ship Cube;
        WarpSystem::QuantumReactor QR;
        WarpSystem::Core core(&QR);
        core.checkReactor()->setStability(false);
        Cube.setupCore(&core);
        cr_assert(Cube.move(30, Destination::VULCAN) == false);
        cr_assert(Cube.move(1, Destination::UNICOMPLEX) == false);
        cr_assert(Cube.move(1, Destination::EARTH) == false);

        cr_assert(Cube.getLocation() != Destination::EARTH);
        cr_assert(Cube.getLocation() == Destination::UNICOMPLEX);
    }
}

Test(
Borg_Ship,
test_Borg_Ship_function_move_with_warp_param_and_destination_param,
.init = redirect_all_stdout)
{
    {
        Borg::Ship Cube;
        WarpSystem::QuantumReactor QR;
        WarpSystem::Core core(&QR);
        Cube.setupCore(&core);

        cr_assert(Cube.getLocation() == Destination::UNICOMPLEX);
        cr_assert(Cube.move(1, Destination::VULCAN) == true);
        cr_assert(Cube.getLocation() == Destination::VULCAN);
    }
}

Test(
Borg_Ship,
test_Borg_Ship_function_move_with_warp_param,
.init = redirect_all_stdout)
{
    {
        Borg::Ship Cube;
        WarpSystem::QuantumReactor QR;
        WarpSystem::Core core(&QR);
        Cube.setupCore(&core);

        cr_assert(Cube.getLocation() == Destination::UNICOMPLEX);
        cr_assert(Cube.move(1, Destination::VULCAN) == true);
        cr_assert(Cube.getLocation() == Destination::VULCAN);
        cr_assert(Cube.move(1) == true);
        cr_assert(Cube.getLocation() == Destination::UNICOMPLEX);
    }
}

Test(
Borg_Ship,
test_Borg_Ship_function_move_with_destination_param,
.init = redirect_all_stdout)
{
    {
        Borg::Ship Cube;
        WarpSystem::QuantumReactor QR;
        WarpSystem::Core core(&QR);
        Cube.setupCore(&core);

        cr_assert(Cube.getLocation() == Destination::UNICOMPLEX);
        cr_assert(Cube.move(1, Destination::VULCAN) == true);
        cr_assert(Cube.getLocation() == Destination::VULCAN);
        cr_assert(Cube.move(1) == true);
        cr_assert(Cube.getLocation() == Destination::UNICOMPLEX);
        cr_assert(Cube.move(Destination::VULCAN) == true);
        cr_assert(Cube.getLocation() == Destination::VULCAN);
    }
}

Test(
Borg_Ship,
test_Borg_Ship_function_move_without_param,
.init = redirect_all_stdout)
{
    {
        Borg::Ship Cube;
        WarpSystem::QuantumReactor QR;
        WarpSystem::Core core(&QR);
        Cube.setupCore(&core);

        cr_assert(Cube.getLocation() == Destination::UNICOMPLEX);
        cr_assert(Cube.move(1, Destination::VULCAN) == true);
        cr_assert(Cube.getLocation() == Destination::VULCAN);
        cr_assert(Cube.move() == true);
        cr_assert(Cube.getLocation() == Destination::UNICOMPLEX);
    }
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//                               Destination                                 //
///////////////////////////////////////////////////////////////////////////////
Test(Destination, Test_Destination_enum_isDefined)
{
    e_Destination e_destination = EARTH;
    cr_assert(e_destination == 0);

    Destination destination = VULCAN;
    cr_assert(destination == 1);
}
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//                                      MAIN                                 //
///////////////////////////////////////////////////////////////////////////////

Test(
main, test_main, .init = redirect_all_stdout)
{
    {
        Federation::Starfleet::Ship UssKreog(289, 132, "Kreog", 6);
        Federation::Starfleet::Captain James("James T. Kirk");
        Federation::Starfleet::Ensign Ensign("Pavel Chekov");
        Federation::Ship     Independent(150, 230, "Greok");
        WarpSystem::QuantumReactor QR;
        WarpSystem::QuantumReactor QR2;
        WarpSystem::QuantumReactor QR3;

        WarpSystem::Core core(&QR);
        WarpSystem::Core core2(&QR2);
        WarpSystem::Core core3(&QR3);


        UssKreog.setupCore(&core);
        UssKreog.checkCore();
        UssKreog.promote(&James);

        cr_assert(UssKreog.getLocation() == Destination::EARTH);
        cr_assert(UssKreog.move(1, Destination::VULCAN) == true);
        cr_assert(UssKreog.getLocation() == Destination::VULCAN);
        cr_assert(UssKreog.move(1) == true);
        cr_assert(UssKreog.getLocation() == Destination::EARTH);
        cr_assert(UssKreog.move(Destination::VULCAN) == true);
        cr_assert(UssKreog.getLocation() == Destination::VULCAN);
        cr_assert(UssKreog.move() == true);
        cr_assert(UssKreog.getLocation() == Destination::EARTH);

        Borg::Ship  Cube;
        Cube.setupCore(&core2);
        Cube.checkCore();

        cr_assert(Cube.getLocation() == Destination::UNICOMPLEX);
        cr_assert(Cube.move(1, Destination::EARTH) == true);
        cr_assert(Cube.getLocation() == Destination::EARTH);
        cr_assert(Cube.move(1) == true);
        cr_assert(Cube.getLocation() == Destination::UNICOMPLEX);
        cr_assert(Cube.move(Destination::VULCAN) == true);
        cr_assert(Cube.getLocation() == Destination::VULCAN);
        cr_assert(Cube.move() == true);
        cr_assert(Cube.getLocation() == Destination::UNICOMPLEX);

        Independent.setupCore(&core3);
        Independent.checkCore();
        cr_assert(Independent.getLocation() == Destination::VULCAN);
        cr_assert(Independent.move(1, Destination::EARTH) == true);
        cr_assert(Independent.getLocation() == Destination::EARTH);
        cr_assert(Independent.move(1) == true);
        cr_assert(Independent.getLocation() == Destination::VULCAN);
        cr_assert(Independent.move(Destination::UNICOMPLEX) == true);
        cr_assert(Independent.getLocation() == Destination::UNICOMPLEX);
        cr_assert(Independent.move() == true);
        cr_assert(Independent.getLocation() == Destination::VULCAN);
    }
    cr_assert_stdout_eq_str
    (
        "The ship USS Kreog has been finished.\n"
        "It is 289 m in length and 132 m in width.\n"
        "It can go to Warp 6!\n"
        "Ensign Pavel Chekov, awaiting orders.\n"
        "The independent ship Greok just finished its construction.\n"
        "It is 150 m in length and 230 m in width.\n"
        "USS Kreog: The core is set.\n"
        "USS Kreog: The core is stable at the time.\n"
        "James T. Kirk: I'm glad to be the captain of the USS Kreog.\n"
        "We are the Borgs. "
        "Lower your shields and surrender yourselves unconditionally.\n"
        "Your biological characteristics and technologies will be assimilated.\n"
        "Resistance is futile.\n"
        "Everything is in order.\n"
        "Greok: The core is set.\n"
        "Greok: The core is stable at the time.\n"
    );
}
