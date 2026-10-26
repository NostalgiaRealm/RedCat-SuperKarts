/*
 * FUN_0043cb14 at 0043cb14
 * undefined __register FUN_0043cb14(int * param_1)
 * Address ranges: 0043cb14-0043cb55
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043cb14(int *param_1)

{
  undefined4 uVar1;
  HWND hWnd;
  int *piVar2;
  
  ReleaseCapture();
  DAT_0047b9b8 = (int *)0x0;
  if (param_1 != (int *)0x0) {
    uVar1 = FUN_00403024(param_1,(int)&PTR_FUN_0043be00);
    piVar2 = param_1;
    if ((char)uVar1 == '\0') {
      if (param_1[9] == 0) {
        return;
      }
      piVar2 = (int *)param_1[9];
      DAT_0047b9b8 = param_1;
    }
    hWnd = (HWND)FUN_00445724(piVar2);
    SetCapture(hWnd);
  }
  return;
}

