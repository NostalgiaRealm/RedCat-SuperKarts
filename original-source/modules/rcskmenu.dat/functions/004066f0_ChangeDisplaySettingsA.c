/*
 * USER32.DLL::ChangeDisplaySettingsA at 004066f0
 * LONG __stdcall ChangeDisplaySettingsA(DEVMODEA * lpDevMode, DWORD dwFlags)
 * Address ranges: 004066f0-004066f5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::ChangeDisplaySettingsA
 */

LONG __stdcall ChangeDisplaySettingsA(DEVMODEA *lpDevMode,DWORD dwFlags)

{
  LONG LVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004066f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LVar1 = ChangeDisplaySettingsA(lpDevMode,dwFlags);
  return LVar1;
}

