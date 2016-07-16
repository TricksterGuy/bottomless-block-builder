#include "BBBApp.hpp"
#include "BBBFrame.hpp"
#include "panels_gfx.xpm"
#include <wx/bitmap.h>
#include <vector>

#include "wxlogger.hpp"

IMPLEMENT_APP(BBBApp)

std::vector<wxBitmap> panelImages;


 /** OnInit
  *
  * Initializes the program
  */
bool BBBApp::OnInit()
{
    srand(time(NULL));
    logger.reset(new LoggerWx());

    if (!wxApp::OnInit())
        return false;

    wxHandleFatalExceptions();
    wxInitAllImageHandlers();

    SetVendorName("Bottomless Block Builder");
    SetAppName("Bottomless Block Builder");

    wxBitmap bitmap(panels_gfx_xpm);
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

bool BBBApp::OnExceptionInMainLoop()
{
    wxString error;
    try {
        throw; // Rethrow the current exception.
    } catch (const std::exception& e) {
        error = e.what();
    } catch (const char* e) {
        error = e;
    } catch ( ... ) {
        error = "unknown error.";
    }
    FatalLog("Unexpected exception has occurred: %s, the program will terminate.", error.c_str().AsChar());
    // Exit the main loop and thus terminate the program.
    return false;
}

void BBBApp::OnFatalException()
{
    FatalLog("Unexpected exception has occurred: the program will terminate.");
}

void BBBApp::OnUnhandledException()
{
    FatalLog("Unexpected exception has occurred: the program will terminate.");
}
