/* msvcrt.dll predates C11 quick_exit/at_quick_exit; libstdc++ headers built
 * against UCRT declare std::quick_exit unconditionally.  Declare the pair here
 * so <cstdlib> resolves; the implementation lives in
 * msvcrt_quick_exit_shim.cpp and runs registered handlers before _exit. */
#pragma once
#if defined(__MINGW32__) && !defined(_UCRT)
#ifdef __cplusplus
extern "C" {
#endif
int at_quick_exit(void (*handler)(void));
__attribute__((noreturn)) void quick_exit(int status);
#ifdef __cplusplus
}
#endif
#endif
