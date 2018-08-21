#pragma once
#include <string>
#include "../srcs/Error.hpp"

#define SDL_CHECK(x, msg) if (!(x))                                      \
    throw Error::RuntimeError(std::string(msg": ") + SDL_GetError())
