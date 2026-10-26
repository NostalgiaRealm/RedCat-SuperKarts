/*
 * FUN_00409068 at 00409068
 * undefined __register FUN_00409068(void)
 * Address ranges: 00409068-004090a6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00409068(void)

{
  int in_stack_00000004;
  
  if (*(char *)(in_stack_00000004 + -0x1d) == '\0') {
    FUN_00408c54((undefined2 *)(in_stack_00000004 + -0x16),(undefined2 *)(in_stack_00000004 + -0x18)
                 ,(undefined2 *)(in_stack_00000004 + -0x1a),
                 (undefined2 *)(in_stack_00000004 + -0x1c),
                 *(undefined4 *)(*(int *)(in_stack_00000004 + 8) + 8),
                 *(undefined4 *)(*(int *)(in_stack_00000004 + 8) + 0xc));
    *(undefined1 *)(in_stack_00000004 + -0x1d) = 1;
  }
  return;
}

