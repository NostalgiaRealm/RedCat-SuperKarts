/*
 * FUN_004035cc at 004035cc
 * undefined4 __register FUN_004035cc(void)
 * Address ranges: 004035cc-00403601
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004035cc(void)

{
  int iVar1;
  code *extraout_ECX;
  int in_stack_00000004;
  int in_stack_00000008;
  
  if ((*(uint *)(in_stack_00000004 + 4) & 6) != 0) {
    iVar1 = *(int *)(in_stack_00000008 + 4);
    *(undefined4 *)(in_stack_00000008 + 4) = 0x4035fc;
    FUN_004032b4(in_stack_00000004,in_stack_00000008,(char *)(iVar1 + 5));
    (*extraout_ECX)();
  }
  return 1;
}

