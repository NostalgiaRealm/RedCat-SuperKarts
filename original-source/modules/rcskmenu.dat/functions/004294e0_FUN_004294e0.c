/*
 * FUN_004294e0 at 004294e0
 * undefined4 __register FUN_004294e0(void)
 * Address ranges: 004294e0-004294ff
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004294e0(void)

{
  undefined4 uVar1;
  int in_stack_00000004;
  int *in_stack_00000008;
  
  uVar1 = 0xffffffff;
  if (*in_stack_00000008 == in_stack_00000004) {
    uVar1 = 0;
    *(undefined1 *)(in_stack_00000008 + 1) = 1;
  }
  return uVar1;
}

