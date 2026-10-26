/*
 * FUN_004152ac at 004152ac
 * undefined FUN_004152ac(void)
 * Address ranges: 004152ac-004152fa;0041530a-00415312
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004152ac(void)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  int in_stack_00000004;
  int in_stack_00000008;
  undefined4 in_stack_0000000c;
  undefined4 *in_stack_00000010;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  
  puStack_14 = &stack0xfffffffc;
  puStack_18 = &LAB_004152fb;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  if (in_stack_00000008 == 0) {
    uVar1 = 0x80030009;
    *in_FS_OFFSET = uStack_1c;
  }
  else {
    uVar1 = (**(code **)(**(int **)(in_stack_00000004 + 0xc) + 8))
                      (*(int **)(in_stack_00000004 + 0xc),in_stack_00000008,in_stack_0000000c);
    if (in_stack_00000010 != (undefined4 *)0x0) {
      *in_stack_00000010 = uVar1;
    }
    uVar1 = 0;
    *in_FS_OFFSET = uStack_1c;
  }
  return uVar1;
}

