/*
 * FUN_0046263c at 0046263c
 * undefined __register FUN_0046263c(int param_1)
 * Address ranges: 0046263c-00462690
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0046263c(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  HWND hWnd;
  UINT Msg;
  WPARAM wParam;
  LPARAM lParam;
  
  (**(code **)(**(int **)(param_1 + 4) + 0x74))();
  piVar2 = *(int **)(param_1 + 4);
  uVar1 = FUN_00403024(piVar2,(int)&PTR_FUN_0043be00);
  if ((char)uVar1 != '\0') {
    lParam = 0;
    wParam = 0;
    Msg = 0x85;
    piVar2 = (int *)FUN_0040303c(piVar2,(int)&PTR_FUN_0043be00);
    hWnd = (HWND)FUN_00445724(piVar2);
    PostMessageA(hWnd,Msg,wParam,lParam);
  }
  FUN_004405f0(*(int *)(param_1 + 4),0x1401,0,0);
  return;
}

