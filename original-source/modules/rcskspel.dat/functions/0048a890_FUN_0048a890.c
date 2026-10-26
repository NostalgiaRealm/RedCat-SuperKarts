/*
 * FUN_0048a890 at 0048a890
 * undefined FUN_0048a890(void)
 * Address ranges: 0048a890-0048ac2c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x0048abc4) */
/* WARNING: Removing unreachable block (ram,0x0048abce) */

void __thiscall FUN_0048a890(int *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  int iStack_18;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (DAT_0053ba78 != 0) {
    if (param_1[3] < 1) {
      iVar2 = (**(code **)*param_1)();
      if ((0 < iVar2) && (iVar8 = 0, 0 < iVar2)) {
        do {
          iVar3 = FUN_004895d0();
          if (iVar3 == param_2) {
            cVar1 = FUN_00489610();
            if (cVar1 != '\0') {
              puVar4 = (undefined4 *)FUN_00489600();
              uStack_c = *puVar4;
              uStack_8 = puVar4[1];
              puVar7 = &uStack_c;
              uStack_4 = puVar4[2];
              uVar5 = FUN_004895d0(puVar7);
              FUN_00488a90(uVar5);
              FUN_00488d70(uVar5,puVar7);
            }
            uVar5 = (**(code **)(*param_1 + 8))();
            FUN_0048af00(uVar5);
            FUN_0048b220(*(int *)(param_1[1] + 8) + -0x120);
            iVar8 = iVar2;
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 < iVar2);
        return;
      }
    }
    else {
      iVar2 = (**(code **)*param_1)();
      if ((0 < iVar2) && (iVar8 = 0, 0 < iVar2)) {
        do {
          iVar3 = FUN_004895d0();
          if (iVar3 == param_2) {
            cVar1 = FUN_00489610();
            if (cVar1 != '\0') {
              puVar4 = (undefined4 *)FUN_00489600();
              uStack_c = *puVar4;
              uStack_8 = puVar4[1];
              puVar7 = &uStack_c;
              uStack_4 = puVar4[2];
              uVar5 = FUN_004895d0(puVar7);
              FUN_00488a90(uVar5);
              FUN_00488d70(uVar5,puVar7);
            }
            uVar5 = (**(code **)(*param_1 + 8))();
            FUN_0048af00(uVar5);
            FUN_0048b220(*(int *)(param_1[1] + 8) + -0x120);
            iVar8 = iVar2;
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 < iVar2);
      }
      iVar2 = (**(code **)*param_1)();
      if ((0 < iVar2) && (iVar8 = 0, 0 < iVar2)) {
        do {
          iVar3 = FUN_004895d0();
          if (iVar3 == param_2) {
            cVar1 = FUN_00489610();
            if (cVar1 != '\0') {
              puVar4 = (undefined4 *)FUN_00489600();
              uStack_c = *puVar4;
              uStack_8 = puVar4[1];
              puVar7 = &uStack_c;
              uStack_4 = puVar4[2];
              uVar5 = FUN_004895d0(puVar7);
              FUN_00488a90(uVar5);
              FUN_00488d70(uVar5,puVar7);
            }
            iVar3 = *(int *)(param_1[1] + 4);
            iVar6 = (**(code **)(*param_1 + 8))();
            iVar3 = iVar8 * 0x120 + iVar3;
            FUN_0048baa0(iVar6);
            iStack_18 = 7;
            puVar7 = (undefined4 *)(iVar3 + 8);
            do {
              puVar4 = (undefined4 *)((iVar6 - iVar3) + (int)puVar7);
              puVar9 = puVar7;
              for (iVar8 = 8; iVar8 != 0; iVar8 = iVar8 + -1) {
                *puVar9 = *puVar4;
                puVar4 = puVar4 + 1;
                puVar9 = puVar9 + 1;
              }
              iStack_18 = iStack_18 + -1;
              puVar7 = puVar7 + 8;
            } while (iStack_18 != 0);
            *(undefined4 *)(iVar3 + 0xe8) = *(undefined4 *)(iVar6 + 0xe8);
            *(undefined1 *)(iVar3 + 0xec) = *(undefined1 *)(iVar6 + 0xec);
            *(undefined4 *)(iVar3 + 0xf0) = *(undefined4 *)(iVar6 + 0xf0);
            *(undefined4 *)(iVar3 + 0xf4) = *(undefined4 *)(iVar6 + 0xf4);
            *(undefined4 *)(iVar3 + 0xf8) = *(undefined4 *)(iVar6 + 0xf8);
            *(undefined4 *)(iVar3 + 0xfc) = *(undefined4 *)(iVar6 + 0xfc);
            *(undefined1 *)(iVar3 + 0x100) = *(undefined1 *)(iVar6 + 0x100);
            *(undefined1 *)(iVar3 + 0x101) = *(undefined1 *)(iVar6 + 0x101);
            *(undefined1 *)(iVar3 + 0x102) = *(undefined1 *)(iVar6 + 0x102);
            *(undefined4 *)(iVar3 + 0x104) = *(undefined4 *)(iVar6 + 0x104);
            *(undefined1 *)(iVar3 + 0x108) = *(undefined1 *)(iVar6 + 0x108);
            *(undefined4 *)(iVar3 + 0x10c) = *(undefined4 *)(iVar6 + 0x10c);
            *(undefined4 *)(iVar3 + 0x110) = *(undefined4 *)(iVar6 + 0x110);
            *(undefined4 *)(iVar3 + 0x114) = *(undefined4 *)(iVar6 + 0x114);
            *(undefined4 *)(iVar3 + 0x118) = *(undefined4 *)(iVar6 + 0x118);
            *(undefined1 *)(iVar3 + 0x11c) = *(undefined1 *)(iVar6 + 0x11c);
            iVar8 = param_1[1];
            FUN_0048ba00(*(int *)(iVar8 + 8) + -0x120,*(int *)(iVar8 + 8));
            *(int *)(iVar8 + 8) = *(int *)(iVar8 + 8) + -0x120;
            param_1[3] = param_1[3] + -1;
            iVar8 = iVar2;
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 < iVar2);
      }
    }
  }
  return;
}

