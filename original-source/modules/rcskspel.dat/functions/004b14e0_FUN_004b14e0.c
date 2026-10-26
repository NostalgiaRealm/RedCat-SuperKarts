/*
 * FUN_004b14e0 at 004b14e0
 * undefined FUN_004b14e0(void)
 * Address ranges: 004b14e0-004b184c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b14e0(HINSTANCE param_1,int param_2,LPCSTR param_3,LPCSTR param_4)

{
  char cVar1;
  int nHeight;
  undefined4 uVar2;
  int iVar3;
  DWORD dwExStyle;
  DWORD dwStyle;
  undefined4 local_3c;
  tagRECT local_38;
  WNDCLASSA local_28;
  
  FUN_004bf48c(&local_3c);
  FUN_004be6bf(local_3c);
  if (DAT_006a64d8 == 0) {
    local_28.style = 3;
    local_28.lpfnWndProc = FUN_004bb050;
    local_28.cbClsExtra = 0;
    local_28.cbWndExtra = 0;
    local_28.hInstance = param_1;
    local_28.hIcon = LoadIconA(param_1,(LPCSTR)0x7f00);
    local_28.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    local_28.hbrBackground = (HBRUSH)0x0;
    local_28.lpszMenuName = (LPCSTR)0x0;
    local_28.lpszClassName = param_3;
    RegisterClassA(&local_28);
    cVar1 = FUN_004afcb0();
    if (cVar1 == '\0') {
      dwExStyle = 0x40000;
      dwStyle = 0x80000000;
      iVar3 = GetSystemMetrics(0);
      nHeight = GetSystemMetrics(1);
    }
    else {
      dwExStyle = 0x300;
      dwStyle = 0xc00000;
      DAT_004fe93c = 8;
      iVar3 = DAT_004fe930;
      nHeight = DAT_004fe934;
    }
    FUN_004afce0(s_____init_xvgalib_______version___004ff8e0,s_Mar_15_2000_004ff904);
    DAT_006a64b4 = CreateWindowExA(dwExStyle,param_3,param_4,dwStyle,0,0,iVar3,nHeight,(HWND)0x0,
                                   (HMENU)0x0,param_1,(LPVOID)0x0);
    if (DAT_006a64b4 == (HWND)0x0) {
      FUN_004afce0(s_failure_to_make_window_004ff8c8);
      return 0;
    }
    GetClientRect(DAT_006a64b4,&local_38);
    MoveWindow(DAT_006a64b4,local_38.left,local_38.top,(iVar3 * 2 - local_38.right) + local_38.left,
               (nHeight * 2 - local_38.bottom) + local_38.top,1);
    FUN_004afce0(s_window_defined_004ff8b8);
    ShowWindow(DAT_006a64b4,param_2);
    UpdateWindow(DAT_006a64b4);
    DAT_006a64d8 = 1;
  }
  FUN_004afce0(s_starting_direct_draw_driver_sear_004ff894);
  FUN_004b9080();
  FUN_004afce0(s_Finished_search_004ff880);
  if (DAT_006a64dc == 0) {
    FUN_004afce0(s_create_direct_draw_object_004ff864);
    uVar2 = FUN_004b90a0(DAT_004fe944);
    iVar3 = DirectDrawCreate(uVar2,&DAT_006a649c,0);
    if (iVar3 != 0) {
      uVar2 = FUN_004b0190(iVar3);
      FUN_004afee0(s__s__d____could_not_create_dd_obj_004ff838,
                   s_C__libraries_dxdraw_Initlib_cpp_004feb14,0x891,uVar2);
    }
    DAT_006a64dc = 1;
  }
  if (DAT_006a64ec == 0) {
    FUN_004afce0(s_set_cooperative_level_004ff820);
    iVar3 = (**(code **)(*DAT_006a649c + 0x50))(DAT_006a649c,DAT_006a64b4,DAT_004fe93c);
    if (iVar3 != 0) {
      uVar2 = FUN_004b0190(iVar3);
      FUN_004afee0(s__s__d____could_not_set_cooperati_004ff7f0,
                   s_C__libraries_dxdraw_Initlib_cpp_004feb14,0x89b,uVar2);
    }
    DAT_006a64ec = 1;
  }
  iVar3 = (**(code **)*DAT_006a649c)(DAT_006a649c,&DAT_004d34c0,&DAT_006a64a4);
  if (iVar3 != 0) {
    uVar2 = FUN_004b0190(iVar3);
    FUN_004afee0(s__s__d____could_not_query_interfa_004ff7bc,
                 s_C__libraries_dxdraw_Initlib_cpp_004feb14,0x8a1,uVar2);
  }
  FUN_004b9200();
  iVar3 = FUN_004b9260(DAT_004fe92c);
  if (iVar3 == 0) {
    FUN_004afce0(s_could_not_find_mode_004ff7a4);
  }
  FUN_004afce0(s_set_display_mode__dx_dx_d_004ff788,DAT_004fe930,DAT_004fe934,DAT_004fe938);
  cVar1 = FUN_004afcb0();
  if ((cVar1 == '\0') &&
     (iVar3 = (**(code **)(*DAT_006a64a4 + 0x54))
                        (DAT_006a64a4,DAT_004fe930,DAT_004fe934,DAT_004fe938,0,0), iVar3 != 0)) {
    uVar2 = FUN_004b0190(iVar3);
    FUN_004afee0(s__s__d____could_not_set_display_m_004ff75c,
                 s_C__libraries_dxdraw_Initlib_cpp_004feb14,0x8b1,uVar2);
  }
  FUN_004b5d90(0,0,DAT_004fe930,DAT_004fe934);
  FUN_004b0ec0();
  FUN_004afce0(s_init_input_004ff750);
  FUN_004afce0(s_system_info_004ff740);
  FUN_004b8b40();
  return 1;
}

