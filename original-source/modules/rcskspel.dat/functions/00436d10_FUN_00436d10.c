/*
 * FUN_00436d10 at 00436d10
 * undefined FUN_00436d10(void)
 * Address ranges: 00436d10-00436d46
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00436d10(int param_1)

{
  undefined4 uVar1;
  
  if (-1 < *(int *)(param_1 + 0x34)) {
    uVar1 = FUN_004365d0();
    FUN_0049dd20(uVar1);
    FUN_0049d7a0();
    *(undefined4 *)(param_1 + 0x34) = 0xffffffff;
  }
  return;
}

