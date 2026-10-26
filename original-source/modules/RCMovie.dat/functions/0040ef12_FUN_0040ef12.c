/*
 * FUN_0040ef12 at 0040ef12
 * undefined4 __stdcall FUN_0040ef12(void)
 * Address ranges: 0040ef12-0040f144
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0040ef12(void)

{
  BOOL BVar1;
  int iVar2;
  _MEMORYSTATUS local_4c;
  DWORD local_2c;
  _SYSTEM_INFO local_28;
  
  FUN_004015a6((byte *)s_Getting_system_information_00432d60);
  local_2c = 0x27;
  BVar1 = GetComputerNameA(&DAT_0043d770,&local_2c);
  if (BVar1 != 0) {
    FUN_004015a6((byte *)s_Computername____s_00432d7c);
  }
  local_2c = 0x27;
  BVar1 = GetUserNameA(&DAT_0043d7a0,&local_2c);
  if (BVar1 != 0) {
    FUN_004015a6((byte *)s_Username____s_00432d90);
  }
  FUN_0040ed2f(0x1b);
  GlobalMemoryStatus(&local_4c);
  DAT_0043d7e0 = local_4c.dwTotalPhys;
  DAT_0043d7e4 = local_4c.dwAvailPhys;
  DAT_0043d7e8 = local_4c.dwMemoryLoad;
  FUN_004015a6((byte *)s_Total_Physical_Memory____d_Kb_00432da0);
  FUN_004015a6((byte *)s_Available_Physical_Memory____d_K_00432dc4);
  FUN_004015a6((byte *)s_Memory_Load__of_total_____d_00432de8);
  GetSystemInfo(&local_28);
  DAT_0043d7dc = local_28.dwProcessorType;
  if (local_28.dwProcessorType == 0x182) {
    FUN_004015a6((byte *)s_386_processor_installed_00432e08);
  }
  else if (local_28.dwProcessorType == 0x1e6) {
    FUN_004015a6((byte *)s_486_processor_installed_00432e24);
  }
  else if (local_28.dwProcessorType == 0x24a) {
    FUN_004015a6((byte *)s_Pentium_processor_installed_00432e40);
  }
  else {
    FUN_004015a6((byte *)s_Unknown_processor_installed_00432e60);
  }
  iVar2 = GetSystemMetrics(0x43);
  if (iVar2 == 0) {
    _DAT_0043d7d8 = 0;
    FUN_004015a6((byte *)s_Startup___Normal_Boot_00432e80);
  }
  else if (iVar2 == 1) {
    _DAT_0043d7d8 = 1;
    FUN_004015a6((byte *)s_Startup___Safe_Mode_Boot_00432e98);
  }
  else if (iVar2 == 2) {
    _DAT_0043d7d8 = 1;
    FUN_004015a6((byte *)s_Startup___Safe_Mode_Boot_With_Ne_00432eb4);
  }
  iVar2 = GetSystemMetrics(0x13);
  if (iVar2 != 0) {
    FUN_004015a6((byte *)s_Mouse_is_present_00432edc);
    _DAT_0043d7cc = 1;
  }
  iVar2 = GetSystemMetrics(0x3f);
  if (iVar2 != 0) {
    FUN_004015a6((byte *)s_Network_is_present_00432ef0);
    _DAT_0043d7d0 = 1;
  }
  iVar2 = GetSystemMetrics(0x49);
  if (iVar2 != 0) {
    FUN_004015a6((byte *)s_Windows_95_thinks_this_is_a_slow_00432f04);
    _DAT_0043d7d4 = 1;
  }
  return 0;
}

