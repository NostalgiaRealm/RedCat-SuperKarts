/*
 * KERNEL32.DLL::GetCPInfo at 004062e0
 * BOOL __stdcall GetCPInfo(UINT CodePage, LPCPINFO lpCPInfo)
 * Address ranges: 004062e0-004062e5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to KERNEL32.DLL::GetCPInfo
 */

BOOL __stdcall GetCPInfo(UINT CodePage,LPCPINFO lpCPInfo)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004062e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = GetCPInfo(CodePage,lpCPInfo);
  return BVar1;
}

