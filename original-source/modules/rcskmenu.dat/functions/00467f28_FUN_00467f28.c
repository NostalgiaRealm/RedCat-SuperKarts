/*
 * FUN_00467f28 at 00467f28
 * undefined __register FUN_00467f28(int * param_1, int param_2)
 * Address ranges: 00467f28-00467f9e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00467f28(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  if (param_2 != param_1[0x94]) {
    param_1[0x94] = param_2;
    (**(code **)(*param_1 + 0x74))();
    iVar1 = FUN_004674c4((int)param_1);
    if (-1 < iVar1 + -1) {
      iVar4 = 0;
      do {
        iVar2 = FUN_004674ac((int)param_1,iVar4);
        iVar2 = FUN_00417e98(*(int *)(iVar2 + 0x130));
        if (iVar2 != param_1[0x94]) {
          iVar2 = FUN_004674ac((int)param_1,iVar4);
          FUN_00417ea0(*(int **)(iVar2 + 0x130),param_1[0x94]);
          piVar3 = (int *)FUN_004674ac((int)param_1,iVar4);
          (**(code **)(*piVar3 + 0x74))();
        }
        iVar4 = iVar4 + 1;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
  }
  return;
}

