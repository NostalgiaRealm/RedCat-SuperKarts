/*
 * FUN_00478958 at 00478958
 * undefined __register FUN_00478958(int param_1)
 * Address ranges: 00478958-00478a25;00478a40-00478a5a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00478958(int param_1)

{
  undefined4 extraout_ECX;
  int *in_FS_OFFSET;
  int *piVar1;
  char *pcVar2;
  undefined *puVar3;
  undefined4 uVar4;
  undefined1 *puStack_3c;
  undefined1 *puStack_38;
  undefined1 *puStack_34;
  int iStack_30;
  undefined1 *puStack_2c;
  undefined1 *puStack_28;
  uint *local_18;
  undefined4 *local_14;
  int local_10;
  int *local_c;
  int *local_8;
  
  puStack_28 = &stack0xfffffffc;
  puStack_34 = &stack0xfffffffc;
  local_8 = (int *)0x0;
  local_c = (int *)0x0;
  local_10 = 0;
  local_14 = (undefined4 *)0x0;
  local_18 = (uint *)0x0;
  puStack_2c = &LAB_00478a5b;
  iStack_30 = *in_FS_OFFSET;
  *in_FS_OFFSET = (int)&iStack_30;
  puStack_38 = &LAB_00478a26;
  puStack_3c = (undefined1 *)*in_FS_OFFSET;
  *in_FS_OFFSET = (int)&puStack_3c;
  uVar4 = *(undefined4 *)PTR_DAT_0047c694;
  puVar3 = &DAT_00478a74;
  pcVar2 = "shellimg.dat";
  FUN_00403e90((int *)&local_14,3);
  local_8 = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',local_14);
  local_c = FUN_00454494((int *)&LAB_00454484,'\x01',extraout_ECX);
  piVar1 = &local_10;
  (**(code **)*local_8)
            (local_8,"DEBRIEFPICS",
             *(undefined4 *)(PTR_PTR_0047c804 + (uint)*(byte *)(param_1 + 0x390) * 4),piVar1,0,
             pcVar2,puVar3,uVar4);
  if (local_10 != 0) {
    FUN_00454510((int)local_c,local_10);
    FUN_0045471c((int)local_c,0,(int *)&local_18);
    FUN_00452c0c(*(int *)(*(int *)(param_1 + 0x378) + 300),local_18);
  }
  *in_FS_OFFSET = (int)piVar1;
  *in_FS_OFFSET = (int)puVar3;
  puStack_3c = &LAB_00478a62;
  FUN_00403b74((int *)&local_18,3);
  return;
}

