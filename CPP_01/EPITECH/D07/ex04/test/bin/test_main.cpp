/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex03/test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Thu Sep 26 6:43:34 PM 2024 Paradis
** Last update Thu Jan 15 6:58:03 PM 2025 Paradis
*/

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include "../../include/Federation.hpp"
#include "../../include/WarpSystem.hpp"
#include "../../include/Borg.hpp"
#include "../../include/Destination.hpp"
#include "../../include/Admiral.hpp"
#include "../../include/BorgQueen.hpp"


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

Test(
Federation_Starfleet_Ship,
test_Federation_Starfleet_Ship_functions_fire_error_captain_and_target_cannot_be_nullptr,
.init = redirect_all_stdout)
{
    {
        Federation::Starfleet::Ship     UssKreog(289, 132, "Kreog", 6);

        UssKreog.fire(nullptr);

        cr_assert_stdout_eq_str(
            "The ship USS Kreog has been finished.\n"
            "It is 289 m in length and 132 m in width.\n"
            "It can go to Warp 6!\n"
        );
        cr_assert_stderr_eq_str(
            "Error: Captain and target must be set, cannot be nullptr.\n"
        );
    }
}

Test(
Federation_Starfleet_Ship,
test_Federation_Starfleet_Ship_functions_fire_not_enough_torpedoes,
.init = redirect_all_stdout)
{
    {
        Federation::Starfleet::Ship     UssKreog(289, 132, "Kreog", 6);
        Federation::Starfleet::Captain James("James T. Kirk");
        Borg::Ship Cube(20);

        UssKreog.promote(&James);
        UssKreog.fire(&Cube);
        cr_assert_stdout_eq_str(
            (
                "The ship USS Kreog has been finished.\n"
                "It is 289 m in length and 132 m in width.\n"
                "It can go to Warp 6!\n"
                "We are the Borgs. "
                "Lower your shields and surrender yourselves unconditionally.\n"
                "Your biological characteristics and technologies will be assimilated.\n"
                "Resistance is futile.\n"
                "James T. Kirk: I'm glad to be the captain of the USS " + UssKreog.getName() + ".\n"
                "Kreog: No enough torpedoes to fire, " + UssKreog.getCaptain()->getName() + "!\n"
            ).c_str()
        );
    }
}

Test(
Federation_Starfleet_Ship,
test_Federation_Starfleet_Ship_functions_fire_with_not_enough_torpedoes,
.init = redirect_all_stdout)
{
    {
        Federation::Starfleet::Ship     UssKreog(289, 132, "Kreog", 6, 1);
        Federation::Starfleet::Captain James("James T. Kirk");
        Borg::Ship Cube(20);

        UssKreog.promote(&James);
        UssKreog.fire(&Cube);
        UssKreog.fire(&Cube);
        cr_assert_stdout_eq_str(
            (
                "The ship USS Kreog has been finished.\n"
                "It is 289 m in length and 132 m in width.\n"
                "It can go to Warp 6!\n"
                "Weapons are set: 1 torpedoes ready.\n"
                "We are the Borgs. "
                "Lower your shields and surrender yourselves unconditionally.\n"
                "Your biological characteristics and technologies will be assimilated.\n"
                "Resistance is futile.\n"
                "James T. Kirk: I'm glad to be the captain of the USS " + UssKreog.getName() + ".\n"
                "Kreog: Firing on target. 1 torpedoes remaining.\n"
                "Kreog: No enough torpedoes to fire, " + UssKreog.getCaptain()->getName() + "!\n"
            ).c_str()
        );
    }
}

