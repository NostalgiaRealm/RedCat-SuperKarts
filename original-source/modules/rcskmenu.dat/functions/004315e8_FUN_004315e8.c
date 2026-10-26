/*
 * FUN_004315e8 at 004315e8
 * undefined __register FUN_004315e8(void)
 * Address ranges: 004315e8-00431631
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004315e8(void)

{
  HDC hDC;
  HICON hIcon;
  int in_stack_00000004;
  tagPAINTSTRUCT local_44;
  
  hDC = BeginPaint(*(HWND *)(*(int *)(in_stack_00000004 + -4) + 0x24),&local_44);
  hIcon = (HICON)FUN_00431cd0(*(int *)(in_stack_00000004 + -4));
  DrawIcon(hDC,0,0,hIcon);
  EndPaint(*(HWND *)(*(int *)(in_stack_00000004 + -4) + 0x24),&local_44);
  return;
}

