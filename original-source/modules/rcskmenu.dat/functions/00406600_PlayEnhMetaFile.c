/*
 * GDI32.DLL::PlayEnhMetaFile at 00406600
 * BOOL __stdcall PlayEnhMetaFile(HDC hdc, HENHMETAFILE hmf, RECT * lprect)
 * Address ranges: 00406600-00406605
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::PlayEnhMetaFile
 */

BOOL __stdcall PlayEnhMetaFile(HDC hdc,HENHMETAFILE hmf,RECT *lprect)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406600. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = PlayEnhMetaFile(hdc,hmf,lprect);
  return BVar1;
}

