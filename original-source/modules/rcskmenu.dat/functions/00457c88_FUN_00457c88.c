/*
 * FUN_00457c88 at 00457c88
 * int __register FUN_00457c88(int param_1, int param_2)
 * Address ranges: 00457c88-00457ca9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00457c88(int param_1,int param_2)

{
  int iVar1;
  
  if ((param_2 < 0x1e) && (iVar1 = param_2 + 1, iVar1 < 0x1e)) {
    do {
      if (*(char *)(param_1 + 0xc + iVar1) == '\x01') {
        return iVar1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 != 0x1e);
  }
  return -1;
}

