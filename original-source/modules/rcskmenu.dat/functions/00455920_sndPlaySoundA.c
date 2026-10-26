/*
 * WINMM.DLL::sndPlaySoundA at 00455920
 * BOOL __stdcall sndPlaySoundA(LPCSTR pszSound, UINT fuSound)
 * Address ranges: 00455920-00455925
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to WINMM.DLL::sndPlaySoundA
 */

BOOL __stdcall sndPlaySoundA(LPCSTR pszSound,UINT fuSound)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00455920. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = sndPlaySoundA(pszSound,fuSound);
  return BVar1;
}

