/*
 * FUN_00468e54 at 00468e54
 * undefined __register FUN_00468e54(void)
 * Address ranges: 00468e54-00468ec6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00468e54(void)

{
  HMODULE hModule;
  
  hModule = GetModuleHandleA("ole32.dll");
  if (hModule != (HMODULE)0x0) {
    _DAT_0047c3e8 = GetProcAddress(hModule,"CoCreateInstanceEx");
    DAT_0047c3ec = GetProcAddress(hModule,"CoInitializeEx");
    _DAT_0047c3f0 = GetProcAddress(hModule,"CoAddRefServerProcess");
    _DAT_0047c3f4 = GetProcAddress(hModule,"CoReleaseServerProcess");
    _DAT_0047c3f8 = GetProcAddress(hModule,"CoResumeClassObjects");
    _DAT_0047c3fc = GetProcAddress(hModule,"CoSuspendClassObjects");
  }
  return;
}

