/*
 * FUN_00472f00 at 00472f00
 * undefined __register FUN_00472f00(void)
 * Address ranges: 00472f00-00472f7b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00472f00(void)

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
  undefined4 local_8;
  
  puStack_18 = &stack0xfffffffc;
  puStack_24 = &stack0xfffffffc;
  local_10 = (undefined4 *)0x0;
  puStack_1c = &LAB_00472f99;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  puStack_28 = &LAB_00472f7c;
  uStack_2c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_2c;
  FUN_00403e1c((int *)&local_10,*(undefined4 **)PTR_DAT_0047c694,(undefined4 *)"race.ini");
  local_c = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',local_10);
  local_8 = (**(code **)(*local_c + 8))(local_c,"PLAYER","EUROSTARS");
  *in_FS_OFFSET = 0;
  puStack_28 = &LAB_00472f83;
  uStack_2c = 0x472f7b;
  FUN_00402eac(local_c);
  return;
}

