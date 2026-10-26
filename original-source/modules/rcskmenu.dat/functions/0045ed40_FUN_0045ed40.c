/*
 * FUN_0045ed40 at 0045ed40
 * undefined FUN_0045ed40(void)
 * Address ranges: 0045ed40-0045ede6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045ed40(int *param_1,byte param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  if (param_2 != *(byte *)(param_1 + 0x90)) {
    *(byte *)(param_1 + 0x90) = param_2;
    if ((param_2 != 0) && (param_1[9] != 0)) {
      iVar1 = FUN_0044268c(param_1[9]);
      if (-1 < iVar1 + -1) {
        iVar5 = 0;
        do {
          piVar2 = (int *)FUN_00442650(param_1[9],iVar5);
          uVar3 = FUN_00403024(piVar2,(int)&PTR_FUN_0045ea00);
          if ((char)uVar3 != '\0') {
            piVar2 = (int *)FUN_00442650(param_1[9],iVar5);
            if (param_1 != piVar2) {
              piVar2 = (int *)FUN_00442650(param_1[9],iVar5);
              iVar4 = FUN_0040303c(piVar2,(int)&PTR_FUN_0045ea00);
              *(byte *)(iVar4 + 0x240) = param_2 ^ 1;
              piVar2 = (int *)FUN_00442650(param_1[9],iVar5);
              piVar2 = (int *)FUN_0040303c(piVar2,(int)&PTR_FUN_0045ea00);
              (**(code **)(*piVar2 + 0x74))();
            }
          }
          iVar5 = iVar5 + 1;
          iVar1 = iVar1 + -1;
        } while (iVar1 != 0);
      }
    }
    (**(code **)(*param_1 + 0x74))();
  }
  return;
}

