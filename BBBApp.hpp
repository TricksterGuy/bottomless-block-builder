#ifndef BBBAPP_HPP
#define BBBAPP_HPP

#include <wx/app.h>

class BBBApp : public wxApp
{
    public:
        virtual bool OnInit();
        virtual bool OnExceptionInMainLoop();
        virtual void OnFatalException();
        virtual void OnUnhandledException();
};

#endif

