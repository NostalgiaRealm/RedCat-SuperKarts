/*
 * FUN_00405740 at 00405740
 * longlong __fastcall FUN_00405740(undefined4 param_1, uint param_2)
 * Address ranges: 00405740-004059a7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

longlong __fastcall FUN_00405740(undefined4 param_1,uint param_2)

{
  int in_EAX;
  int iVar1;
  uint extraout_ECX;
  uint extraout_ECX_00;
  int iVar2;
  int *piVar3;
  uint lDistanceToMove;
  undefined4 *puVar4;
  uint uVar5;
  
  if (*(int *)(in_EAX + 0x370) == 0) {
    puVar4 = (undefined4 *)(in_EAX + 0x6c);
    for (iVar1 = 0xc1; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
      *(undefined1 *)puVar4 = 0;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
    iVar1 = *(int *)(in_EAX + 0x420);
    if ((iVar1 != -1) && (*(int *)(*(int *)(in_EAX + 0x404 + iVar1 * 4) + 0x28) != 0)) {
      iVar2 = 1;
      if (iVar1 + 1U < 7) {
        uVar5 = (iVar1 + 1U) * 4 + in_EAX;
        do {
          if (*(int *)(uVar5 + 0x404) != 0) {
            iVar2 = iVar2 + 1;
          }
          uVar5 = uVar5 + 4;
        } while (uVar5 < in_EAX + 0x1cU);
      }
      if (iVar2 == DAT_0040e83c) {
        iVar1 = in_EAX;
        do {
          puVar4 = *(undefined4 **)(iVar1 + 0x404);
          if (puVar4 != (undefined4 *)0x0) {
            (*DAT_00410470)(puVar4);
            puVar4[4] = 0;
            puVar4[10] = 0;
            puVar4[3] = *puVar4;
            puVar4[2] = *puVar4;
            iVar2 = puVar4[8];
            puVar4[8] = 0;
            puVar4[9] = puVar4[9] - iVar2;
          }
          iVar1 = iVar1 + 4;
        } while (iVar1 != in_EAX + 0x1c);
      }
    }
  }
  iVar1 = 0;
  uVar5 = 0;
  if (*(int *)(in_EAX + 0x370) != 0) {
    piVar3 = *(int **)(in_EAX + 0x3b8);
    do {
      uVar5 = uVar5 + 1;
      iVar2 = *piVar3;
      piVar3 = piVar3 + 1;
      iVar1 = iVar1 + iVar2;
    } while (uVar5 < *(uint *)(in_EAX + 0x370));
  }
  if ((*(byte *)(in_EAX + 0x385) & 2) == 0) {
    uVar5 = *(uint *)(in_EAX + 0x444);
    lDistanceToMove = iVar1 + *(int *)(in_EAX + 0x3a8);
    if ((lDistanceToMove < uVar5) || (uVar5 + *(int *)(in_EAX + 0x43c) < lDistanceToMove)) {
      iVar1 = *(int *)(in_EAX + 0x42c);
      *(undefined4 *)(in_EAX + 0x43c) = 0;
      *(int *)(in_EAX + 0x438) = iVar1;
      *(int *)(in_EAX + 0x434) = iVar1;
      *(int *)(in_EAX + 0x430) = iVar1 + *(int *)(in_EAX + 0x440);
      SetFilePointer(*(HANDLE *)(in_EAX + 0x394),lDistanceToMove,(PLONG)0x0,0);
      uVar5 = extraout_ECX;
      if ((lDistanceToMove & 0xfff) != 0) {
        *(undefined4 *)(in_EAX + 0x42c) = 0;
        uVar5 = FUN_004059b0(extraout_ECX,*(undefined4 **)(in_EAX + 0x434));
        *(uint *)(in_EAX + 0x43c) = uVar5;
        *(uint *)(in_EAX + 0x438) = *(int *)(in_EAX + 0x438) + uVar5;
        *(undefined4 *)(in_EAX + 0x42c) = *(undefined4 *)(in_EAX + 0x434);
        uVar5 = extraout_ECX_00;
      }
    }
    else {
      *(uint *)(in_EAX + 0x43c) = *(int *)(in_EAX + 0x43c) - (lDistanceToMove - uVar5);
      uVar5 = *(int *)(in_EAX + 0x434) + (lDistanceToMove - uVar5);
      *(uint *)(in_EAX + 0x434) = uVar5;
      if (*(uint *)(in_EAX + 0x430) <= uVar5) {
        *(uint *)(in_EAX + 0x434) = *(int *)(in_EAX + 0x42c) + (uVar5 - *(uint *)(in_EAX + 0x430));
        *(int *)(in_EAX + 0x430) = *(int *)(in_EAX + 0x42c) + *(int *)(in_EAX + 0x440);
      }
    }
    *(uint *)(in_EAX + 0x444) = lDistanceToMove;
    if ((*(byte *)(in_EAX + 0x385) & 2) != 0) {
      return (ulonglong)param_2 << 0x20;
    }
    *(undefined4 *)(in_EAX + 0x3b0) = *(undefined4 *)(in_EAX + 0x3ac);
    uVar5 = FUN_004059b0(uVar5,*(undefined4 **)(in_EAX + 0x3ac));
  }
  else {
    *(int *)(in_EAX + 0x3b0) = *(int *)(in_EAX + 0x3ac) + iVar1;
    uVar5 = 0;
  }
  return CONCAT44(param_2,uVar5);
}

