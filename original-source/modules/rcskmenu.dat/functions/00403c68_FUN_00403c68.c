/*
 * FUN_00403c68 at 00403c68
 * undefined __register FUN_00403c68(int * param_1, LPCWSTR param_2, int param_3)
 * Address ranges: 00403c68-00403cf6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00403c68(int *param_1,LPCWSTR param_2,int param_3)

{
  uint uVar1;
  CHAR local_810 [2048];
  
  if (param_3 < 1) {
    FUN_00403b50(param_1);
  }
  else {
    if (param_3 < 0x400) {
      uVar1 = WideCharToMultiByte(0,0,param_2,param_3,local_810,0x800,(LPCSTR)0x0,(LPBOOL)0x0);
      if (0 < (int)uVar1) {
        FUN_00403c38(param_1,(undefined4 *)local_810,uVar1);
        return;
      }
    }
    uVar1 = WideCharToMultiByte(0,0,param_2,param_3,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
    FUN_00403c38(param_1,(undefined4 *)0x0,uVar1);
    WideCharToMultiByte(0,0,param_2,param_3,(LPSTR)*param_1,uVar1,(LPCSTR)0x0,(LPBOOL)0x0);
  }
  return;
}

