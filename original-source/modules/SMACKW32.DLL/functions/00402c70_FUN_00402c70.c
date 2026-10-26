/*
 * FUN_00402c70 at 00402c70
 * undefined4 * __stdcall FUN_00402c70(uint param_1, int param_2, undefined4 * param_3, undefined4 * param_4, undefined4 * param_5)
 * Address ranges: 00402c70-00402ce4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 *
FUN_00402c70(uint param_1,int param_2,undefined4 *param_3,undefined4 *param_4,undefined4 *param_5)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  uVar3 = param_2 - (int)param_4;
  puVar2 = param_4;
  if ((uVar3 <= param_1) && (puVar2 = param_3, uVar3 != 0)) {
    puVar4 = param_5;
    for (uVar1 = uVar3 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar4 = *param_4;
      param_4 = param_4 + 1;
      puVar4 = puVar4 + 1;
    }
    for (uVar1 = uVar3 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
      *(undefined1 *)puVar4 = *(undefined1 *)param_4;
      param_4 = (undefined4 *)((int)param_4 + 1);
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
    param_5 = (undefined4 *)((int)param_5 + uVar3);
    param_1 = param_1 - uVar3;
  }
  if (param_1 != 0) {
    puVar4 = puVar2;
    for (uVar3 = param_1 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *param_5 = *puVar4;
      puVar4 = puVar4 + 1;
      param_5 = param_5 + 1;
    }
    for (uVar3 = param_1 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined1 *)param_5 = *(undefined1 *)puVar4;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      param_5 = (undefined4 *)((int)param_5 + 1);
    }
    puVar2 = (undefined4 *)((int)puVar2 + param_1);
  }
  return puVar2;
}

