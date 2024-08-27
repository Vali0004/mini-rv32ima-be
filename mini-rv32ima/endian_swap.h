#pragma once
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// Return: 1 is LE, 0 is BE
static int test_endianess()
{
	uint32_t x = 1;
	return (int)*((char*)&x);
}

static uint8_t uint8(uint8_t v)
{
	return v;
}
#define int8(v) (int8_t)(uint8(v))

static uint16_t uint16(uint16_t v)
{
	if (test_endianess())
	{
		return v;
	}
	return (v>>8) | (v<<8);
}
#define int16(v) (int16_t)(uint16(v))

static uint32_t uint32(uint32_t v)
{
	if (test_endianess())
	{
		return v;
	}
	return (v>>24) | ((v>>8) & 0xFF00) | ((v<<8) & 0xFF0000) | (v<<24);
}
#define int32(v) (int32_t)(uint32(v))

#ifdef __cplusplus
};
#endif