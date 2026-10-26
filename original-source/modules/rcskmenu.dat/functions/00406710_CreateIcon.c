/*
 * USER32.DLL::CreateIcon at 00406710
 * HICON __stdcall CreateIcon(HINSTANCE hInstance, int nWidth, int nHeight, BYTE cPlanes, BYTE cBitsPixel, BYTE * lpbANDbits, BYTE * lpbXORbits)
 * Address ranges: 00406710-00406715
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to USER32.DLL::CreateIcon
 */

HICON __stdcall
CreateIcon(HINSTANCE hInstance,int nWidth,int nHeight,BYTE cPlanes,BYTE cBitsPixel,BYTE *lpbANDbits,
          BYTE *lpbXORbits)

{
  HICON pHVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00406710. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pHVar1 = CreateIcon(hInstance,nWidth,nHeight,cPlanes,cBitsPixel,lpbANDbits,lpbXORbits);
  return pHVar1;
}

