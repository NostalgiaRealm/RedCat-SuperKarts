/*
 * GDI32.DLL::CopyEnhMetaFileA at 00406498
 * HENHMETAFILE __stdcall CopyEnhMetaFileA(HENHMETAFILE hEnh, LPCSTR lpFileName)
 * Address ranges: 00406498-0040649d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to GDI32.DLL::CopyEnhMetaFileA
 */

HENHMETAFILE __stdcall CopyEnhMetaFileA(HENHMETAFILE hEnh,LPCSTR lpFileName)

{
  HENHMETAFILE pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406498. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar1 = CopyEnhMetaFileA(hEnh,lpFileName);
  return pHVar1;
}

