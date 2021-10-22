#include <Windows.h>

/* little endian decode 16 bit integer */
#define led16(a, b) ((UINT16)a << 8) + b

/* AF */
BYTE A;

/* BC */
BYTE B; // Hi
BYTE C; // Lo
void bc(UINT16 bc)
{
	B = bc & 0xFF00;
	C = bc & 0x00FF;
}

/* DE */
BYTE D; // Hi
BYTE E; // Lo
void de(UINT16 de)
{
	D = de & 0xFF00;
	E = de & 0x00FF;
}

/* HL */
BYTE H; // Hi
BYTE L; // Lo
void hl(UINT16 hl)
{
	H = hl & 0xFF00;
	L = hl & 0x00FF;
}

/* SP */
UINT16 SP;

/* PC */
UINT16 PC;