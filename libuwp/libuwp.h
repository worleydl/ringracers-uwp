#pragma once

#define LIBAPI extern "C" __declspec(dllexport)
LIBAPI void uwp_GetScreenSize(int* x, int* y);
LIBAPI void uwp_GetBundlePath(char* buffer);
LIBAPI void uwp_GetBundleFilePath(char* buffer, const char* filename);
LIBAPI float uwp_GetRefreshRate();
