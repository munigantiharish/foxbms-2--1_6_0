/**
 *
 * @copyright &copy; 2010 - 2023, Fraunhofer-Gesellschaft zur Foerderung der angewandten Forschung e.V.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * We kindly request you to use one or more of the following phrases to refer to
 * foxBMS in your hardware, software, documentation or advertising materials:
 *
 * - &Prime;This product uses parts of foxBMS&reg;&Prime;
 * - &Prime;This product includes parts of foxBMS&reg;&Prime;
 * - &Prime;This product is derived from foxBMS&reg;&Prime;
 *
 */

/**
 * @file    test_mcu.c
 * @author  foxBMS Team
 * @date    2020-04-01 (date of creation)
 * @updated 2023-10-12 (date of last update)
 * @version v1.6.0
 * @ingroup UNIT_TEST_IMPLEMENTATION
 * @prefix  TEST
 *
 * @brief   Tests for the mcu module
 *
 */

/*========== Includes =======================================================*/
#include "unity.h"

#include "mcu.h"

/*========== Unit Testing Framework Directives ==============================*/

/*========== Definitions and Implementations for Unit Test ==================*/
volatile uint32_t MCU_RTI_CNT0_FRC0_REG = 0u;

/*========== Setup and Teardown =============================================*/
void setUp(void) {
    MCU_RTI_CNT0_FRC0_REG = 0u;
}

void tearDown(void) {
}

/*========== Test Cases =====================================================*/
void testMCU_Delay_us(void) {
    MCU_Delay_us(1);
}

/** test whether #MCU_GetFreeRunningCount() returns the correct value */
void testMCU_GetFreeRunningCount(void) {
    TEST_ASSERT_EQUAL(0u, MCU_GetFreeRunningCount());
    MCU_RTI_CNT0_FRC0_REG = 42u;
    TEST_ASSERT_EQUAL(42u, MCU_GetFreeRunningCount());
}

/** test conversion function for FRC #MCU_ConvertFrcDifferenceToTimespan_us() */
void testMCU_ConvertFrcDifferenceToTimespan_us(void) {
    TEST_ASSERT_EQUAL(0u, MCU_ConvertFrcDifferenceToTimespan_us(0u));

    TEST_ASSERT_EQUAL(977u, MCU_ConvertFrcDifferenceToTimespan_us(0xBEEFu));
}
