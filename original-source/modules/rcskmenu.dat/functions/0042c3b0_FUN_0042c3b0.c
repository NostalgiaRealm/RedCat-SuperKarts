/*
 * FUN_0042c3b0 at 0042c3b0
 * undefined __register FUN_0042c3b0(int * param_1, int * param_2, undefined4 * param_3)
 * Address ranges: 0042c3b0-0042c3f6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042c3b0(int *param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_1c [4];
  
  puVar3 = local_1c;
  for (iVar2 = 4; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *param_3;
    param_3 = param_3 + 1;
    puVar3 = puVar3 + 1;
  }
  iVar2 = param_1[9];
  iVar1 = param_1[0x24];
  FUN_0043eef0(param_1,param_2,local_1c);
  if (((param_1[9] != 0) && (iVar2 == param_1[9])) && (iVar1 != param_1[0x24])) {
    FUN_00442cd4((int)param_1);
  }
  return;
}

