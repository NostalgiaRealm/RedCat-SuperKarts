/*
 * FUN_00458d6c at 00458d6c
 * undefined __register FUN_00458d6c(int param_1)
 * Address ranges: 00458d6c-00458e2d;00458e38-00458e4d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00458d6c(int param_1)

{
  undefined4 uVar1;
  byte bVar2;
  undefined **ppuVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_44;
  undefined1 *puStack_40;
  undefined1 *puStack_3c;
  undefined4 uStack_38;
  undefined1 *puStack_34;
  undefined1 *puStack_30;
  undefined4 uStack_2c;
  undefined1 *puStack_28;
  undefined1 *puStack_24;
  undefined *local_14;
  undefined4 *local_10;
  int *local_c;
  int local_8;
  
  puStack_24 = &stack0xfffffffc;
  local_10 = (undefined4 *)0x0;
  local_14 = (undefined *)0x0;
  puStack_28 = &LAB_00458e70;
  uStack_2c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_2c;
  puStack_30 = (undefined1 *)0x458da3;
  local_8 = param_1;
  FUN_0040282c((undefined4 *)&DAT_0047c0cc,(undefined4 *)(param_1 + 4),0x18);
  puStack_34 = &LAB_00458e4e;
  uStack_38 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_38;
  puStack_40 = &LAB_00458e2e;
  uStack_44 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_44;
  puStack_3c = &stack0xfffffffc;
  puStack_30 = &stack0xfffffffc;
  FUN_0043285c(*(undefined4 *)PTR_DAT_0047c86c,(int *)&local_14);
  FUN_004081c4(local_14,(int *)&local_10);
  FUN_00403dd8((int *)&local_10,(undefined4 *)"game.ini");
  local_c = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',local_10);
  bVar2 = 0;
  ppuVar3 = &PTR_s_KEY_ACCELERATE_0047c0b4;
  do {
    uVar1 = (**(code **)(*local_c + 8))(local_c,"INPUT",*ppuVar3,0);
    *(undefined4 *)(local_8 + 4 + (uint)bVar2 * 4) = uVar1;
    bVar2 = bVar2 + 1;
    ppuVar3 = ppuVar3 + 1;
  } while (bVar2 != 6);
  *in_FS_OFFSET = uStack_44;
  *in_FS_OFFSET = uStack_38;
  puStack_30 = &LAB_00458e55;
  puStack_34 = (undefined1 *)0x458e4d;
  FUN_00402eac(local_c);
  return;
}