Test(
Federation_Starfleet_Ship,
test_Federation_Starfleet_Ship_functions_fire_reduces_target_shield,
.init = redirect_all_stdout)
{
    {
        Federation::Starfleet::Ship     UssKreog(289, 132, "Kreog", 6, 1);
        Federation::Starfleet::Captain James("James T. Kirk");
        Borg::Ship Cube(20);

        UssKreog.promote(&James);

        cr_assert(Cube.getShield() == 100);
        UssKreog.fire(&Cube);
        cr_assert(Cube.getShield() == 50);
        cr_assert_stdout_eq_str(
            (
                "The ship USS Kreog has been finished.\n"
                "It is 289 m in length and 132 m in width.\n"
                "It can go to Warp 6!\n"
                "Weapons are set: 1 torpedoes ready.\n"
                "We are the Borgs. "
                "Lower your shields and surrender yourselves unconditionally.\n"
                "Your biological characteristics and technologies will be assimilated.\n"
                "Resistance is futile.\n"
                "James T. Kirk: I'm glad to be the captain of the USS " + UssKreog.getName() + ".\n"
                "Kreog: Firing on target. 1 torpedoes remaining.\n"
            ).c_str()
        );
    }
}

Test(
Federation_Starfleet_Ship,
test_Federation_Starfleet_Ship_functions_fire_reduces_target_shield_with_std_output,
.init = redirect_all_stdout)
{
    {
        Federation::Starfleet::Ship     UssKreog(289, 132, "Kreog", 6, 1);
        Federation::Starfleet::Captain James("James T. Kirk");
        Borg::Ship Cube(20);

        UssKreog.promote(&James);

        cr_assert(Cube.getShield() == 100);
        UssKreog.fire(&Cube);
        cr_assert(Cube.getShield() == 50);
    }
}

