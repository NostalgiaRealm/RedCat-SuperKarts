/*
 * FUN_0048ed60 at 0048ed60
 * undefined FUN_0048ed60(void)
 * Address ranges: 0048ed60-0048edb7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0048ed60(undefined4 param_1,LPCSTR param_2)

{
  LPCSTR lpFileName;
  char cVar1;
  
  lpFileName = param_2;
  if (param_2 != (LPCSTR)0x0) {
    cVar1 = FUN_0048ed00(param_2);
    if (cVar1 != '\0') {
      GetFullPathNameA(lpFileName,0x104,&DAT_0067eb20,&param_2);
      _strncpy(&DAT_0067e920,param_2,0x200);
      DAT_0067eb1f = 0;
    }
  }
  FUN_0048ec10(1);
  return;
}

