#include "BBBApp.hpp"
#include "BBBFrame.hpp"
#include <wx/bitmap.h>
#include <vector>

IMPLEMENT_APP(BBBApp)

std::vector<wxBitmap> panelImages;


 /** OnInit
  *
  * Initializes the program
  */
bool BBBApp::OnInit()
{
    srand(time(NULL));

    if (!wxApp::OnInit())
        return false;

    SetVendorName("Bottomless Block Builder");
    SetAppName("Bottomless Block Builder");

    wxBitmap bitmap("panels_gfx.png");
    panelImages.push_back(bitmap.GetSubBitmap(wxRect(112, 16, 16, 16)));
    panelImages.push_back(bitmap.GetSubBitmap(wxRect(0, 0, 16, 16)));
    panelImages.push_back(bitmap.GetSubBitmap(wxRect(16, 0, 16, 16)));
    panelImages.push_back(bitmap.GetSubBitmap(wxRect(32, 0, 16, 16)));
    panelImages.push_back(bitmap.GetSubBitmap(wxRect(48, 0, 16, 16)));
    panelImages.push_back(bitmap.GetSubBitmap(wxRect(64, 0, 16, 16)));
    panelImages.push_back(bitmap.GetSubBitmap(wxRect(80, 0, 16, 16)));
    panelImages.push_back(bitmap.GetSubBitmap(wxRect(96, 0, 16, 16)));
    panelImages.push_back(bitmap.GetSubBitmap(wxRect(112, 0, 16, 16)));

    BBBFrame* frame = new BBBFrame();
    frame->Show();

    return true;
}

