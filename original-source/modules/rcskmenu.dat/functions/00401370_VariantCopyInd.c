/*
 * OLEAUT32.DLL::VariantCopyInd at 00401370
 * HRESULT __stdcall VariantCopyInd(VARIANT * pvarDest, VARIANTARG * pvargSrc)
 * Address ranges: 00401370-00401375
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to OLEAUT32.DLL::VariantCopyInd
 */

HRESULT __stdcall VariantCopyInd(VARIANT *pvarDest,VARIANTARG *pvargSrc)

{
  HRESULT HVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00401370. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HVar1 = VariantCopyInd(pvarDest,pvargSrc);
  return HVar1;
}

