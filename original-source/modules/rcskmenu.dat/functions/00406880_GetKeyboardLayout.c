/*
 * USER32.DLL::GetKeyboardLayout at 00406880
 * HKL __stdcall GetKeyboardLayout(DWORD idThread)
 * Address ranges: 00406880-00406885
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::GetKeyboardLayout
 */

HKL __stdcall GetKeyboardLayout(DWORD idThread)

{
  HKL pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406880. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar1 = GetKeyboardLayout(idThread);
  return pHVar1;
}

