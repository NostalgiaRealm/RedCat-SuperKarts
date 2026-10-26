/*
 * FUN_00429ce4 at 00429ce4
 * int __register FUN_00429ce4(int param_1)
 * Address ranges: 00429ce4-00429d62
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00429ce4(int param_1)

{
  HWND hWnd;
  int iVar1;
  int extraout_ECX;
  undefined2 extraout_var;
  int iVar2;
  
  iVar2 = -0x10;
  hWnd = (HWND)FUN_00445724(*(int **)(param_1 + 4));
  GetWindowLongA(hWnd,iVar2);
  if (*(char *)(param_1 + 0x18) == '\x01') {
    iVar1 = FUN_00429c68(0,CONCAT22(extraout_var,0x15),extraout_ECX,(int)&stack0xfffffffc);
    iVar2 = FUN_0043f0f4(*(int **)(param_1 + 4));
    iVar1 = iVar1 + iVar2;
  }
  else {
    iVar1 = FUN_00429c68(1,CONCAT22(extraout_var,0x14),extraout_ECX,(int)&stack0xfffffffc);
    iVar2 = FUN_0043f0b0(*(int **)(param_1 + 4));
    iVar1 = iVar1 + iVar2;
  }
  return iVar1;
}

