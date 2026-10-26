/*
 * FUN_004278f8 at 004278f8
 * int * __cdecl FUN_004278f8(int * param_1, uint * param_2)
 * Address ranges: 004278f8-00427a17
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * __cdecl FUN_004278f8(int *param_1,uint *param_2)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  uint *puVar4;
  
  if (param_1 == (int *)0x0) {
    piVar1 = _malloc((size_t)param_2);
  }
  else {
    if (param_2 == (uint *)0x0) {
      FUN_0041fd93(param_1);
    }
    else {
      do {
        if (param_2 < (uint *)0xffffffe1) {
          puVar2 = (uint *)FUN_00422b65((int)param_1);
          if (puVar2 == (uint *)0x0) {
            if (param_2 == (uint *)0x0) {
              param_2 = (uint *)0x1;
            }
            param_2 = (uint *)((int)param_2 + 0xfU & 0xfffffff0);
            piVar1 = HeapReAlloc(DAT_0043f81c,0,param_1,(SIZE_T)param_2);
          }
          else {
            if (param_2 <= DAT_00437490) {
              iVar3 = FUN_00423370(puVar2,(int)param_1,(int)param_2);
              piVar1 = param_1;
              if (iVar3 == 0) {
                piVar1 = FUN_00422ebb(param_2);
                if (piVar1 == (int *)0x0) goto LAB_00427991;
                puVar4 = (uint *)(param_1[-1] - 1U);
                if (param_2 <= (uint *)(param_1[-1] - 1U)) {
                  puVar4 = param_2;
                }
                FUN_00420910(piVar1,param_1,(uint)puVar4);
                FUN_00422b90(puVar2,(uint)param_1);
              }
              if (piVar1 != (int *)0x0) {
                return piVar1;
              }
            }
LAB_00427991:
            if (param_2 == (uint *)0x0) {
              param_2 = (uint *)0x1;
            }
            param_2 = (uint *)((int)param_2 + 0xfU & 0xfffffff0);
            piVar1 = HeapAlloc(DAT_0043f81c,0,(SIZE_T)param_2);
            if (piVar1 == (int *)0x0) goto LAB_004279f4;
            puVar4 = (uint *)(param_1[-1] - 1U);
            if (param_2 <= (uint *)(param_1[-1] - 1U)) {
              puVar4 = param_2;
            }
            FUN_00420910(piVar1,param_1,(uint)puVar4);
            FUN_00422b90(puVar2,(uint)param_1);
          }
          if (piVar1 != (int *)0x0) {
            return piVar1;
          }
        }
LAB_004279f4:
        if (DAT_0043e578 == 0) {
          return (int *)0x0;
        }
        iVar3 = FUN_004262e6(param_2);
      } while (iVar3 != 0);
    }
    piVar1 = (int *)0x0;
  }
  return piVar1;
}

