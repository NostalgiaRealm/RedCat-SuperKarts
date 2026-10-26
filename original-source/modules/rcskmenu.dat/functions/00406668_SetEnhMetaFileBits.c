/*
 * GDI32.DLL::SetEnhMetaFileBits at 00406668
 * HENHMETAFILE __stdcall SetEnhMetaFileBits(UINT nSize, BYTE * pb)
 * Address ranges: 00406668-0040666d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::SetEnhMetaFileBits
 */

HENHMETAFILE __stdcall SetEnhMetaFileBits(UINT nSize,BYTE *pb)

{
  HENHMETAFILE pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406668. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar1 = SetEnhMetaFileBits(nSize,pb);
  return pHVar1;
}

