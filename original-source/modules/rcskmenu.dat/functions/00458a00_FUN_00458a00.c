/*
 * FUN_00458a00 at 00458a00
 * int __register FUN_00458a00(int param_1, int param_2)
 * Address ranges: 00458a00-00458a3e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00458a00(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = 0;
  iVar3 = param_2;
  do {
    iVar1 = *(int *)(param_1 + 0x14 + iVar2 * 0x18);
    iVar3 = iVar3 + iVar1;
    if (iVar1 == 0) {
      return iVar2;
    }
    iVar4 = iVar2;
  } while ((iVar1 <= param_2) && (iVar2 = iVar2 + 1, iVar4 = -1, iVar2 != 5));
  if (iVar3 == 0) {
    iVar4 = 0;
  }
  return iVar4;
}

