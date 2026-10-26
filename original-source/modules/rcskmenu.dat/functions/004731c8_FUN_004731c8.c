/*
 * FUN_004731c8 at 004731c8
 * undefined FUN_004731c8(void)
 * Address ranges: 004731c8-00473200
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004731c8(byte param_1,int param_2)

{
  int iVar1;
  
  if ((-1 < param_2) && (param_2 < 5)) {
    iVar1 = FUN_00402b74(2);
    param_1 = *(byte *)(param_2 * 2 + 0x47c4e8 + iVar1);
  }
  FUN_0045c5cc(*(byte *)(*(int *)(*(int *)PTR_DAT_0047c670 + 0x80) + 0x22),param_1);
  return;
}

