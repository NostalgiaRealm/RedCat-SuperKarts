/*
 * FUN_0042ba9c at 0042ba9c
 * undefined __register FUN_0042ba9c(int param_1, int * param_2, int param_3)
 * Address ranges: 0042ba9c-0042bb2d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042ba9c(int param_1,int *param_2,int param_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  int iVar6;
  int local_14;
  
  uVar2 = FUN_00403024(param_2,(int)&PTR_FUN_0043b888);
  if ((char)uVar2 == '\0') {
    iVar3 = FUN_0044268c(param_1);
    local_14 = -1;
    iVar4 = FUN_00414da8(param_1);
    if (-1 < iVar4 + -1) {
      iVar6 = 0;
      do {
        piVar5 = (int *)FUN_00414d7c(param_1,iVar6);
        cVar1 = FUN_00403088(piVar5,extraout_EDX,extraout_ECX);
        if ((cVar1 == '\0') && (local_14 = local_14 + 1, local_14 == param_3 - iVar3)) {
          FUN_00414db8((int)param_2,iVar6);
          return;
        }
        iVar6 = iVar6 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
  }
  else {
    FUN_00445d00(param_1,param_2,param_3);
  }
  return;
}

