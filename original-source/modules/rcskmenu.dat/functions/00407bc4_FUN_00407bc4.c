/*
 * FUN_00407bc4 at 00407bc4
 * undefined __register FUN_00407bc4(undefined4 * param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 00407bc4-00407c15
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00407bc4(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  byte *local_8;
  
  puStack_18 = &stack0xfffffffc;
  local_8 = (byte *)0x0;
  puStack_1c = &LAB_00407c16;
  puStack_20 = (undefined1 *)*in_FS_OFFSET;
  *in_FS_OFFSET = &puStack_20;
  FUN_00405438(param_1,(int *)&local_8);
  uVar1 = FUN_0040aca0((int)&DAT_0040774c,'\x01',local_8,param_3,param_2);
  FUN_00403604(uVar1);
  *in_FS_OFFSET = param_3;
  puStack_20 = &LAB_00407c1d;
  FUN_00403b50((int *)&local_8);
  return;
}

