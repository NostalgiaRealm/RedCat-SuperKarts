/*
 * FUN_0049d7a0 at 0049d7a0
 * undefined FUN_0049d7a0(void)
 * Address ranges: 0049d7a0-0049d7c0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0049d7a0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_0049d870();
  if (iVar1 != 0) {
    FUN_004b3fd0(*(undefined4 *)(param_1 + 0x38));
    *(undefined4 *)(param_1 + 0x38) = 0xffffffff;
  }
  return;
}

