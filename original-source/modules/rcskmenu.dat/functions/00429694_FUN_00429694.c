/*
 * FUN_00429694 at 00429694
 * HWND __register FUN_00429694(void)
 * Address ranges: 00429694-00429740
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

HWND FUN_00429694(void)

{
  BOOL BVar1;
  HWND hWnd;
  undefined1 *dwNewLong;
  undefined4 in_stack_00000004;
  tagWNDCLASSA local_2c;
  
  _DAT_0047b6e0 = DAT_0047d4dc;
  BVar1 = GetClassInfoA(DAT_0047d4dc,PTR_s_TPUtilWindow_0047b6f4,&local_2c);
  if ((BVar1 == 0) || (local_2c.lpfnWndProc != DefWindowProcA)) {
    if (BVar1 != 0) {
      UnregisterClassA(PTR_s_TPUtilWindow_0047b6f4,DAT_0047d4dc);
    }
    RegisterClassA((WNDCLASSA *)&DAT_0047b6d0);
  }
  hWnd = CreateWindowExA(0x80,PTR_s_TPUtilWindow_0047b6f4,"",0x80000000,0,0,0,0,(HWND)0x0,(HMENU)0x0
                         ,DAT_0047d4dc,(LPVOID)0x0);
  if (in_stack_00000004._2_2_ != 0) {
    dwNewLong = FUN_004295d8();
    SetWindowLongA(hWnd,-4,(LONG)dwNewLong);
  }
  return hWnd;
}

