/*
 * FUN_00449d30 at 00449d30
 * undefined FUN_00449d30(void)
 * Address ranges: 00449d30-00449d69
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00449d30(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    FUN_004be99e(iVar1,0x10,*(undefined4 *)(iVar1 + -4),FUN_00449910);
    FUN_004bc150(iVar1 + -4);
    param_1[1] = 0;
    return;
  }
  param_1[1] = 0;
  return;
}

