/*
 * FUN_00479a4c at 00479a4c
 * undefined __register FUN_00479a4c(int param_1)
 * Address ranges: 00479a4c-00479af6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00479a4c(int param_1)

{
  int *in_FS_OFFSET;
  undefined4 **ppuVar1;
  char *pcVar2;
  undefined *puVar3;
  int iVar4;
  int iStack_38;
  undefined1 *puStack_34;
  undefined1 *puStack_30;
  int iStack_2c;
  undefined1 *puStack_28;
  undefined1 *puStack_24;
  undefined4 *local_18;
  undefined *local_14;
  int local_10;
  undefined4 *local_c;
  int *local_8;
  
  puStack_24 = &stack0xfffffffc;
  puStack_30 = &stack0xfffffffc;
  local_8 = (int *)0x0;
  local_c = (undefined4 *)0x0;
  local_10 = 0;
  local_14 = (undefined *)0x0;
  local_18 = (undefined4 *)0x0;
  puStack_28 = &LAB_00479b19;
  iStack_2c = *in_FS_OFFSET;
  *in_FS_OFFSET = (int)&iStack_2c;
  puStack_34 = &LAB_00479af7;
  iStack_38 = *in_FS_OFFSET;
  *in_FS_OFFSET = (int)&iStack_38;
  FUN_0043285c(*(undefined4 *)PTR_DAT_0047c86c,(int *)&local_14);
  FUN_004081c4(local_14,&local_10);
  puVar3 = &DAT_00479b30;
  pcVar2 = "settings.ini";
  iVar4 = local_10;
  FUN_00403e90((int *)&local_c,3);
  local_8 = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',local_c);
  ppuVar1 = &local_18;
  (**(code **)*local_8)(local_8,"SETTINGS","INTRO_MOVIE",ppuVar1,0,pcVar2,puVar3,iVar4);
  FUN_00403ba4((int *)(param_1 + 0x2ec),local_18);
  *in_FS_OFFSET = (int)ppuVar1;
  FUN_00402eac(local_8);
  return;
}

