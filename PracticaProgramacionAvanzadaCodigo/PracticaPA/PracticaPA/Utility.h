#pragma once
#include <iostream>
#include <ostream>
#include <string>

#define COLOR_BLACK_FG "\033[30m"
#define COLOR_BLACK_BG "\033[40m"
#define COLOR_RED_FG "\033[31m"
#define COLOR_RED_BG "\033[41m"
#define COLOR_GREEN_FG "\033[32m"
#define COLOR_GREEN_BG "\033[42m"
#define COLOR_YELLOW_FG "\033[33m"
#define COLOR_YELLOW_BG "\033[43m"
#define COLOR_BLUE_FG "\033[34m"
#define COLOR_BLUE_BG "\033[44m"
#define COLOR_MAGENTA_FG "\033[35m"
#define COLOR_MAGENTA_BG "\033[45m"
#define COLOR_CYAN_FG "\033[36m"
#define COLOR_CYAN_BG "\033[46m"
#define COLOR_WHITE_FG "\033[37m"
#define COLOR_WHITE_BG "\033[47m"
#define COLOR_BRIGHT_BLACK_FG "\033[90m"
#define COLOR_BRIGHT_BLACK_BG "\033[100m"
#define COLOR_BRIGHT_RED_FG "\033[91m"
#define COLOR_BRIGHT_RED_BG "\033[101m"
#define COLOR_BRIGHT_GREEN_FG "\033[92m"
#define COLOR_BRIGHT_GREEN_BG "\033[102m"
#define COLOR_BRIGHT_YELLOW_FG "\033[93m"
#define COLOR_BRIGHT_YELLOW_BG "\033[103m"
#define COLOR_BRIGHT_BLUE_FG "\033[94m"
#define COLOR_BRIGHT_BLUE_BG "\033[104m"
#define COLOR_BRIGHT_MAGENTA_FG "\033[95m"
#define COLOR_BRIGHT_MAGENTA_BG "\033[105m"
#define COLOR_BRIGHT_CYAN_FG "\033[96m"
#define COLOR_BRIGHT_CYAN_BG "\033[106m"
#define COLOR_BRIGHT_WHITE_FG "\033[97m"
#define COLOR_BRIGHT_WHITE_BG "\033[107m"
#define COLOR_END "\033[0m"

namespace Utility
{
    template<typename T>
    void printToStream(std::ostream& os, T const& elem)
    {
        os << elem;
    }

    template<typename T, typename ...Args>
    void printToStream(std::ostream& os, T const& elem, Args ...args)
    {
        printToStream(os, elem);
        printToStream(os, args...);
    }

    template<typename T, typename ...Args>
    void print(T const& elem, Args ...args)
    {
        printToStream(std::cout, elem, args...);
    }

    template<typename T, typename ...Args>
    void printError(T const& elem, Args ...args)
    {
        print("[",COLOR_BRIGHT_RED_FG,"ERROR",COLOR_END,"]: ");
        print(elem,args...);
    }

    template<typename T, typename ...Args>
    void printWarning(T const& elem, Args ...args)
    {
        print("[", COLOR_BRIGHT_YELLOW_FG, "WARNING", COLOR_END, "]: ");
        print(elem, args...);
    }

    template<typename T, typename ...Args>
    void printSuccess(T const& elem, Args ...args)
    {
        print("[", COLOR_BRIGHT_GREEN_FG, "SUCCESS", COLOR_END, "]: ");
        print(elem, args...);
    }
}
