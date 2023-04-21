#include <PwmSin.h>

#define TRIANGLE_CYCLE 0.02655 // sankakuha syuhasuu

void PwmSin_Gen(uint8_t *array, uint16_t size)
{
	uint16_t i; // loop counter
	double try;
	double sin_var;
	double sample;
	double step_value;

	sample = 0.0;
	step_value = (1.0 / (double)size);

	for (i = 0; i < size; i++)
	{
		try = ((0 <= fmod(sample, TRIANGLE_CYCLE)) && fmod(sample, TRIANGLE_CYCLE) < TRIANGLE_CYCLE / 2.0) ? (1 * (fmod(sample, TRIANGLE_CYCLE) / (TRIANGLE_CYCLE / 2.0))) : ((-1.0) * (fmod(sample, TRIANGLE_CYCLE) / (TRIANGLE_CYCLE / 2.0)) + 2.0 * 1.0);

		sin_var = (sinf(2 * PI * 1 * sample) * 0.5) + 0.5;

		if (sin_var >= try)
		{
			array[i] = 0xFF;
		}
		else
		{
			array[i] = 0x00;
		}

		sample += step_value;
	}
}
