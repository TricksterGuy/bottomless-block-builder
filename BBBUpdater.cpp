#include "panel_table.hpp"
#include "logger.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
        FatalLog("bbb_updater file_to_update.bbb");

    const std::string& filename = argv[1];

    PanelTable table(12, 6);
    if (!table.load(filename))
        FatalLog("Could not open %s for reading", filename.c_str());
    if (!table.save(filename))
        FatalLog("Could not save %s", filename.c_str());
    InfoLog("Done");
}
