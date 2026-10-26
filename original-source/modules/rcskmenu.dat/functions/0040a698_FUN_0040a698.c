/*
 * FUN_0040a698 at 0040a698
 * undefined FUN_0040a698(void)
 * Address ranges: 0040a698-0040a6d1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0040a698(void)

{
  int iVar1;
  char *in_stack_00000004;
  
  iVar1 = 1;
  while( true ) {
    if (*(int *)(&DAT_0047d5b8 + iVar1 * 4) == 0) {
      FUN_00403d08((int *)(&DAT_0047d5b8 + iVar1 * 4),in_stack_00000004);
      return 1;
    }
    if (iVar1 == 7) break;
    iVar1 = iVar1 + 1;
  }
  return 0;
}

