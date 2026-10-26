/*
 * KERNEL32.DLL::MulDiv at 004063f0
 * int __stdcall MulDiv(int nNumber, int nNumerator, int nDenominator)
 * Address ranges: 004063f0-004063f5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::MulDiv
 */

int __stdcall MulDiv(int nNumber,int nNumerator,int nDenominator)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004063f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = MulDiv(nNumber,nNumerator,nDenominator);
  return iVar1;
}

