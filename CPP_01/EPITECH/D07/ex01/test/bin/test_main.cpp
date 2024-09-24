/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex00/test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Fri Sep 20 7:46:17 PM 2024 Paradis
** Last update Wed Sep 24 7:42:46 PM 2024 Paradis
*/



#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include "../../include/Federation.hpp"
#include "../../include/WarpSystem.hpp"
#include "../../include/Borg.hpp"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

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
Federation_Ship,
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
Federation_Ship,
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
Test(
main,
test_main,
.init = redirect_all_stdout)
{
    {
        Federation::Starfleet::Ship UssKreog (289, 132, "Kreog", 6);
        Federation::Ship Independent (150, 230, "Greok");
        WarpSystem::QuantumReactor QR;
        WarpSystem::QuantumReactor QR2;
        WarpSystem::Core core(&QR);
        WarpSystem::Core core2 (&QR2);

        UssKreog.setupCore(&core);
        UssKreog.checkCore();
        Independent.setupCore(&core2);
        Independent.checkCore();
        QR.setStability(false);
        QR2.setStability(false);
        UssKreog.checkCore();
        Independent.checkCore();
    }
    cr_assert_stdout_eq_str
    (
        "The ship USS Kreog has been finished.\n"
        "It is 289 m in length and 132 m in width.\n"
        "It can go to Warp 6!\n"
        "The independent ship Greok just finished its construction.\n"
        "It is 150 m in length and 230 m in width.\n"
        "USS Kreog: The core is set.\n"
        "USS Kreog: The core is stable at the time.\n"
        "Greok: The core is set.\n"
        "Greok: The core is stable at the time.\n"
        "USS Kreog: The core is unstable at the time.\n"
        "Greok: The core is unstable at the time.\n"
    );
}
