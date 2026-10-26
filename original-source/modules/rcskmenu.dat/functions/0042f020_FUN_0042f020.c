/*
 * FUN_0042f020 at 0042f020
 * undefined __register FUN_0042f020(int param_1)
 * Address ranges: 0042f020-0042f08d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042f020(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (*(char *)(param_1 + 0x168) != '\0') {
    iVar1 = FUN_0044268c(param_1);
    if (-1 < iVar1 + -1) {
      iVar4 = 0;
      do {
        piVar2 = (int *)FUN_00442650(param_1,iVar4);
        if (((*(byte *)((int)piVar2 + 0x41) & 0x80) != 0) && (*(char *)((int)piVar2 + 0x47) != '\0')
           ) {
          (**(code **)(*piVar2 + 0x70))();
        }
        uVar3 = FUN_00403024(piVar2,(int)&PTR_FUN_0043be00);
        if ((char)uVar3 != '\0') {
          FUN_0042f020((int)piVar2);
        }
        iVar4 = iVar4 + 1;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
  }
  return;
}

