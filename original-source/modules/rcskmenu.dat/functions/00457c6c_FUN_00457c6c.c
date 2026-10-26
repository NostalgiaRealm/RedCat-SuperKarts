/*
 * FUN_00457c6c at 00457c6c
 * int __register FUN_00457c6c(int param_1)
 * Address ranges: 00457c6c-00457c85
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00457c6c(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (*(char *)(param_1 + 0xc + iVar1) == '\x01') {
      return iVar1;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 != 0x1f);
  return -1;
}

