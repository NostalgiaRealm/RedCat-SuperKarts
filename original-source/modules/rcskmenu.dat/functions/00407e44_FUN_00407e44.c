/*
 * FUN_00407e44 at 00407e44
 * undefined __register FUN_00407e44(int param_1, int * param_2)
 * Address ranges: 00407e44-00407e90
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00407e44(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_00403dd0(param_1);
  for (iVar2 = 1; (iVar2 <= iVar1 && (*(byte *)(param_1 + -1 + iVar2) < 0x21)); iVar2 = iVar2 + 1) {
  }
  if (iVar1 < iVar2) {
    FUN_00403b50(param_2);
  }
  else {
    for (; *(byte *)(param_1 + -1 + iVar1) < 0x21; iVar1 = iVar1 + -1) {
    }
    FUN_00403fd8(param_1,iVar2,(iVar1 - iVar2) + 1,param_2);
  }
  return;
}

