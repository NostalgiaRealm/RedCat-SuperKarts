/*
 * FUN_00445274 at 00445274
 * undefined __register FUN_00445274(int param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 00445274-004452b8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00445274(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = FUN_0044268c(param_1);
  if (-1 < iVar1 + -1) {
    iVar3 = 0;
    do {
      piVar2 = (int *)FUN_00442650(param_1,iVar3);
      FUN_00403088(piVar2,param_2,param_3);
      iVar3 = iVar3 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}

