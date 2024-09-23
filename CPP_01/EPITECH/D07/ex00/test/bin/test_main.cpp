/*
** test_main.cpp for EPITECH_42_CPP_POOL in /home/paradis/Workspace/Development/CPP/EPITECH_42_CPP_POOL/CPP_01/EPITECH/D07/ex00/test/bin
**
** Made by Paradis
** Login   <Adil Denia>
**
** Started on  Fri Sep 20 7:46:17 PM 2024 Paradis
** Last update Tue Sep 23 9:04:09 PM 2024 Paradis
*/



#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>

#include "../../include/Federation.hpp"
#include "../../include/WarpSystem.hpp"

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
test_Federation_Starfleet_Ship_setupCore_smartPointer_std_output,
.init = redirect_all_stdout)
{
    {
        Federation::Starfleet::Ship     UssKreog(289, 132, "Kreog", 6);
        WarpSystem::QuantumReactor QR;
        std::unique_ptr<WarpSystem::Core> core = std::make_unique<WarpSystem::Core>(&QR);
        UssKreog.setupCore(std::move(core));
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
test_Federation_Starfleet_Ship_setupCore_smartPointer_with_NULLPTR_stderr_output,
.init = redirect_all_stdout)
{
    {
        Federation::Starfleet::Ship     UssKreog(289, 132, "Kreog", 6);
        std::unique_ptr<WarpSystem::Core> core = nullptr;
        UssKreog.setupCore(std::move(core));
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
test_Federation_Starfleet_Ship_checkCore_with_smartPointer_is_stable_std_output,
.init = redirect_all_stdout)
{
    {
        Federation::Starfleet::Ship UssKreog(289, 132, "Kreog", 6);
        WarpSystem::QuantumReactor QR;
        std::unique_ptr<WarpSystem::Core> core(std::make_unique<WarpSystem::Core>(&QR));
        UssKreog.setupCore(std::move(core));
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
test_Federation_Starfleet_Ship_checkCore_with_smartPointer_is_unstable_std_output,
.init = redirect_all_stdout)
{
    {
        Federation::Starfleet::Ship     UssKreog(289, 132, "Kreog", 6);
        WarpSystem::QuantumReactor QR;

        QR.setStability(false);
        std::unique_ptr<WarpSystem::Core> core(std::make_unique<WarpSystem::Core>(&QR));

        UssKreog.setupCore(std::move(core));
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