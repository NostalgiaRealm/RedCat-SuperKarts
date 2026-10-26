/*
 * FUN_0049c800 at 0049c800
 * undefined FUN_0049c800(void)
 * Address ranges: 0049c800-0049c848
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0049c800(int param_1,int param_2,int param_3)

{
  int *piVar1;
  
  FUN_004afce0(s_TXTCACHE_Filling_pipeline__d_004fbbac,param_2);
  piVar1 = (int *)(param_1 + param_2 * 9);
  FUN_004afce0(s_TXTCACHE_Filling_with_texture__d_004fbb04,param_3);
  *(undefined4 *)(DAT_006a5e80 + 0x2c + param_3 * 0x48) = 4;
  *piVar1 = param_3;
  piVar1[1] = param_3;
  *(undefined1 *)(piVar1 + 2) = 1;
  return;
}

