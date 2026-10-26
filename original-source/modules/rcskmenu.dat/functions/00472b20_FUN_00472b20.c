/*
 * FUN_00472b20 at 00472b20
 * undefined __register FUN_00472b20(undefined4 param_1, int param_2, undefined4 param_3)
 * Address ranges: 00472b20-00472bac
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00472b20(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined4 *in_FS_OFFSET;
  char *pcVar1;
  undefined *puVar2;
  undefined4 uVar3;
  undefined4 uStack_2c;
  undefined1 *puStack_28;
  undefined1 *puStack_24;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  undefined4 *local_10;
  int *local_c;
  int local_8;
  
  local_10 = (undefined4 *)0x0;
  puStack_18 = (undefined1 *)0x472b39;
  local_8 = param_2;
  FUN_00403f84(param_2);
  puStack_1c = &LAB_00472bd2;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  puStack_28 = &LAB_00472bad;
  uStack_2c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_2c;
  uVar3 = *(undefined4 *)PTR_DAT_0047c694;
  puVar2 = &DAT_00472be8;
  pcVar1 = "shellimg.dat";
  puStack_24 = &stack0xfffffffc;
  puStack_18 = &stack0xfffffffc;
  FUN_00403e90((int *)&local_10,3);
  local_c = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',local_10);
  (**(code **)*local_c)(local_c,"DEBRIEFPICS",local_8,param_3,0,pcVar1,puVar2,uVar3);
  *in_FS_OFFSET = param_3;
  FUN_00402eac(local_c);
  return;
}

