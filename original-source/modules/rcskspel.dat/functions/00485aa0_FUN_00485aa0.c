/*
 * FUN_00485aa0 at 00485aa0
 * undefined FUN_00485aa0(void)
 * Address ranges: 00485aa0-00485c07
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00485aa0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  float10 fVar4;
  
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x244)) {
    puVar2 = (undefined4 *)(param_1 + 0x14);
    do {
      iVar1 = *(int *)(param_1 + 0x27c) * 0xc;
      iVar3 = iVar3 + 1;
      puVar2[-1] = ((*(uint *)(&DAT_004f9e60 + iVar1) | 0xffffff00) << 8 |
                   *(uint *)(&DAT_004f9e64 + iVar1)) << 8 | *(uint *)(&DAT_004f9e68 + iVar1);
      *puVar2 = 0;
      puVar2 = puVar2 + 8;
    } while (iVar3 < *(int *)(param_1 + 0x244));
  }
  fVar4 = (float10)FUN_0048f4e0();
  iVar3 = 0;
  *(int *)(param_1 + 0x280) = *(int *)(param_1 + 0x280) + 1;
  fVar4 = (float10)60.0 / ((float10)1.0 / fVar4);
  if (0 < *(int *)(param_1 + 0x244)) {
    puVar2 = (undefined4 *)(param_1 + 0x94);
    do {
      iVar1 = *(int *)(param_1 + 0x27c) * 0xc;
      iVar3 = iVar3 + 1;
      puVar2[-1] = ((*(uint *)(&DAT_004f9e6c + iVar1) | 0xffffff00) << 8 |
                   *(uint *)(&DAT_004f9e70 + iVar1)) << 8 | *(uint *)(&DAT_004f9e74 + iVar1);
      *puVar2 = 0;
      puVar2 = puVar2 + 8;
    } while (iVar3 < *(int *)(param_1 + 0x244));
  }
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x244)) {
    puVar2 = (undefined4 *)(param_1 + 0x114);
    do {
      iVar1 = *(int *)(param_1 + 0x27c) * 0xc;
      iVar3 = iVar3 + 1;
      puVar2[-1] = ((*(uint *)(&DAT_004f9e78 + iVar1) | 0xffffff00) << 8 |
                   *(uint *)(&DAT_004f9e7c + iVar1)) << 8 | *(uint *)(&DAT_004f9e80 + iVar1);
      *puVar2 = 0;
      puVar2 = puVar2 + 8;
    } while (iVar3 < *(int *)(param_1 + 0x244));
  }
  if (fVar4 + fVar4 < (float10)*(int *)(param_1 + 0x280)) {
    *(undefined4 *)(param_1 + 0x280) = 0;
    *(int *)(param_1 + 0x27c) = *(int *)(param_1 + 0x27c) + 1;
  }
  if (3 < *(int *)(param_1 + 0x27c)) {
    *(undefined4 *)(param_1 + 0x27c) = 0;
  }
  return;
}

