/*
 * FUN_004055dc at 004055dc
 * undefined FUN_004055dc(void)
 * Address ranges: 004055dc-00405769
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

DWORD FUN_004055dc(undefined4 *param_1)

{
  int iVar1;
  DWORD DVar2;
  HANDLE pvVar3;
  LONG lDistanceToMove;
  BOOL BVar4;
  uint uVar5;
  DWORD dwCreationDisposition;
  uint uVar6;
  
  param_1[3] = 0;
  param_1[4] = 0;
  iVar1 = param_1[1];
  if (iVar1 == 0xd7b1) {
    DVar2 = 0x80000000;
    dwCreationDisposition = 3;
    param_1[7] = &LAB_00405568;
  }
  else {
    if (iVar1 == 0xd7b2) {
      DVar2 = 0x40000000;
      dwCreationDisposition = 2;
    }
    else {
      if (iVar1 - 0xd7b3U != 0) {
        return iVar1 - 0xd7b3U;
      }
      DVar2 = 0xc0000000;
      dwCreationDisposition = 3;
    }
    param_1[7] = &LAB_00405597;
  }
  param_1[9] = FUN_004055c4;
  param_1[8] = FUN_00405594;
  if (*(char *)(param_1 + 0x12) == '\0') {
    param_1[9] = FUN_00405594;
    if (param_1[1] == 0xd7b2) {
      DVar2 = 0xfffffff5;
    }
    else {
      DVar2 = 0xfffffff6;
    }
    pvVar3 = GetStdHandle(DVar2);
    if (pvVar3 != (HANDLE)0xffffffff) {
      *param_1 = pvVar3;
LAB_00405723:
      if (param_1[1] != 0xd7b1) {
        DVar2 = GetFileType((HANDLE)*param_1);
        if (DVar2 == 0) {
          CloseHandle((HANDLE)*param_1);
          param_1[1] = 0xd7b0;
          return 0x69;
        }
        if (DVar2 == 2) {
          param_1[8] = &LAB_00405597;
        }
      }
      return 0;
    }
  }
  else {
    pvVar3 = CreateFileA((LPCSTR)(param_1 + 0x12),DVar2,1,(LPSECURITY_ATTRIBUTES)0x0,
                         dwCreationDisposition,0x80,(HANDLE)0x0);
    if (pvVar3 != (HANDLE)0xffffffff) {
      *param_1 = pvVar3;
      if (param_1[1] != 0xd7b3) goto LAB_00405723;
      param_1[1] = param_1[1] + -1;
      DVar2 = GetFileSize((HANDLE)*param_1,(LPDWORD)0x0);
      if (DVar2 != 0xffffffff) {
        lDistanceToMove = DVar2 - 0x80;
        if (DVar2 + 1 < 0x81) {
          lDistanceToMove = 0;
        }
        DVar2 = SetFilePointer((HANDLE)*param_1,lDistanceToMove,(PLONG)0x0,0);
        if (DVar2 != 0xffffffff) {
          uVar6 = 0;
          BVar4 = ReadFile((HANDLE)*param_1,param_1 + 0x53,0x80,(LPDWORD)&stack0xfffffff8,
                           (LPOVERLAPPED)0x0);
          if (BVar4 == 1) {
            for (uVar5 = 0; uVar5 < uVar6; uVar5 = uVar5 + 1) {
              if (*(char *)((int)param_1 + uVar5 + 0x14c) == '\x1a') {
                DVar2 = SetFilePointer((HANDLE)*param_1,uVar5 - uVar6,(PLONG)0x0,2);
                if ((DVar2 == 0xffffffff) || (BVar4 = SetEndOfFile((HANDLE)*param_1), BVar4 != 1))
                goto LAB_0040575c;
                break;
              }
            }
            goto LAB_00405723;
          }
        }
      }
    }
  }
LAB_0040575c:
  param_1[1] = 0xd7b0;
  DVar2 = GetLastError();
  return DVar2;
}

