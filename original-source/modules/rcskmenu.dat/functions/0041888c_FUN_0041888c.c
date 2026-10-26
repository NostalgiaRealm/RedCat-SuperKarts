/*
 * FUN_0041888c at 0041888c
 * undefined __register FUN_0041888c(int param_1)
 * Address ranges: 0041888c-004188b0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041888c(int param_1)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x38));
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_0047d6b0);
  *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + -1;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_0047d6b0);
  return;
}

