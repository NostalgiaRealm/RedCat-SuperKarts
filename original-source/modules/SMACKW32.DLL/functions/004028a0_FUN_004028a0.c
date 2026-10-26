/*
 * FUN_004028a0 at 004028a0
 * undefined FUN_004028a0(void)
 * Address ranges: 004028a0-004028fd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

LRESULT FUN_004028a0(HWND param_1,UINT param_2,ushort param_3,LPARAM param_4)

{
  LRESULT LVar1;
  
  if ((param_2 == 0x112) && ((param_3 & 0xfff0) == 0xf120)) {
    SetFocus(*(HWND *)(DAT_00410440 + 0x470));
    LVar1 = 0;
  }
  else {
    LVar1 = CallWindowProcA(*(WNDPROC *)(DAT_00410440 + 0x468),param_1,param_2,(uint)param_3,param_4
                           );
  }
  return LVar1;
}

