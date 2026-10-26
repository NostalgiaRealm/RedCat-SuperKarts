/*
 * FUN_0042fab4 at 0042fab4
 * undefined __register FUN_0042fab4(int * param_1, char param_2)
 * Address ranges: 0042fab4-0042fb2d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042fab4(int *param_1,char param_2)

{
  byte extraout_DL;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  undefined1 *puStack_10;
  byte local_9;
  int *local_8;
  
  puStack_10 = (undefined1 *)0x42fabf;
  local_8 = FUN_0040320c(param_1,param_2);
  local_9 = extraout_DL;
  if ((*(byte *)(local_8 + 8) & 8) == 0) {
    puStack_10 = (undefined1 *)0x42fada;
    FUN_0040bf7c(*(int *)PTR_DAT_0047c9b0);
  }
  puStack_14 = &LAB_0042fb2e;
  uStack_18 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_18;
  puStack_10 = &stack0xfffffffc;
  if ((char)local_8[0x12] != '\0') {
    puStack_10 = &stack0xfffffffc;
    (**(code **)(*local_8 + 0x34))();
  }
  FUN_004302d4(DAT_0047d774,(int)local_8);
  FUN_004147c4(local_8,local_9 & 0xfc);
  *in_FS_OFFSET = uStack_18;
  puStack_10 = &LAB_0042fb35;
  puStack_14 = (undefined1 *)0x42fb2d;
  FUN_0040bfc8(*(int *)PTR_DAT_0047c9b0);
  return;
}

