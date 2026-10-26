/*
 * FUN_0044420c at 0044420c
 * undefined __register FUN_0044420c(int * param_1, int param_2)
 * Address ranges: 0044420c-004442d0;004442f3-004442f9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044420c(int *param_1,int param_2)

{
  HWND hWndTo;
  int iVar1;
  LONG *pLVar2;
  tagPOINT *ptVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 uVar4;
  UINT cPoints;
  tagPOINT local_1c [2];
  int local_c;
  int *local_8;
  
  if (*(int *)(param_2 + 0xc) == 0) {
    pLVar2 = (LONG *)(*(int *)(param_2 + 4) + 0x44);
    ptVar3 = local_1c;
    local_c = param_2;
    local_8 = param_1;
    for (iVar1 = 4; iVar1 != 0; iVar1 = iVar1 + -1) {
      ptVar3->x = *pLVar2;
      pLVar2 = pLVar2 + 1;
      ptVar3 = (tagPOINT *)&ptVar3->y;
    }
    cPoints = 2;
    ptVar3 = local_1c;
    hWndTo = (HWND)FUN_00445724(local_8);
    MapWindowPoints((HWND)0x0,hWndTo,ptVar3,cPoints);
    FUN_004421f4((int)local_8);
    uVar4 = *in_FS_OFFSET;
    *in_FS_OFFSET = &stack0xffffffcc;
    FUN_00403088(*(int **)(*(int *)(local_c + 4) + 0x38),local_8,local_1c);
    if (((char)local_8[0x5f] != '\0') && (local_8[0x52] != 0)) {
      iVar1 = *(int *)(local_c + 4);
      (**(code **)(*(int *)local_8[0x52] + 0x18))
                ((int *)local_8[0x52],*(undefined4 *)(iVar1 + 0x38),*(undefined1 *)(iVar1 + 0x54),
                 *(undefined4 *)(iVar1 + 0x58));
    }
    *in_FS_OFFSET = uVar4;
    FUN_004421fc((int)local_8);
    return;
  }
  return;
}

