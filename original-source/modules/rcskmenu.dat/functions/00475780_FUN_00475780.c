/*
 * FUN_00475780 at 00475780
 * undefined __register FUN_00475780(void)
 * Address ranges: 00475780-00475890;0047589b-004758b0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00475780(void)

{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_60;
  undefined1 *puStack_5c;
  undefined1 *puStack_58;
  char *pcStack_54;
  undefined *puStack_50;
  undefined1 *puStack_4c;
  undefined4 uStack_48;
  undefined1 *puStack_44;
  undefined1 *puStack_40;
  undefined4 uStack_3c;
  undefined1 *puStack_38;
  undefined1 *puStack_34;
  undefined4 *local_24;
  undefined4 *local_20;
  undefined4 *local_1c;
  int *local_18;
  int local_14;
  int *local_10;
  int *local_c;
  char local_5;
  
  puStack_34 = &stack0xfffffffc;
  puStack_40 = &stack0xfffffffc;
  local_24 = (undefined4 *)0x0;
  local_20 = (undefined4 *)0x0;
  local_1c = (undefined4 *)0x0;
  local_14 = 0;
  puStack_38 = &LAB_004758e9;
  uStack_3c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_3c;
  puStack_44 = &LAB_004758b1;
  uStack_48 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_48;
  puStack_4c = *(undefined1 **)PTR_DAT_0047c694;
  puStack_50 = &DAT_00475900;
  pcStack_54 = "shellimg.dat";
  puStack_58 = (undefined1 *)0x4757d1;
  FUN_00403e90((int *)&local_1c,3);
  puStack_58 = (undefined1 *)0x4757e0;
  local_c = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',local_1c);
  puStack_58 = (undefined1 *)0x4757ef;
  local_10 = FUN_00454494((int *)&LAB_00454484,'\x01',extraout_ECX);
  puStack_5c = &LAB_00475891;
  uStack_60 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_60;
  local_5 = '\x05';
  piVar3 = &DAT_0047e498;
  local_18 = &DAT_0047e4ac;
  puVar2 = (undefined4 *)PTR_PTR_0047c7dc;
  puStack_58 = &stack0xfffffffc;
  do {
    (**(code **)*local_c)(local_c,"staticons",*puVar2,&local_14,0);
    iVar1 = FUN_00403dd0(local_14);
    if (0 < iVar1) {
      FUN_00454510((int)local_10,local_14);
      FUN_0045471c((int)local_10,0,(int *)&local_20);
      FUN_00403ba4(piVar3,local_20);
      FUN_0045471c((int)local_10,1,(int *)&local_24);
      FUN_00403ba4(local_18,local_24);
    }
    local_18 = local_18 + 1;
    piVar3 = piVar3 + 1;
    puVar2 = puVar2 + 1;
    local_5 = local_5 + -1;
  } while (local_5 != '\0');
  *in_FS_OFFSET = uStack_60;
  *in_FS_OFFSET = pcStack_54;
  puStack_4c = &LAB_004758b8;
  puStack_50 = (undefined *)0x4758b0;
  FUN_00402eac(local_c);
  return;
}

