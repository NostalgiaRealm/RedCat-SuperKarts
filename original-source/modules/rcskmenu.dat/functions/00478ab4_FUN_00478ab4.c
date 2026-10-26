/*
 * FUN_00478ab4 at 00478ab4
 * undefined __register FUN_00478ab4(int param_1, undefined4 param_2)
 * Address ranges: 00478ab4-00478bae
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00478ab4(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *in_FS_OFFSET;
  undefined1 *puStack_44;
  undefined1 *puStack_40;
  undefined1 *puStack_3c;
  undefined4 uStack_38;
  undefined1 *puStack_34;
  undefined1 *puStack_30;
  undefined4 *local_24;
  undefined4 *local_20;
  undefined4 *local_1c;
  int local_18;
  uint *local_14;
  uint *local_10;
  int *local_c;
  undefined4 local_8;
  
  puStack_30 = &stack0xfffffffc;
  puStack_3c = &stack0xfffffffc;
  local_c = (int *)0x0;
  local_10 = (uint *)0x0;
  local_14 = (uint *)0x0;
  local_18 = 0;
  local_1c = (undefined4 *)0x0;
  local_20 = (undefined4 *)0x0;
  local_24 = (undefined4 *)0x0;
  puStack_34 = &LAB_00478bd1;
  uStack_38 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_38;
  puStack_40 = &LAB_00478baf;
  puStack_44 = (undefined1 *)*in_FS_OFFSET;
  *in_FS_OFFSET = &puStack_44;
  local_8 = param_2;
  FUN_00403e1c((int *)&local_1c,*(undefined4 **)PTR_DAT_0047c694,(undefined4 *)"race.ini");
  local_c = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',local_1c);
  FUN_00407f60(local_8,(int *)&local_20);
  FUN_00403e1c(&local_18,(undefined4 *)"RACE_RECORD_E",local_20);
  iVar1 = (**(code **)(*local_c + 8))(local_c,"BEST TIMES",local_18,0);
  FUN_0045c910(iVar1,(int *)&local_10);
  FUN_0043f67c(*(int *)(param_1 + 900),local_10);
  FUN_00407f60(local_8,(int *)&local_24);
  FUN_00403e1c(&local_18,(undefined4 *)"LAP_RECORD_E",local_24);
  iVar1 = (**(code **)(*local_c + 8))(local_c,"BEST TIMES",local_18);
  FUN_0045c910(iVar1,(int *)&local_14);
  FUN_0043f67c(*(int *)(param_1 + 0x388),local_14);
  *in_FS_OFFSET = 0;
  puStack_44 = &LAB_00478bb6;
  FUN_00402eac(local_c);
  return;
}

