/*
 * FUN_00417254 at 00417254
 * undefined __register FUN_00417254(int param_1)
 * Address ranges: 00417254-00417261
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00417254(int param_1)

{
  if (*(LPCRITICAL_SECTION *)(param_1 + 0x14) != (LPCRITICAL_SECTION)0x0) {
    EnterCriticalSection(*(LPCRITICAL_SECTION *)(param_1 + 0x14));
  }
  return;
}

