/*
 * FUN_0040282c at 0040282c
 * undefined __register FUN_0040282c(undefined4 * param_1, undefined4 * param_2, uint param_3)
 * Address ranges: 0040282c-0040286b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040282c(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  undefined1 *puVar6;
  
  iVar1 = (int)param_3 >> 2;
  if (param_1 < param_2) {
    puVar3 = (undefined4 *)((int)param_1 + (param_3 - 4));
    puVar5 = (undefined4 *)((int)param_2 + (param_3 - 4));
    if (-1 < iVar1) {
      for (; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar5 = *puVar3;
        puVar3 = puVar3 + -1;
        puVar5 = puVar5 + -1;
      }
      puVar4 = (undefined1 *)((int)puVar3 + 3);
      puVar6 = (undefined1 *)((int)puVar5 + 3);
      for (uVar2 = param_3 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar6 = *puVar4;
        puVar4 = puVar4 + -1;
        puVar6 = puVar6 + -1;
      }
    }
  }
  else if ((param_2 != param_1) && (-1 < iVar1)) {
    for (; iVar1 != 0; iVar1 = iVar1 + -1) {
      *param_2 = *param_1;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    }
    for (uVar2 = param_3 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined1 *)param_2 = *(undefined1 *)param_1;
      param_1 = (undefined4 *)((int)param_1 + 1);
      param_2 = (undefined4 *)((int)param_2 + 1);
    }
    return;
  }
  return;
}

