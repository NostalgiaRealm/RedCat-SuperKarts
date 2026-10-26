/*
 * FUN_00405438 at 00405438
 * undefined __register FUN_00405438(undefined4 * param_1, int * param_2)
 * Address ranges: 00405438-0040548d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00405438(undefined4 *param_1,int *param_2)

{
  HINSTANCE hInstance;
  uint uVar1;
  UINT uID;
  CHAR *lpBuffer;
  int cchBufferMax;
  CHAR local_408 [1024];
  
  lpBuffer = local_408;
  if (param_1 != (undefined4 *)0x0) {
    if ((int)param_1[1] < 0x10000) {
      cchBufferMax = 0x400;
      uID = param_1[1];
      hInstance = (HINSTANCE)FUN_00404ef0(*(int *)*param_1);
      uVar1 = LoadStringA(hInstance,uID,lpBuffer,cchBufferMax);
      FUN_00403c38(param_2,(undefined4 *)local_408,uVar1);
    }
    else {
      FUN_00403d08(param_2,(char *)param_1[1]);
    }
  }
  return;
}

