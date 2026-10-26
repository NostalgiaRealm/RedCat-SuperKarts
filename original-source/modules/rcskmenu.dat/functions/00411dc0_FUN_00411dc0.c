/*
 * FUN_00411dc0 at 00411dc0
 * undefined __register FUN_00411dc0(void)
 * Address ranges: 00411dc0-00411e22
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00411dc0(void)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  int in_stack_00000004;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  byte *local_10;
  undefined4 local_c;
  undefined1 local_8;
  
  puStack_14 = &stack0xfffffffc;
  local_10 = (byte *)0x0;
  puStack_18 = &LAB_00411e23;
  puStack_1c = (undefined1 *)*in_FS_OFFSET;
  *in_FS_OFFSET = &puStack_1c;
  local_c = *(undefined4 *)(in_stack_00000004 + -4);
  local_8 = 6;
  puVar3 = &local_c;
  uVar2 = 0;
  FUN_00405438((undefined4 *)PTR_PTR_0047c7b4,(int *)&local_10);
  uVar1 = FUN_0040aca0((int)&DAT_0040dbe8,'\x01',local_10,uVar2,puVar3);
  FUN_00403604(uVar1);
  *in_FS_OFFSET = uVar2;
  puStack_1c = &LAB_00411e2a;
  FUN_00403b50((int *)&local_10);
  return;
}

