/*
 * USER32.DLL::TranslateMDISysAccel at 00406b70
 * BOOL __stdcall TranslateMDISysAccel(HWND hWndClient, LPMSG lpMsg)
 * Address ranges: 00406b70-00406b75
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::TranslateMDISysAccel
 */

BOOL __stdcall TranslateMDISysAccel(HWND hWndClient,LPMSG lpMsg)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406b70. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = TranslateMDISysAccel(hWndClient,lpMsg);
  return BVar1;
}

