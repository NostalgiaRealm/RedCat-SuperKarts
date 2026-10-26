/*
 * FUN_004478c8 at 004478c8
 * undefined4 __register FUN_004478c8(int param_1, int param_2, int param_3)
 * Address ranges: 004478c8-004478f2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004478c8(int param_1,int param_2,int param_3)

{
  if ((param_2 != 0) && (*(int *)(param_1 + 100) != 0)) {
    FUN_00447870(*(int *)(param_1 + 100),0,param_3,(int)&stack0xfffffffc);
  }
  return 0;
}

