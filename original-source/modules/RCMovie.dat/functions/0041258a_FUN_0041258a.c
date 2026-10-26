/*
 * FUN_0041258a at 0041258a
 * undefined __cdecl FUN_0041258a(int param_1, int param_2, int param_3, int param_4, int param_5)
 * Address ranges: 0041258a-00412617
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0041258a(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  byte local_38 [52];
  
  GetWindowTextA(*(HWND *)(DAT_0043d850 + 0x18 + param_1 * 0x1c),(LPSTR)local_38,0x32);
  if (param_2 == 0) {
    FUN_00412173(param_1,(LPCSTR)local_38,param_3,param_5);
  }
  else if (param_2 == 1) {
    FUN_004122f5(param_1,local_38,param_4,param_5);
  }
  else {
    FUN_0040187a((byte *)s__s__d_____draw_control_text__inv_004344dc);
  }
  return;
}

