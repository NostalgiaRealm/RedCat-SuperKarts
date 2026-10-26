/*
 * FUN_0045a3c8 at 0045a3c8
 * undefined __register FUN_0045a3c8(int param_1, undefined4 * param_2)
 * Address ranges: 0045a3c8-0045a4fb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045a3c8(int param_1,undefined4 *param_2)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_30;
  undefined1 *puStack_2c;
  undefined1 *puStack_28;
  undefined4 uStack_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  undefined4 *local_10;
  int *local_c;
  undefined4 *local_8;
  
  local_10 = (undefined4 *)0x0;
  puStack_1c = (undefined1 *)0x45a3e2;
  local_8 = param_2;
  FUN_00403f84((int)param_2);
  puStack_20 = &LAB_0045a523;
  uStack_24 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_24;
  puStack_2c = &LAB_0045a4fc;
  uStack_30 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_30;
  puStack_28 = &stack0xfffffffc;
  puStack_1c = &stack0xfffffffc;
  FUN_00454968(*(int *)(param_1 + 0x18),local_8);
  local_c = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',local_8);
  (**(code **)*local_c)(local_c,"playerdata",&DAT_0045a53c,&local_10,0);
  FUN_00403ba4((int *)(param_1 + 0xc),local_10);
  uVar1 = (**(code **)(*local_c + 8))(local_c,"playerdata","character",0);
  *(undefined1 *)(param_1 + 0x22) = uVar1;
  uVar2 = (**(code **)(*local_c + 8))(local_c,"playerdata","adventure",0);
  *(undefined4 *)(param_1 + 0x14) = uVar2;
  uVar1 = (**(code **)(*local_c + 8))(local_c,"playerdata","cartype",0);
  *(undefined1 *)(param_1 + 0x23) = uVar1;
  uVar1 = (**(code **)(*local_c + 8))(local_c,"playerdata","racetype",0);
  *(undefined1 *)(param_1 + 0x24) = uVar1;
  uVar1 = (**(code **)(*local_c + 8))(local_c,"playerdata","country",0);
  *(undefined1 *)(param_1 + 0x25) = uVar1;
  uVar1 = (**(code **)(*local_c + 8))(local_c,"playerdata","completed",0);
  *(undefined1 *)(param_1 + 0x26) = uVar1;
  uVar1 = (**(code **)(*local_c + 8))(local_c,"playerdata","difficulty");
  *(undefined1 *)(param_1 + 0x10) = uVar1;
  iVar3 = 6;
  do {
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *in_FS_OFFSET = 0;
  FUN_00402eac(local_c);
  return;
}

