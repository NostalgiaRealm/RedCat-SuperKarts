/*
 * FUN_0042b17c at 0042b17c
 * undefined __register FUN_0042b17c(int * param_1, char param_2)
 * Address ranges: 0042b17c-0042b245
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042b17c(int *param_1,char param_2)

{
  bool bVar1;
  byte extraout_DL;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  undefined1 *puStack_10;
  byte local_9;
  int *local_8;
  
  puStack_10 = (undefined1 *)0x42b187;
  local_8 = FUN_0040320c(param_1,param_2);
  local_9 = extraout_DL;
  if ((*(byte *)(local_8 + 8) & 8) == 0) {
    puStack_10 = (undefined1 *)0x42b1a2;
    FUN_0040bf7c(*(int *)PTR_DAT_0047c9b0);
  }
  puStack_14 = &LAB_0042b246;
  uStack_18 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_18;
  puStack_10 = &stack0xfffffffc;
  if ((char)local_8[0x87] != '\0') {
    puStack_10 = &stack0xfffffffc;
    (**(code **)(*local_8 + 0xc4))();
  }
  FUN_0042d770((int)local_8,'\0');
  bVar1 = FUN_00445a20((int)local_8);
  if (bVar1) {
    (**(code **)(*local_8 + 0x9c))();
  }
  FUN_00430280(DAT_0047d774,(int)local_8);
  FUN_00402eac((int *)local_8[0x88]);
  FUN_00402eac((int *)local_8[0x8a]);
  FUN_0040bfec(local_8 + 0xb2);
  FUN_0042a550(local_8,local_9 & 0xfc);
  *in_FS_OFFSET = uStack_18;
  puStack_10 = &LAB_0042b24d;
  puStack_14 = (undefined1 *)0x42b245;
  FUN_0040bfc8(*(int *)PTR_DAT_0047c9b0);
  return;
}

