/*
 * FUN_0043855c at 0043855c
 * undefined __register FUN_0043855c(int param_1)
 * Address ranges: 0043855c-00438587
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043855c(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = FUN_00438084(param_1);
  if (-1 < iVar1 + -1) {
    iVar3 = 0;
    do {
      piVar2 = (int *)FUN_00438094(param_1,iVar3);
      (**(code **)(*piVar2 + 0x3c))();
      iVar3 = iVar3 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}

