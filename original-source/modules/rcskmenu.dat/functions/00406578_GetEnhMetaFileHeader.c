/*
 * GDI32.DLL::GetEnhMetaFileHeader at 00406578
 * UINT __stdcall GetEnhMetaFileHeader(HENHMETAFILE hemf, UINT nSize, LPENHMETAHEADER lpEnhMetaHeader)
 * Address ranges: 00406578-0040657d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::GetEnhMetaFileHeader
 */

UINT __stdcall GetEnhMetaFileHeader(HENHMETAFILE hemf,UINT nSize,LPENHMETAHEADER lpEnhMetaHeader)

{
  UINT UVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406578. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  UVar1 = GetEnhMetaFileHeader(hemf,nSize,lpEnhMetaHeader);
  return UVar1;
}

