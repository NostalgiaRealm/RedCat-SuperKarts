/*
 * FUN_0042c1f0 at 0042c1f0
 * undefined FUN_0042c1f0(void)
 * Address ranges: 0042c1f0-0042c22a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042c1f0(int *param_1,undefined4 param_2,int *param_3)

{
  FUN_0042a5c8(param_1,param_2,param_3);
  if ((HWND)param_1[0x8f] != (HWND)0x0) {
    SetWindowPos((HWND)param_1[0x8f],(HWND)0x1,*param_3,param_3[1],param_3[2] - *param_3,
                 param_3[3] - param_3[1],0x14);
  }
  return;
}