Test(
Federation_Starfleet_Ship,
test_Federation_Starfleet_Ship_functions_fire_runs_out_of_torpedoes,
.init = redirect_all_stdout)
{
    {
        Federation::Starfleet::Ship     UssKreog(289, 132, "Kreog", 6, 1);
        Federation::Starfleet::Captain James("James T. Kirk");
        Borg::Ship Cube(20);

        UssKreog.promote(&James);
        UssKreog.fire(10, &Cube);
        cr_assert_stdout_eq_str(
            (
                "The ship USS Kreog has been finished.\n"
                "It is 289 m in length and 132 m in width.\n"
                "It can go to Warp 6!\n"
                "Weapons are set: 1 torpedoes ready.\n"
                "We are the Borgs. "
                "Lower your shields and surrender yourselves unconditionally.\n"
                "Your biological characteristics and technologies will be assimilated.\n"
                "Resistance is futile.\n"
                "James T. Kirk: I'm glad to be the captain of the USS " + UssKreog.getName() + ".\n"
                "Kreog: No more torpedo to fire, " + UssKreog.getCaptain()->getName() + "!\n"
            ).c_str()
        );
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

Test(
Federation_Ship,
test_Federation_Ship_function_getCore,
.init = redirect_all_stdout)
{
    {
        Federation::Ship     Independent(150, 230, "Greok");

        cr_assert_null(Independent.getCore());
        WarpSystem::QuantumReactor QR;
        WarpSystem::Core core(&QR);
        Independent.setupCore(&core);
        cr_assert_not_null(Independent.getCore());
    }
}
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//                                 Borg::Ship                                //
///////////////////////////////////////////////////////////////////////////////

Test(Borg_Ship, Test_Borg_Ship_class_isDefinied, .init = redirect_all_stdout)
{
    Borg::Ship Cube(20, 10);
    Borg::Ship Cube2(20);
    cr_assert_not_null(&Cube);
    cr_assert_not_null(&Cube2);
}

Test(Borg_Ship, Test_Borg_Ship_CTOR_std_output, .init = redirect_all_stdout)
{
    {
        Borg::Ship Cube(20, 10);
        Borg::Ship Cube2(20);
    }

    cr_assert_stdout_eq_str(
        "We are the Borgs. "
        "Lower your shields and surrender yourselves unconditionally.\n"
        "Your biological characteristics and technologies will be assimilated.\n"
        "Resistance is futile.\n"
        "We are the Borgs. "
        "Lower your shields and surrender yourselves unconditionally.\n"
        "Your biological characteristics and technologies will be assimilated.\n"
        "Resistance is futile.\n"
    );
}

Test(Borg_Ship, Test_Borg_Ship_getShield, .init = redirect_all_stdout)
{
    {
        Borg::Ship Cube(20, 10);

        cr_assert(Cube.getShield() == 100);
    }
}


Test(Borg_Ship, Test_Borg_Ship_setShield, .init = redirect_all_stdout)
{
    {
        Borg::Ship Cube(20, 10);

        cr_assert(Cube.getShield() == 100);
        Cube.setShield(50);
        cr_assert(Cube.getShield() == 50);
    }
}

Test(Borg_Ship, Test_Borg_Ship_getWeaponFrequency, .init = redirect_all_stdout)
{
    {
        Borg::Ship Cube(20, 10);

        cr_assert(Cube.getWeaponFrequency() == 20);
    }
}


Test(Borg_Ship, Test_Borg_Ship_setWeaponFrequency, .init = redirect_all_stdout)
{
    {
        Borg::Ship Cube(20, 10);

        cr_assert(Cube.getWeaponFrequency() == 20);
        Cube.setWeaponFrequency(50);
        cr_assert(Cube.getWeaponFrequency() == 50);
    }
}

Test(Borg_Ship, Test_Borg_Ship_getRepair, .init = redirect_all_stdout)
{
    {
        Borg::Ship Cube(20, 10);

        cr_assert(Cube.getRepair() == 10);
    }
}


Test(Borg_Ship, Test_Borg_Ship_setRepair, .init = redirect_all_stdout)
{
    {
        Borg::Ship Cube(20, 10);

        cr_assert(Cube.getRepair() == 10);
        Cube.setRepair(50);
        cr_assert(Cube.getRepair() == 50);
    }
}


Test(
Borg_Ship,
Test_Borg_Ship_setupCore_stdout_output,
.init = redirect_all_stdout)
{
    {
        Borg::Ship Cube(20);
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
        Borg::Ship Cube(20);
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
        Borg::Ship Cube(20);
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
        Borg::Ship Cube(20);
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
        Borg::Ship Cube(20);

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
        Borg::Ship Cube(20);
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
        Borg::Ship Cube(20);
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
        Borg::Ship Cube(20);
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
        Borg::Ship Cube(20);
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
        Borg::Ship Cube(20);
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
        Borg::Ship Cube(20);
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
        Borg::Ship Cube(20);
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

Test(
Borg_Ship,
test_Borg_Ship_function_fire_reduces_Federation_Starfleet_Ship_shield_by_weaponFrequency,
.init = redirect_all_stdout)
{
    {
        Borg::Ship Cube(20);
        Federation::Starfleet::Ship UssKreog;

        cr_assert(UssKreog.getShield() == 100);
        Cube.fire(&UssKreog);
        cr_assert(UssKreog.getShield() == 80);
    }
}

Test(
Borg_Ship,
test_Borg_Ship_function_fire_reduces_Federation_Starfleet_Ship_shield_but_shield_cant_be_negative,
.init = redirect_all_stdout)
{
    {
        Borg::Ship Cube(200);
        Federation::Starfleet::Ship UssKreog;

        cr_assert(UssKreog.getShield() == 100);
        Cube.fire(&UssKreog);
        cr_assert(UssKreog.getShield() == 0);
    }
}

Test(
Borg_Ship,
test_Borg_Ship_function_fire_stdout_output,
.init = redirect_all_stdout)
{
    {
        Borg::Ship Cube(200);
        Federation::Starfleet::Ship UssKreog;

        cr_assert(UssKreog.getShield() == 100);
        Cube.fire(&UssKreog);
        cr_assert(UssKreog.getShield() == 0);

        cr_assert_stdout_eq_str(
            "We are the Borgs. "
            "Lower your shields and surrender yourselves unconditionally.\n"
            "Your biological characteristics and technologies will be assimilated.\n"
            "Resistance is futile.\n"
            "The ship USS Kreog has been finished.\n"
            "It is 289 m in length and 132 m in width.\n"
            "It can go to Warp 6!\n"
            "Firing on target with 200GW frequency.\n"
        );
    }
}

Test(
Borg_Ship,
test_Borg_Ship_function_fire_make_Federation_Ship_coreReactor_unstable,
.init = redirect_all_stdout)
{
    {
        Borg::Ship Cube(20);
        WarpSystem::QuantumReactor QR;
        WarpSystem::Core core(&QR);
        Federation::Ship Independent(150, 230, "Greok");

        Independent.setupCore(&core);

        cr_assert(Independent.getCore()->checkReactor()->isStable() == true);
        Cube.fire(&Independent);
        cr_assert(Independent.getCore()->checkReactor()->isStable() == false);
    }
}

Test(
Borg_Ship,
test_Borg_Ship_function_fire_Federation_Ship_stdout_output,
.init = redirect_all_stdout)
{
    {
        Borg::Ship Cube(20);
        WarpSystem::QuantumReactor QR;
        WarpSystem::Core core(&QR);
        Federation::Ship Independent(150, 230, "Greok");

        Independent.setupCore(&core);

        cr_assert(Independent.getCore()->checkReactor()->isStable() == true);
        Cube.fire(&Independent);
        cr_assert(Independent.getCore()->checkReactor()->isStable() == false);
        cr_assert_stdout_eq_str(
            "We are the Borgs. "
            "Lower your shields and surrender yourselves unconditionally.\n"
            "Your biological characteristics and technologies will be assimilated.\n"
            "Resistance is futile.\n"
            "The independent ship Greok just finished its construction.\n"
            "It is 150 m in length and 230 m in width.\n"
            "Greok: The core is set.\n"
            "Firing on target with 20GW frequency.\n"
        );
    }
}

Test(
Borg_Ship,
test_Borg_Ship_function_repair,
.init = redirect_all_stdout)
{
    {
        Borg::Ship Cube(20);
        WarpSystem::QuantumReactor QR;
        WarpSystem::Core core(&QR);
        Federation::Starfleet::Ship     UssKreog(289, 132, "Kreog", 6, 1);
        Federation::Starfleet::Captain captain("James T. Kirk");

        UssKreog.promote(&captain);

        cr_assert(Cube.getShield() == 100);
        cr_assert(Cube.getRepair() == 3);
        UssKreog.fire(&Cube);
        cr_assert(Cube.getShield() == 50);
        Cube.repair();
        cr_assert(Cube.getRepair() == 2);
        cr_assert(Cube.getShield() == 100);
    }
}

Test(
Borg_Ship,
test_Borg_Ship_function_repair_with_no_enough_energy,
.init = redirect_all_stdout)
{
    {
        Borg::Ship Cube(20, 0);
        WarpSystem::QuantumReactor QR;
        WarpSystem::Core core(&QR);
        Federation::Starfleet::Ship     UssKreog(289, 132, "Kreog", 6, 1);
        Federation::Starfleet::Captain captain("James T. Kirk");

        UssKreog.promote(&captain);

        cr_assert(Cube.getShield() == 100);
        cr_assert(Cube.getRepair() == 0);
        UssKreog.fire(&Cube);
        cr_assert(Cube.getShield() == 50);
        Cube.repair();
        cr_assert(Cube.getRepair() == 0);
        cr_assert(Cube.getShield() == 50);


        cr_assert_stdout_eq_str(
            "We are the Borgs. Lower your shields and surrender yourselves unconditionally.\n"
            "Your biological characteristics and technologies will be assimilated.\n"
            "Resistance is futile.\n"
            "The ship USS Kreog has been finished.\n"
            "It is 289 m in length and 132 m in width.\n"
            "It can go to Warp 6!\n"
            "Weapons are set: 1 torpedoes ready.\n"
            "James T. Kirk: I'm glad to be the captain of the USS Kreog.\n"
            "Kreog: Firing on target. 1 torpedoes remaining.\n"
            "Energy cells depleted, shield weakening.\n"
        );
    }
}

Test(
Borg_Ship,
test_Borg_Ship_function_repair_std_output,
.init = redirect_all_stdout)
{
    {
        Borg::Ship Cube(20);
        WarpSystem::QuantumReactor QR;
        WarpSystem::Core core(&QR);
        Federation::Starfleet::Ship     UssKreog(289, 132, "Kreog", 6, 1);
        Federation::Starfleet::Captain captain("James T. Kirk");

        UssKreog.promote(&captain);

        cr_assert(Cube.getShield() == 100);
        cr_assert(Cube.getRepair() == 3);
        UssKreog.fire(&Cube);
        cr_assert(Cube.getShield() == 50);
        Cube.repair();
        cr_assert(Cube.getRepair() == 2);
        cr_assert(Cube.getShield() == 100);


        cr_assert_stdout_eq_str(
            "We are the Borgs. Lower your shields and surrender yourselves unconditionally.\n"
            "Your biological characteristics and technologies will be assimilated.\n"
            "Resistance is futile.\n"
            "The ship USS Kreog has been finished.\n"
            "It is 289 m in length and 132 m in width.\n"
            "It can go to Warp 6!\n"
            "Weapons are set: 1 torpedoes ready.\n"
            "James T. Kirk: I'm glad to be the captain of the USS Kreog.\n"
            "Kreog: Firing on target. 1 torpedoes remaining.\n"
            "Begin shield re-initialisation... Done. Awaiting further instructions.\n"
        );
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
//                      Federation::Starfleet::Admiral                       //
///////////////////////////////////////////////////////////////////////////////
Test(Admiral, Test_Admiral_isDefined, .init = redirect_all_stdout)
{
    Federation::Starfleet::Admiral admiral("Picard");
    cr_assert_not_null(&admiral);
}

Test(Admiral, Test_Admiral_std_output, .init = redirect_all_stdout)
{
    Federation::Starfleet::Admiral admiral("Picard");

    cr_assert_stdout_eq_str(
        "Admiral Picard ready for action.\n"
    );
}

Test(Admiral, Test_Admiral_fire_on_borg, .init = redirect_all_stdout)
{
    Federation::Starfleet::Ship    UssKreog(289, 132, "Kreog", 6, 1);
    Federation::Starfleet::Captain captain("James T. Kirk");
    Federation::Starfleet::Admiral admiral("Picard");
    Borg::Ship Cube(20);

    UssKreog.promote(&captain);
    cr_assert(Cube.getShield() == 100);
    admiral.fire(&UssKreog,&Cube);
    cr_assert(Cube.getShield() == 50);
}

Test(Admiral, Test_Admiral_fire_on_borg_std_output, .init = redirect_all_stdout)
{
    Federation::Starfleet::Ship    UssKreog(289, 132, "Kreog", 6, 1);
    Federation::Starfleet::Captain captain("James T. Kirk");
    Federation::Starfleet::Admiral admiral("Picard");
    Borg::Ship Cube(20);

    UssKreog.promote(&captain);
    cr_assert(Cube.getShield() == 100);
    admiral.fire(&UssKreog,&Cube);
    cr_assert(Cube.getShield() == 50);

    cr_assert_stdout_eq_str
    (
        "The ship USS Kreog has been finished.\n"
        "It is 289 m in length and 132 m in width.\n"
        "It can go to Warp 6!\n"
        "Weapons are set: 1 torpedoes ready.\n"
        "Admiral Picard ready for action.\n"
        "We are the Borgs. Lower your shields and surrender yourselves unconditionally.\n"
        "Your biological characteristics and technologies will be assimilated.\n"
        "Resistance is futile.\n"
        "James T. Kirk: I'm glad to be the captain of the USS Kreog.\n"
        "On order from Admiral Picard:\n"
        "Kreog: Firing on target. 1 torpedoes remaining.\n"
    );
}

Test(Admiral, Test_Admiral_move_go_to_dest, .init = redirect_all_stdout)
{
    Federation::Starfleet::Ship    UssKreog(289, 132, "Kreog", 6, 1);
    Federation::Starfleet::Admiral admiral("Picard");
    Borg::Ship Cube(20);
    WarpSystem::QuantumReactor QR;
    WarpSystem::Core core(&QR);

    UssKreog.setupCore(&core);
    cr_assert(UssKreog.getLocation() == EARTH);
    cr_assert(admiral.move(&UssKreog, VULCAN) == true);
    cr_assert(UssKreog.getLocation() == VULCAN);
}

Test(Admiral, Test_Admiral_move_go_to_dest_std_output, .init = redirect_all_stdout)
{
    Federation::Starfleet::Ship    UssKreog(289, 132, "Kreog", 6, 1);
    Federation::Starfleet::Admiral admiral("Picard");
    Borg::Ship Cube(20);
    WarpSystem::QuantumReactor QR;
    WarpSystem::Core core(&QR);

    UssKreog.setupCore(&core);
    cr_assert(UssKreog.getLocation() == EARTH);
    cr_assert(admiral.move(&UssKreog, VULCAN) == true);
    cr_assert(UssKreog.getLocation() == VULCAN);
    cr_assert_stdout_eq_str(
        "The ship USS Kreog has been finished.\n"
        "It is 289 m in length and 132 m in width.\n"
        "It can go to Warp 6!\n"
        "Weapons are set: 1 torpedoes ready.\n"
        "Admiral Picard ready for action.\n"
        "We are the Borgs. Lower your shields and surrender yourselves unconditionally.\n"
        "Your biological characteristics and technologies will be assimilated.\n"
        "Resistance is futile.\n"
        "USS Kreog: The core is set.\n"
    );
}
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//                      Borg::BorgQueen::BorgQueen                           //
///////////////////////////////////////////////////////////////////////////////
Test(BorgQueen, Test_BorgQueen_isDefined, .init = redirect_all_stdout)
{
    Borg::BorgQueen borgQueen;
    cr_assert_not_null(&borgQueen);
}

Test(BorgQueen, Test_BorgQueen_fire_on_Starfleet_ship, .init = redirect_all_stdout)
{
    Federation::Starfleet::Ship    UssKreog(289, 132, "Kreog", 6, 1);
    Federation::Starfleet::Captain captain("James T. Kirk");
    Federation::Starfleet::Admiral admiral("Picard");
    Borg::Ship Cube(20);

    UssKreog.promote(&captain);
    cr_assert(Cube.getShield() == 100);
    admiral.fire(&UssKreog,&Cube);
    cr_assert(Cube.getShield() == 50);

    Borg::BorgQueen borgQueen;
    borgQueen.fire(&Cube, &UssKreog);
    cr_assert(UssKreog.getShield() == 80);
}

Test(BorgQueen, Test_BorgQueen_fire_on_Starfleet_ship_stdoutput, .init = redirect_all_stdout)
{
    Federation::Starfleet::Ship    UssKreog(289, 132, "Kreog", 6, 1);
    Federation::Starfleet::Captain captain("James T. Kirk");
    Federation::Starfleet::Admiral admiral("Picard");
    Borg::Ship Cube(20);

    UssKreog.promote(&captain);
    cr_assert(Cube.getShield() == 100);
    admiral.fire(&UssKreog,&Cube);
    cr_assert(Cube.getShield() == 50);

    Borg::BorgQueen borgQueen;
    borgQueen.fire(&Cube, &UssKreog);
    cr_assert(UssKreog.getShield() == 80);
    cr_assert_stdout_eq_str(
        "The ship USS Kreog has been finished.\n"
        "It is 289 m in length and 132 m in width.\n"
        "It can go to Warp 6!\n"
        "Weapons are set: 1 torpedoes ready.\n"
        "Admiral Picard ready for action.\n"
        "We are the Borgs. Lower your shields and surrender yourselves unconditionally.\n"
        "Your biological characteristics and technologies will be assimilated.\n"
        "Resistance is futile.\n"
        "James T. Kirk: I'm glad to be the captain of the USS Kreog.\n"
        "On order from Admiral Picard:\n"
        "Kreog: Firing on target. 1 torpedoes remaining.\n"
        "Firing on target with 20GW frequency.\n"
    );
}

Test(BorgQueen, Test_BorgQueen_destroys_Federation_ship, .init = redirect_all_stdout)
{
    Federation::Ship    Independent(150, 230, "Greok");
    WarpSystem::QuantumReactor QR;
    WarpSystem::Core core(&QR);
    Borg::Ship          Cube(20);
    Borg::BorgQueen     borgQueen;

    Independent.setupCore(&core);
    cr_assert(Independent.getCore()->checkReactor()->isStable() == true);
    borgQueen.destroy(&Cube, &Independent);
    cr_assert(Independent.getCore()->checkReactor()->isStable() == false);
}

Test(BorgQueen, Test_BorgQueen_destroys_Federation_ship_stdoutput, .init = redirect_all_stdout)
{
    Federation::Ship    Independent(150, 230, "Greok");
    WarpSystem::QuantumReactor QR;
    WarpSystem::Core core(&QR);
    Borg::Ship          Cube(20);
    Borg::BorgQueen     borgQueen;

    Independent.setupCore(&core);
    cr_assert(Independent.getCore()->checkReactor()->isStable() == true);
    borgQueen.destroy(&Cube, &Independent);
    cr_assert(Independent.getCore()->checkReactor()->isStable() == false);

    cr_assert_stdout_eq_str(
        "The independent ship Greok just finished its construction.\n"
        "It is 150 m in length and 230 m in width.\n"
        "We are the Borgs. Lower your shields and surrender yourselves unconditionally.\n"
        "Your biological characteristics and technologies will be assimilated.\n"
        "Resistance is futile.\n"
        "Greok: The core is set.\n"
        "Firing on target with 20GW frequency.\n"
    );
}

Test(BorgQueen, Test_BorgQueen_move_go_to_dest, .init = redirect_all_stdout)
{
    Borg::Ship                  Cube(20);
    WarpSystem::QuantumReactor  QR;
    WarpSystem::Core            core(&QR);
    Borg::BorgQueen             borgQueen;

    Cube.setupCore(&core);
    cr_assert(Cube.getLocation() == UNICOMPLEX);
    cr_assert(borgQueen.move(&Cube, EARTH) == true);
    cr_assert(Cube.getLocation() == EARTH);
}

Test(BorgQueen, Test_BorgQueen_move_go_to_dest_stdout, .init = redirect_all_stdout)
{
    Borg::Ship                  Cube(20);
    WarpSystem::QuantumReactor  QR;
    WarpSystem::Core            core(&QR);
    Borg::BorgQueen             borgQueen;

    Cube.setupCore(&core);
    cr_assert(Cube.getLocation() == UNICOMPLEX);
    cr_assert(borgQueen.move(&Cube, EARTH) == true);
    cr_assert(Cube.getLocation() == EARTH);
    
    cr_assert_stdout_eq_str(
        "We are the Borgs. Lower your shields and surrender yourselves unconditionally.\n"
        "Your biological characteristics and technologies will be assimilated.\n"
        "Resistance is futile.\n"
    );
}

///////////////////////////////////////////////////////////////////////////////
//                                      MAIN                                 //
///////////////////////////////////////////////////////////////////////////////

Test(
main, test_main, .init = redirect_all_stdout)
{
    {
        Federation::Starfleet::Ship UssKreog(289, 132, "Kreog", 6, 2);
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

        Borg::Ship Cube(20);
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

        cr_assert(UssKreog.getTorpedo() == 2);
        cr_assert(Cube.getRepair() == 3);
        cr_assert(Cube.getShield() == 100);
        UssKreog.fire(&Cube);
        cr_assert(Cube.getShield() == 50);
        cr_assert(UssKreog.getTorpedo() == 1);
        UssKreog.fire(2, &Cube);
        cr_assert(Cube.getShield() == 50);
        UssKreog.fire(1, &Cube);
        cr_assert(Cube.getShield() == 0);
        UssKreog.fire(1, &Cube);
        cr_assert(Cube.getShield() == 0);
        UssKreog.setTorpedo(20);
        UssKreog.fire(20, &Cube);
        cr_assert(Cube.getShield() == 0);
        Cube.repair();
        cr_assert(Cube.getRepair() == 2);
        cr_assert(Cube.getShield() == 100);

        cr_assert(UssKreog.getShield() == 100);
        Cube.fire(&UssKreog);
        cr_assert(UssKreog.getShield() == 80);

        cr_assert(Independent.getCore()->checkReactor()->isStable() == true);
        Cube.fire(&Independent);
        cr_assert(Independent.getCore()->checkReactor()->isStable() == false);


        Federation::Starfleet::Admiral admiral("Picard");
        Cube.repair();
        UssKreog.setTorpedo(20);
        cr_assert(UssKreog.getLocation() == EARTH);
        cr_assert(UssKreog.getTorpedo() == 20);
        admiral.move(&UssKreog, UNICOMPLEX);
        cr_assert(UssKreog.getLocation() == UNICOMPLEX);
        cr_assert(Cube.getShield() == 100);
        admiral.fire(&UssKreog,&Cube);
        cr_assert(Cube.getShield() == 50);
        admiral.move(&UssKreog, EARTH);
        cr_assert(UssKreog.getLocation() == EARTH);

        Borg::BorgQueen borgQueen;
        cr_assert(Cube.getLocation() == UNICOMPLEX);
        borgQueen.move(&Cube, EARTH);
        cr_assert(UssKreog.getShield() == 80);
        borgQueen.fire(&Cube, &UssKreog);
        cr_assert(UssKreog.getShield() == 60);
        cr_assert(Independent.getLocation() == Destination::VULCAN);
        borgQueen.move(&Cube, VULCAN);
        cr_assert(Cube.getLocation() == Destination::VULCAN);
        Independent.getCore()->checkReactor()->setStability(true);
        cr_assert(Independent.getCore()->checkReactor()->isStable() == true);
        borgQueen.destroy(&Cube, &Independent);
        cr_assert(Independent.getCore()->checkReactor()->isStable() == false);

    }
    cr_assert_stdout_eq_str
    (
        "The ship USS Kreog has been finished.\n"
        "It is 289 m in length and 132 m in width.\n"
        "It can go to Warp 6!\n"
        "Weapons are set: 2 torpedoes ready.\n"
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
        "Kreog: Firing on target. 1 torpedoes remaining.\n"
        "Kreog: No more torpedo to fire, James T. Kirk!\n"
        "Kreog: Firing on target. 1 torpedoes remaining.\n"
        "Kreog: No enough torpedoes to fire, James T. Kirk!\n"
        "Kreog: Firing on target. 20 torpedoes remaining.\n"
        "Begin shield re-initialisation... Done. Awaiting further instructions.\n"
        "Firing on target with 20GW frequency.\n"
        "Firing on target with 20GW frequency.\n"
        "Admiral Picard ready for action.\n"
        "Begin shield re-initialisation... Done. Awaiting further instructions.\n"
        "On order from Admiral Picard:\n"
        "Kreog: Firing on target. 1 torpedoes remaining.\n"
        "Firing on target with 20GW frequency.\n"
        "Firing on target with 20GW frequency.\n"
    );
}
