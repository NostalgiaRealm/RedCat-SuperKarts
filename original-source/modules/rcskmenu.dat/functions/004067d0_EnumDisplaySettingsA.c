/*
 * USER32.DLL::EnumDisplaySettingsA at 004067d0
 * BOOL __stdcall EnumDisplaySettingsA(LPCSTR lpszDeviceName, DWORD iModeNum, DEVMODEA * lpDevMode)
 * Address ranges: 004067d0-004067d5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::EnumDisplaySettingsA
 */

BOOL __stdcall EnumDisplaySettingsA(LPCSTR lpszDeviceName,DWORD iModeNum,DEVMODEA *lpDevMode)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004067d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = EnumDisplaySettingsA(lpszDeviceName,iModeNum,lpDevMode);
  return BVar1;
}

