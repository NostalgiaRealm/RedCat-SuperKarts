/*
 * KERNEL32.DLL::EnumCalendarInfoA at 00406298
 * BOOL __stdcall EnumCalendarInfoA(CALINFO_ENUMPROCA lpCalInfoEnumProc, LCID Locale, CALID Calendar, CALTYPE CalType)
 * Address ranges: 00406298-0040629d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::EnumCalendarInfoA
 */

BOOL __stdcall
EnumCalendarInfoA(CALINFO_ENUMPROCA lpCalInfoEnumProc,LCID Locale,CALID Calendar,CALTYPE CalType)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406298. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = EnumCalendarInfoA(lpCalInfoEnumProc,Locale,Calendar,CalType);
  return BVar1;
}

