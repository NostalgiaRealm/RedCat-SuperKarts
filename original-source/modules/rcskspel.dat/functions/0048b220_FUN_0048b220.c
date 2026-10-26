/*
 * FUN_0048b220 at 0048b220
 * undefined FUN_0048b220(void)
 * Address ranges: 0048b220-0048b367
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall FUN_0048b220(int param_1,int param_2)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  puVar2 = *(undefined1 **)(param_1 + 8);
  if ((undefined1 *)(param_2 + 0x120) != puVar2) {
    puVar5 = (undefined1 *)(param_2 + 0x20c);
    do {
      FUN_0048baa0(puVar5 + -0xec);
      iVar6 = 7;
      puVar3 = (undefined4 *)(puVar5 + -0x204);
      do {
        iVar6 = iVar6 + -1;
        puVar7 = (undefined4 *)(((int)(puVar5 + -0xec) - (int)(puVar5 + -0x20c)) + (int)puVar3);
        puVar8 = puVar3;
        for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
        puVar3 = puVar3 + 8;
      } while (iVar6 != 0);
      *(undefined4 *)(puVar5 + -0x124) = *(undefined4 *)(puVar5 + -4);
      puVar5[-0x120] = *puVar5;
      *(undefined4 *)(puVar5 + -0x11c) = *(undefined4 *)(puVar5 + 4);
      *(undefined4 *)(puVar5 + -0x118) = *(undefined4 *)(puVar5 + 8);
      *(undefined4 *)(puVar5 + -0x114) = *(undefined4 *)(puVar5 + 0xc);
      *(undefined4 *)(puVar5 + -0x110) = *(undefined4 *)(puVar5 + 0x10);
      puVar5[-0x10c] = puVar5[0x14];
      puVar5[-0x10b] = puVar5[0x15];
      puVar5[-0x10a] = puVar5[0x16];
      *(undefined4 *)(puVar5 + -0x108) = *(undefined4 *)(puVar5 + 0x18);
      puVar5[-0x104] = puVar5[0x1c];
      *(undefined4 *)(puVar5 + -0x100) = *(undefined4 *)(puVar5 + 0x20);
      *(undefined4 *)(puVar5 + -0xfc) = *(undefined4 *)(puVar5 + 0x24);
      *(undefined4 *)(puVar5 + -0xf8) = *(undefined4 *)(puVar5 + 0x28);
      puVar1 = puVar5 + 0x34;
      *(undefined4 *)(puVar5 + -0xf4) = *(undefined4 *)(puVar5 + 0x2c);
      puVar5[-0xf0] = puVar5[0x30];
      puVar5 = puVar5 + 0x120;
    } while (puVar1 != puVar2);
  }
  iVar4 = *(int *)(param_1 + 8);
  for (iVar6 = iVar4 + -0x120; iVar6 != iVar4; iVar6 = iVar6 + 0x120) {
    FUN_0048aca0();
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x120;
  return param_2;
}

