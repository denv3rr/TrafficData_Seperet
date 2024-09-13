#include "link_opener.h"
#include <cstdlib>

void LinkOpener::openSeperetWebsite()
{
    openURL("https://seperet.com");
}

void LinkOpener::openSeperetYouTube()
{
    openURL("https://youtube.com/@seperet");
}

void LinkOpener::openURL(const std::string &url)
{
    std::string command = "start " + url;
    system(command.c_str());
}
