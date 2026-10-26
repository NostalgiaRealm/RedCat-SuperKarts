/*
 * USER32.DLL::GetSystemMetrics at 00406918
 * int __stdcall GetSystemMetrics(int nIndex)
 * Address ranges: 00406918-0040691d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::GetSystemMetrics
 */

int __stdcall GetSystemMetrics(int nIndex)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406918. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = GetSystemMetrics(nIndex);
  return iVar1;
}

