/*
 * FUN_00426b30 at 00426b30
 * undefined __register FUN_00426b30(int * param_1, uint * param_2)
 * Address ranges: 00426b30-00426b95
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00426b30(int *param_1,uint *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined1 in_ZF;
  
  FUN_00403ee0(param_2,(uint *)param_1[0x18]);
  if (!(bool)in_ZF) {
    iVar4 = *(int *)(param_1[0x10] + 8);
    if (-1 < iVar4 + -1) {
      iVar3 = 0;
      do {
        piVar1 = (int *)FUN_0040f6b0((undefined4 *)param_1[0x10],iVar3);
        uVar2 = FUN_00403024(piVar1,(int)&LAB_00426280);
        if ((char)uVar2 != '\0') {
          piVar1 = (int *)FUN_0040f6b0((undefined4 *)param_1[0x10],iVar3);
          (**(code **)(*piVar1 + 0x50))(piVar1,param_2);
        }
        iVar3 = iVar3 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    FUN_00403ba4(param_1 + 0x18,param_2);
    (**(code **)(*param_1 + 0x30))();
  }
  return;
}

