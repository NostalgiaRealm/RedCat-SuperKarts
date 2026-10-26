/*
 * FUN_00457c50 at 00457c50
 * int __register FUN_00457c50(int param_1)
 * Address ranges: 00457c50-00457c69
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00457c50(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (*(char *)(param_1 + 0xc + iVar1) == '\0') {
      return iVar1;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 != 0x1e);
  return -1;
}

