/*
 * FUN_00430d74 at 00430d74
 * LRESULT __register FUN_00430d74(void)
 * Address ranges: 00430d74-00430db4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

LRESULT FUN_00430d74(void)

{
  LRESULT LVar1;
  int in_stack_00000004;
  WPARAM in_stack_00000008;
  LPARAM in_stack_0000000c;
  
  LVar1 = CallNextHookEx(DAT_0047d78c,in_stack_00000004,in_stack_00000008,in_stack_0000000c);
  if ((-1 < in_stack_00000004) && (DAT_0047d770 != 0)) {
    FUN_004320b4(DAT_0047d770,in_stack_0000000c);
  }
  return LVar1;
}

