/*
 * FUN_00454968 at 00454968
 * undefined __register FUN_00454968(int param_1, undefined4 * param_2)
 * Address ranges: 00454968-00454a40;00454a4b-00454a58
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00454968(int param_1,undefined4 *param_2)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_4c;
  undefined1 *puStack_48;
  undefined1 *puStack_44;
  undefined4 uStack_40;
  undefined1 *puStack_3c;
  undefined1 *puStack_38;
  undefined4 uStack_34;
  undefined1 *puStack_30;
  undefined1 *puStack_2c;
  char local_19;
  int local_18;
  int *local_14;
  int *local_10;
  undefined4 *local_c;
  int local_8;
  
  local_18 = 0;
  puStack_2c = (undefined1 *)0x454984;
  local_c = param_2;
  local_8 = param_1;
  FUN_00403f84((int)param_2);
  puStack_30 = &LAB_00454a7e;
  uStack_34 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_34;
  puStack_3c = &LAB_00454a59;
  uStack_40 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_40;
  puStack_44 = (undefined1 *)0x4549af;
  puStack_38 = &stack0xfffffffc;
  puStack_2c = &stack0xfffffffc;
  local_10 = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',local_c);
  puStack_44 = (undefined1 *)0x4549be;
  local_14 = FUN_00454494((int *)&LAB_00454484,'\x01',extraout_ECX);
  puStack_48 = &LAB_00454a41;
  uStack_4c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_4c;
  local_19 = '\0';
  puVar4 = (undefined4 *)PTR_PTR_0047c804;
  puStack_44 = &stack0xfffffffc;
  do {
    (**(code **)*local_10)(local_10,"advmatrix",*puVar4,&local_18,0);
    iVar2 = FUN_00403dd0(local_18);
    if (0 < iVar2) {
      FUN_00454510((int)local_14,local_18);
      uVar3 = 0;
      do {
        uVar1 = FUN_004546b4((int)local_14,uVar3 & 0xff);
        FUN_004547ec(local_8,CONCAT31((int3)((uint)extraout_EDX >> 8),local_19),uVar3,uVar1);
        uVar3 = uVar3 + 1;
      } while ((char)uVar3 != '\x05');
    }
    local_19 = local_19 + '\x01';
    puVar4 = puVar4 + 1;
  } while (local_19 != '\x06');
  *in_FS_OFFSET = uStack_4c;
  *in_FS_OFFSET = uStack_40;
  return;
}

