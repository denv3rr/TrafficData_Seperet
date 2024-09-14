/*
 * write callback c++ file
 *
 */

// Standard
#include <string>

// Local
#include "write_callback.h"

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string *)userp)->append((char *)contents, size * nmemb);
    return size * nmemb;
}