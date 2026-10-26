/*
 * FUN_0042d66c at 0042d66c
 * undefined __register FUN_0042d66c(int * param_1)
 * Address ranges: 0042d66c-0042d6b8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042d66c(int *param_1)

{
  HWND pHVar1;
  HWND pHVar2;
  
  if (((int *)param_1[0x82] != (int *)0x0) && (param_1[0x8e] == 0)) {
    param_1 = (int *)param_1[0x82];
  }
  pHVar1 = (HWND)FUN_00445724(param_1);
  SetFocus(pHVar1);
  pHVar1 = (HWND)FUN_00445724(param_1);
  pHVar2 = GetFocus();
  if (pHVar1 == pHVar2) {
    FUN_004405f0((int)param_1,0xb029,0,0);
  }
  return;
}

