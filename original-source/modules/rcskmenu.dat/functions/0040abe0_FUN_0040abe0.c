/*
 * FUN_0040abe0 at 0040abe0
 * undefined __register FUN_0040abe0(int * param_1, LPCVOID param_2)
 * Address ranges: 0040abe0-0040ac54
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040abe0(int *param_1,LPCVOID param_2)

{
  undefined *puVar1;
  HINSTANCE hInstance;
  UINT uID;
  CHAR *lpBuffer;
  int cchBufferMax;
  CHAR local_440 [64];
  byte local_400 [1024];
  
  FUN_0040aa58(param_1,param_2,local_400,(byte *)0x400);
  lpBuffer = local_440;
  if (*PTR_DAT_0047c8d8 == '\0') {
    cchBufferMax = 0x40;
    uID = *(UINT *)(PTR_PTR_0047c6a8 + 4);
    hInstance = (HINSTANCE)FUN_00404ef0(DAT_0047d4dc);
    LoadStringA(hInstance,uID,lpBuffer,cchBufferMax);
    MessageBoxA((HWND)0x0,(LPCSTR)local_400,local_440,0x2010);
  }
  else {
    puVar1 = (undefined *)FUN_004059e0(PTR_DAT_0047c6f0,(char *)local_400);
    FUN_00405963(puVar1);
    FUN_004027e4();
  }
  return;
}

