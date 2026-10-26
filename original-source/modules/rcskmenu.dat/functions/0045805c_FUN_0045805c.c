/*
 * FUN_0045805c at 0045805c
 * undefined __register FUN_0045805c(int param_1)
 * Address ranges: 0045805c-00458116;00458121-0045813c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045805c(int param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_58;
  undefined1 *puStack_54;
  undefined1 *puStack_50;
  char *pcStack_4c;
  undefined *puStack_48;
  undefined1 *puStack_44;
  undefined4 uStack_40;
  undefined1 *puStack_3c;
  undefined1 *puStack_38;
  undefined4 uStack_34;
  undefined1 *puStack_30;
  undefined1 *puStack_2c;
  int local_1c;
  undefined *local_18;
  int local_14;
  undefined4 *local_10;
  int *local_c;
  int local_8;
  
  puStack_2c = &stack0xfffffffc;
  puStack_38 = &stack0xfffffffc;
  local_c = (int *)0x0;
  local_10 = (undefined4 *)0x0;
  local_14 = 0;
  local_18 = (undefined *)0x0;
  local_1c = 0;
  puStack_30 = &LAB_0045815f;
  uStack_34 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_34;
  puStack_3c = &LAB_0045813d;
  uStack_40 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_40;
  puStack_44 = (undefined1 *)0x458098;
  local_8 = param_1;
  FUN_0043285c(*(undefined4 *)PTR_DAT_0047c86c,(int *)&local_18);
  puStack_44 = (undefined1 *)0x4580a3;
  FUN_004081c4(local_18,&local_14);
  puStack_44 = (undefined1 *)local_14;
  puStack_48 = &DAT_00458178;
  pcStack_4c = "shellimg.dat";
  puStack_50 = (undefined1 *)0x4580bd;
  FUN_00403e90((int *)&local_10,3);
  puStack_50 = (undefined1 *)0x4580cc;
  local_c = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',local_10);
  puStack_54 = &LAB_00458117;
  uStack_58 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_58;
  uVar2 = 0;
  puStack_50 = &stack0xfffffffc;
  do {
    uVar1 = (uint)*(byte *)(local_8 + 4 + (uVar2 & 0x7f));
    FUN_00407f60(uVar2 & 0x7f,&local_1c);
    (**(code **)(*local_c + 0xc))(local_c,"LOCKEDSTATE",local_1c,uVar1);
    uVar2 = uVar2 + 1;
  } while ((char)uVar2 != '\x06');
  *in_FS_OFFSET = uStack_58;
  *in_FS_OFFSET = pcStack_4c;
  puStack_44 = &LAB_00458144;
  if (local_c != (int *)0x0) {
    puStack_48 = (undefined *)0x45813c;
    FUN_00402eac(local_c);
  }
  return;
}

