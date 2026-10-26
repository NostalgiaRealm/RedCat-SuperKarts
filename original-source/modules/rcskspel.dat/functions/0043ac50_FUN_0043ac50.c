/*
 * FUN_0043ac50 at 0043ac50
 * undefined FUN_0043ac50(void)
 * Address ranges: 0043ac50-0043ac71
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0043ac50(int *param_1,int param_2,int *param_3)

{
  int iVar1;
  
  *param_1 = *param_3;
  iVar1 = *param_3;
  param_1[3] = (int)param_3;
  param_1[1] = iVar1 + 0x1000;
  param_1[2] = param_2;
  return;
}

