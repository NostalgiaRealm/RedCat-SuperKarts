/*
 * USER32.DLL::MapVirtualKeyA at 00406a00
 * UINT __stdcall MapVirtualKeyA(UINT uCode, UINT uMapType)
 * Address ranges: 00406a00-00406a05
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::MapVirtualKeyA
 */

UINT __stdcall MapVirtualKeyA(UINT uCode,UINT uMapType)

{
  UINT UVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406a00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  UVar1 = MapVirtualKeyA(uCode,uMapType);
  return UVar1;
}

