/*
 * FUN_00411d9b at 00411d9b
 * undefined __cdecl FUN_00411d9b(int param_1)
 * Address ranges: 00411d9b-00411de6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_00411d9b(int param_1)

{
  HWND pHVar1;
  undefined4 local_8;
  
  local_8 = FUN_00412a9d(param_1);
  do {
    if (local_8 == 0) {
      local_8 = DAT_0043d84c;
    }
    else {
      local_8 = local_8 + -1;
    }
    pHVar1 = SetFocus(*(HWND *)(DAT_0043d850 + 0x18 + local_8 * 0x1c));
  } while (pHVar1 == (HWND)0x0);
  return;
}

