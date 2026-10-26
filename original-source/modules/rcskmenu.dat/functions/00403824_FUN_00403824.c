/*
 * FUN_00403824 at 00403824
 * undefined __register FUN_00403824(void)
 * Address ranges: 00403824-00403848
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00403824(void)

{
  int *piVar1;
  int *in_FS_OFFSET;
  
  piVar1 = (int *)*in_FS_OFFSET;
  if (DAT_0047d4a8 == piVar1) {
    *in_FS_OFFSET = *DAT_0047d4a8;
    return;
  }
  while( true ) {
    if (piVar1 == (int *)0xffffffff) {
      return;
    }
    if ((int *)*piVar1 == DAT_0047d4a8) break;
    piVar1 = (int *)*piVar1;
  }
  *piVar1 = *DAT_0047d4a8;
  return;
}

