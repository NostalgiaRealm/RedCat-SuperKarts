/*
 * FUN_0041b4b4 at 0041b4b4
 * undefined __register FUN_0041b4b4(int * param_1, int param_2, undefined4 param_3)
 * Address ranges: 0041b4b4-0041b4ec
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041b4b4(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 extraout_ECX;
  
  if (param_1[8] == 0) {
    FUN_0041b0b4((int)param_1);
    param_3 = extraout_ECX;
  }
  iVar1 = param_1[8];
  *(undefined4 *)(iVar1 + 0x20) = 0;
  if (param_2 != *(int *)(iVar1 + 0x10)) {
    FUN_0041b604((int)param_1,0,param_3);
    *(int *)(param_1[8] + 0x10) = param_2;
    (**(code **)(*param_1 + 0x10))(param_1,param_1);
  }
  return;
}

