/*
 * FUN_00469ec4 at 00469ec4
 * undefined __register FUN_00469ec4(void)
 * Address ranges: 00469ec4-00469f2a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00469ec4(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *in_FS_OFFSET;
  byte bVar4;
  undefined4 *in_stack_00000004;
  char *in_stack_00000008;
  int *in_stack_00000010;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  int local_8;
  
  bVar4 = 0;
  puStack_18 = &stack0xfffffffc;
  local_8 = 0;
  puStack_1c = &LAB_00469f2b;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  if (in_stack_00000004 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
    puStack_18 = &stack0xfffffffc;
  }
  else {
    puVar1 = (undefined4 *)FUN_00402714(0x10);
    puVar3 = puVar1;
    for (iVar2 = 4; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *in_stack_00000004;
      in_stack_00000004 = in_stack_00000004 + (uint)bVar4 * -2 + 1;
      puVar3 = puVar3 + (uint)bVar4 * -2 + 1;
    }
  }
  FUN_00403d08(&local_8,in_stack_00000008);
  (**(code **)(*in_stack_00000010 + 0x38))(in_stack_00000010,local_8,puVar1);
  *in_FS_OFFSET = uStack_20;
  puStack_18 = &LAB_00469f32;
  puStack_1c = (undefined1 *)0x469f2a;
  FUN_00403b50(&local_8);
  return;
}

