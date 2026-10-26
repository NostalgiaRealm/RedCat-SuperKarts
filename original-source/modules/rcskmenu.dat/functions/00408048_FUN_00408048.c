/*
 * FUN_00408048 at 00408048
 * DWORD __register FUN_00408048(HANDLE param_1, LPVOID param_2, DWORD param_3)
 * Address ranges: 00408048-00408073
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

DWORD FUN_00408048(HANDLE param_1,LPVOID param_2,DWORD param_3)

{
  BOOL BVar1;
  DWORD local_10;
  
  local_10 = param_3;
  BVar1 = ReadFile(param_1,param_2,param_3,&local_10,(LPOVERLAPPED)0x0);
  if (BVar1 == 0) {
    local_10 = 0xffffffff;
  }
  return local_10;
}

