/*
 * FUN_0043a400 at 0043a400
 * undefined FUN_0043a400(void)
 * Address ranges: 0043a400-0043a432
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0043a400(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[2];
  param_1[2] = iVar1 + 4;
  if (iVar1 + 4 == param_1[1]) {
    iVar1 = param_1[3];
    param_1[3] = iVar1 + 4;
    iVar1 = *(int *)(iVar1 + 4);
    *param_1 = iVar1;
    param_1[1] = iVar1 + 0x1000;
    param_1[2] = *param_1;
  }
  return;
}

