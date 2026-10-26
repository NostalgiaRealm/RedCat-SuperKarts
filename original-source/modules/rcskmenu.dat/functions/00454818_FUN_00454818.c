/*
 * FUN_00454818 at 00454818
 * undefined __register FUN_00454818(int param_1, undefined4 * param_2)
 * Address ranges: 00454818-004548ea;004548f5-0045490a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00454818(int param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 uVar2;
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
  undefined4 *local_1c;
  char local_15;
  int local_14;
  int *local_10;
  undefined4 *local_c;
  int local_8;
  
  local_1c = (undefined4 *)0x0;
  local_14 = 0;
  puStack_2c = (undefined1 *)0x454837;
  local_c = param_2;
  local_8 = param_1;
  FUN_00403f84((int)param_2);
  puStack_30 = &LAB_00454938;
  uStack_34 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_34;
  puStack_3c = &LAB_0045490b;
  uStack_40 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_40;
  puStack_44 = (undefined1 *)0x454862;
  puStack_38 = &stack0xfffffffc;
  puStack_2c = &stack0xfffffffc;
  local_10 = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',local_c);
  puStack_48 = &LAB_004548eb;
  uStack_4c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_4c;
  local_15 = '\0';
  puVar4 = (undefined4 *)PTR_PTR_0047c804;
  puStack_44 = &stack0xfffffffc;
  do {
    FUN_00403b50(&local_14);
    uVar3 = 0;
    uVar2 = extraout_EDX;
    do {
      uVar1 = FUN_00454808(local_8,CONCAT31((int3)((uint)uVar2 >> 8),local_15),uVar3);
      FUN_00407f60(uVar1 & 0x7f,(int *)&local_1c);
      FUN_00403dd8(&local_14,local_1c);
      uVar2 = extraout_EDX_00;
      if ((byte)uVar3 < 4) {
        FUN_00403dd8(&local_14,(undefined4 *)&DAT_00454950);
        uVar2 = extraout_EDX_01;
      }
      uVar3 = uVar3 + 1;
    } while ((char)uVar3 != '\x05');
    (**(code **)(*local_10 + 4))(local_10,"advmatrix",*puVar4,local_14);
    local_15 = local_15 + '\x01';
    puVar4 = puVar4 + 1;
  } while (local_15 != '\x06');
  *in_FS_OFFSET = uStack_4c;
  *in_FS_OFFSET = uStack_40;
  puStack_38 = &LAB_00454912;
  puStack_3c = (undefined1 *)0x45490a;
  FUN_00402eac(local_10);
  return;
}

