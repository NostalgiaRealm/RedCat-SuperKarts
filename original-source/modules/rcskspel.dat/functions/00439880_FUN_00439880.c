/*
 * FUN_00439880 at 00439880
 * undefined FUN_00439880(void)
 * Address ranges: 00439880-004398b2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00439880(int *param_1)

{
  int iVar1;
  
  if (param_1[2] == *param_1) {
    iVar1 = param_1[3];
    param_1[3] = iVar1 + -4;
    iVar1 = *(int *)(iVar1 + -4);
    *param_1 = iVar1;
    param_1[1] = iVar1 + 0x1000;
    param_1[2] = iVar1 + 0x1000;
    param_1[2] = iVar1 + 0xffc;
    return;
  }
  param_1[2] = param_1[2] + -4;
  return;
}

