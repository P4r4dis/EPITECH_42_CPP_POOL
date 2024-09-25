/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex00/test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Fri Sep 20 7:46:17 PM 2024 Paradis
** Last update Thu Sep 25 8:02:10 PM 2024 Paradis
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
    cr_assert_not_null(&UssKreog);
}

Test(
Federation_Starfleet_Ship,
test_Federation_Starfleet_Ship_CTOR_std_output,
.init = redirect_all_stdout)
{
    {
        Federation::Starfleet::Ship     UssKreog(289, 132, "Kreog", 6);
    }
    cr_assert_stdout_eq_str
    (
        "The ship USS Kreog has been finished.\n"
        "It is 289 m in length and 132 m in width.\n"
        "It can go to Warp 6!\n"
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
main,
test_main,
.init = redirect_all_stdout)
{
    {
        Federation::Starfleet::Ship UssKreog(289, 132, "Kreog", 6);
        Federation::Starfleet::Captain James("James T. Kirk");
        Federation::Starfleet::Ensign Ensign("Pavel Chekov");
        WarpSystem::QuantumReactor QR;
        WarpSystem::QuantumReactor QR2;
        WarpSystem::Core core(&QR);
        WarpSystem::Core core2 (&QR2);

        UssKreog.setupCore(&core);
        UssKreog.checkCore();
        UssKreog.promote(&James);

        Borg::Ship  Cube;
        Cube.setupCore(&core2);
        Cube.checkCore();
    }
    cr_assert_stdout_eq_str
    (
        "The ship USS Kreog has been finished.\n"
        "It is 289 m in length and 132 m in width.\n"
        "It can go to Warp 6!\n"
        "Ensign Pavel Chekov, awaiting orders.\n"
        "USS Kreog: The core is set.\n"
        "USS Kreog: The core is stable at the time.\n"
        "James T. Kirk: I'm glad to be the captain of the USS Kreog.\n"
        "We are the Borgs. "
        "Lower your shields and surrender yourselves unconditionally.\n"
        "Your biological characteristics and technologies will be assimilated.\n"
        "Resistance is futile.\n"
        "Everything is in order.\n"
    );
}
