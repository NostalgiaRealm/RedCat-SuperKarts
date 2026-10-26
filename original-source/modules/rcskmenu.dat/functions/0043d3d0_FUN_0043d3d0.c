/*
 * FUN_0043d3d0 at 0043d3d0
 * bool __register FUN_0043d3d0(void)
 * Address ranges: 0043d3d0-0043d410
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool FUN_0043d3d0(void)

{
  undefined4 uVar1;
  HWND hWnd;
  HWND hWndParent;
  BOOL BVar2;
  int in_stack_00000004;
  
  uVar1 = FUN_00403024(*(int **)(in_stack_00000004 + -0x10),(int)&PTR_FUN_0043be00);
  if ((char)uVar1 != '\0') {
    hWnd = (HWND)FUN_00445724(*(int **)(in_stack_00000004 + -0x14));
    hWndParent = (HWND)FUN_00445724(*(int **)(in_stack_00000004 + -0x10));
    BVar2 = IsChild(hWndParent,hWnd);
    return BVar2 != 0;
  }
  return false;
}

