/*
 * WINMM.DLL::mciSendCommandA at 00455918
 * MCIERROR __stdcall mciSendCommandA(MCIDEVICEID mciId, UINT uMsg, DWORD_PTR dwParam1, DWORD_PTR dwParam2)
 * Address ranges: 00455918-0045591d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to WINMM.DLL::mciSendCommandA
 */

MCIERROR __stdcall
mciSendCommandA(MCIDEVICEID mciId,UINT uMsg,DWORD_PTR dwParam1,DWORD_PTR dwParam2)

{
  MCIERROR MVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00455918. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  MVar1 = mciSendCommandA(mciId,uMsg,dwParam1,dwParam2);
  return MVar1;
}

