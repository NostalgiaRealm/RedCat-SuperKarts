/*
 * FUN_00418f1c at 00418f1c
 * int __register FUN_00418f1c(int param_1, int param_2, int param_3)
 * Address ranges: 00418f1c-00418f2f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00418f1c(int param_1,int param_2,int param_3)

{
  uint uVar1;
  
  uVar1 = param_1 * param_2 + (param_3 - 1U) & ~(param_3 - 1U);
  if ((int)uVar1 < 0) {
    uVar1 = uVar1 + 7;
  }
  return (int)uVar1 >> 3;
}

