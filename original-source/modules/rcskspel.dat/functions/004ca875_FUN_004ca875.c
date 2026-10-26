/*
 * FUN_004ca875 at 004ca875
 * undefined FUN_004ca875(void)
 * Address ranges: 004ca875-004ca925
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_004ca875(uint param_1,LONG param_2,LONG param_3,DWORD param_4)

{
  byte *pbVar1;
  HANDLE hFile;
  DWORD DVar2;
  DWORD DVar3;
  int iVar4;
  LONG local_8;
  
  if (param_1 < DAT_006b6b60) {
    iVar4 = (param_1 & 0x1f) * 8;
    if ((*(byte *)((&DAT_006b6a60)[(int)param_1 >> 5] + 4 + iVar4) & 1) == 0) goto LAB_004ca90b;
    local_8 = param_3;
    hFile = (HANDLE)FUN_004c0be4(param_1);
    if (hFile != (HANDLE)0xffffffff) {
      DVar3 = SetFilePointer(hFile,param_2,&local_8,param_4);
      if (DVar3 == 0xffffffff) {
        DVar2 = GetLastError();
        if (DVar2 != 0) {
          FUN_004c6e51(DVar2);
          goto LAB_004ca91c;
        }
      }
      pbVar1 = (byte *)((&DAT_006b6a60)[(int)param_1 >> 5] + 4 + iVar4);
      *pbVar1 = *pbVar1 & 0xfd;
      goto LAB_004ca922;
    }
    _DAT_006b66e8 = 9;
  }
  else {
LAB_004ca90b:
    DAT_006b66ec = 0;
    _DAT_006b66e8 = 9;
  }
LAB_004ca91c:
  DVar3 = 0xffffffff;
  local_8 = -1;
LAB_004ca922:
  return CONCAT44(local_8,DVar3);
}

