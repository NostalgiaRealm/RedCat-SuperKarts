/*
 * FUN_004044ec at 004044ec
 * undefined __register FUN_004044ec(int param_1, int param_2, int param_3)
 * Address ranges: 004044ec-00404605
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004044ec(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  
  puVar8 = (undefined4 *)(param_3 + 10 + (uint)*(byte *)(param_3 + 1));
  iVar7 = puVar8[-1];
  iVar5 = 0;
  iVar2 = puVar8[-2];
  do {
    uVar6 = puVar8[1] - iVar5;
    if (uVar6 != 0 && iVar5 <= (int)puVar8[1]) {
      FUN_0040282c((undefined4 *)(iVar5 + param_2),(undefined4 *)(iVar5 + param_1),uVar6);
    }
    iVar3 = puVar8[1];
    pcVar4 = *(char **)*puVar8;
    cVar1 = *pcVar4;
    if (cVar1 == '\n') {
      FUN_00403ba4((int *)(iVar3 + param_1),*(undefined4 **)(param_2 + iVar3));
      iVar5 = 4;
    }
    else if (cVar1 == '\v') {
      FUN_004041bc((BSTR *)(iVar3 + param_1),*(OLECHAR **)(param_2 + iVar3));
      iVar5 = 4;
    }
    else if (cVar1 == '\f') {
      FUN_004048b0((VARIANT *)(iVar3 + param_1),(VARIANTARG *)(param_2 + iVar3));
      iVar5 = 0x10;
    }
    else if (cVar1 == '\r') {
      uVar6 = (uint)(byte)pcVar4[1];
      iVar5 = *(int *)(pcVar4 + uVar6 + 2);
      FUN_00404608((VARIANT *)(iVar3 + param_1),(VARIANTARG *)(param_2 + iVar3),
                   (char *)**(undefined4 **)(pcVar4 + uVar6 + 10),*(int *)(pcVar4 + uVar6 + 6));
    }
    else if (cVar1 == '\x0e') {
      iVar5 = *(int *)(pcVar4 + (byte)pcVar4[1] + 2);
      FUN_004044ec(iVar3 + param_1,param_2 + iVar3,(int)pcVar4);
    }
    else if (cVar1 == '\x0f') {
      FUN_004054a8((int *)(iVar3 + param_1),*(int **)(param_2 + iVar3));
      iVar5 = 4;
    }
    else {
      if (cVar1 != '\x11') {
        FUN_004027a0(CONCAT31((int3)((uint)iVar3 >> 8),2));
        return;
      }
      FUN_00404e98((int *)(iVar3 + param_1),*(int *)(param_2 + iVar3),(int)pcVar4);
      iVar5 = 4;
    }
    iVar5 = iVar5 + puVar8[1];
    puVar8 = puVar8 + 2;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  uVar6 = iVar2 - iVar5;
  if (uVar6 != 0 && iVar5 <= iVar2) {
    FUN_0040282c((undefined4 *)(iVar5 + param_2),(undefined4 *)(param_1 + iVar5),uVar6);
  }
  return;
}

