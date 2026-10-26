/*
 * FUN_004042c3 at 004042c3
 * undefined4 __cdecl FUN_004042c3(HINSTANCE param_1, int param_2, LPCSTR param_3, LPCSTR param_4, uint param_5)
 * Address ranges: 004042c3-00404625
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl
FUN_004042c3(HINSTANCE param_1,int param_2,LPCSTR param_3,LPCSTR param_4,uint param_5)

{
  int iVar1;
  int nWidth;
  HWND hWndParent;
  HMENU hMenu;
  LPVOID lpParam;
  int local_30;
  WNDCLASSA local_2c;
  
  FUN_0041f910(&local_30);
  FUN_0041f8e8(local_30);
  if (DAT_00438450 == 0) {
    local_2c.style = 3;
    local_2c.lpfnWndProc = FUN_0040aa20;
    local_2c.cbClsExtra = 0;
    local_2c.cbWndExtra = 0;
    local_2c.hInstance = param_1;
    local_2c.hIcon = LoadIconA(param_1,(LPCSTR)0x7f00);
    local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    local_2c.hbrBackground = (HBRUSH)0x0;
    local_2c.lpszMenuName = (LPCSTR)(param_5 & 0xffff);
    local_2c.lpszClassName = param_3;
    RegisterClassA(&local_2c);
    FUN_004015a6((byte *)s_____init_xvgalib_____0042dc44);
    lpParam = (LPVOID)0x0;
    hMenu = (HMENU)0x0;
    hWndParent = (HWND)0x0;
    iVar1 = GetSystemMetrics(1);
    nWidth = GetSystemMetrics(0);
    DAT_0043842c = CreateWindowExA(0x40000,param_3,param_4,0x80080000,0,0,nWidth,iVar1,hWndParent,
                                   hMenu,param_1,lpParam);
    if (DAT_0043842c == (HWND)0x0) {
      FUN_004015a6((byte *)s_failure_to_make_window_0042dc5c);
      return 0;
    }
    FUN_004015a6((byte *)s_window_defined_0042dc74);
    ShowWindow(DAT_0043842c,param_2);
    UpdateWindow(DAT_0043842c);
    DAT_00438450 = 1;
  }
  FUN_004015a6((byte *)s_starting_direct_draw_driver_sear_0042dc84);
  FUN_0040f523();
  FUN_004015a6((byte *)s_Finished_search_0042dca8);
  if (DAT_00438454 == 0) {
    FUN_004015a6((byte *)s_create_direct_draw_object_0042dcbc);
    iVar1 = FUN_0040f551(DAT_0042c364);
    iVar1 = DirectDrawCreate(iVar1,&DAT_00438414,0);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____could_not_create_dd_obj_0042dce4);
    }
    DAT_00438454 = 1;
  }
  if (DAT_00438464 == 0) {
    FUN_004015a6((byte *)s_set_cooperative_level_0042dd10);
    iVar1 = (**(code **)(*DAT_00438414 + 0x50))(DAT_00438414,DAT_0043842c,DAT_0042c35c);
    if (iVar1 != 0) {
      FUN_00401f61(iVar1);
      FUN_0040187a((byte *)s__s__d____could_not_set_cooperati_0042dd34);
    }
    DAT_00438464 = 1;
  }
  iVar1 = (**(code **)*DAT_00438414)(DAT_00438414,&DAT_004286d0,&DAT_0043841c);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____could_not_query_interfa_0042dd70);
  }
  FUN_0040f71c();
  iVar1 = FUN_0040f789(DAT_0042c34c);
  if (iVar1 == 0) {
    FUN_004015a6((byte *)s_could_not_find_mode_0042dda4);
  }
  FUN_004015a6((byte *)s_set_display_mode__dx_dx_d_0042ddbc);
  iVar1 = (**(code **)(*DAT_0043841c + 0x54))
                    (DAT_0043841c,DAT_0042c350,DAT_0042c354,DAT_0042c358,0,0);
  if (iVar1 != 0) {
    FUN_00401f61(iVar1);
    FUN_0040187a((byte *)s__s__d____could_not_set_display_m_0042dde4);
  }
  FUN_0040f7fd(0,0,DAT_0042c350,DAT_0042c354);
  FUN_004037f0();
  FUN_004015a6((byte *)s_screen_update_0042de10);
  FUN_0040337e();
  FUN_004015a6((byte *)s_init_input_0042de20);
  FUN_004015a6((byte *)s_system_info_0042de2c);
  FUN_0040ef12();
  return 1;
}

