/*
 * FUN_00442aac at 00442aac
 * undefined __register FUN_00442aac(int param_1, undefined4 * param_2)
 * Address ranges: 00442aac-00442aec
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00442aac(int param_1,undefined4 *param_2)

{
  HWND pHVar1;
  
  pHVar1 = CreateWindowExA(param_2[2],(LPCSTR)(param_2 + 0x13),(LPCSTR)*param_2,param_2[1],
                           param_2[3],param_2[4],param_2[5],param_2[6],(HWND)param_2[7],(HMENU)0x0,
                           (HINSTANCE)param_2[0xd],(LPVOID)param_2[8]);
  *(HWND *)(param_1 + 0x14c) = pHVar1;
  return;
}

