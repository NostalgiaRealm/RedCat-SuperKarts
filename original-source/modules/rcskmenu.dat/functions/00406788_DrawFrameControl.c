/*
 * USER32.DLL::DrawFrameControl at 00406788
 * BOOL __stdcall DrawFrameControl(HDC param_1, LPRECT param_2, UINT param_3, UINT param_4)
 * Address ranges: 00406788-0040678d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::DrawFrameControl
 */

BOOL __stdcall DrawFrameControl(HDC param_1,LPRECT param_2,UINT param_3,UINT param_4)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406788. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = DrawFrameControl(param_1,param_2,param_3,param_4);
  return BVar1;
}

