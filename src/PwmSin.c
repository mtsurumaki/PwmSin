#include <PwmSin.h>

#define TRIANGLE_CYCLE 0.02655 // sankakuha syuhasuu
#define BIT_PER_BYTE 8

void PwmSin_Gen(uint8_t *array, uint16_t size)
{
	uint16_t i; // loop counter
	uint8_t j;
	double try;
	double sin_var;
	double sample;
	double step_value;
	uint16_t = offset;

	sample = 0.0;
	step_value = (1.0 / (double)size);
	offset = (size / BIT_PER_BYTE);

	for (i = 0; i < size; i++)
	{
		try = ((0 <= fmod(sample, TRIANGLE_CYCLE)) && fmod(sample, TRIANGLE_CYCLE) < TRIANGLE_CYCLE / 2.0) ? (1 * (fmod(sample, TRIANGLE_CYCLE) / (TRIANGLE_CYCLE / 2.0))) : ((-1.0) * (fmod(sample, TRIANGLE_CYCLE) / (TRIANGLE_CYCLE / 2.0)) + 2.0 * 1.0);

		sin_var = (sinf(2 * PI * 1 * sample) * 0.5) + 0.5;

		if (sin_var >= try)
		{
			for (j = 0; j < BIT_PER_BYTE; j++)
			{
				array[(i + (j * offset)) % size] |= (0x01 << j);
			}
		}
		else
		{
			for (j = 0; j < BIT_PER_BYTE; j++)
			{
				array[(i + (j * offset)) % size] &= (0xFF ^ (0x01 << j));
			}
		}

		sample += step_value;
	}
}
