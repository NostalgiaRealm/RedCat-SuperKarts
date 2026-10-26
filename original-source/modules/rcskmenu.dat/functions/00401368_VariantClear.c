/*
 * OLEAUT32.DLL::VariantClear at 00401368
 * HRESULT __stdcall VariantClear(VARIANTARG * pvarg)
 * Address ranges: 00401368-0040136d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to OLEAUT32.DLL::VariantClear
 */

HRESULT __stdcall VariantClear(VARIANTARG *pvarg)

{
  HRESULT HVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00401368. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  HVar1 = VariantClear(pvarg);
  return HVar1;
}

