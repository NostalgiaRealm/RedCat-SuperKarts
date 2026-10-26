/*
 * FUN_0049d8a0 at 0049d8a0
 * undefined FUN_0049d8a0(void)
 * Address ranges: 0049d8a0-0049d8fc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_0049d8a0(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x14) == 0) {
    return 0;
  }
  uVar1 = __ftol(*(int *)(param_1 + 0x14));
  return uVar1;
}

