/*
 * FUN_00432e50 at 00432e50
 * undefined __register FUN_00432e50(int param_1)
 * Address ranges: 00432e50-00432e8a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00432e50(int param_1)

{
  bool bVar1;
  HWND pHVar2;
  BOOL BVar3;
  int nCmdShow;
  
  if (*(int *)(param_1 + 0x74) != 0) {
    bVar1 = FUN_00445a20(*(int *)(param_1 + 0x74));
    if (bVar1) {
      pHVar2 = (HWND)FUN_00445724(*(int **)(param_1 + 0x74));
      BVar3 = IsWindowVisible(pHVar2);
      if (BVar3 != 0) {
        nCmdShow = 0;
        pHVar2 = (HWND)FUN_00445724(*(int **)(param_1 + 0x74));
        ShowWindow(pHVar2,nCmdShow);
      }
    }
  }
  return;
}

