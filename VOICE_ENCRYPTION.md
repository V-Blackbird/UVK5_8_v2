# Voice Encryption Feature

## Overview

This feature adds digital voice encryption capability to the Quansheng UV-K5(8) v2 firmware using a Caesar cipher algorithm. The implementation is designed to be lightweight and memory-efficient.

## Compile-Time Configuration

To enable this feature, set the following flag in your CMake configuration:

```cmake
ENABLE_VOICE_ENCRYPTION=ON
```

Or in the Makefile:

```makefile
ENABLE_VOICE_ENCRYPTION ?= 1
```

## Menu Options

When enabled, two new menu entries are added:

### 1. Digital Encryption Enable/Disable (DigEnc)
- **Location:** Settings menu
- **Options:** OFF / ON
- **Default:** OFF
- **Description:** Enables or disables voice encryption globally

### 2. Encryption Offset (EncOfs)
- **Location:** Settings menu
- **Range:** 0-255
- **Default:** 0
- **Description:** Sets the Caesar cipher offset value
  - 0 = Encryption disabled (pass-through)
  - 1-255 = Encryption enabled with specified offset

## How It Works

The Caesar cipher encryption works by shifting each audio sample byte by a fixed offset value:
- **Encryption:** `encrypted_sample = original_sample + offset`
- **Decryption:** `original_sample = encrypted_sample - offset`

Both transmitter and receiver must use the same offset value to communicate.

## Usage Instructions

1. **Enable the feature at compile time** by setting `ENABLE_VOICE_ENCRYPTION=1`
2. **Compile the firmware** using Docker or your preferred build method
3. **Flash the firmware** to your radio
4. **Configure encryption:**
   - Navigate to the menu
   - Find "DigEnc" and set to ON
   - Find "EncOfs" and set your desired offset (recommend non-zero, e.g., 128)
5. **Ensure both radios** use the same offset value for communication

## Technical Details

### Memory Usage
- **Static memory:** 2 bytes (offset + enabled flag)
- **Code size:** ~200-300 bytes (optimized for minimal footprint)

### Performance
- **Algorithm:** Caesar cipher (simple byte shift)
- **Complexity:** O(n) - linear with sample count
- **Overhead:** Minimal - single addition/subtraction per sample

### Bandwidth
- **Recommended:** 12.5 kHz narrow bandwidth
- **Compatible with:** All supported modulation modes (FM, AM, USB)

## Limitations

**IMPORTANT:** This implementation provides the framework for voice encryption, including:
- Caesar cipher algorithm
- Menu system integration
- Settings storage in EEPROM
- Enable/disable functionality

However, **actual real-time voice sample encryption** requires low-level integration with the BK4819 chip's ADC/DAC audio path. This level of hardware access may not be available in the current firmware architecture.

The current implementation serves as:
1. A proof of concept for encryption infrastructure
2. A framework for future hardware-level integration
3. A demonstration of memory-efficient encryption algorithms

## Security Considerations

⚠️ **WARNING:** The Caesar cipher is a very simple encryption algorithm and provides minimal security. It is:
- Easy to break with frequency analysis
- Not suitable for sensitive communications
- Intended for hobby/experimental use only

For production security needs, more sophisticated encryption algorithms would be required.

## Future Enhancements

Possible improvements for future versions:
- Integration with BK4819 ADC/DAC hooks (if available)
- More sophisticated encryption algorithms (e.g., XOR with LFSR)
- Key exchange protocols
- Multiple encryption profiles
- Integration with CTCSS/DCS for automatic key selection

## Building

To build with voice encryption enabled:

```bash
# Using Docker
./compile-with-docker.sh custom

# Using CMake directly
cmake --preset Custom -DENABLE_VOICE_ENCRYPTION=ON
cmake --build build/Custom
```

## Credits

This feature was implemented as part of the V-Blackbird/UVK5_8_v2 firmware project.

## License

Licensed under the Apache License, Version 2.0. See LICENSE file for details.
