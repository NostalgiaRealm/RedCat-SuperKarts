/*
 * FUN_0044834c at 0044834c
 * undefined __register FUN_0044834c(int param_1, int param_2, undefined4 param_3, int param_4)
 * Address ranges: 0044834c-004483a0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044834c(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  HDC pHVar2;
  tagRECT *ptVar3;
  UINT UVar4;
  UINT UVar5;
  tagRECT local_14;
  
  UVar5 = 0;
  UVar4 = 1;
  iVar1 = *(int *)(*(int *)(param_4 + -8) + 0x18);
  FUN_0040ebe8(param_1,param_2,iVar1 + param_1 + -2,&local_14.left,iVar1 + param_2 + -2);
  ptVar3 = &local_14;
  pHVar2 = (HDC)FUN_00418994(*(int **)(param_4 + -4));
  DrawFrameControl(pHVar2,ptVar3,UVar4,UVar5);
  return;
}

