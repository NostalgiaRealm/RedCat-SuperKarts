/*
 * FUN_00426bf0 at 00426bf0
 * undefined __register FUN_00426bf0(int * param_1, undefined4 param_2)
 * Address ranges: 00426bf0-00426c49
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00426bf0(int *param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  if ((short)param_2 != (short)param_1[0x1a]) {
    iVar4 = *(int *)(param_1[0x10] + 8);
    if (-1 < iVar4 + -1) {
      iVar3 = 0;
      do {
        piVar1 = (int *)FUN_0040f6b0((undefined4 *)param_1[0x10],iVar3);
        uVar2 = FUN_00403024(piVar1,(int)&LAB_00426280);
        if ((char)uVar2 != '\0') {
          piVar1 = (int *)FUN_0040f6b0((undefined4 *)param_1[0x10],iVar3);
          (**(code **)(*piVar1 + 0x58))(piVar1,param_2);
        }
        iVar3 = iVar3 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    *(short *)(param_1 + 0x1a) = (short)param_2;
    (**(code **)(*param_1 + 0x30))();
  }
  return;
}

