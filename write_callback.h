/*
 * write callback header file
 *
 */

#ifndef WRITE_CALLBACK_H
#define WRITE_CALLBACK_H

// Standard
#include <cstddef>

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);

#endif // WRITE_CALLBACK_H