/*
 * FUN_00472c1c at 00472c1c
 * undefined __register FUN_00472c1c(void)
 * Address ranges: 00472c1c-00472c97
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00472c1c(void)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_2c;
  undefined1 *puStack_28;
  undefined1 *puStack_24;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  undefined4 *local_10;
  int *local_c;
  undefined1 local_5;
  
  puStack_18 = &stack0xfffffffc;
  puStack_24 = &stack0xfffffffc;
  local_10 = (undefined4 *)0x0;
  puStack_1c = &LAB_00472cb5;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  puStack_28 = &LAB_00472c98;
  uStack_2c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_2c;
  FUN_00403e1c((int *)&local_10,*(undefined4 **)PTR_DAT_0047c694,(undefined4 *)"race.ini");
  local_c = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',local_10);
  local_5 = (**(code **)(*local_c + 8))(local_c,"PLAYER","finished");
  *in_FS_OFFSET = 1;
  puStack_28 = &LAB_00472c9f;
  uStack_2c = 0x472c97;
  FUN_00402eac(local_c);
  return;
}

