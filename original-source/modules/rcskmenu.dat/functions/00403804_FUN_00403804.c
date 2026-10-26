/*
 * FUN_00403804 at 00403804
 * undefined __register FUN_00403804(void)
 * Address ranges: 00403804-00403821
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00403804(void)

{
  int iVar1;
  int unaff_EBP;
  int *in_FS_OFFSET;
  
  DAT_0047d4a8 = (int *)(unaff_EBP + -0xc);
  iVar1 = *in_FS_OFFSET;
  *in_FS_OFFSET = (int)DAT_0047d4a8;
  *DAT_0047d4a8 = iVar1;
  *(code **)(unaff_EBP + -8) = FUN_00403768;
  *(int *)(unaff_EBP + -4) = unaff_EBP;
  return;
}

