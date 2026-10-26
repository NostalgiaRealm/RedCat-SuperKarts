/*
 * FUN_004224d1 at 004224d1
 * undefined __stdcall FUN_004224d1(void)
 * Address ranges: 004224d1-004224f9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004224d1(void)

{
  HMODULE hModule;
  FARPROC pFVar1;
  
  hModule = GetModuleHandleA("KERNEL32");
  if (hModule != (HMODULE)0x0) {
    pFVar1 = GetProcAddress(hModule,"IsProcessorFeaturePresent");
    if (pFVar1 != (FARPROC)0x0) {
      (*pFVar1)(0);
      return;
    }
  }
  FUN_00422493();
  return;
}

