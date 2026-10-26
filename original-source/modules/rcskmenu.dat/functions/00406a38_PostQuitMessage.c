/*
 * USER32.DLL::PostQuitMessage at 00406a38
 * void __stdcall PostQuitMessage(int nExitCode)
 * Address ranges: 00406a38-00406a3d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::PostQuitMessage
 */

void __stdcall PostQuitMessage(int nExitCode)

{
                    /* WARNING: Could not recover jumptable at 0x00406a38. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  PostQuitMessage(nExitCode);
  return;
}

