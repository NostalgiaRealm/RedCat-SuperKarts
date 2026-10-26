/*
 * USER32.DLL::ReleaseCapture at 00406a68
 * BOOL __stdcall ReleaseCapture(void)
 * Address ranges: 00406a68-00406a6d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::ReleaseCapture
 */

BOOL __stdcall ReleaseCapture(void)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406a68. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = ReleaseCapture();
  return BVar1;
}

