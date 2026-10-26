/*
 * FUN_00458c44 at 00458c44
 * undefined FUN_00458c44(void)
 * Address ranges: 00458c44-00458cf6;00458d01-00458d16
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00458c44(int param_1)

{
  byte bVar1;
  undefined **ppuVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_48;
  undefined *puStack_44;
  undefined1 *puStack_40;
  undefined4 uStack_3c;
  undefined *puStack_38;
  undefined1 *puStack_34;
  undefined4 uStack_30;
  undefined *puStack_2c;
  undefined1 *puStack_28;
  int iStack_18;
  undefined *puStack_14;
  undefined4 *puStack_10;
  int *piStack_c;
  int iStack_8;
  
  puStack_28 = &stack0xfffffffc;
  puStack_34 = &stack0xfffffffc;
  puStack_40 = &stack0xfffffffc;
  piStack_c = (int *)0x0;
  puStack_10 = (undefined4 *)0x0;
  puStack_14 = (undefined *)0x0;
  iStack_18 = 0;
  puStack_2c = &UNK_00458d39;
  uStack_30 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_30;
  puStack_38 = &UNK_00458d17;
  uStack_3c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_3c;
  puStack_44 = &UNK_00458cf7;
  uStack_48 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_48;
  iStack_8 = param_1;
  FUN_0043285c(*(undefined4 *)PTR_DAT_0047c86c,(int *)&puStack_14);
  FUN_004081c4(puStack_14,(int *)&puStack_10);
  FUN_00403dd8((int *)&puStack_10,(undefined4 *)"game.ini");
  piStack_c = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',puStack_10);
  bVar1 = 0;
  ppuVar2 = &PTR_s_KEY_ACCELERATE_0047c0b4;
  do {
    FUN_00407f60(*(undefined4 *)(iStack_8 + 4 + (uint)bVar1 * 4),&iStack_18);
    (**(code **)(*piStack_c + 4))(piStack_c,"INPUT",*ppuVar2,iStack_18);
    bVar1 = bVar1 + 1;
    ppuVar2 = ppuVar2 + 1;
  } while (bVar1 != 6);
  *in_FS_OFFSET = uStack_48;
  *in_FS_OFFSET = uStack_3c;
  puStack_34 = &UNK_00458d1e;
  puStack_38 = (undefined *)0x458d16;
  FUN_00402eac(piStack_c);
  return;
}

