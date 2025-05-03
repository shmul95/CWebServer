/*
** EPITECH PROJECT, 2025
** CWebServer
** File description:
** debug
*/

#ifndef DEBUG_H_
    #define DEBUG_H_
    #include "libs.h"
    #include "struct.h"
    #include "const.h"

    static inline int is_debug_enabled() {
        const char *env = getenv("DEBUG");
        return env ? atoi(env) : 0;
    }

    #define DO_DEBUG (is_debug_enabled())

    #define debug_print(...)                                \
    ({                                                      \
        pdebug(__FILE__, __LINE__, __VA_ARGS__);            \
    })

    #define debug_str(var)                                  \
    ({                                                      \
        pdebug(__FILE__, __LINE__,                          \
            #var "<%p> : %s", var, var);                    \
    })

    #define debug_ret(type, fn, ...)                        \
    ({                                                      \
        pdebug(__FILE__, __LINE__, "Calling " #fn);         \
        type res = fn(__VA_ARGS__);                         \
        pdebug(__FILE__, __LINE__, #fn " returned");        \
        res;                                                \
    })

    #define debug_void(fn, ...)                             \
    ({                                                      \
        pdebug(__FILE__, __LINE__, "Calling " #fn);         \
        fn(__VA_ARGS__);                                    \
        pdebug(__FILE__, __LINE__, #fn " returned");        \
    })

    void pdebug(
        const char *file, const int line,
        const char *format, ...
    );

#endif /* !DEBUG_H_ */
