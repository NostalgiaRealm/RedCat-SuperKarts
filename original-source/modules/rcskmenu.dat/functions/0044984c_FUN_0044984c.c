/*
 * FUN_0044984c at 0044984c
 * undefined __register FUN_0044984c(int param_1)
 * Address ranges: 0044984c-00449864
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044984c(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)PTR_DAT_0047c734)();
  *(bool *)(param_1 + 0xc) = iVar1 != 0;
  return;
}

