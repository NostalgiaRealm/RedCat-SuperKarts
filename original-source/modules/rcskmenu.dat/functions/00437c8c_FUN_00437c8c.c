/*
 * FUN_00437c8c at 00437c8c
 * undefined __register FUN_00437c8c(void)
 * Address ranges: 00437c8c-00437cd4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00437c8c(void)

{
  BOOL BVar1;
  int in_stack_00000004;
  undefined4 local_158 [38];
  undefined4 local_c0;
  undefined4 local_bc;
  
  local_158[0] = 0x154;
  BVar1 = SystemParametersInfoA(0x29,0,local_158,0);
  if (BVar1 != 0) {
    **(undefined4 **)(in_stack_00000004 + -4) = local_c0;
    **(undefined4 **)(in_stack_00000004 + 8) = local_bc;
  }
  return;
}

