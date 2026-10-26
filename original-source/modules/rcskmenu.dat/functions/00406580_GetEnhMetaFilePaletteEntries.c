/*
 * GDI32.DLL::GetEnhMetaFilePaletteEntries at 00406580
 * UINT __stdcall GetEnhMetaFilePaletteEntries(HENHMETAFILE hemf, UINT nNumEntries, LPPALETTEENTRY lpPaletteEntries)
 * Address ranges: 00406580-00406585
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::GetEnhMetaFilePaletteEntries
 */

UINT __stdcall
GetEnhMetaFilePaletteEntries(HENHMETAFILE hemf,UINT nNumEntries,LPPALETTEENTRY lpPaletteEntries)

{
  UINT UVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406580. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  UVar1 = GetEnhMetaFilePaletteEntries(hemf,nNumEntries,lpPaletteEntries);
  return UVar1;
}

