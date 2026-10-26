/*
 * OLEAUT32.DLL::VariantChangeTypeEx at 00401378
 * HRESULT __stdcall VariantChangeTypeEx(VARIANTARG * pvargDest, VARIANTARG * pvarSrc, LCID lcid, USHORT wFlags, VARTYPE vt)
 * Address ranges: 00401378-0040137d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to OLEAUT32.DLL::VariantChangeTypeEx
 */

HRESULT __stdcall
VariantChangeTypeEx(VARIANTARG *pvargDest,VARIANTARG *pvarSrc,LCID lcid,USHORT wFlags,VARTYPE vt)

{
  HRESULT HVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00401378. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HVar1 = VariantChangeTypeEx(pvargDest,pvarSrc,lcid,wFlags,vt);
  return HVar1;
}

