/*
 * FUN_004b8b40 at 004b8b40
 * undefined FUN_004b8b40(void)
 * Address ranges: 004b8b40-004b8d0d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004b8b40(void)

{
  BOOL BVar1;
  int iVar2;
  char *pcVar3;
  DWORD local_48;
  _MEMORYSTATUS local_44;
  _SYSTEM_INFO local_24;
  
  FUN_004afce0(s_Getting_system_information_005015ec);
  local_48 = 0x27;
  BVar1 = GetComputerNameA(&DAT_006ab89c,&local_48);
  if (BVar1 != 0) {
    FUN_004afce0(s_Computername____s_005015d8,&DAT_006ab89c);
  }
  local_48 = 0x27;
  BVar1 = GetUserNameA(&DAT_006ab8cc,&local_48);
  if (BVar1 != 0) {
    FUN_004afce0(s_Username____s_005015c8,&DAT_006ab8cc);
  }
  FUN_004b89b0(0x1b);
  GlobalMemoryStatus(&local_44);
  _DAT_006ab90c = local_44.dwTotalPhys;
  DAT_006ab914 = local_44.dwMemoryLoad;
  DAT_006ab910 = local_44.dwAvailPhys;
  FUN_004afce0(s_Total_Physical_Memory____d_Kb_005015a4,
               (int)(local_44.dwTotalPhys + ((int)local_44.dwTotalPhys >> 0x1f & 0x3ffU)) >> 10);
  FUN_004afce0(s_Available_Physical_Memory____d_K_00501580,
               (int)(DAT_006ab910 + ((int)DAT_006ab910 >> 0x1f & 0x3ffU)) >> 10);
  FUN_004afce0(s_Memory_Load__of_total_____d_00501560,DAT_006ab914);
  GetSystemInfo(&local_24);
  _DAT_006ab908 = local_24.dwProcessorType;
  if (local_24.dwProcessorType == 0x182) {
    pcVar3 = s_386_processor_installed_005014e8;
  }
  else if (local_24.dwProcessorType == 0x1e6) {
    pcVar3 = s_486_processor_installed_00501504;
  }
  else if (local_24.dwProcessorType == 0x24a) {
    pcVar3 = s_Pentium_processor_installed_00501520;
  }
  else {
    pcVar3 = s_Unknown_processor_installed_00501540;
  }
  FUN_004afce0(pcVar3);
  iVar2 = GetSystemMetrics(0x43);
  if (iVar2 == 0) {
    _DAT_006ab904 = 0;
    pcVar3 = s_Startup___Normal_Boot_0050148c;
  }
  else if (iVar2 == 1) {
    _DAT_006ab904 = 1;
    pcVar3 = s_Startup___Safe_Mode_Boot_005014a4;
  }
  else {
    if (iVar2 != 2) goto LAB_004b8cb5;
    _DAT_006ab904 = 1;
    pcVar3 = s_Startup___Safe_Mode_Boot_With_Ne_005014c0;
  }
  FUN_004afce0(pcVar3);
LAB_004b8cb5:
  iVar2 = GetSystemMetrics(0x13);
  if (iVar2 != 0) {
    FUN_004afce0(s_Mouse_is_present_00501478);
    _DAT_006ab8f8 = 1;
  }
  iVar2 = GetSystemMetrics(0x3f);
  if (iVar2 != 0) {
    FUN_004afce0(s_Network_is_present_00501464);
    _DAT_006ab8fc = 1;
  }
  iVar2 = GetSystemMetrics(0x49);
  if (iVar2 != 0) {
    FUN_004afce0(s_Windows_95_thinks_this_is_a_slow_00501438);
    _DAT_006ab900 = 1;
  }
  return 0;
}

