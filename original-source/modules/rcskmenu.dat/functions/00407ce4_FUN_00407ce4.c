/*
 * FUN_00407ce4 at 00407ce4
 * undefined4 __register FUN_00407ce4(int * param_1, int * param_2, uint param_3)
 * Address ranges: 00407ce4-00407d02
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00407ce4(int *param_1,int *param_2,uint param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  bool bVar6;
  
  uVar1 = 0;
  uVar3 = param_3 & 3;
  uVar2 = param_3 >> 2;
  bVar6 = uVar2 == 0;
  do {
    piVar4 = param_1;
    piVar5 = param_2;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    piVar5 = param_2 + 1;
    piVar4 = param_1 + 1;
    bVar6 = *param_1 == *param_2;
    param_1 = piVar4;
    param_2 = piVar5;
  } while (bVar6);
  if (bVar6) {
    bVar6 = true;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      bVar6 = (char)*piVar4 == (char)*piVar5;
      piVar4 = (int *)((int)piVar4 + 1);
      piVar5 = (int *)((int)piVar5 + 1);
    } while (bVar6);
    if (bVar6) {
      uVar1 = 1;
    }
  }
  return uVar1;
}

