/*
 * FUN_0040be3c at 0040be3c
 * undefined __register FUN_0040be3c(void)
 * Address ranges: 0040be3c-0040be71
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040be3c(void)

{
  HMODULE hModule;
  
  hModule = GetModuleHandleA("kernel32.dll");
  if (hModule != (HMODULE)0x0) {
    DAT_0047b138 = GetProcAddress(hModule,"GetDiskFreeSpaceExA");
  }
  if (DAT_0047b138 == (FARPROC)0x0) {
    DAT_0047b138 = FUN_004082b4;
  }
  return;
}

