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

#ifndef CAESAR_H
#define CAESAR_H

#include <stdbool.h>
#include <stdint.h>

// Caesar cipher encryption/decryption for voice samples
// Operates on 8-bit audio samples with configurable offset

// Initialize the Caesar cipher with an offset value (0-255)
void CAESAR_Init(uint8_t offset);

// Get the current Caesar cipher offset
uint8_t CAESAR_GetOffset(void);

// Set the Caesar cipher offset
void CAESAR_SetOffset(uint8_t offset);

// Enable or disable Caesar cipher encryption/decryption
void CAESAR_SetEnabled(bool enabled);

// Check if Caesar cipher is enabled
bool CAESAR_IsEnabled(void);

// Encrypt a buffer of audio samples
// input: source buffer
// output: destination buffer (can be same as input for in-place encryption)
// length: number of samples to process
void CAESAR_Encrypt(const uint8_t *input, uint8_t *output, uint16_t length);

// Decrypt a buffer of audio samples
// input: source buffer
// output: destination buffer (can be same as input for in-place decryption)
// length: number of samples to process
void CAESAR_Decrypt(const uint8_t *input, uint8_t *output, uint16_t length);

#endif // CAESAR_H
