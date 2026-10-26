/*
 * FUN_004041bc at 004041bc
 * BSTR * __register FUN_004041bc(BSTR * param_1, OLECHAR * param_2)
 * Address ranges: 00404168-0040416e;004041bc-004041df
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

BSTR * FUN_004041bc(BSTR *param_1,OLECHAR *param_2)

{
  BSTR bstrString;
  BSTR *ppOVar1;
  
  if ((param_2 != (OLECHAR *)0x0) && (*(uint *)(param_2 + -2) >> 1 != 0)) {
    ppOVar1 = (BSTR *)SysReAllocStringLen(param_1,param_2,*(uint *)(param_2 + -2) >> 1);
    if (ppOVar1 != (BSTR *)0x0) {
      return ppOVar1;
    }
    ppOVar1 = (BSTR *)FUN_004027a0(1);
    return ppOVar1;
  }
  bstrString = *param_1;
  if (bstrString != (BSTR)0x0) {
    *param_1 = (BSTR)0x0;
    SysFreeString(bstrString);
  }
  return param_1;
}

