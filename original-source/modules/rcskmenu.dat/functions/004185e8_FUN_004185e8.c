/*
 * FUN_004185e8 at 004185e8
 * undefined __register FUN_004185e8(int param_1)
 * Address ranges: 004185e8-0041860c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004185e8(int param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_0047d6b0);
  *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + 1;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_0047d6b0);
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x38));
  return;
}

