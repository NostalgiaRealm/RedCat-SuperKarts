/*
 * FUN_00457cac at 00457cac
 * int __register FUN_00457cac(int param_1, int param_2)
 * Address ranges: 00457cac-00457ccc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00457cac(int param_1,int param_2)

{
  int iVar1;
  
  if ((0 < param_2) && (iVar1 = param_2 + -1, -1 < iVar1)) {
    do {
      if (*(char *)(param_1 + 0xc + iVar1) == '\x01') {
        return iVar1;
      }
      iVar1 = iVar1 + -1;
    } while (iVar1 != -1);
  }
  return -1;
}

