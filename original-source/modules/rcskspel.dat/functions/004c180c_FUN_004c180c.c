/*
 * FUN_004c180c at 004c180c
 * undefined FUN_004c180c(void)
 * Address ranges: 004c180c-004c1834
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004c180c(void)

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
  FUN_004c17ce();
  return;
}

