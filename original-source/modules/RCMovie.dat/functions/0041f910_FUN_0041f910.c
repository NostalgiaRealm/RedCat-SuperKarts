/*
 * FUN_0041f910 at 0041f910
 * undefined __cdecl FUN_0041f910(int * param_1)
 * Address ranges: 0041f910-0041f9eb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_0041f910(int *param_1)

{
  DWORD DVar1;
  int iVar2;
  _TIME_ZONE_INFORMATION local_d0;
  _SYSTEMTIME local_24;
  _SYSTEMTIME local_14;
  
  GetLocalTime(&local_14);
  GetSystemTime(&local_24);
  if (local_24.wMinute == DAT_0043e320._2_2_) {
    if (local_24.wHour == (WORD)DAT_0043e320) {
      if (local_24.wDay == DAT_0043e31c._2_2_) {
        if (local_24.wMonth == DAT_0043e318._2_2_) {
          if (local_24.wYear == (WORD)DAT_0043e318) goto LAB_0041f9ba;
        }
      }
    }
  }
  DVar1 = GetTimeZoneInformation(&local_d0);
  if (DVar1 == 0xffffffff) {
    DAT_0043e310 = -1;
  }
  else if (((DVar1 == 2) && (local_d0.DaylightDate.wMonth != 0)) && (local_d0.DaylightBias != 0)) {
    DAT_0043e310 = 1;
  }
  else {
    DAT_0043e310 = 0;
  }
  DAT_0043e318._0_2_ = local_24.wYear;
  DAT_0043e318._2_2_ = local_24.wMonth;
  DAT_0043e31c._0_2_ = local_24.wDayOfWeek;
  DAT_0043e31c._2_2_ = local_24.wDay;
  DAT_0043e320._0_2_ = local_24.wHour;
  DAT_0043e320._2_2_ = local_24.wMinute;
  DAT_0043e324._0_2_ = local_24.wSecond;
  DAT_0043e324._2_2_ = local_24.wMilliseconds;
LAB_0041f9ba:
  iVar2 = FUN_0042227d((uint)local_14.wYear,(uint)local_14.wMonth,(uint)local_14.wDay,
                       (uint)local_14.wHour,(uint)local_14.wMinute,(uint)local_14.wSecond,
                       DAT_0043e310);
  if (param_1 != (int *)0x0) {
    *param_1 = iVar2;
  }
  return;
}

