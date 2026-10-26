/*
 * FUN_004bf48c at 004bf48c
 * undefined FUN_004bf48c(void)
 * Address ranges: 004bf48c-004bf567
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004bf48c(undefined4 *param_1)

{
  DWORD DVar1;
  undefined4 uVar2;
  _TIME_ZONE_INFORMATION local_d0;
  _SYSTEMTIME local_24;
  _SYSTEMTIME local_14;
  
  GetLocalTime(&local_14);
  GetSystemTime(&local_24);
  if (local_24.wMinute == DAT_006b66d8._2_2_) {
    if (local_24.wHour == (WORD)DAT_006b66d8) {
      if (local_24.wDay == DAT_006b66d4._2_2_) {
        if (local_24.wMonth == DAT_006b66d0._2_2_) {
          if (local_24.wYear == (WORD)DAT_006b66d0) goto LAB_004bf536;
        }
      }
    }
  }
  DVar1 = GetTimeZoneInformation(&local_d0);
  if (DVar1 == 0xffffffff) {
    DAT_006b66c8 = 0xffffffff;
  }
  else if (((DVar1 == 2) && (local_d0.DaylightDate.wMonth != 0)) && (local_d0.DaylightBias != 0)) {
    DAT_006b66c8 = 1;
  }
  else {
    DAT_006b66c8 = 0;
  }
  DAT_006b66d0._0_2_ = local_24.wYear;
  DAT_006b66d0._2_2_ = local_24.wMonth;
  DAT_006b66d4._0_2_ = local_24.wDayOfWeek;
  DAT_006b66d4._2_2_ = local_24.wDay;
  DAT_006b66d8._0_2_ = local_24.wHour;
  DAT_006b66d8._2_2_ = local_24.wMinute;
  DAT_006b66dc._0_2_ = local_24.wSecond;
  DAT_006b66dc._2_2_ = local_24.wMilliseconds;
LAB_004bf536:
  uVar2 = FUN_004c4619(local_14.wYear,local_14.wMonth,local_14.wDay,local_14.wHour,local_14.wMinute,
                       local_14.wSecond,DAT_006b66c8);
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = uVar2;
  }
  return;
}

