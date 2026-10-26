/*
 * USER32.DLL::GetKeyboardLayoutList at 00406888
 * int __stdcall GetKeyboardLayoutList(int nBuff, HKL * lpList)
 * Address ranges: 00406888-0040688d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::GetKeyboardLayoutList
 */

int __stdcall GetKeyboardLayoutList(int nBuff,HKL *lpList)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406888. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = GetKeyboardLayoutList(nBuff,lpList);
  return iVar1;
}

