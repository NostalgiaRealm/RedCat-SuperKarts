/*
 * FUN_00429bfc at 00429bfc
 * undefined4 __register FUN_00429bfc(int param_1)
 * Address ranges: 00429bfc-00429c33
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00429bfc(int param_1)

{
  HWND hWnd;
  uint uVar1;
  uint uVar2;
  int nIndex;
  
  uVar2 = 0x100000;
  if (*(char *)(param_1 + 0x18) == '\x01') {
    uVar2 = 0x200000;
  }
  if (*(char *)(param_1 + 0x1c) != '\0') {
    nIndex = -0x10;
    hWnd = (HWND)FUN_00445724(*(int **)(param_1 + 4));
    uVar1 = GetWindowLongA(hWnd,nIndex);
    if ((uVar1 & uVar2) != 0) {
      return CONCAT31((int3)(uVar1 >> 8),1);
    }
  }
  return 0;
}

