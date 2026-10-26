/*
 * FUN_0042d20c at 0042d20c
 * undefined FUN_0042d20c(void)
 * Address ranges: 0042d20c-0042d24d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042d20c(int *param_1)

{
  WPARAM wParam;
  LPARAM lParam;
  
  if ((*(byte *)(param_1 + 0xb3) & 0x10) == 0) {
    FUN_00442b48((int)param_1);
  }
  else {
    lParam = 0;
    wParam = FUN_00445724(param_1);
    SendMessageA(*(HWND *)(*(int *)(DAT_0047d770 + 0x38) + 0x23c),0x221,wParam,lParam);
  }
  param_1[0x8f] = 0;
  return;
}

