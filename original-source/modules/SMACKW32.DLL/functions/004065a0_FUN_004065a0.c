/*
 * FUN_004065a0 at 004065a0
 * undefined __cdecl FUN_004065a0(int param_1, int param_2, int param_3, int param_4, uint param_5, int param_6, int param_7, int param_8)
 * Address ranges: 004065a0-004065de
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl
FUN_004065a0(int param_1,int param_2,int param_3,int param_4,uint param_5,int param_6,int param_7,
            int param_8)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)(param_1 + param_7);
  puVar2 = (undefined4 *)(param_3 + param_8);
  do {
    uVar1 = param_5 >> 2;
    if (uVar1 != 0) {
      for (; uVar1 != 0; uVar1 = uVar1 - 1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
    }
    for (uVar1 = param_5 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
      *(undefined1 *)puVar3 = *(undefined1 *)puVar2;
      puVar2 = (undefined4 *)((int)puVar2 + 1);
      puVar3 = (undefined4 *)((int)puVar3 + 1);
    }
    puVar3 = (undefined4 *)((int)puVar3 + param_2);
    puVar2 = (undefined4 *)((int)puVar2 + param_4);
    param_6 = param_6 + -1;
  } while (param_6 != 0);
  return;
}

