/*
 * FUN_0040ec2c at 0040ec2c
 * undefined __register FUN_0040ec2c(undefined4 param_1)
 * Address ranges: 0040ec2c-0040ec8b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040ec2c(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  byte *local_10;
  undefined4 local_c;
  undefined1 local_8;
  
  puStack_18 = &stack0xfffffffc;
  local_10 = (byte *)0x0;
  puStack_1c = &LAB_0040ec8c;
  puStack_20 = (undefined1 *)*in_FS_OFFSET;
  *in_FS_OFFSET = &puStack_20;
  local_8 = 0xb;
  puVar3 = &local_c;
  uVar2 = 0;
  local_c = param_1;
  FUN_00405438((undefined4 *)PTR_PTR_0047c950,(int *)&local_10);
  uVar1 = FUN_0040aca0((int)&DAT_0040db8c,'\x01',local_10,uVar2,puVar3);
  FUN_00403604(uVar1);
  *in_FS_OFFSET = uVar2;
  puStack_20 = &LAB_0040ec93;
  FUN_00403b50((int *)&local_10);
  return;
}

