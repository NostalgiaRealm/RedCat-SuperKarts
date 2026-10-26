/*
 * FUN_0044cb68 at 0044cb68
 * undefined __register FUN_0044cb68(int param_1, int param_2, int * param_3)
 * Address ranges: 0044cb68-0044cc01
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044cb68(int param_1,int param_2,int *param_3)

{
  int iVar1;
  uint cbMultiByte;
  LPSTR lpMultiByteStr;
  LPCWSTR lpWideCharStr;
  undefined4 *in_FS_OFFSET;
  LPCSTR lpDefaultChar;
  LPBOOL lpUsedDefaultChar;
  undefined4 uStack_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  
  puStack_1c = (undefined1 *)0x44cb80;
  FUN_0044ccfc(param_1);
  puStack_20 = &LAB_0044cc02;
  uStack_24 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_24;
  puStack_1c = &stack0xfffffffc;
  iVar1 = FUN_0044cc38(param_1,param_2);
  if (iVar1 == 0) {
    FUN_00403b50(param_3);
  }
  else {
    lpWideCharStr = (LPCWSTR)(*(int *)(param_1 + 0xc) + *(int *)(iVar1 + 4));
    iVar1 = *(int *)(iVar1 + 8);
    cbMultiByte = WideCharToMultiByte(0,0,lpWideCharStr,iVar1,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
    FUN_00404104(param_3,cbMultiByte);
    lpUsedDefaultChar = (LPBOOL)0x0;
    lpDefaultChar = (LPCSTR)0x0;
    lpMultiByteStr = FUN_00403f94((undefined *)*param_3);
    WideCharToMultiByte(0,0,lpWideCharStr,iVar1,lpMultiByteStr,cbMultiByte,lpDefaultChar,
                        lpUsedDefaultChar);
  }
  *in_FS_OFFSET = uStack_24;
  puStack_1c = &LAB_0044cc09;
  puStack_20 = (undefined1 *)0x44cc01;
  FUN_0044cf50(param_1);
  return;
}

