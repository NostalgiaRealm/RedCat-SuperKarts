/*
 * GDI32.DLL::GetEnhMetaFileBits at 00406570
 * UINT __stdcall GetEnhMetaFileBits(HENHMETAFILE hEMF, UINT nSize, LPBYTE lpData)
 * Address ranges: 00406570-00406575
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::GetEnhMetaFileBits
 */

UINT __stdcall GetEnhMetaFileBits(HENHMETAFILE hEMF,UINT nSize,LPBYTE lpData)

{
  UINT UVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406570. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  UVar1 = GetEnhMetaFileBits(hEMF,nSize,lpData);
  return UVar1;
}

