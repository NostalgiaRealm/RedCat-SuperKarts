/*
 * FUN_00426c4c at 00426c4c
 * undefined __register FUN_00426c4c(int * param_1, undefined4 param_2)
 * Address ranges: 00426c4c-00426ca3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00426c4c(int *param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  if ((char)param_2 != *(char *)((int)param_1 + 0x6a)) {
    iVar4 = *(int *)(param_1[0x10] + 8);
    if (-1 < iVar4 + -1) {
      iVar3 = 0;
      do {
        piVar1 = (int *)FUN_0040f6b0((undefined4 *)param_1[0x10],iVar3);
        uVar2 = FUN_00403024(piVar1,(int)&LAB_00426280);
        if ((char)uVar2 != '\0') {
          piVar1 = (int *)FUN_0040f6b0((undefined4 *)param_1[0x10],iVar3);
          (**(code **)(*piVar1 + 0x5c))(piVar1,param_2);
        }
        iVar3 = iVar3 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    *(char *)((int)param_1 + 0x6a) = (char)param_2;
    (**(code **)(*param_1 + 0x30))();
  }
  return;
}

