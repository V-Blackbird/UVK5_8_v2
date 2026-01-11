/* Copyright 2023 Dual Tachyon
 * https://github.com/DualTachyon
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 *     Unless required by applicable law or agreed to in writing, software
 *     distributed under the License is distributed on an "AS IS" BASIS,
 *     WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *     See the License for the specific language governing permissions and
 *     limitations under the License.
 */

#include "caesar.h"
#include <string.h>

// Internal state
static uint8_t g_caesar_offset = 0;
static bool g_caesar_enabled = false;

void CAESAR_Init(uint8_t offset)
{
    g_caesar_offset = offset;
    g_caesar_enabled = false;
}

uint8_t CAESAR_GetOffset(void)
{
    return g_caesar_offset;
}

void CAESAR_SetOffset(uint8_t offset)
{
    g_caesar_offset = offset;
}

void CAESAR_SetEnabled(bool enabled)
{
    g_caesar_enabled = enabled;
}

bool CAESAR_IsEnabled(void)
{
    return g_caesar_enabled;
}

void CAESAR_Encrypt(const uint8_t *input, uint8_t *output, uint16_t length)
{
    if (!g_caesar_enabled || g_caesar_offset == 0)
    {
        // If disabled or offset is 0, just copy input to output
        if (input != output)
        {
            memcpy(output, input, length);
        }
        return;
    }

    // Apply Caesar cipher encryption (simple addition with wrap-around)
    for (uint16_t i = 0; i < length; i++)
    {
        output[i] = input[i] + g_caesar_offset;
    }
}

void CAESAR_Decrypt(const uint8_t *input, uint8_t *output, uint16_t length)
{
    if (!g_caesar_enabled || g_caesar_offset == 0)
    {
        // If disabled or offset is 0, just copy input to output
        if (input != output)
        {
            memcpy(output, input, length);
        }
        return;
    }

    // Apply Caesar cipher decryption (simple subtraction with wrap-around)
    for (uint16_t i = 0; i < length; i++)
    {
        output[i] = input[i] - g_caesar_offset;
    }
}
