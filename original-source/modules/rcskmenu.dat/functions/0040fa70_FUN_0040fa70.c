/*
 * FUN_0040fa70 at 0040fa70
 * undefined4 __register FUN_0040fa70(int param_1)
 * Address ranges: 0040fa70-0040fa80
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0040fa70(int param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  return *(undefined4 *)(param_1 + 4);
}

