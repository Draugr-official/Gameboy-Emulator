#include "Registers.h"
#include "Cpu.h"
#include <exception>
 
int base = 0;
BYTE cache[8000] = { 0 }; // 8kb default
BYTE instrcache[1] = { 0 };

bool halted = false;

void execute_instruction()
{
	if (sizeof(instrcache) == 1)
	{
		throw new std::exception("FATAL - No instructions in cache");
	}

	for (base = 0; base < sizeof(cache); base++)
	{
		switch (cache[base])
		{
			/* Ignore NOP */
			case 0x21: /* LD HL, i16 */
			{
				H = cache[base + 2];
				L = cache[base + 1];
				break;
			}

			case 0x31: /* LD SP, i16 */
			{
				SP = led16(cache[base + 1], cache[base + 2]);
				break;
			}

			case 0x32: /* LD (HL-), A */
			{
				int loc = led16(H, L);
				cache[loc] = A;

				hl(--loc);
				
				break;
			}

			case 0xAF: /* xor A */
			{
				A ^= A;
				break;
			}

			case 0xCB: /* Opcode subdiv prefix */
			{
				switch (cache[++base])
				{
					case 0x7C:/* BIT 7, H */
					{
					
						break;
					}
				}
				break;
			}
		}
	}
}