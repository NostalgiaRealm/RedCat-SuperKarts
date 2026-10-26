/*
 * FUN_00457624 at 00457624
 * undefined FUN_00457624(void)
 * Address ranges: 00457624-0045768a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00457624(int param_1)

{
  byte bVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_1c;
  undefined *puStack_18;
  undefined1 *puStack_14;
  int iStack_8;
  
  puStack_14 = &stack0xfffffffc;
  iStack_8 = 0;
  puStack_18 = &UNK_0045768b;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  FUN_00403e90(&iStack_8,3);
  FUN_0045738c(*(undefined4 *)(param_1 + 0x14),iStack_8);
  bVar1 = 0;
  do {
    FUN_00457518(param_1,bVar1);
    bVar1 = bVar1 + 1;
  } while (bVar1 != 4);
  *in_FS_OFFSET = "soundset.dat";
  FUN_00403b50(&iStack_8);
  return;
}

