/*
 * FUN_0044bb50 at 0044bb50
 * undefined FUN_0044bb50(void)
 * Address ranges: 0044bb50-0044bdca
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x0044bbcb) */

undefined4 * FUN_0044bb50(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  char cVar1;
  undefined1 *puVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  void *pvVar7;
  uint uVar8;
  undefined4 *puVar9;
  int *piVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  
  if (param_1 == param_2) {
    return param_3;
  }
  piVar10 = param_3 + 0x15;
  puVar9 = param_1 + 0x11;
  do {
    *param_3 = *param_1;
    piVar10[-0x14] = puVar9[-0x10];
    piVar10[-0x13] = puVar9[-0xf];
    piVar10[-0x12] = puVar9[-0xe];
    piVar10[-0x11] = puVar9[-0xd];
    piVar10[-0x10] = puVar9[-0xc];
    piVar10[-0xf] = puVar9[-0xb];
    *(undefined1 *)(piVar10 + -0xe) = *(undefined1 *)(puVar9 + -10);
    FUN_00412870(puVar9 + -9,0,0xffffffff);
    FUN_00412870(puVar9 + -5,0,0xffffffff);
    uVar8 = puVar9[1];
    if (piVar10 + -5 == puVar9 + -1) {
      FUN_004478a0(uVar8,0xffffffff);
      FUN_004478a0(0,0);
    }
    else {
      if (uVar8 != 0) {
        puVar2 = (undefined1 *)*puVar9;
        if (puVar2 == (undefined1 *)0x0) {
          puVar2 = &DAT_004d2404;
        }
        if ((byte)puVar2[-1] < 0xfe) {
          FUN_0040b4f0(1);
          puVar2 = (undefined1 *)*puVar9;
          if (puVar2 == (undefined1 *)0x0) {
            puVar2 = &DAT_004d2404;
          }
          piVar10[-4] = (int)puVar2;
          piVar10[-3] = puVar9[1];
          piVar10[-2] = puVar9[2];
          puVar2[-1] = puVar2[-1] + '\x01';
          goto LAB_0044bc85;
        }
      }
      cVar1 = FUN_0040b600(uVar8,1);
      if (cVar1 != '\0') {
        puVar11 = (undefined4 *)*puVar9;
        if (puVar11 == (undefined4 *)0x0) {
          puVar11 = (undefined4 *)&DAT_004d2404;
        }
        puVar12 = (undefined4 *)piVar10[-4];
        for (uVar3 = uVar8 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
          *puVar12 = *puVar11;
          puVar11 = puVar11 + 1;
          puVar12 = puVar12 + 1;
        }
        for (uVar3 = uVar8 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
          *(undefined1 *)puVar12 = *(undefined1 *)puVar11;
          puVar11 = (undefined4 *)((int)puVar11 + 1);
          puVar12 = (undefined4 *)((int)puVar12 + 1);
        }
        piVar10[-3] = uVar8;
        *(undefined1 *)(piVar10[-4] + uVar8) = 0;
      }
    }
LAB_0044bc85:
    if (piVar10 + -1 != puVar9 + 3) {
      iVar5 = puVar9[4];
      if (iVar5 == 0) {
        uVar8 = 0;
      }
      else {
        uVar8 = puVar9[5] - iVar5 >> 2;
      }
      iVar6 = *piVar10;
      if (iVar6 == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = piVar10[1] - iVar6 >> 2;
      }
      if (uVar3 < uVar8) {
        uVar8 = FUN_0044ca80();
        uVar3 = FUN_00477770();
        if (uVar3 < uVar8) {
          FUN_0048b600(*piVar10,piVar10[1]);
          FUN_004bc150(*piVar10);
          iVar5 = FUN_0044ca80();
          if (iVar5 < 0) {
            iVar5 = 0;
          }
          pvVar7 = operator_new(iVar5 * 4);
          *piVar10 = (int)pvVar7;
          iVar5 = FUN_00476950(puVar9[4],puVar9[5],pvVar7);
          piVar10[1] = iVar5;
          piVar10[2] = iVar5;
        }
        else {
          iVar5 = puVar9[4];
          iVar6 = FUN_0044ca80();
          iVar5 = iVar5 + iVar6 * 4;
          FUN_0043afb0(puVar9[4],iVar5,*piVar10);
          FUN_00476950(iVar5,puVar9[5],piVar10[1]);
          iVar5 = FUN_0044ca80();
          piVar10[1] = *piVar10 + iVar5 * 4;
        }
      }
      else {
        uVar4 = FUN_0043afb0(iVar5,puVar9[5],iVar6);
        FUN_0048b600(uVar4,piVar10[1]);
        iVar5 = FUN_0044ca80();
        piVar10[1] = *piVar10 + iVar5 * 4;
      }
    }
    param_1 = param_1 + 0x18;
    param_3 = param_3 + 0x18;
    piVar10 = piVar10 + 0x18;
    puVar9 = puVar9 + 0x18;
    if (param_1 == param_2) {
      return param_3;
    }
  } while( true );
}

