/*
 * FUN_00409030 at 00409030
 * undefined __register FUN_00409030(void)
 * Address ranges: 00409030-00409067
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00409030(void)

{
  int in_stack_00000004;
  
  if (*(char *)(in_stack_00000004 + -0x13) == '\0') {
    FUN_00408ef8((short *)(in_stack_00000004 + -0xe),(ushort *)(in_stack_00000004 + -0x10),
                 (short *)(in_stack_00000004 + -0x12),
                 *(undefined4 *)(*(int *)(in_stack_00000004 + 8) + 8),
                 *(undefined4 *)(*(int *)(in_stack_00000004 + 8) + 0xc));
    *(undefined1 *)(in_stack_00000004 + -0x13) = 1;
  }
  return;
}

