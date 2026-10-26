/*
 * FUN_004240f8 at 004240f8
 * undefined FUN_004240f8(void)
 * Address ranges: 004240f8-0042412c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004240f8(int param_1,UINT *param_2)

{
  BOOL BVar1;
  
  if ((*param_2 == 7) && (*(int *)PTR_DAT_0047c9d4 == 1)) {
    BVar1 = IsWindow((HWND)param_2[1]);
    if (BVar1 == 0) {
      param_2[1] = 0;
    }
  }
  FUN_0044329c(param_1,param_2);
  return;
}

