#pragma once

#define LIBAPI extern "C" __declspec(dllexport)
LIBAPI void uwp_GetScreenSize(int* x, int* y);
