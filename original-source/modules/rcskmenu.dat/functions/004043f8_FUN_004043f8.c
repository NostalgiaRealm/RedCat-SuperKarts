/*
 * FUN_004043f8 at 004043f8
 * VARIANTARG * __register FUN_004043f8(VARIANTARG * param_1, char * param_2, int param_3)
 * Address ranges: 004043f8-004044de
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Type propagation algorithm not settling */

VARIANTARG * FUN_004043f8(VARIANTARG *param_1,char *param_2,int param_3)

{
  char cVar1;
  bool bVar2;
  VARIANTARG *pVVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  if (param_3 != 0) {
    cVar1 = *param_2;
    uVar4 = (uint)(byte)param_2[1];
    if (cVar1 == '\n') {
      if (param_3 < 2) {
        FUN_00403b50((int *)param_1);
      }
      else {
        FUN_00403b74((int *)param_1,param_3);
      }
    }
    else if (cVar1 == '\v') {
      if (param_3 < 2) {
        FUN_00404180((undefined4 *)param_1);
      }
      else {
        FUN_00404198((undefined4 *)param_1,param_3);
      }
    }
    else {
      pVVar3 = param_1;
      if (cVar1 == '\f') {
        do {
          FUN_00404c68(pVVar3);
          iVar6 = param_3 + -1;
          bVar2 = 0 < param_3;
          pVVar3 = pVVar3 + 1;
          param_3 = iVar6;
        } while (iVar6 != 0 && bVar2);
      }
      else if (cVar1 == '\r') {
        do {
          iVar6 = *(int *)(param_2 + uVar4 + 2);
          FUN_004043f8(pVVar3,(char *)**(undefined4 **)(param_2 + uVar4 + 10),
                       *(int *)(param_2 + uVar4 + 6));
          iVar5 = param_3 + -1;
          bVar2 = 0 < param_3;
          pVVar3 = (VARIANTARG *)((int)&pVVar3->n1 + iVar6);
          param_3 = iVar5;
        } while (iVar5 != 0 && bVar2);
      }
      else if (cVar1 == '\x0e') {
        do {
          iVar6 = *(int *)(param_2 + uVar4 + 2);
          FUN_004043cc((int)pVVar3,(int)param_2);
          iVar5 = param_3 + -1;
          bVar2 = 0 < param_3;
          pVVar3 = (VARIANTARG *)((int)&pVVar3->n1 + iVar6);
          param_3 = iVar5;
        } while (iVar5 != 0 && bVar2);
      }
      else if (cVar1 == '\x0f') {
        do {
          FUN_00405490((int *)pVVar3);
          iVar6 = param_3 + -1;
          bVar2 = 0 < param_3;
          pVVar3 = (VARIANTARG *)((int)&pVVar3->n1 + 4);
          param_3 = iVar6;
        } while (iVar6 != 0 && bVar2);
      }
      else {
        if (cVar1 != '\x11') {
          pVVar3 = (VARIANTARG *)FUN_004027a0(CONCAT31((int3)((uint)param_1 >> 8),2));
          return pVVar3;
        }
        do {
          FUN_00404e5c((undefined4 *)pVVar3,(int)param_2);
          iVar6 = param_3 + -1;
          bVar2 = 0 < param_3;
          pVVar3 = (VARIANTARG *)((int)&pVVar3->n1 + 4);
          param_3 = iVar6;
        } while (iVar6 != 0 && bVar2);
      }
    }
  }
  return param_1;
}

