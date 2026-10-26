/*
 * FUN_00404720 at 00404720
 * undefined __register FUN_00404720(LPCWSTR param_1, int param_2, int * param_3)
 * Address ranges: 00404720-004047a8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00404720(LPCWSTR param_1,int param_2,int *param_3)

{
  uint uVar1;
  CHAR local_810 [2048];
  
  if (param_2 == 0) {
    FUN_00403b50(param_3);
  }
  else if (param_2 < 0x400) {
    uVar1 = WideCharToMultiByte(0,0,param_1,param_2,local_810,0x800,(LPCSTR)0x0,(LPBOOL)0x0);
    FUN_00403c38(param_3,(undefined4 *)local_810,uVar1);
  }
  else {
    uVar1 = WideCharToMultiByte(0,0,param_1,param_2,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
    FUN_00403c38(param_3,(undefined4 *)0x0,uVar1);
    WideCharToMultiByte(0,0,param_1,param_2,(LPSTR)*param_3,uVar1,(LPCSTR)0x0,(LPBOOL)0x0);
  }
  return;
}

