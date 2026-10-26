/*
 * FUN_00408278 at 00408278
 * undefined __register FUN_00408278(undefined * param_1, int * param_2)
 * Address ranges: 00408278-004082b1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00408278(undefined *param_1,int *param_2)

{
  LPCSTR lpFileName;
  DWORD DVar1;
  CHAR *lpBuffer;
  LPSTR *lpFilePart;
  LPSTR pCStack_110;
  CHAR local_10c [260];
  
  lpFilePart = &pCStack_110;
  lpBuffer = local_10c;
  DVar1 = 0x104;
  lpFileName = FUN_00403f94(param_1);
  DVar1 = GetFullPathNameA(lpFileName,DVar1,lpBuffer,lpFilePart);
  FUN_00403c38(param_2,(undefined4 *)local_10c,DVar1);
  return;
}

