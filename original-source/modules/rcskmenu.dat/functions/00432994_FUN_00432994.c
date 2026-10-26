/*
 * FUN_00432994 at 00432994
 * undefined __register FUN_00432994(int param_1)
 * Address ranges: 00432994-00432a47;00432a69-00432a8e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00432994(int param_1)

{
  int *piVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_38;
  undefined1 *puStack_34;
  undefined1 *puStack_30;
  undefined4 uStack_2c;
  undefined1 *puStack_28;
  undefined1 *puStack_24;
  undefined4 *local_14;
  uint *local_10;
  char local_9;
  int local_8;
  
  puStack_24 = &stack0xfffffffc;
  local_10 = (uint *)0x0;
  local_14 = (undefined4 *)0x0;
  puStack_28 = &LAB_00432a8f;
  uStack_2c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_2c;
  puStack_30 = (undefined1 *)0x4329be;
  local_8 = param_1;
  piVar1 = FUN_00432910(param_1);
  if ((*(char *)(local_8 + 0x78) != '\0') && (*(int *)(local_8 + 0x3c) == 0)) {
    puStack_30 = (undefined1 *)0x4329da;
    FUN_00432e8c(local_8);
  }
  puStack_30 = (undefined1 *)0x4329e4;
  FUN_00430c74((int)piVar1,(int *)&local_14);
  puStack_30 = (undefined1 *)0x4329ef;
  FUN_0043caa8(local_14,(int *)&local_10);
  puStack_30 = (undefined1 *)0x4329fc;
  FUN_00432b40(DAT_0047d770,local_10);
  local_9 = '\x01';
  puStack_34 = &LAB_00432a48;
  uStack_38 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_38;
  puStack_30 = &stack0xfffffffc;
  if (*(short *)(local_8 + 0xda) != 0) {
    puStack_30 = &stack0xfffffffc;
    (**(code **)(local_8 + 0xd8))(*(undefined4 *)(local_8 + 0xdc),local_8,&local_9);
  }
  if (local_9 != '\0') {
    FUN_004328ac();
  }
  *in_FS_OFFSET = uStack_38;
  if (local_9 != '\0') {
    puStack_30 = (undefined1 *)0x432a74;
    WaitMessage();
  }
  *in_FS_OFFSET = uStack_2c;
  puStack_24 = &LAB_00432a96;
  puStack_28 = (undefined1 *)0x432a8e;
  FUN_00403b74((int *)&local_14,2);
  return;
}

