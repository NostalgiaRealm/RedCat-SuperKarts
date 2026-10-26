/*
 * GDI32.DLL::GetWinMetaFileBits at 004065c8
 * UINT __stdcall GetWinMetaFileBits(HENHMETAFILE hemf, UINT cbData16, LPBYTE pData16, INT iMapMode, HDC hdcRef)
 * Address ranges: 004065c8-004065cd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::GetWinMetaFileBits
 */

UINT __stdcall
GetWinMetaFileBits(HENHMETAFILE hemf,UINT cbData16,LPBYTE pData16,INT iMapMode,HDC hdcRef)

{
  UINT UVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004065c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  UVar1 = GetWinMetaFileBits(hemf,cbData16,pData16,iMapMode,hdcRef);
  return UVar1;
}

