/*
 * FUN_004c1c70 at 004c1c70
 * undefined FUN_004c1c70(void)
 * Address ranges: 004c1c70-004c1d8f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void * FUN_004c1c70(LPVOID param_1,uint param_2)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  LPVOID pvVar4;
  uint uVar5;
  
  if (param_1 == (LPVOID)0x0) {
    pvVar1 = _malloc(param_2);
  }
  else {
    if (param_2 == 0) {
      FUN_004bff99(param_1);
    }
    else {
      do {
        if (param_2 < 0xffffffe1) {
          iVar2 = FUN_004c6350(param_1);
          if (iVar2 == 0) {
            if (param_2 == 0) {
              param_2 = 1;
            }
            param_2 = param_2 + 0xf & 0xfffffff0;
            pvVar4 = HeapReAlloc(DAT_006b6da0,0,param_1,param_2);
          }
          else {
            if (param_2 <= DAT_005031e4) {
              iVar3 = FUN_004c6b5b(iVar2,param_1,param_2);
              pvVar4 = param_1;
              if (iVar3 == 0) {
                pvVar4 = (LPVOID)FUN_004c66a6(param_2);
                if (pvVar4 == (LPVOID)0x0) goto LAB_004c1d09;
                uVar5 = *(int *)((int)param_1 + -4) - 1;
                if (param_2 <= uVar5) {
                  uVar5 = param_2;
                }
                FUN_004c0e10(pvVar4,param_1,uVar5);
                FUN_004c637b(iVar2,param_1);
              }
              if (pvVar4 != (LPVOID)0x0) {
                return pvVar4;
              }
            }
LAB_004c1d09:
            if (param_2 == 0) {
              param_2 = 1;
            }
            param_2 = param_2 + 0xf & 0xfffffff0;
            pvVar4 = HeapAlloc(DAT_006b6da0,0,param_2);
            if (pvVar4 == (LPVOID)0x0) goto LAB_004c1d6c;
            uVar5 = *(int *)((int)param_1 + -4) - 1;
            if (param_2 <= uVar5) {
              uVar5 = param_2;
            }
            FUN_004c0e10(pvVar4,param_1,uVar5);
            FUN_004c637b(iVar2,param_1);
          }
          if (pvVar4 != (LPVOID)0x0) {
            return pvVar4;
          }
        }
LAB_004c1d6c:
        if (DAT_006b67bc == 0) {
          return (void *)0x0;
        }
        iVar2 = FUN_004c62bb(param_2);
      } while (iVar2 != 0);
    }
    pvVar1 = (void *)0x0;
  }
  return pvVar1;
}

