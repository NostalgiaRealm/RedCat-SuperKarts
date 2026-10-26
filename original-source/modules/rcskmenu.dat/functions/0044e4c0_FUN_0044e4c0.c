/*
 * FUN_0044e4c0 at 0044e4c0
 * undefined __register FUN_0044e4c0(undefined * param_1, int * param_2)
 * Address ranges: 0044e4c0-0044e4f7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044e4c0(undefined *param_1,int *param_2)

{
  LPCSTR lpName;
  undefined **lpBuffer;
  DWORD DVar1;
  undefined *local_1008 [1024];
  
  lpBuffer = local_1008;
  DVar1 = 0x1000;
  local_1008[0] = param_1;
  lpName = FUN_00403f94(param_1);
  DVar1 = GetEnvironmentVariableA(lpName,(LPSTR)lpBuffer,DVar1);
  FUN_00403c38(param_2,local_1008,DVar1);
  return;
}

