/*
 * FUN_0045a19c at 0045a19c
 * undefined __register FUN_0045a19c(int param_1)
 * Address ranges: 0045a19c-0045a2d6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045a19c(int param_1)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_34;
  undefined1 *puStack_30;
  undefined1 *puStack_2c;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  undefined4 *local_14;
  undefined *local_10;
  undefined4 *local_c;
  int *local_8;
  
  puStack_20 = &stack0xfffffffc;
  puStack_2c = &stack0xfffffffc;
  local_8 = (int *)0x0;
  local_c = (undefined4 *)0x0;
  local_10 = (undefined *)0x0;
  local_14 = (undefined4 *)0x0;
  puStack_24 = &LAB_0045a2fb;
  uStack_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_28;
  puStack_30 = &LAB_0045a2d7;
  uStack_34 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_34;
  FUN_0043285c(*(undefined4 *)PTR_DAT_0047c86c,(int *)&local_10);
  FUN_004081c4(local_10,(int *)&local_c);
  FUN_00403dd8((int *)&local_c,(undefined4 *)"race.ini");
  local_8 = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',local_c);
  (**(code **)*local_8)(local_8,"playerdata",&DAT_0045a328,&local_14,0);
  FUN_00403ba4((int *)(param_1 + 0xc),local_14);
  uVar1 = (**(code **)(*local_8 + 8))(local_8,"playerdata","character",0);
  *(undefined1 *)(param_1 + 0x22) = uVar1;
  uVar2 = (**(code **)(*local_8 + 8))(local_8,"playerdata","adventure",0);
  *(undefined4 *)(param_1 + 0x14) = uVar2;
  uVar1 = (**(code **)(*local_8 + 8))(local_8,"playerdata","cartype",0);
  *(undefined1 *)(param_1 + 0x23) = uVar1;
  uVar1 = (**(code **)(*local_8 + 8))(local_8,"playerdata","racetype",0);
  *(undefined1 *)(param_1 + 0x24) = uVar1;
  uVar1 = (**(code **)(*local_8 + 8))(local_8,"playerdata","country",0);
  *(undefined1 *)(param_1 + 0x25) = uVar1;
  uVar1 = (**(code **)(*local_8 + 8))(local_8,"playerdata","completed",0);
  *(undefined1 *)(param_1 + 0x26) = uVar1;
  uVar1 = (**(code **)(*local_8 + 8))(local_8,"playerdata","difficulty");
  *(undefined1 *)(param_1 + 0x10) = uVar1;
  *in_FS_OFFSET = 0;
  FUN_00402eac(local_8);
  return;
}

