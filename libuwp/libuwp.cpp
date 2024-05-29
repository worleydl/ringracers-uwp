/*
    Various helpers for UWP apps, add a new function if you need to interop between a dll and UWP calls
*/
#include "pch.h"
#include "libuwp.h"
#include <wrl.h>

#include <winrt/Windows.ApplicationModel.Core.h>
#include <winrt/Windows.UI.Composition.h>
#include <winrt/Windows.Graphics.Display.Core.h>

static int width = 0;
static int height = 0;

using namespace winrt::Windows;
using namespace winrt::Windows::ApplicationModel::Core;
using namespace winrt::Windows::Graphics::Display::Core;

void uwp_GetBundlePath(char* buffer)
{
    sprintf_s(buffer, 1024, "%s", winrt::to_string(ApplicationModel::Package::Current().InstalledPath()).c_str());
}

void uwp_GetBundleFilePath(char* buffer, const char *filename)
{
    sprintf_s(buffer, 1024, "%s\\%s", winrt::to_string(ApplicationModel::Package::Current().InstalledPath()).c_str(), filename);
}


void uwp_GetScreenSize(int* x, int* y)
{
	if (width == 0) {
        HdmiDisplayInformation hdi = HdmiDisplayInformation::GetForCurrentView();
        width = hdi.GetCurrentDisplayMode().ResolutionWidthInRawPixels();
        height = hdi.GetCurrentDisplayMode().ResolutionHeightInRawPixels();
	}

    *x = width;
    *y = height;
}

float uwp_GetRefreshRate()
{
    return HdmiDisplayInformation::GetForCurrentView().GetCurrentDisplayMode().RefreshRate();
}
