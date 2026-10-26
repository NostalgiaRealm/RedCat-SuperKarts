/*
 * FUN_00402714 at 00402714
 * undefined __register FUN_00402714(int param_1)
 * Address ranges: 00402714-00402729
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00402714(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = (*(code *)PTR_FUN_0047b024)();
    if (iVar1 == 0) {
      FUN_004027a0(1);
      return;
    }
  }
  return;
}

