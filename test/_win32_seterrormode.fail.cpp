#include <windows.h>

namespace {

  class Win32ctor {
  public:
    Win32ctor() {
      SetErrorMode(SEM_FAILCRITICALERRORS |
                   SEM_NOGPFAULTERRORBOX |
                   SEM_NOOPENFILEERRORBOX);
    }
  };

  static Win32ctor ctor;
}
