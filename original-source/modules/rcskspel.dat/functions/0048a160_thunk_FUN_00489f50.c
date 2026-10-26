/*
 * thunk_FUN_00489f50 at 0048a160
 * undefined thunk_FUN_00489f50(void)
 * Address ranges: 0048a160-0048a164
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Thunk: forwards to FUN_00489f50
 */

void __fastcall thunk_FUN_00489f50(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  int iVar11;
  undefined4 *puVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  undefined4 *puVar17;
  int iStack_30;
  
  iVar11 = (**(code **)*param_1)();
  iStack_30 = 0;
  if (iVar11 != 1 && -1 < iVar11 + -1) {
    do {
      iVar15 = (iStack_30 + 1) * 0x20;
      iVar16 = *(int *)(param_1[1] + 4);
      iVar13 = iStack_30 * 0x20;
      fVar1 = *(float *)(iVar13 + 4 + iVar16);
      fVar2 = *(float *)(iVar13 + 8 + iVar16);
      fVar3 = *(float *)(iVar16 + iVar15);
      fVar4 = *(float *)(iVar13 + 0x24 + iVar16);
      fVar5 = *(float *)(iVar13 + 0x28 + iVar16);
      fVar6 = 0.7;
      if ((iStack_30 < 6) && (0xc < iVar11)) {
        fVar6 = (float)(&DAT_004f9f0c)[iStack_30];
      }
      if ((char)param_1[0x47] != '\0') {
        fVar6 = fVar6 * 0.7;
      }
      fVar8 = (fVar3 + *(float *)(iVar13 + iVar16)) * 0.5;
      fVar9 = (fVar4 + fVar1) * 0.5;
      fVar10 = (fVar5 + fVar2) * 0.5;
      fVar2 = fVar2 - fVar10;
      fVar1 = fVar1 - fVar9;
      fVar7 = *(float *)(iVar13 + iVar16) - fVar8;
      if (0.25 <= fVar2 * fVar2 + fVar1 * fVar1 + fVar7 * fVar7) {
        *(float *)(iVar13 + iVar16) = fVar7 * fVar6 + fVar8;
        *(float *)(*(int *)(param_1[1] + 4) + 8 + iVar13) = fVar2 * fVar6 + fVar10;
        *(float *)(*(int *)(param_1[1] + 4) + 4 + iVar13) = fVar1 * fVar6 + fVar9;
        *(float *)(*(int *)(param_1[1] + 4) + iVar15) = (fVar3 - fVar8) * fVar6 + fVar8;
        *(float *)(*(int *)(param_1[1] + 4) + 0x28 + iVar13) = (fVar5 - fVar10) * fVar6 + fVar10;
        *(float *)(*(int *)(param_1[1] + 4) + 0x24 + iVar13) = (fVar4 - fVar9) * fVar6 + fVar9;
        iVar16 = iStack_30;
      }
      else {
        iVar16 = iVar11;
        if (iStack_30 < iVar11) {
          iStack_30 = iVar11 - iStack_30;
          do {
            iVar15 = *(int *)(param_1[1] + 4);
            puVar12 = (undefined4 *)(**(code **)(*param_1 + 8))();
            puVar17 = (undefined4 *)(iVar15 + iVar13);
            for (iVar14 = 8; iVar14 != 0; iVar14 = iVar14 + -1) {
              *puVar17 = *puVar12;
              puVar12 = puVar12 + 1;
              puVar17 = puVar17 + 1;
            }
            FUN_0048b1d0(*(int *)(param_1[1] + 8) + -0x20);
            iVar13 = iVar13 + 0x20;
            iStack_30 = iStack_30 + -1;
          } while (iStack_30 != 0);
        }
      }
      iStack_30 = iVar16 + 2;
    } while (iStack_30 < iVar11 + -1);
  }
  return;
}

