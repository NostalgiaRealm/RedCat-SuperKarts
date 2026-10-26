/*
 * FUN_0045d4a0 at 0045d4a0
 * undefined __register FUN_0045d4a0(int param_1, int param_2)
 * Address ranges: 0045d4a0-0045d564
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045d4a0(int param_1,int param_2)

{
  undefined1 uVar1;
  undefined4 *in_FS_OFFSET;
  char *pcVar2;
  undefined *puVar3;
  int iVar4;
  undefined4 uStack_38;
  undefined1 *puStack_34;
  undefined1 *puStack_30;
  undefined4 uStack_2c;
  undefined1 *puStack_28;
  undefined1 *puStack_24;
  undefined *local_1c;
  int local_18;
  undefined4 *local_14;
  int *local_10;
  int local_c;
  int local_8;
  
  local_14 = (undefined4 *)0x0;
  local_18 = 0;
  local_1c = (undefined *)0x0;
  puStack_24 = (undefined1 *)0x45d4c0;
  local_c = param_2;
  local_8 = param_1;
  FUN_00403f84(param_2);
  puStack_28 = &LAB_0045d598;
  uStack_2c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_2c;
  puStack_34 = &LAB_0045d565;
  uStack_38 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_38;
  puStack_30 = &stack0xfffffffc;
  puStack_24 = &stack0xfffffffc;
  FUN_0043285c(*(undefined4 *)PTR_DAT_0047c86c,(int *)&local_1c);
  FUN_004081c4(local_1c,&local_18);
  puVar3 = &DAT_0045d5b0;
  pcVar2 = "settings.ini";
  iVar4 = local_18;
  FUN_00403e90((int *)&local_14,3);
  local_10 = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',local_14);
  uVar1 = (**(code **)(*local_10 + 8))(local_10,"FIRSTTIME",local_c,1,pcVar2,puVar3,iVar4);
  *(undefined1 *)(local_8 + 0x2d5) = uVar1;
  (**(code **)(*local_10 + 0xc))(local_10,"FIRSTTIME",local_c);
  *in_FS_OFFSET = 0;
  FUN_00402eac(local_10);
  return;
}

