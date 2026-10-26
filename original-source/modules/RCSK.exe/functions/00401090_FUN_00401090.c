/*
 * FUN_00401090 at 00401090
 * undefined FUN_00401090(void)
 * Address ranges: 00401090-00401113
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00401090(byte *param_1,undefined1 *param_2)

{
  HANDLE hObject;
  byte abStack_104 [260];
  
  FUN_0040191e(abStack_104,param_1,&DAT_00408c00,(byte *)s_SHELLTRO_00408054,&DAT_00408060);
  hObject = CreateFileA((LPCSTR)abStack_104,0,0,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);
  CloseHandle(hObject);
  if (hObject == (HANDLE)0xffffffff) {
    return 1;
  }
  _strncpy(&DAT_00408034,(char *)param_1,0x20);
  *param_2 = 1;
  return 0;
}

