/*
 * FUN_00477ac0 at 00477ac0
 * undefined __register FUN_00477ac0(int param_1, uint param_2)
 * Address ranges: 00477ac0-00477bd6;00477be1-00477bfe
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00477ac0(int param_1,uint param_2)

{
  undefined4 extraout_ECX;
  int iVar1;
  undefined4 *in_FS_OFFSET;
  int *piVar2;
  undefined4 uVar3;
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
  int local_1c;
  undefined4 *local_18;
  int local_14;
  int local_10;
  int *local_c;
  int *local_8;
  
  puStack_34 = &stack0xfffffffc;
  local_8 = (int *)0x0;
  local_c = (int *)0x0;
  local_10 = 0;
  local_14 = 0;
  local_18 = (undefined4 *)0x0;
  local_1c = 0;
  local_20 = (undefined4 *)0x0;
  local_24 = (undefined4 *)0x0;
  puStack_38 = &LAB_00477c21;
  uStack_3c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_3c;
  puStack_40 = (undefined1 *)0x477afc;
  FUN_00403e1c(&local_10,*(undefined4 **)(PTR_PTR_0047c804 + (param_2 & 0xff) * 4),
               (undefined4 *)"_OVERVIEW");
  puStack_44 = &LAB_00477bff;
  uStack_48 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_48;
  puStack_4c = *(undefined1 **)PTR_DAT_0047c694;
  puStack_50 = &DAT_00477c4c;
  pcStack_54 = "shellimg.dat";
  puStack_58 = (undefined1 *)0x477b28;
  puStack_40 = &stack0xfffffffc;
  FUN_00403e90((int *)&local_18,3);
  puStack_58 = (undefined1 *)0x477b37;
  local_8 = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',local_18);
  puStack_58 = (undefined1 *)0x477b46;
  local_c = FUN_00454494((int *)&LAB_00454484,'\x01',extraout_ECX);
  puStack_5c = &LAB_00477bd7;
  uStack_60 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_60;
  iVar1 = 0;
  puStack_58 = &stack0xfffffffc;
  do {
    uVar3 = 0;
    piVar2 = &local_14;
    FUN_00407f60(iVar1,&local_1c);
    (**(code **)*local_8)(local_8,local_10,local_1c,piVar2,uVar3);
    if (local_14 != 0) {
      FUN_00454510((int)local_c,local_14);
      FUN_0045471c((int)local_c,0,(int *)&local_20);
      FUN_00403ba4((int *)(param_1 + 0x30c + iVar1 * 8),local_20);
      FUN_0045471c((int)local_c,1,(int *)&local_24);
      FUN_00403ba4((int *)(param_1 + 0x310 + iVar1 * 8),local_24);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 != 4);
  *in_FS_OFFSET = uStack_60;
  *in_FS_OFFSET = pcStack_54;
  puStack_4c = &LAB_00477c06;
  puStack_50 = (undefined *)0x477bf6;
  FUN_00402eac(local_8);
  puStack_50 = (undefined *)0x477bfe;
  FUN_00402eac(local_c);
  return;
}

