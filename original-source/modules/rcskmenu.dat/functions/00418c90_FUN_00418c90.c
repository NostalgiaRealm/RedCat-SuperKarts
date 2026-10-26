/*
 * FUN_00418c90 at 00418c90
 * undefined __register FUN_00418c90(void)
 * Address ranges: 00418c90-00418cd9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00418c90(void)

{
  int *piVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_14;
  undefined1 *puStack_10;
  undefined1 *puStack_c;
  undefined4 *local_8;
  
  puStack_c = &stack0xfffffffc;
  local_8 = (undefined4 *)0x0;
  puStack_10 = &LAB_00418cda;
  uStack_14 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_14;
  FUN_00405438((undefined4 *)PTR_PTR_0047c650,(int *)&local_8);
  piVar1 = FUN_0040ac64((int *)&DAT_0040ddb0,'\x01',local_8);
  FUN_00403604(piVar1);
  *in_FS_OFFSET = uStack_14;
  puStack_c = &LAB_00418ce1;
  puStack_10 = (undefined1 *)0x418cd9;
  FUN_00403b50((int *)&local_8);
  return;
}

