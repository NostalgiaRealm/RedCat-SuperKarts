/*
 * FUN_0042f268 at 0042f268
 * undefined4 __register FUN_0042f268(int param_1, undefined4 param_2, undefined4 param_3, int param_4)
 * Address ranges: 0042f268-0042f2e2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0042f268(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  int iVar4;
  
  if ((*(char *)(param_1 + 0x168) != '\0') && (iVar1 = FUN_0044268c(param_1), -1 < iVar1 + -1)) {
    iVar4 = 0;
    do {
      piVar2 = (int *)FUN_00442650(param_1,iVar4);
      if (((*(char *)((int)piVar2 + 0x47) != '\0') &&
          (uVar3 = FUN_0042f238(piVar2,extraout_EDX,extraout_ECX,param_4), (char)uVar3 != '\0')) ||
         ((uVar3 = FUN_00403024(piVar2,(int)&PTR_FUN_0043be00), (char)uVar3 != '\0' &&
          (uVar3 = FUN_0042f268((int)piVar2,extraout_EDX_00,extraout_ECX_00,param_4),
          (char)uVar3 != '\0')))) {
        return CONCAT31((int3)((uint)uVar3 >> 8),1);
      }
      iVar4 = iVar4 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return 0;
}

