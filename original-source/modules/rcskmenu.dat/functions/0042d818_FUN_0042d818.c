/*
 * FUN_0042d818 at 0042d818
 * undefined __register FUN_0042d818(UINT param_1, int * param_2, int * param_3)
 * Address ranges: 0042d818-0042d860
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042d818(UINT param_1,int *param_2,int *param_3)

{
  undefined4 uVar1;
  HWND hWnd;
  int *piVar2;
  WPARAM wParam;
  LPARAM lParam;
  
  if (param_2 != (int *)0x0) {
    do {
      piVar2 = param_2;
      param_2 = (int *)piVar2[9];
      if (param_2 == (int *)0x0) break;
      uVar1 = FUN_00403024(piVar2,(int)&PTR_FUN_00427e2c);
    } while ((char)uVar1 == '\0');
    if ((piVar2 != (int *)0x0) && (param_3 != piVar2)) {
      lParam = 0;
      wParam = 0;
      hWnd = (HWND)FUN_00445724(piVar2);
      SendMessageA(hWnd,param_1,wParam,lParam);
    }
  }
  return;
}

