/*
 * FUN_00464458 at 00464458
 * undefined __register FUN_00464458(int * param_1)
 * Address ranges: 00464458-004644b1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00464458(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar1 = param_1[9];
  if (iVar1 != 0) {
    iVar2 = FUN_0044268c(iVar1);
    if (-1 < iVar2 + -1) {
      iVar5 = 0;
      do {
        piVar3 = (int *)FUN_00442650(iVar1,iVar5);
        if (param_1 != piVar3) {
          uVar4 = FUN_00403024(piVar3,(int)&PTR_FUN_00462960);
          if ((char)uVar4 != '\0') {
            (**(code **)(*piVar3 + 0xb8))(piVar3,0);
          }
        }
        iVar5 = iVar5 + 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
  }
  return;
}

