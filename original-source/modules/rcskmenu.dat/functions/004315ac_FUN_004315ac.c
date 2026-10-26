/*
 * FUN_004315ac at 004315ac
 * undefined __register FUN_004315ac(void)
 * Address ranges: 004315ac-004315e5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004315ac(void)

{
  LRESULT LVar1;
  int in_stack_00000004;
  
  LVar1 = DefWindowProcA(*(HWND *)(*(int *)(in_stack_00000004 + -4) + 0x24),
                         **(UINT **)(in_stack_00000004 + -8),
                         *(WPARAM *)(*(int *)(in_stack_00000004 + -8) + 4),
                         *(LPARAM *)(*(int *)(in_stack_00000004 + -8) + 8));
  *(LRESULT *)(*(int *)(in_stack_00000004 + -8) + 0xc) = LVar1;
  return;
}

