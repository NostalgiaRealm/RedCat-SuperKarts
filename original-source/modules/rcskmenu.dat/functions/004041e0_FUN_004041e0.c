/*
 * FUN_004041e0 at 004041e0
 * undefined __register FUN_004041e0(BSTR param_1, LPCSTR param_2, int param_3)
 * Address ranges: 004041e0-00404262
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004041e0(BSTR param_1,LPCSTR param_2,int param_3)

{
  UINT UVar1;
  WCHAR local_810 [1024];
  
  if (param_3 < 1) {
    FUN_00404180((undefined4 *)param_1);
  }
  else {
    if (param_3 < 0x400) {
      UVar1 = MultiByteToWideChar(0,0,param_2,param_3,local_810,0x400);
      if (0 < (int)UVar1) {
        FUN_00404264(param_1,local_810,UVar1);
        return;
      }
    }
    UVar1 = MultiByteToWideChar(0,0,param_2,param_3,(LPWSTR)0x0,0);
    FUN_00404264(param_1,(OLECHAR *)0x0,UVar1);
    MultiByteToWideChar(0,0,param_2,param_3,*(LPWSTR *)param_1,UVar1);
  }
  return;
}

