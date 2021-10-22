#include "Registers.h"
#include <exception>

int base = 0;
BYTE ram[8000] = { 0 }; // 8kb default
BYTE instrcache[1] = { 0 };

bool halted = false;

void execute_instruction()
{
	if (sizeof(instrcache) == 1)
	{
		throw new std::exception("FATAL - No instructions in cache");
	}

	for (base = 0; base < sizeof(ram); base++)
	{
		switch (ram[base])
		{
			/* Ignore NOP */
			case 0x21: /* LD HL, i16
					   > Load short i16 into HL*/
			{
				H = ram[base + 2];
				L = ram[base + 1];
				break;
			}

			case 0x31: /* LD SP, i16
					   > Loads short i16 into SP*/
			{
				SP = led16(ram[base + 1], ram[base + 2]);
				break;
			}

			case 0x32: /* LD (HL-), A
					   > Load A into memory location at HL, decrement HL*/
			{
				int loc = led16(H, L);
				ram[loc] = A;

				hl(--loc);
				
				break;
			}

			case 0xAF:
			{
				A = A ^ A;
				break;
			}
		}
	}
}