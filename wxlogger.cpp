#include "wxlogger.hpp"
#include <wx/msgdlg.h>

void LoggerWx::Log(LogLevel level, const char* format, va_list ap)
{
    if (level > log_level)
        return;

    char buffer[1024];
    vsnprintf(buffer, 1024, format, ap);
    if (level == LogLevel::ERROR || level == LogLevel::FATAL)
    {
        wxMessageBox(buffer, level == LogLevel::ERROR ? "Error!" : "Fatal!");
        if (level == LogLevel::FATAL)
            throw "Fatal exception occured";
    }
    else
        (*out) << buffer << std::endl;
}
