/*
 * FUN_004673a0 at 004673a0
 * undefined __register FUN_004673a0(int param_1, undefined4 param_2, undefined4 param_3, undefined * param_4, undefined4 param_5)
 * Address ranges: 004673a0-004673df
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004673a0(int param_1,undefined4 param_2,undefined4 param_3,undefined *param_4,
                 undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(*(int *)(param_1 + 0x240) + 8);
  if (-1 < iVar2 + -1) {
    iVar3 = 0;
    do {
      uVar1 = FUN_0040f6b0(*(undefined4 **)(param_1 + 0x240),iVar3);
      (*(code *)param_4)(param_5,uVar1);
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}

