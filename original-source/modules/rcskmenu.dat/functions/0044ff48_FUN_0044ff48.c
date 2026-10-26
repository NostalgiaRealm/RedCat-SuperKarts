/*
 * FUN_0044ff48 at 0044ff48
 * undefined FUN_0044ff48(void)
 * Address ranges: 0044ff48-0044ff60
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044ff48(int param_1)

{
  LPCSTR lpFileName;
  
  lpFileName = FUN_00403f94(*(undefined **)(param_1 + 4));
  WritePrivateProfileStringA((LPCSTR)0x0,(LPCSTR)0x0,(LPCSTR)0x0,lpFileName);
  return;
}

